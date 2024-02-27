#include "catch_amalgamated.hpp"

#include "09.hpp"

TEST_CASE("Day09", "[day-09]") {
    std::vector<std::string> test_data{
        "0 3 6 9 12 15",
        "1 3 6 10 15 21",
        "10 13 16 21 30 45",
    };
    myg::Day09 d09(test_data);

    SECTION("Part 1") {
        REQUIRE( d09.part_1() == 114 );
    }

    SECTION("Part 2") {
        REQUIRE( d09.part_2() == 2 );
    }
}
