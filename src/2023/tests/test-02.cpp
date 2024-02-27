#include "catch_amalgamated.hpp"

#include "02.hpp"

TEST_CASE("Day02", "[day-02]") {
    std::vector<std::string> test_data{
        "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
        "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
        "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
        "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
        "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green",
    };
    myg::Day02 d02(test_data);

    SECTION("Part 1") {
        REQUIRE( d02.part_1() == 8 );
    }

    SECTION("Part 2") {
        REQUIRE( d02.part_2() == 2286 );
    }
}
