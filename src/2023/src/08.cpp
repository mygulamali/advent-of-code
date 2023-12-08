#include <iostream>

#include "utils.hpp"

#include "08.hpp"

using namespace std;
using namespace myg;

const regex Day08::RGX("(\\w{3})");

int Day08::part_1(void) {
    const string rule = _data[0];
    graph_t g = build_graph();

    string start("AAA");
    string end("ZZZ");

    uint steps = 0;
    uint i = 0;
    uint n = rule.size();
    string next = start;
    while (next != end) {
        if (rule[i] == 'L')
            next = g[next].first;
        else
            next = g[next].second;
        i = (i + 1) % n;
        steps++;
    }

    return steps;
}

int Day08::part_2(void) {
    return 0;
}

const graph_t Day08::build_graph() const {
    graph_t g;

    for (int i = 2, n = _data.size(); i < n; i++) {
        vector<string> m = myg::matches(_data[i], Day08::RGX);
        pair<string, string> p(m[1], m[2]);
        g[m[0]] = p;
    }

    return g;
}
