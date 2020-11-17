//
// Created by Milky on 17/11/2020.
//
#include <iomanip>
#include "../include/Graph.h"
#include "../include/Session.h"
#include <iostream>
#include "../include/Agent.h"
#include <fstream>
#include "../include/json.hpp"
using json = nlohmann::json;
using namespace std;

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

TEST_CASE( "config1 test", "[config1]" ) {


    Session sess("config1.JSON");
    sess.simulate();
    REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
    REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
    REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
    REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
   REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);
      std::string st="output1.json";
    std::ifstream i(st);
    json expect;
    i >>expect;
    std::string stout="output.JSON";
    std::ifstream ik(stout);
    json joutput;
    ik >>joutput;
    REQUIRE(joutput.at("graph")==expect.at("graph")) ;



}
TEST_CASE( "config4", "[config4]" ) {


    Session sess("config4.JSON");
    sess.simulate();
    REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
    REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
   REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
   REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
   REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);

}
TEST_CASE( "Maintest", "[configtest]" ) {
    for (int i=1;i<=4;i++)
    SECTION( "change config number" + std::to_string(i)) {
        if (i==1){
            string stringi="config"+std::to_string(i)+".JSON";
            Session sess(stringi);
            sess.simulate();
            REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
            REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
            REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
            REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
            REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);
            string st="output"+ std::to_string(i) + ".json";
            std::ifstream i(st);
            json expect;
            i >>expect;
            std::string stout="output.JSON";
            std::ifstream ik(stout);
            json joutput;
            ik >>joutput;
            REQUIRE(joutput.at("graph")==joutput.at("graph")) ;
            REQUIRE(joutput.at("infected")==expect.at("infected")) ;
        }
    }
}