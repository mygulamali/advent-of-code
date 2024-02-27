#include "catch_amalgamated.hpp"

#include "05.hpp"

TEST_CASE("Day05", "[day-05]") {
    SECTION("Map") {
        myg::Map map;
        struct myg::mapping_t mapping;
        mapping = {50, 98, 2};
        map.add_mapping(mapping);
        mapping = {52, 50, 48};
        map.add_mapping(mapping);

        REQUIRE( map[48] == 48 );
        REQUIRE( map[49] == 49 );
        REQUIRE( map[50] == 52 );
        REQUIRE( map[51] == 53 );
        REQUIRE( map[96] == 98 );
        REQUIRE( map[97] == 99 );
        REQUIRE( map[98] == 50 );
        REQUIRE( map[99] == 51 );
    }

    std::vector<std::string> test_data{
        "seeds: 79 14 55 13",
        "",
        "seed-to-soil map:",
        "50 98 2",
        "52 50 48",
        "",
        "soil-to-fertilizer map:",
        "0 15 37",
        "37 52 2",
        "39 0 15",
        "",
        "fertilizer-to-water map:",
        "49 53 8",
        "0 11 42",
        "42 0 7",
        "57 7 4",
        "",
        "water-to-light map:",
        "88 18 7",
        "18 25 70",
        "",
        "light-to-temperature map:",
        "45 77 23",
        "81 45 19",
        "68 64 13",
        "",
        "temperature-to-humidity map:",
        "0 69 1",
        "1 0 69",
        "",
        "humidity-to-location map:",
        "60 56 37",
        "56 93 4",
    };
    myg::Day05 d05(test_data);

    SECTION("Part 1") {
        REQUIRE( d05.part_1() == 35 );
    }

    SECTION("Part 2") {
        REQUIRE( d05.part_2() == 46 );
    }
}
