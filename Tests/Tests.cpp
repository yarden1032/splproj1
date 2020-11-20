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
#include "../include/Tester.h"
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

TEST_CASE( "config3 test", "[config3]" ) {


    Session sess("config3.JSON");
    sess.simulate();
  /*  REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
    REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
    REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
    REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
   REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);*/
      std::string st="output3.json";
    std::ifstream i(st);
    json expect;
    i >>expect;
    std::string stout="output.JSON";
    std::ifstream ik(stout);
    json joutput;
    ik >>joutput;
//    REQUIRE(joutput.at("graph")==expect.at("graph")) ;
    REQUIRE(joutput.at("infected")==expect.at("infected")) ;


}
TEST_CASE( "config4", "[config4]" ) {


    Session sess("config4.JSON");
    sess.simulate();
 /*   REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
    REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
   REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
   REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
   REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);*/
    string st="output"+ std::to_string(4) + ".json";
    std::ifstream iJ(st);
    json expect;
    iJ >>expect;
    std::string stout="output.JSON";
    std::ifstream ik(stout);
    json joutput;
    ik >>joutput;
    REQUIRE(joutput.at("graph")==joutput.at("graph")) ;
    REQUIRE(joutput.at("infected")==expect.at("infected")) ;





 REQUIRE(joutput.at("graph")==expect.at("graph")) ;
    REQUIRE(joutput.at("infected")==expect.at("infected")) ;



}
TEST_CASE( "Maintest", "[configtest]" ) {
    for (int i=1;i<=4;i++)
    SECTION( "change config number" + std::to_string(i)) {
       // if (i==2){
            string stringi="config"+std::to_string(i)+".JSON";
            Session sess(stringi);
            sess.simulate();
            //REQUIRE( sess.getGraph().getEdges()[4][0] == 1);
          //  REQUIRE( sess.getGraph().getinfected_nodes()[0]==0);
          //  REQUIRE( sess.getGraph().getinfected_nodes()[1]==1);
          //  REQUIRE( sess.getGraph().getinfected_nodes()[2]==4);
          //  REQUIRE( sess.getGraph().getinfected_nodes()[3]==5);
            string st="output"+ std::to_string(i) + ".json";
            std::ifstream iJ(st);
            json expect;
            iJ >>expect;
            std::string stout="output.JSON";
            std::ifstream ik(stout);
            json joutput;
            ik >>joutput;
            REQUIRE(joutput.at("graph")==joutput.at("graph")) ;
            REQUIRE(joutput.at("infected")==expect.at("infected")) ;
      //  }
    }
}

TEST_CASE( "RonTest", "[RonTest]" ) {



    using namespace std;

//Coded By Ron Rachev

    Tester * testGenerator;



//    Session testSession("../config1.json");
        //  testSession.simulate();



        srand(time(NULL));
        int testerOptionChosen = 2;

      //  std::cout << "---------------\r\nWelcome\r\n---------------\r\nPlease type 1 to generate tests or 2 to run tests file" << std::endl;
        //cin >> testerOptionChosen ;

        if(testerOptionChosen == 2) {
            testGenerator = new Tester(2, 1);
            testGenerator->initate();
           // REQUIRE() ;

         /*   std::cout << "----------------------\r\nTotal Passed Tests : " << testGenerator->numPassedTests
                      << "\r\nFailed Tests : " << testGenerator->numInvalidTests << "\r\n----------------------\r\n"
                      << std::endl;*/

            REQUIRE(testGenerator->numInvalidTests==0) ;
            delete (testGenerator);
        }

     /*   if(testerOptionChosen == 1){
            std::cout << " Generating Random 4000 Tests " << std::endl;
            for(int i = 0 ;i < 4000 ; i ++)
            {
                testGenerator = new Tester(1,i);
                testGenerator->initate();
                delete(testGenerator);
            }
            std::cout << "\r\nTests Written To tests.json, have fun." << std::endl;
        }else
            std::cout << "Invalid Input" << std::endl;

*/

}
