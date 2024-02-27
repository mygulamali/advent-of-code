#include "utils.hpp"

#include "09.hpp"

using namespace std;
using namespace myg;

const regex Day09::RGX("(\\-?\\d+)");

int Day09::part_1(void) {
    int total = 0;

    for (auto str : _data) {
        vector<deque<int>> h = create_histories(str);

        // backtrack to predict new value at end of history
        int m = h.size() - 1;
        h[m].push_back(0);
        for (int i = m; i > 0; --i)
            h[i - 1].push_back(h[i].back() + h[i - 1].back());

        total += h[0].back();
    }

    return total;
}

int Day09::part_2(void) {
    int total = 0;

    for (auto str : _data) {
        vector<deque<int>> h = create_histories(str);

        // backtrack to predict new value at beginning of history
        int m = h.size() - 1;
        h[m].push_front(0);
        for (int i = m; i > 0; --i)
            h[i - 1].push_front(h[i - 1].front() - h[i].front());

        total += h[0].front();
    }

    return total;
}

const vector<deque<int>> Day09::create_histories(const string& s) const {
    // create first history
    vector<string> h_str = myg::matches(s, RGX);
    int n = h_str.size();
    deque<int> h_int(n);
    for (int i = 0; i < n; i++)
        h_int[i] = stoi(h_str[i]);

    // create subsequent histories until history is all zeros
    vector<deque<int>> ret;
    ret.push_back(h_int);
    while (!all_zeros(ret.back())) {
        deque<int> current = ret.back();
        int m = current.size();

        deque<int> next(m - 1);
        for (int i = 0; i < m - 1; i++)
            next[i] = current[i + 1] - current[i];

        ret.push_back(next);
    }

    return ret;
};

bool Day09::all_zeros(const deque<int>& d) {
    for (auto e : d)
        if (e != 0) return false;
    return true;
}
