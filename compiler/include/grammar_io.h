#pragma once

#include "grammar.h"

#include <iosfwd>

using namespace std;

namespace elite {
Grammar readGrammar(istream &in, ostream &out);
Sequence readInputTokens(istream &in, ostream &out);
} // namespace elite
