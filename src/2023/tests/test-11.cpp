#include "catch_amalgamated.hpp"

#include "11.hpp"

TEST_CASE("Day11", "[day-11]") {
    std::vector<std::string> test_data{
        "...#......",
        ".......#..",
        "#.........",
        "..........",
        "......#...",
        ".#........",
        ".........#",
        "..........",
        ".......#..",
        "#...#.....",
    };
    myg::Day11 d11(test_data);

    SECTION("Part 1") {
        REQUIRE( d11.part_1() == 374 );
    }

    SECTION("Part 2") {
        REQUIRE( d11.part_2(100) == 8410 );
    }
}
