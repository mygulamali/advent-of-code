#include "catch_amalgamated.hpp"

#include "01.hpp"

TEST_CASE("Day01", "[day-01]") {
    SECTION("Part 1") {
        std::vector<std::string> test_data{
            "1abc2",
            "pqr3stu8vwx",
            "a1b2c3d4e5f",
            "treb7uchet",
        };
        myg::Day01 d01(test_data);

        REQUIRE( d01.part_1() == 142 );
    }

    SECTION("Part 2") {
        std::vector<std::string> test_data{
            "two1nine",
            "eightwothree",
            "abcone2threexyz",
            "xtwone3four",
            "4nineeightseven2",
            "zoneight234",
            "7pqrstsixteen",
        };
        myg::Day01 d01(test_data);

        REQUIRE( d01.part_2() == 281 );
    }

    SECTION("Part 2 with overlapping number matches") {
        std::vector<std::string> test_data{
            "xoneightx",
        };
        myg::Day01 d01(test_data);

        REQUIRE( d01.part_2() == 18 );
    }
}
