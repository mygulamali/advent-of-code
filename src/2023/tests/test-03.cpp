#include "catch_amalgamated.hpp"

#include "03.hpp"

TEST_CASE("Day03", "[day-03]") {
    SECTION("Part 1") {
        std::vector<std::string> test_data{
            "467..114..",
            "...*......",
            "..35..633.",
            "......#...",
            "617*......",
            ".....+.58.",
            "..592.....",
            "......755.",
            "...$.*....",
            ".664.598..",
        };
        myg::Day03 d03(test_data);

        REQUIRE( d03.part_1() == 4361 );
    }
}
