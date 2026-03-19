#include "left_recursion.h"

#include <algorithm>

using namespace std;

namespace elite {
namespace {
void addNonTerminal(Grammar &grammar, const Symbol &symbol) {
    if (!grammar.isNonTerminal(symbol)) {
        grammar.nonTerminals.push_back(symbol);
    }
}

Symbol makePrimeSymbol(const Grammar &grammar, const Symbol &lhs) {
    Symbol candidate = lhs + "'";

    while (grammar.isNonTerminal(candidate)) {
        candidate += "'";
    }

    return candidate;
}

void substituteLeadingRule(Rule &target, const Rule &processedRule) {
    vector<Sequence> expandedAlternatives;

    for (const auto &alternative : target.alternatives) {
        if (!alternative.empty() && alternative.front() == processedRule.lhs) {
            Sequence suffix(alternative.begin() + 1, alternative.end());
            suffix = normalizeSequence(move(suffix));

            for (const auto &replacement : processedRule.alternatives) {
                expandedAlternatives.push_back(
                    concatenateSequences(replacement, suffix));
            }
        } else {
            expandedAlternatives.push_back(alternative);
        }
    }

    target.alternatives = move(expandedAlternatives);
}

void removeImmediateLeftRecursion(Grammar &grammar, size_t index) {
    Rule &rule = grammar.rules[index];
    vector<Sequence> recursiveAlternatives;
    vector<Sequence> nonRecursiveAlternatives;

    for (const auto &alternative : rule.alternatives) {
        if (!alternative.empty() && alternative.front() == rule.lhs) {
            Sequence tail(alternative.begin() + 1, alternative.end());
            recursiveAlternatives.push_back(normalizeSequence(move(tail)));
        } else {
            nonRecursiveAlternatives.push_back(alternative);
        }
    }

    if (recursiveAlternatives.empty()) {
        return;
    }

    if (nonRecursiveAlternatives.empty()) {
        nonRecursiveAlternatives.push_back({kEpsilon});
    }

    const Symbol primeSymbol = makePrimeSymbol(grammar, rule.lhs);
    Rule primeRule;
    primeRule.lhs = primeSymbol;

    vector<Sequence> rewrittenAlternatives;
    rewrittenAlternatives.reserve(nonRecursiveAlternatives.size());

    for (const auto &beta : nonRecursiveAlternatives) {
        rewrittenAlternatives.push_back(
            concatenateSequences(beta, Sequence{primeSymbol}));
    }

    for (const auto &alpha : recursiveAlternatives) {
        primeRule.alternatives.push_back(
            concatenateSequences(alpha, Sequence{primeSymbol}));
    }
    primeRule.alternatives.push_back({kEpsilon});

    rule.alternatives = move(rewrittenAlternatives);
    addNonTerminal(grammar, primeSymbol);
    grammar.rules.push_back(move(primeRule));
}
} // namespace

void removeLeftRecursion(Grammar &grammar) {
    for (size_t current = 0; current < grammar.rules.size(); ++current) {
        for (size_t previous = 0; previous < current; ++previous) {
            substituteLeadingRule(grammar.rules[current], grammar.rules[previous]);
        }

        removeImmediateLeftRecursion(grammar, current);
    }
}
} // namespace elite
