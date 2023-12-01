#pragma once

#include <regex>
#include <unordered_map>

#include "problem.hpp"

namespace myg {
    class Day01: public Problem {
    public:
        using Problem::Problem;

        static const int VAL_0;
        static const int VAL_9;
        static const std::regex RGX;
        static const std::unordered_map<std::string, char> NUMBER_MAP;

        int part_1(void);
        int part_2(void);

    private:
        bool is_numeric(const char& c);
        char as_number(const std::string& s);
    };
};
