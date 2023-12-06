#include <cmath>
#include <limits>

#include "utils.hpp"

#include "06.hpp"

using namespace std;
using namespace myg;

const regex Day06::RGX("(\\d+)");

int Day06::part_1(void) {
    int ret = 1;

    for (auto race : parse_races())
        ret *= Day06::n_winning_races(race);

    return ret;
}

int Day06::part_2(void) {
    return 0;
}

vector<race> Day06::parse_races(void) {
    vector<race> races;

    vector<string> times = myg::matches(_data[0], Day06::RGX);
    vector<string> distances = myg::matches(_data[1], Day06::RGX);

    for (int i = 0, n = times.size(); i < n; i++) {
        struct race a_race = { stoi(times[i]), stoi(distances[i]) };
        races.push_back(a_race);
    }

    return races;
}

int Day06::n_winning_races(const race& r) {
    double det = r.time * r.time - 4.0 * r.distance;

    if (det < 0)
        return 0;

    double t_p = -0.5 * (-r.time + sqrt(det));
    if (abs(t_p - ceil(t_p)) < 2.0 * numeric_limits<double>::min())
        t_p += 0.5;

    double t_m = -0.5 * (-r.time - sqrt(det));
    if (abs(t_m - floor(t_m)) < 2.0 * numeric_limits<double>::min())
        t_m -= 0.5;

    return static_cast<int>(ceil(t_m) - floor(t_p) - 1);
}
