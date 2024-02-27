#include "catch_amalgamated.hpp"

#include "problem.hpp"

TEST_CASE("Problem", "[problem]") {
    std::string test_filename = "tests/test-data.txt";
    std::vector<std::string> test_data{
        "alpha",
        "beta",
        "gamma",
    };

    SECTION("Problem object can be created from filename") {
        myg::Problem p(test_filename);

        REQUIRE( p.filename() == test_filename );
        REQUIRE( p.data() == test_data );
    }

    SECTION("Problem object can be created from data") {
        myg::Problem p(test_data);

        REQUIRE( p.filename() == "" );
        REQUIRE( p.data() == test_data );
    }
}
