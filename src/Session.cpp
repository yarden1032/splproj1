
using namespace std;
#include "../include/Graph.h"
#include "../include/Session.h"
#include <iostream>
#include "../include/Agent.h"
#include <fstream>
#include "../include/json.hpp"
//#include "../config1.JSON"
#include <list>
using json = nlohmann::json;
#include <vector>
//session::Session() { } //Constructor empty
Session::Session(const string &path):treeType (Cycle) { //constructor not empty

//    treeType = (Cycle); /////// only for test need to change
    std::string st=path;
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
   // cout << graphST.at(3) << endl;
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

        g=* new Graph (vec); //memory leak here
        ///Here we finish with the graph
        /////// Read the tree type
        treeType = Cycle; //Just for default for making sure.
        json jTreeType=j.at("tree");

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



    //// We need to add here Agents - Finished but we maybe need to add here. -finished
    ///I will write here down the Agents read - we need to add the agents then we can use the read from here - test only after Agents writing

/*
////Issue with iterator= try manual:
    json jAgents =j.at("agents");
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




*/


   // std::ifstream k(st);
    //k >>j;

//end manual
    int interator; //For Agents === the initial place of the Agents
    string ageString ; //For Agents === the type of Agent
    json jAgents =j.at("agents");
    for (json::iterator it =jAgents.begin() ; it !=jAgents.end() ;++it) {
        interator = (it.value())[1];
        ageString=(it.value())[0];
        if (ageString =="V")
        {
          Virus* vir =  new Virus (interator);
            agents.push_back(vir);
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
    agents=(aSession.agents);
}
/* Not sure if we need it
Session::Session(const string &path) {
}

*/

Session::~Session()
{
    clear();
}
void Session::clear()
{

    for(int i=0;i<=agents.size();i++) {
        delete agents[i];
    }
    agents.clear();
    //TODO: destructor to treeType - we have issue

    //Delete graph

    for (int i = 0; i <g.getEdges().size(); i++){
        for (int j= 0; j < g.getEdges().size(); j++)
        {

            delete &((g.getEdges()[i])[j]);
        }
        delete[] &g.getEdges()[i];
    }
    g.getEdges().clear();

}


/*
Session* Session::copy(const string &path ){

}*/

Session& Session::operator=(const Session &other)
{
    // check for "self assignment" and do nothing in that case
    if (this == &other) {
        return *this;
    }
    clear();


     g= *new Graph (other.getGraph());
    treeType=other.treeType;


    for(int i=0;i<=other.agents.size();i++) {
        agents.push_back(other.agents[i]); //TODO: We maybe have problem here, we maybe copy the poiters themself - recheck if we have issue - We need a specific test for that
    }
    //agents =*new Agent (other.getAgents());//We have issue here
    // return this List
    return *this;
}

// Move Constructor
Session::Session( Session&& other)
        : g(other.g), agents(other.agents),treeType(other.treeType)
{
    other.clear();
}
// Move Assignment
Session& Session::operator=(Session &&other)
{
    if (this != &other)
    {
        clear();
        g = other.g;
        agents = other.agents;
        treeType= other.treeType;

        other.clear();


    }

    return *this;
}

 Graph Session::getGraph() const {

    return g;
}





TreeType Session::getTreeType() const  {
    return treeType;

}

int Session::dequeueInfected() {
    int last =g.getinfected_nodes()[g.getinfected_nodes().size()-1];
    g.getinfected_nodes().pop_back(); // we maybe have issue with the order
    return last;
    //TODO: finish - not sure if this is it

}

void Session::simulate() {
//TODO: finish
//method to find CC in the graph
//kind of while
bool continue_sim=true;
while (continue_sim)
{
    int agentCurrentSize= agents.size();
for(int i=0;i<agentCurrentSize;i++)
    {
        Session& session(*this);
       agents[i]->act(session); //make sure memory is ok here

    }
    continue_sim=is_ConnectedCopOk();
}
//make output
}
bool Session::is_ConnectedCopOk() //TODO: change names and continue

{
    std::vector<std::vector<int>> cc;

    //line of something
    // Mark all the vertices as not visited
    bool *visited = new bool[g.getEdges().size()];
    for (int v = 0; v < g.getEdges().size(); v++)
        visited[v] = false;

    for (int v = 0; v < g.getEdges().size(); v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v

            //create of first CC
            vector<int> vecy = *new vector<int>();  ////TODO: show Roni - It tried to allocate non existed vector
            cc.push_back(vecy);
          //  cc[v] = *new std::vector<int>;
            DFS_helper(v, visited, cc);

            //  cout << "\n";  //Delete
        }
    }
    delete[] visited;


    //TODO: finish - We need here to finish it it just making cc ready for use
    //We need to check all the cc: if it's all in infected = good and we finish.
    //else check if all not infected.

    //check the first node in the cc[i] and then decide what to do:

    for (int k = 0; k < cc.size(); k++) {
        bool infected_cc = false; //here we check the specific cc if it's infected or not (what to expect)
        for (int l = 0; l < cc[k].size(); l++) {
            bool found = false; //this one is found in the infected vector
            for (int i = 0; i < g.getinfected_nodes().size(); i++) {
                if (cc[k][l] == g.getinfected_nodes()[i]) {
                    found = true;
                    break;
                }
            }
            if (l == 0) {
                infected_cc = found; //what do we expect from the first one and the other is the same
            } else {
                if (infected_cc != found) { //if this is different it means we have difference between the CC if it is full infected or full non-infected
                    return true;
                }
            }
        }
    }
    return false;

}


void Session::DFS_helper(int v, bool visited[],std::vector<std::vector<int>> cc)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cc[cc.size()-1].push_back(v);
    //cout << v << " "; //to delete

    // Recur for all the vertices
    // adjacent to this vertex

    for (int i=0;i<g.getEdges()[i].size(); ++i)
        if (!visited[i])
            DFS_helper(i, visited,cc);
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

    g=graph;
    }

    //TODO: finish



std::vector<Agent *> Session::getAgents(){
    return agents;
}
