//
// Created by Milky on 02/11/2020.
//
using namespace std;
#include "../include/Session.h"
#include <iostream>
#include "../include/Agent.h"
#include <fstream>
#include "../include/json.hpp"
using json = nlohmann::json;
#include <vector>
Session::Session() {




} //Constructor empty
Session::Session(const string &path) { //constructor not empty
//    treeType = (Cycle); /////// only for test need to change
    std::string st=path;
    st=st.replace(st.find("/splproj1"),sizeof("/splproj1")-1,"");


    st = ("/tmp/tmp.c5RtcnDezT/cmake-build-debug");
    st=(st+"/config1.json");
    std::ifstream i(st);
    json j;
    i >>j;
    ///Here we read the Json

    ///No we use the graph json and get it as string and convert to vector

    json j2=j.at("graph");
    string graphST= j2.dump();

    vector<std::vector<int>> vec;
    int indexi=1;

    int indexj=-1;
    cout << graphST.at(3) << endl;
    while (graphST.at(indexi)!=']'||graphST.at(indexi+1)!=']') {
        if ((graphST.at(indexi)=='['))
        {
            vector<int> *vecy = new vector<int>();
            vec.push_back(*vecy);
            indexi++;
            indexj++;
            continue;

        }
        if(graphST.at(indexi)==',')
        {
            indexi++;
            continue;
        }
        if(graphST.at(indexi)=='1') {
            vec[indexj].push_back((1));
            indexi++;
            continue;
        }
        if(graphST.at(indexi)=='0'){
            vec[indexj].push_back((0));
            indexi++;
            continue;
        }
        if(graphST.at(indexi)==']') {

            indexi++;
        }



    }
        g=*(new Graph (vec));
        ///Here we finish with the graph
        /////// Read the tree type
        treeType = Cycle; //Just for default for making sure.
        json jTreeType=j.at("tree");
        if (jTreeType.dump()=="M")
        {
            treeType = MaxRank;
        }
        if (jTreeType.dump()=="C")
        {
            treeType = Cycle;
        }
        if (jTreeType.dump()=="R")
        {
            treeType = Cycle;
        }

        /*Dont use it
        /*if(tempindex==0) {
        vec[0][indexi]=graphST.at
        }*/




  /*  for (int a = 0; a <5; a++){
        vector <int>* vecy= new vector<int>();
        vec.push_back(*vecy);
        for (int j= 0; j < 5; j++)
        {

            vec[a].push_back((1));
        }
        */
    //   std::vector<Agent*> agents;


    //TODO: We need to add here Agents
    ///I will write here down the Agents read - we need to add the agents then we can use the read from here - test only after Agents writing

    json jAgents =j.at("agents");
    for (json::iterator it = jAgents.begin(); it != jAgents.end(); ++it) {
        std::cout << it.key() << " : " << it.value() << "\n";
    }
        indexi = 0;
        indexj = 0;






    }







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

