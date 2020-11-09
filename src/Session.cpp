//
// Created by Milky on 02/11/2020.
//
using namespace std;
#include "../include/Graph.h"
#include "../include/Session.h"
#include <iostream>
#include "../include/Agent.h"
#include <fstream>
#include "../include/json.hpp"
//#include "../config1.JSON"

using json = nlohmann::json;
#include <vector>
Session::Session() {




} //Constructor empty
Session::Session(const string &path):treeType (Cycle) { //constructor not empty
//    treeType = (Cycle); /////// only for test need to change
    std::string st=path;
    st=st.replace(st.find("/splproj1"),sizeof("/splproj1")-1,"");

//TODO:We need to confirm the right arguments in the end - if we can, to do so from IDE and not to wait
    st = ("/tmp/tmp.c5RtcnDezT/cmake-build-debug");
    st=(st+"/config1.json");
    std::ifstream i(st);
    json j;
    i >>j;
    ///Here we read the Json


    ///Now we use the graph json and get it as string and convert to vector

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
    cout <<  jTreeType.dump() << endl;
        if (jTreeType.dump().at(1)=='M')
        {
            treeType = MaxRank;
        }
        if (jTreeType.dump().at(1)=='C')
        {
            treeType = Cycle;
        }
        if (jTreeType.dump().at(1)=='R')
        {
            treeType = Root;
        }



    //TODO: We need to add here Agents - Finished but we maybe need to add here.
    ///I will write here down the Agents read - we need to add the agents then we can use the read from here - test only after Agents writing
    int interator; //For Agents === the initial place of the Agents
    string ageString ; //For Agents === the type of Agent
    json jAgents =j.at("agents");
    for (json::iterator it = jAgents.begin(); it != jAgents.end(); ++it) {
         interator = it.value()[1];
        ageString=it.value()[0];
        if (ageString =="V")
        {
            agents.push_back(new Virus (interator));
        }
        else {
            agents.push_back(new ContactTracer());
        }
    }

///Finish constraction - be advised the changes here to agents

            /////   std::vector<Agent*> agents;;
}


////////We also need here copy constructor
Session::Session(const Session &aSession)// copy constructor - shallow one
/*{
--this is start of deep construction - only if we need it - continue
    vector<std::vector<int>> vec;
    int maxsize = aSession.getGraph().getEdges().size();


    for ( int i = 0; i <maxsize ; i++) {
        vector<int> *vecy = new vector<int>();
        vec.push_back(*vecy);
        for (int j = 0; j < aSession.getGraph().getEdges()[i].size(); j++) {
            int a=aSession.getGraph().getEdges()[i][j];
            vec[i].push_back((a));
        }
    }
    g=*(new Graph (vec));
        }*/
{
    g=*(new Graph(aSession.getGraph()));
    treeType=aSession.getTreeType();
}
/* Not sure if we need it
Session::Session(const string &path) {
}

*/

 Graph Session::getGraph() const {

    return g;
}





TreeType Session::getTreeType() const {
    return treeType;

}

int Session::dequeueInfected() {

    return 0;
    //TODO: finish
}

void Session::simulate() {
//TODO: finish
}

void Session::addAgent(Agent *agent) {


    agents.push_back((Agent *const) agent);


     //TODO: finish - I don't sure if we need more here and if it's ok
 }

void Session::enqueueInfected(int nodeInd) { //add to infected and we also check if we need to do so

     g.infectNode(nodeInd);
    //TODO: finish
 }






void Session::setGraph(const Graph &graph) {
    //TODO: finish
 }

