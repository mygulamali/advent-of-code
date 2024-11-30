#include <set>

#include "11.hpp"

using namespace std;
using namespace myg;

Universe::Universe(const vector<string> data) {
    _height = data.size();
    _width = data[0].size();
    _galaxies = vector<galaxy>();

    for (auto i = ZERO; i < _height; i++)
        for (auto j = ZERO; j < _width; j++) {
            if (data[i][j] == '#') {
                const uint x = static_cast<uint>(i);
                const uint y = static_cast<uint>(j);
                struct galaxy g = { x, y };

                _galaxies.push_back(g);
            }
        }

    _n = _galaxies.size();
}

void Universe::expand(const uint amount) {
    set<uint> x_voids = set<uint>();
    for (auto i = ZERO; i < _width; i++)
        x_voids.insert(static_cast<uint>(i));

    set<uint> y_voids = set<uint>();
    for (auto i = ZERO; i < _height; i++)
        y_voids.insert(static_cast<uint>(i));

    for (auto g: _galaxies) {
        x_voids.erase(g.x);
        y_voids.erase(g.y);
    }

    vector<galaxy> new_galaxies = vector<galaxy>(_galaxies);
    uint new_width = static_cast<uint>(_width);
    uint new_height = static_cast<uint>(_height);
    const uint expansion = amount - 1;

    for (auto i = ZERO; i < _n; i++) {
        for (auto x: x_voids)
            if (_galaxies[i].x > x) {
                new_galaxies[i].x += expansion;
                new_width = max(new_width, new_galaxies[i].x);
            }

        for (auto y: y_voids)
            if (_galaxies[i].y > y) {
                new_galaxies[i].y += expansion;
                new_height = max(new_height, new_galaxies[i].y);
            }
    }

    _galaxies = new_galaxies;
    _width = static_cast<size_t>(new_width);
    _height = static_cast<size_t>(new_height);
};

ulong Universe::total_distance(void) const {
    ulong d_total = 0;

    for (auto i = ZERO; i < _n; i++)
        for (auto j = i + 1; j < _n; j++)
            d_total += distance(i, j);

    return d_total;
};

ulong Universe::distance(const size_t i, const size_t j) const {
    const uint d_horizontal =
        _galaxies[i].x < _galaxies[j].x ?
        _galaxies[j].x - _galaxies[i].x :
        _galaxies[i].x - _galaxies[j].x;

    const uint d_vertical =
        _galaxies[i].y < _galaxies[j].y ?
        _galaxies[j].y - _galaxies[i].y :
        _galaxies[i].y - _galaxies[j].y;

    return static_cast<ulong>(d_horizontal) + static_cast<ulong>(d_vertical);
};

ulong Day11::part_1(void) {
    return part_2(2);
};

ulong Day11::part_2(const uint amount) {
    Universe u = Universe(_data);
    u.expand(amount);
    return u.total_distance();
};
