#pragma once

#include "problem.hpp"

#define ZERO static_cast<size_t>(0)

namespace myg {
    struct galaxy {
        uint x;
        uint y;
    };

    class Universe {
    public:
        Universe(const std::vector<std::string> data);

        void expand(const uint amount);
        ulong total_distance(void) const;

    protected:
        std::vector<galaxy> _galaxies;
        size_t _height;
        size_t _width;
        size_t _n;

        ulong distance(const size_t i, const size_t j) const;
    };

    class Day11: public Problem {
    public:
        using Problem::Problem;

        ulong part_1(void);
        ulong part_2(const uint amount);
    };
};
