#include "first_follow.h"
#include <ostream>
using namespace std;

namespace elite{
    namespace{
        bool insertSymbol(set<Symbol> &target, const Symbol &value){
            return target.insert(value).second;
        }
    } // namespace

    set<Symbol> firstOfSequence(
        const Sequence &sequence,
        const Grammar &grammar,
        const FirstSets &firstSets){
        set<Symbol> result;

        if (sequence.empty() || (sequence.size() == 1U && isEpsilon(sequence.front()))){
            result.insert(kEpsilon);
            return result;
        }

        bool allNullable = true;

        for (const auto &symbol : sequence){
            if (isEpsilon(symbol)){
                continue;
            }

            if (!grammar.isNonTerminal(symbol)){
                result.insert(symbol);
                allNullable = false;
                break;
            }

            const auto firstIt = firstSets.find(symbol);
            const set<Symbol> currentFirst =
                (firstIt != firstSets.end()) ? firstIt->second : set<Symbol>{};

            for (const auto &item : currentFirst){
                if (!isEpsilon(item)){
                    result.insert(item);
                }
            }

            if (currentFirst.find(kEpsilon) == currentFirst.end()){
                allNullable = false;
                break;
            }
        }

        if (allNullable){
            result.insert(kEpsilon);
        }

        return result;
    }

    FirstSets computeFirstSets(const Grammar &grammar){
        FirstSets firstSets;

        for (const auto &nonTerminal : grammar.nonTerminals){
            firstSets[nonTerminal];
        }

        bool changed = true;
        while (changed){
            changed = false;

            for (const auto &rule : grammar.rules){
                auto &first = firstSets[rule.lhs];

                for (const auto &alternative : rule.alternatives){
                    const set<Symbol> alternativeFirst =
                        firstOfSequence(alternative, grammar, firstSets);

                    for (const auto &symbol : alternativeFirst){
                        changed = insertSymbol(first, symbol) || changed;
                    }
                }
            }
        }

        return firstSets;
    }

    FollowSets computeFollowSets(const Grammar &grammar, const FirstSets &firstSets){
        FollowSets followSets;

        for (const auto &nonTerminal : grammar.nonTerminals){
            followSets[nonTerminal];
        }

        if (!grammar.empty()){
            followSets[grammar.startSymbol].insert(kEndMarker);
        }

        bool changed = true;
        while (changed){
            changed = false;

            for (const auto &rule : grammar.rules){
                for (const auto &alternative : rule.alternatives){
                    if (alternative.size() == 1U && isEpsilon(alternative.front())){
                        continue;
                    }

                    for (size_t index = 0; index < alternative.size(); ++index){
                        const Symbol &current = alternative[index];
                        if (!grammar.isNonTerminal(current)){
                            continue;
                        }

                        Sequence suffix(alternative.begin() + index + 1, alternative.end());
                        const set<Symbol> suffixFirst =
                            firstOfSequence(suffix, grammar, firstSets);

                        for (const auto &symbol : suffixFirst){
                            if (!isEpsilon(symbol)){
                                changed = insertSymbol(followSets[current], symbol) || changed;
                            }
                        }

                        if (suffix.empty() || suffixFirst.find(kEpsilon) != suffixFirst.end()){
                            for (const auto &symbol : followSets[rule.lhs]){
                                changed = insertSymbol(followSets[current], symbol) || changed;
                            }
                        }
                    }
                }
            }
        }

        return followSets;
    }

    void printFirstSets(const FirstSets &firstSets, ostream &out){
        for (const auto &entry : firstSets){
            out << entry.first << " : ";

            bool firstItem = true;
            for (const auto &symbol : entry.second){
                if (!firstItem){
                    out << ' ';
                }
                out << symbol;
                firstItem = false;
            }

            out << '\n';
        }
    }

    void printFollowSets(const FollowSets &followSets, ostream &out){
        for (const auto &entry : followSets){
            out << entry.first << " : ";

            bool firstItem = true;
            for (const auto &symbol : entry.second){
                if (!firstItem){
                    out << ' ';
                }
                out << symbol;
                firstItem = false;
            }

            out << '\n';
        }
    }
} // namespace elite