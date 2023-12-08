#pragma once

#include <regex>
#include <unordered_map>

#include "problem.hpp"

namespace myg {
    typedef std::unordered_map<
        std::string,
        std::pair<std::string, std::string>
    > graph_t;

    class Day08: public Problem {
    public:
        using Problem::Problem;

        static const std::regex RGX;

        int part_1(void);
        int part_2(void);

    protected:
        const graph_t build_graph(void) const;
    };
};
