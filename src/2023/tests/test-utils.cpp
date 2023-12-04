#include "catch_amalgamated.hpp"

#include "utils.hpp"

TEST_CASE("utils matches", "[utils-matches]") {
    SECTION("matches") {
        std::regex rgx("(\\d)");
        std::string str("123");

        auto matches = myg::matches(str, rgx);

        REQUIRE( matches.size() == 3 );
        REQUIRE( matches[0] == "1" );
        REQUIRE( matches[1] == "2" );
        REQUIRE( matches[2] == "3" );
    }

    SECTION("matches with specific group") {
        std::regex rgx("(?=(\\d{2}))");
        std::string str("123");

        auto matches = myg::matches(str, rgx, 1);

        REQUIRE( matches.size() == 2 );
        REQUIRE( matches[0] == "12" );
        REQUIRE( matches[1] == "23" );
    }
}

TEST_CASE("utils split", "[utils-split]") {
    SECTION("split") {
        char delim = ';';
        std::string str("Alpha;Beta;Gamma");

        auto tokens = myg::split(str, delim);

        REQUIRE( tokens.size() == 3 );
        REQUIRE( tokens[0] == "Alpha" );
        REQUIRE( tokens[1] == "Beta" );
        REQUIRE( tokens[2] == "Gamma" );
    };
}
