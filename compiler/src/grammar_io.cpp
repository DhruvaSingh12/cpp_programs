#include "grammar_io.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace elite {
namespace {
void replaceAll(string &text, const string &from, const string &to) {
    if (from.empty()) {
        return;
    }

    size_t start = 0;
    while ((start = text.find(from, start)) != string::npos) {
        text.replace(start, from.length(), to);
        start += to.length();
    }
}

vector<string> splitTokens(const string &line) {
    string prepared = line;
    replaceAll(prepared, "->", " -> ");
    replaceAll(prepared, "|", " | ");

    istringstream input(prepared);
    vector<string> tokens;
    string token;

    while (input >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

string normalizeUserToken(string token) {
    string lowered = token;
    transform(
        lowered.begin(),
        lowered.end(),
        lowered.begin(),
        [](unsigned char ch) {
            return static_cast<char>(tolower(ch));
        });

    if (lowered == "eps" || lowered == "epsilon") {
        return kEpsilon;
    }

    return token;
}

void addNonTerminal(Grammar &grammar, const Symbol &lhs) {
    if (!grammar.isNonTerminal(lhs)) {
        grammar.nonTerminals.push_back(lhs);
    }
}

void appendRule(Grammar &grammar, Rule rule) {
    addNonTerminal(grammar, rule.lhs);

    auto existing = find_if(
        grammar.rules.begin(),
        grammar.rules.end(),
        [&](const Rule &candidate) {
            return candidate.lhs == rule.lhs;
        });

    if (existing != grammar.rules.end()) {
        existing->alternatives.insert(
            existing->alternatives.end(),
            rule.alternatives.begin(),
            rule.alternatives.end());
        return;
    }

    grammar.rules.push_back(move(rule));
}

Rule parseProductionLine(const string &line) {
    const vector<string> tokens = splitTokens(line);

    if (tokens.size() < 3U) {
        throw runtime_error("Production must look like A -> alpha | beta");
    }

    if (tokens[1] != "->" && tokens[1] != "-") {
        throw runtime_error("Use -> or - after the non-terminal");
    }

    Rule rule;
    rule.lhs = tokens[0];

    Sequence current;
    for (size_t index = 2; index < tokens.size(); ++index) {
        if (tokens[index] == "|") {
            rule.alternatives.push_back(normalizeSequence(move(current)));
            current.clear();
            continue;
        }

        current.push_back(normalizeUserToken(tokens[index]));
    }

    rule.alternatives.push_back(normalizeSequence(move(current)));
    return rule;
}
} // namespace

Grammar readGrammar(istream &in, ostream &out) {
    Grammar grammar;

    out << "Enter number of productions: " << flush;

    int productionCount = 0;
    if (!(in >> productionCount)) {
        throw runtime_error("Failed to read the number of productions");
    }

    in.ignore(numeric_limits<streamsize>::max(), '\n');

    if (productionCount <= 0) {
        throw runtime_error("Number of productions must be positive");
    }

    for (int index = 0; index < productionCount;) {
        out << "Enter production " << (index + 1) << ": " << flush;

        string line;
        getline(in, line);

        if (line.empty()) {
            out << "Please enter a production.\n";
            continue;
        }

        try {
            appendRule(grammar, parseProductionLine(line));
            ++index;
        } catch (const exception &error) {
            out << "Invalid production: " << error.what() << '\n';
        }
    }

    if (!grammar.rules.empty()) {
        grammar.startSymbol = grammar.rules.front().lhs;
    }

    return grammar;
}

Sequence readInputTokens(istream &in, ostream &out) {
    out << "Enter input tokens separated by spaces: " << flush;

    string line;
    getline(in, line);

    Sequence tokens;
    for (auto &token : splitTokens(line)) {
        if (token == "|" || token == "->" || token == "-") {
            continue;
        }
        tokens.push_back(normalizeUserToken(token));
    }

    if (!tokens.empty() && tokens.back() == kEndMarker) {
        tokens.pop_back();
    }

    return tokens;
}
} // namespace elite