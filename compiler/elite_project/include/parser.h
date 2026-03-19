#pragma once

#include "parsing_table.h"

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace elite {
struct ParseResult {
    bool accepted = false;
    vector<string> steps;
    string errorMessage;
    unique_ptr<ParseNode> tree;
};

ParseResult parseInput(
    const Grammar &grammar,
    const ParsingTable &table,
    const Sequence &inputTokens);
} // namespace elite
