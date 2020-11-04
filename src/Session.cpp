//
// Created by Milky on 02/11/2020.
//
#include "../include/Session.h"
#include <iostream>
using namespace std;
Session::Session():g(),treeType(),agents(){} //Constructor empty
Session::Session(const std::string& path):g(),treeType(),agents(){ //constructor not empty


//    this->treeType= nullptr;
    std::vector<Agent*> agents;

}
void simulate() {

}

void addAgent(const Agent& agent){}

void enqueueInfected(int){}



int dequeueInfected(){}


TreeType getTreeType() {

  //  return treeType;
}
void setGraph(const Graph& graph){}

