#include "catch_amalgamated.hpp"

#include "08.hpp"

TEST_CASE("Day08", "[day-08]") {
    SECTION("Part 1 - example 1") {
        std::vector<std::string> test_data{
            "RL",
            "",
            "AAA = (BBB, CCC)",
            "BBB = (DDD, EEE)",
            "CCC = (ZZZ, GGG)",
            "DDD = (DDD, DDD)",
            "EEE = (EEE, EEE)",
            "GGG = (GGG, GGG)",
            "ZZZ = (ZZZ, ZZZ)",
        };
        myg::Day08 d08(test_data);

        REQUIRE( d08.part_1() == 2 );
    }

    SECTION("Part 1 - example 2") {
        std::vector<std::string> test_data{
            "LLR",
            "",
            "AAA = (BBB, BBB)",
            "BBB = (AAA, ZZZ)",
            "ZZZ = (ZZZ, ZZZ)",
        };
        myg::Day08 d08(test_data);

        REQUIRE( d08.part_1() == 6 );
    }

    SECTION("Part 2") {
        std::vector<std::string> test_data{
            "LR",
            "",
            "11A = (11B, XXX)",
            "11B = (XXX, 11Z)",
            "11Z = (11B, XXX)",
            "22A = (22B, XXX)",
            "22B = (22C, 22C)",
            "22C = (22Z, 22Z)",
            "22Z = (22B, 22B)",
            "XXX = (XXX, XXX)",
        };
        myg::Day08 d08(test_data);

        REQUIRE( d08.part_2() == 6 );
    }
}
