#include "catch_amalgamated.hpp"

#include "06.hpp"

TEST_CASE("Day06", "[day-06]") {
    SECTION("Part 1") {
        std::vector<std::string> test_data{
            "Time:      7  15   30",
            "Distance:  9  40  200",
        };
        myg::Day06 d06(test_data);

        REQUIRE( d06.part_1() == 288 );
    }
}
