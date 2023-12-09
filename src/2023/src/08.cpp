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
    const string rule = _data[0];
    graph_t g = build_graph();

    vector<string> start_nodes;
    for (auto i = g.begin(); i != g.end(); ++i)
        if (i->first.back() == 'A')
            start_nodes.push_back(i->first);

    vector<string> end_nodes;
    for (auto i = g.begin(); i != g.end(); ++i)
        if (i->first.back() == 'Z')
            end_nodes.push_back(i->first);

    uint steps = 0;
    uint i = 0;
    uint n = rule.size();
    vector<string> next_nodes(start_nodes);

    while (!all_end_nodes(next_nodes)) {
        vector<string> nn;

        if (rule[i] == 'L') {
            for (auto node : next_nodes)
                nn.push_back(g[node].first);
        } else {
            for (auto node : next_nodes)
                nn.push_back(g[node].second);
        }

        next_nodes = nn;
        i = (i + 1) % n;
        steps++;
    }

    return steps;
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

bool Day08::all_end_nodes(const vector<string>& nodes) {
    for (auto node : nodes)
        if (node.back() != 'Z')
            return false;
    return true;
}
