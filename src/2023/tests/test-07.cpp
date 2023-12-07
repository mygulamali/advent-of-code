#include "catch_amalgamated.hpp"

#include "07.hpp"

TEST_CASE("Day07 - ") {
    REQUIRE( true );
}


TEST_CASE("Day07 - Hand") {
    SECTION("operator< - hands with different strengths") {
        myg::Hand test_hand_1("TTT98", 1);
        myg::Hand test_hand_2("23332", 1);

        REQUIRE( test_hand_1 < test_hand_2 );
    }

    SECTION("operator< - hands with same strengths") {
        myg::Hand test_hand_1("2AAAA", 1);
        myg::Hand test_hand_2("33332", 1);

        REQUIRE( test_hand_1 < test_hand_2 );
    }

    SECTION("card_counts") {
        myg::Hand test_hand("TTT98", 1);
        std::vector<int> card_counts = {1, 1, 3};

        REQUIRE( test_hand.card_counts() == card_counts );
    }

    SECTION("is_five") {
        myg::Hand test_hand("AAAAA", 1);

        REQUIRE( test_hand.is_five() );
    }

    SECTION("is_four") {
        myg::Hand test_hand("AA8AA", 1);

        REQUIRE( test_hand.is_four() );
    }

    SECTION("is_full") {
        myg::Hand test_hand("23332", 1);

        REQUIRE( test_hand.is_full() );
    }

    SECTION("is_three") {
        myg::Hand test_hand("TTT98", 1);

        REQUIRE( test_hand.is_three() );
    }

    SECTION("is_two") {
        myg::Hand test_hand("23432", 1);

        REQUIRE( test_hand.is_two() );
    }

    SECTION("is_one") {
        myg::Hand test_hand("A23A4", 1);

        REQUIRE( test_hand.is_one() );
    }

    SECTION("is_high") {
        myg::Hand test_hand("23456", 1);

        REQUIRE( test_hand.is_high() );
    }
}

TEST_CASE("Day07", "[day-07]") {
    SECTION("Part 1") {
        std::vector<std::string> test_data{
            "32T3K 765",
            "T55J5 684",
            "KK677 28",
            "KTJJT 220",
            "QQQJA 483",
        };
        myg::Day07 d07(test_data);

        REQUIRE( d07.part_1() == 6440 );
    }
}
