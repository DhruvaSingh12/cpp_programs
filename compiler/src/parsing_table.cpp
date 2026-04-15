#include "parsing_table.h"

#include <ostream>
#include <sstream>

using namespace std;

namespace elite {
namespace {
void registerEntry(
    TableBuildResult &result,
    const Symbol &nonTerminal,
    const Symbol &lookahead,
    const Sequence &production) {
    Sequence &cell = result.table[nonTerminal][lookahead];

    if (!cell.empty() && cell != production) {
        ostringstream message;
        message << "Conflict at M[" << nonTerminal << ", " << lookahead
                << "] between \"" << sequenceToString(cell)
                << "\" and \"" << sequenceToString(production) << '"';
        result.conflicts.push_back(message.str());
        return;
    }

    cell = production;
}
} // namespace

TableBuildResult buildParsingTable(
    const Grammar &grammar,
    const FirstSets &firstSets,
    const FollowSets &followSets) {
    TableBuildResult result;

    for (const auto &rule : grammar.rules) {
        for (const auto &alternative : rule.alternatives) {
            const set<Symbol> first =
                firstOfSequence(alternative, grammar, firstSets);

            for (const auto &symbol : first) {
                if (!isEpsilon(symbol)) {
                    registerEntry(result, rule.lhs, symbol, alternative);
                }
            }

            if (first.find(kEpsilon) != first.end()) {
                const auto followIt = followSets.find(rule.lhs);
                if (followIt == followSets.end()) {
                    continue;
                }

                for (const auto &symbol : followIt->second) {
                    registerEntry(result, rule.lhs, symbol, alternative);
                }
            }
        }
    }

    return result;
}

void printParsingTable(const TableBuildResult &result, ostream &out) {
    for (const auto &row : result.table) {
        for (const auto &cell : row.second) {
            out << "M[" << row.first << ", " << cell.first << "] = "
                << sequenceToString(cell.second) << '\n';
        }
    }
}
} // namespace elite
