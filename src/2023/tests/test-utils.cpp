#include "catch_amalgamated.hpp"

#include "utils.hpp"

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
