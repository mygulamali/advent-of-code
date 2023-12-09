// TODO: remove <iostream>
#include <iostream>

#include "utils.hpp"

#include "09.hpp"

using namespace std;
using namespace myg;

const regex Day09::RGX("(\\-?\\d+)");

int Day09::part_1(void) {
    int total = 0;

    for (auto str : _data) {
        // create first history
        vector<string> h_str = myg::matches(str, RGX);
        int n = h_str.size();
        vector<int> h_int(n);
        for (int i = 0; i < n; i++)
            h_int[i] = stoi(h_str[i]);

        // create subsequent histories until history is all zeros
        vector<vector<int>> h;
        h.push_back(h_int);
        while (!all_zeros(h.back())) {
            vector<int> current = h.back();
            int m = current.size();

            vector<int> next(m - 1);
            for (int i = 0; i < m - 1; i++)
                next[i] = current[i + 1] - current[i];

            h.push_back(next);
        }

        // backtrack to predict new value
        int m = h.size() - 1;
        h[m].push_back(0);
        for (int i = m; i > 0; --i)
            h[i - 1].push_back(h[i].back() + h[i - 1].back());

        total += h[0].back();
    }

    return total;
}

int Day09::part_2(void) {
    return 0;
}

bool Day09::all_zeros(const vector<int>& v) {
    for (auto e : v)
        if (e != 0) return false;
    return true;
}
