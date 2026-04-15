#include "first_follow.h"
#include "grammar.h"
#include "grammar_io.h"
#include "left_recursion.h"
#include "parser.h"
#include "parsing_table.h"

#include <exception>
#include <iostream>

using namespace std;

int main() {
    try {
        elite::Grammar grammar = elite::readGrammar(cin, cout);

        elite::removeLeftRecursion(grammar);

        const elite::FirstSets firstSets = elite::computeFirstSets(grammar);
        const elite::FollowSets followSets = elite::computeFollowSets(grammar, firstSets);
        const elite::TableBuildResult tableResult =
            elite::buildParsingTable(grammar, firstSets, followSets);

        cout << "\nGrammar after removing left recursion:\n";
        elite::printGrammar(grammar, cout);

        cout << "\nFIRST sets:\n";
        elite::printFirstSets(firstSets, cout);

        cout << "\nFOLLOW sets:\n";
        elite::printFollowSets(followSets, cout);

        cout << "\nLL(1) Parsing Table:\n";
        elite::printParsingTable(tableResult, cout);

        if (!tableResult.conflicts.empty()) {
            cout << "\nConflicts detected:\n";
            for (const auto &conflict : tableResult.conflicts) {
                cout << conflict << '\n';
            }
        }

        const elite::Sequence inputTokens = elite::readInputTokens(cin, cout);
        const elite::ParseResult parseResult =
            elite::parseInput(grammar, tableResult.table, inputTokens);

        cout << "\nParsing Steps:\n";
        for (const auto &step : parseResult.steps) {
            cout << step << '\n';
        }

        cout << "\nResult: "
             << (parseResult.accepted ? "ACCEPTED" : "REJECTED") << '\n';

        if (!parseResult.errorMessage.empty()) {
            cout << "Reason: " << parseResult.errorMessage << '\n';
        }

        if (parseResult.tree) {
            cout << "\nParse Tree:\n";
            elite::printParseTree(parseResult.tree.get(), cout);
        }
    } catch (const exception &error) {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
