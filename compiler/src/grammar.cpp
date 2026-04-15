#include "grammar.h"

#include <algorithm>
#include <ostream>
#include <sstream>

using namespace std;

namespace elite {
bool Grammar::empty() const {
    return rules.empty();
}

bool Grammar::isNonTerminal(const Symbol &symbol) const {
    return find(nonTerminals.begin(), nonTerminals.end(), symbol) != nonTerminals.end();
}

bool isEpsilon(const Symbol &symbol) {
    return symbol == kEpsilon;
}

Sequence normalizeSequence(Sequence sequence) {
    if (sequence.empty()) {
        return {kEpsilon};
    }

    if (sequence.size() > 1U) {
        sequence.erase(
            remove(sequence.begin(), sequence.end(), kEpsilon),
            sequence.end());
    }

    if (sequence.empty()) {
        return {kEpsilon};
    }

    return sequence;
}

Sequence concatenateSequences(const Sequence &prefix, const Sequence &suffix) {
    Sequence combined;

    if (!(prefix.size() == 1U && isEpsilon(prefix.front()))) {
        combined.insert(combined.end(), prefix.begin(), prefix.end());
    }

    if (!(suffix.size() == 1U && isEpsilon(suffix.front()))) {
        combined.insert(combined.end(), suffix.begin(), suffix.end());
    }

    return normalizeSequence(move(combined));
}

string sequenceToString(const Sequence &sequence) {
    if (sequence.empty()) {
        return kEpsilon;
    }

    ostringstream builder;

    for (size_t index = 0; index < sequence.size(); ++index) {
        if (index != 0U) {
            builder << ' ';
        }
        builder << sequence[index];
    }

    return builder.str();
}

void printGrammar(const Grammar &grammar, ostream &out) {
    for (const auto &rule : grammar.rules) {
        out << rule.lhs << " -> ";

        for (size_t index = 0; index < rule.alternatives.size(); ++index) {
            if (index != 0U) {
                out << " | ";
            }
            out << sequenceToString(rule.alternatives[index]);
        }

        out << '\n';
    }
}

void printParseTree(const ParseNode *node, ostream &out, int level) {
    if (node == nullptr) {
        return;
    }

    for (int index = 0; index < level; ++index) {
        out << "  ";
    }
    out << node->value << '\n';

    for (const auto &child : node->children) {
        printParseTree(child.get(), out, level + 1);
    }
}
} // namespace elite
