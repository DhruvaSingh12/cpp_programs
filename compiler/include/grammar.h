#pragma once

#include <iosfwd>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace elite {
constexpr const char kEpsilon[] = "eps";
constexpr const char kEndMarker[] = "$";

using Symbol = string;
using Sequence = vector<Symbol>;

struct Rule {
    Symbol lhs;
    vector<Sequence> alternatives;
};

struct Grammar {
    vector<Rule> rules;
    vector<Symbol> nonTerminals;
    Symbol startSymbol;

    bool empty() const;
    bool isNonTerminal(const Symbol &symbol) const;
};

struct ParseNode {
    explicit ParseNode(Symbol value = {}) : value(move(value)) {}

    Symbol value;
    vector<unique_ptr<ParseNode>> children;
};

using FirstSets = map<Symbol, set<Symbol>>;
using FollowSets = map<Symbol, set<Symbol>>;
using ParsingTable = map<Symbol, map<Symbol, Sequence>>;

bool isEpsilon(const Symbol &symbol);
Sequence normalizeSequence(Sequence sequence);
Sequence concatenateSequences(const Sequence &prefix, const Sequence &suffix);
string sequenceToString(const Sequence &sequence);
void printGrammar(const Grammar &grammar, ostream &out);
void printParseTree(const ParseNode *node, ostream &out, int level = 0);
} // namespace elite
