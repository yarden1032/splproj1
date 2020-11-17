//
// Created by Milky on 17/11/2020.
//
#define CATCH_CONFIG_MAIN
#include "Tests.h"
#include "catch.hpp"
#include "../include/Session.h"
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}TEST_CASE( "Factorials are computed2", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1);
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE( "config1", "[config1]" ) {


    Session sess("config1.JSON");
    sess.simulate();
    REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
    REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
    REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
    REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
    REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);

}
TEST_CASE( "config4", "[config4]" ) {


    Session sess("config4.JSON");
    sess.simulate();
 //   REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
 //   REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
//    REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
//    REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
//    REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);

}
