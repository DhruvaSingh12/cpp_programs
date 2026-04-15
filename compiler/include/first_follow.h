#pragma once

#include "grammar.h"

#include <iosfwd>
#include <set>

using namespace std;

namespace elite {
    set<Symbol> firstOfSequence(
        const Sequence &sequence,
        const Grammar &grammar,
        const FirstSets &firstSets);
    FirstSets computeFirstSets(const Grammar &grammar);
    FollowSets computeFollowSets(const Grammar &grammar, const FirstSets &firstSets);
    void printFirstSets(const FirstSets &firstSets, ostream &out);
    void printFollowSets(const FollowSets &followSets, ostream &out);
} // namespace elite