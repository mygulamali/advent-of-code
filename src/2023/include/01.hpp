#pragma once

#include "problem.hpp"

namespace myg {
    class Day01: public Problem {
    public:
        using Problem::Problem;

        static const int VAL_0;
        static const int VAL_9;

        int part_1(void);

    private:
        bool is_numeric(const char& c);
    };
};
