#pragma once

#include "first_follow.h"

#include <iosfwd>
#include <string>
#include <vector>

using namespace std;

namespace elite {
struct TableBuildResult {
    ParsingTable table;
    vector<string> conflicts;
};

TableBuildResult buildParsingTable(
    const Grammar &grammar,
    const FirstSets &firstSets,
    const FollowSets &followSets);
void printParsingTable(const TableBuildResult &result, ostream &out);
} // namespace elite
