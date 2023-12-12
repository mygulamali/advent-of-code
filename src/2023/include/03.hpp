#pragma once

#include <regex>
#include <tuple>

#include "problem.hpp"

namespace myg {
    typedef std::vector<std::tuple<std::string, int, int>> numbers_t;

    class Day03: public Problem {
    public:
        Day03(const std::string& filename);
        Day03(const std::vector<std::string>& data);

        static const std::regex RGX;

        int part_1(void);
        int part_2(void);

    private:
        int       _height;
        int       _width;
        numbers_t _numbers;

        void fetch_numbers(void);
        bool is_part_number(const int& i) const;
    };
};
