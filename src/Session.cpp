//
// Created by Milky on 02/11/2020.
//
using namespace std;
#include "../include/Session.h"
#include <iostream>
#include "../include/Agent.h"


Session::Session() {

    treeType = Cycle; /////// only for test need to change
    int a = 5;
   // Virus* vivi= new Virus();

  //  agents.push_back(new Virus(*this, a));


} //Constructor empty
Session::Session(const string &path,std::vector<std::vector<int>> gr) { //constructor not empty
    treeType = (Cycle); /////// only for test need to change
    Graph *gg = new Graph(gr);
   // g(*gg);
}




//   std::vector<Agent*> agents;



TreeType Session::getTreeType() const {
    return Root;
}

int Session::dequeueInfected() {
    return 0;
}

void Session::simulate() {

}

//void Session::addAgent(const Agent &agent) {}

void Session::enqueueInfected(int) {}






void Session::setGraph(const Graph &graph) {}

