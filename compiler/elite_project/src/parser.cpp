#include "parser.h"

#include <sstream>

using namespace std;

namespace elite {
namespace {
struct StackFrame {
    Symbol symbol;
    ParseNode *node;
};

string formatStack(const vector<StackFrame> &stack) {
    ostringstream out;

    for (size_t index = 0; index < stack.size(); ++index) {
        if (index != 0U) {
            out << ' ';
        }
        out << stack[index].symbol;
    }

    return out.str();
}

string formatRemainingInput(const Sequence &tokens, size_t currentIndex) {
    ostringstream out;

    for (size_t index = currentIndex; index < tokens.size(); ++index) {
        if (index != currentIndex) {
            out << ' ';
        }
        out << tokens[index];
    }

    return out.str();
}
} // namespace

ParseResult parseInput(
    const Grammar &grammar,
    const ParsingTable &table,
    const Sequence &inputTokens) {
    ParseResult result;

    if (grammar.empty()) {
        result.errorMessage = "Grammar is empty.";
        return result;
    }

    Sequence tokens = inputTokens;
    tokens.push_back(kEndMarker);

    result.tree = make_unique<ParseNode>(grammar.startSymbol);

    vector<StackFrame> stack;
    stack.push_back({kEndMarker, nullptr});
    stack.push_back({grammar.startSymbol, result.tree.get()});

    size_t inputIndex = 0;

    while (!stack.empty()) {
        result.steps.push_back(
            "Stack: " + formatStack(stack) +
            " | Input: " + formatRemainingInput(tokens, inputIndex));

        const StackFrame top = stack.back();
        stack.pop_back();

        const Symbol &currentToken = tokens[inputIndex];

        if (top.symbol == currentToken) {
            ++inputIndex;
            continue;
        }

        if (!grammar.isNonTerminal(top.symbol)) {
            result.errorMessage =
                "Unexpected token \"" + currentToken +
                "\" while matching \"" + top.symbol + "\".";
            result.tree.reset();
            return result;
        }

        const auto rowIt = table.find(top.symbol);
        if (rowIt == table.end()) {
            result.errorMessage = "No parsing-table row exists for " + top.symbol + '.';
            result.tree.reset();
            return result;
        }

        const auto cellIt = rowIt->second.find(currentToken);
        if (cellIt == rowIt->second.end()) {
            result.errorMessage =
                "No rule for (" + top.symbol + ", " + currentToken + ").";
            result.tree.reset();
            return result;
        }

        const Sequence &production = cellIt->second;

        if (production.size() == 1U && isEpsilon(production.front())) {
            if (top.node != nullptr) {
                top.node->children.push_back(make_unique<ParseNode>(kEpsilon));
            }
            continue;
        }

        if (top.node != nullptr) {
            for (const auto &symbol : production) {
                top.node->children.push_back(make_unique<ParseNode>(symbol));
            }

            for (size_t index = production.size(); index > 0U; --index) {
                stack.push_back({production[index - 1], top.node->children[index - 1].get()});
            }
        }
    }

    if (inputIndex == tokens.size()) {
        result.accepted = true;
        return result;
    }

    result.errorMessage = "Input was not fully consumed.";
    result.tree.reset();
    return result;
}
} // namespace elite
