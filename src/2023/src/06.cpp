#include <cmath>
#include <limits>

#include "utils.hpp"

#include "06.hpp"

using namespace std;
using namespace myg;

const regex Day06::RGX("(\\d+)");

ulong Day06::part_1(void) {
    ulong ret = 1;

    for (auto r : parse_races())
        ret *= Day06::n_winning_races(r);

    return ret;
}

int Day06::part_2(void) {
    return 0;
}

vector<race> Day06::parse_races(void) {
    vector<string> times = myg::matches(_data[0], Day06::RGX);
    vector<string> distances = myg::matches(_data[1], Day06::RGX);

    uint n = times.size();
    vector<race> races(n);
    for (uint i = 0; i < n; i++) {
        struct race r = { stoul(times[i]), stoul(distances[i]) };
        races[i] = r;
    }

    return races;
}

ulong Day06::n_winning_races(const race& r) {
    double t = static_cast<double>(r.time);
    double d = static_cast<double>(r.distance);
    double det = t * t - 4.0 * d;

    if (det <= 2.0 * numeric_limits<double>::min())
        return 0;

    double t_p = -0.5 * (-t + sqrt(det));
    if (abs(t_p - ceil(t_p)) <= 2.0 * numeric_limits<double>::min())
        t_p += 2.0 * numeric_limits<double>::min();

    double t_m = -0.5 * (-t - sqrt(det));
    if (abs(t_m - floor(t_m)) <= 2.0 * numeric_limits<double>::min())
        t_m -= 2.0 * numeric_limits<double>::min();

    return static_cast<ulong>(ceil(t_m) - floor(t_p) - 1);
}
