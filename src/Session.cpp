

#include <iomanip>
#include "../include/Graph.h"
#include "../include/Session.h"
#include <iostream>
#include <fstream>
#include "../include/json.hpp"
using json = nlohmann::json;
#include <vector>
using namespace std;
//session::Session() { } //Constructor empty
Session::Session(const string &path):g(* new Graph()),agents(* new std::vector<Agent *>),curriteration(-1),treeType (Cycle),indicator(-1) { //constructor not empty


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
    while (graphST.at(indexi)!=']'||graphST.at(indexi+1)!=']') {
        if ((graphST.at(indexi)=='['))//36
        {
            vector<int> *vecy = new vector<int>();
            vec.push_back(*vecy);
            indexi++;
            indexj++;
            delete vecy;
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
            continue;
        }
        else
        {
            indexi++;
            continue;
        }
    }

        g=(vec);

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




    int interator; //For Agents === the initial place of the Agents
    string ageString ; //For Agents === the type of Agent
    json jAgents =j.at("agents");
    for (json::iterator it =jAgents.begin() ; it !=jAgents.end() ;++it) {
        interator = (it.value())[1];
        ageString=(it.value())[0];
        if (ageString =="V")
        {
          Virus * vir= new Virus (interator);
            agents.push_back(vir);


        }
        else {
            ContactTracer * cont  =new ContactTracer();
            agents.push_back(cont);

        }

    }





}



Session::Session(const Session &aSession): g(aSession.getGraph()),agents(aSession.getAgents()),curriteration(aSession.getCurriteration()),treeType(aSession.getTreeType()),indicator(-1)// copy constructor - shallow one

{
    g=*(new Graph(aSession.getGraph()));
    treeType=aSession.getTreeType();
    agents=(aSession.agents);
}


Session::~Session()
{
    clear();
}
void Session::clear()
{

    for(unsigned int i=0;i<=agents.size();i++) {
    //    delete agents[i];
    }
   agents.clear();
    //TODO: destructor to treeType - we have issue

    //Delete graph
    
    g.getEdges().clear();

}





Session& Session::operator=(const Session &other)
{
    // check for "self assignment" and do nothing in that case
    if (this == &other) {
        return *this;
    }
    clear();


     g= *new Graph (other.getGraph());
    treeType=other.treeType;


    for(unsigned int i=0;i<=other.agents.size();i++) {
        agents.push_back(other.agents[i]);
    }
    //agents =*new Agent (other.getAgents());//We have issue here
    // return this List
    return *this;
}

// Move Constructor
Session::Session( Session&& other) : g(other.getGraph()),agents(other.getAgents()),curriteration(-1),treeType(other.getTreeType()),indicator(-1)
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

 Graph Session::getGraph() const  {

    return g;
}


Graph Session::getGraph()   {

    return g;
}


TreeType Session::getTreeType() const  {
    return treeType;

}

int Session::dequeueInfected() {
int checker =(g.getinfected_nodes()).size();

  if(indicator<checker-1)
  {indicator ++;
      int last =g.getinfected_nodes()[indicator];
      return last;
  }
  else
      return -1;

}

int Session::getCurriteration() const
{
    return curriteration;
}

void Session::isolateNode(int node){
    g.isolate(node);

    }

void Session::simulate() {

//method to find CC in the graph
//kind of while
bool continue_sim=true;
while (continue_sim)
{
    curriteration++;
    int agentCurrentSize= agents.size();
for(int i=0;i<agentCurrentSize;i++)
    {

       agents[i]->act((Session &) *this); //make sure memory is ok here

    }
    continue_sim=is_ConnectedCopOk();  ///HERE
}
//TODO: make output and manage memory
output();
memoManage();

}
//Output of the session to json file
void Session::output() {
    json jtotal;
    jtotal["graph"]=g.getEdges();
    jtotal["infected"]=g.getinfected_nodes();
    std::ofstream o("output.json");
    o << std::setw(4) << jtotal ;


    //start config jgraph
 

}

void Session::memoManage()
{
    for (unsigned int i=0;i<agents.size();i++)
    {
       delete agents[i];
    }
}
/*
 *
 */
bool Session::is_ConnectedCopOk() {
    std::vector<std::vector<int>> cc;

    //line of something
    // Mark all the vertices as not visited
    std::vector<bool> visited;
    for (unsigned int v = 0; v < g.getEdges().size(); v++) {
        visited.push_back(false);
    }

    for (unsigned int v = 0; v < g.getEdges().size(); v++) {
        if (!visited[v]) {
            // print all reachable vertices
            // from v

            //create of first CC
            vector<int> vecy;
            cc.push_back(vecy);
            //  cc[v] = *new std::vector<int>;
            std::vector<std::vector<int>> &cc1 = cc;
            std::vector<bool> &visited1 = visited;

            DFS_helper(v, visited1, cc1);

            //  cout << "\n";  //Delete
        }
    }


    visited.clear();



    //We need to check all the cc: if it's all in infected = good and we finish.
    //else check if all not infected.

    //check the first node in the cc[i] and then decide what to do:
    bool forexit = true;
    for (unsigned int k = 0; k < cc.size(); k++) {
        bool infected_cc = false; //here we check the specific cc if it's infected or not (what to expect)
        for (unsigned int l = 0; l < cc[k].size() && forexit; l++) {
            bool found = false; //this one is found in the infected vector
            for (unsigned int i = 0; i < g.getinfected_nodes().size(); i++) {
                if (cc[k][l] == g.getinfected_nodes()[i]) {
                    found = true;
                    break;
                }
            }
            for (unsigned int i = 0; i < this->getAgents().size(); i++) {
                if (cc[k][l] == this->getAgents()[i]->getNodeInd() ) { ////Notice a litlle different  &&g.isInfected(cc[k][l])
                    found = true;
                    break;
                }
            }
            if (l == 0) {
                infected_cc = found; //what do we expect from the first one and the other is the same
            } else {
                if (infected_cc !=
                    found) { //if this is different it means we have difference between the CC if it is full infected or full non-infected
                    return true;
                }
            }
        }
    }
      bool attach_agent_to_infected=false;
      for (unsigned int j = 0; j < this->getAgents().size(); j++){
          attach_agent_to_infected=false;
          for (unsigned int i = 0; i < g.getinfected_nodes().size(); i++) {

         if (this->getAgents()[j]->getNodeInd()==g.getinfected_nodes()[i])
         {
             attach_agent_to_infected=true;
             break;
         }
          }
          if (!attach_agent_to_infected&&this->getAgents()[j]->getNodeInd()>=0)
          {
              return true;
          }
          }

    return false;
}


void Session::DFS_helper(int v, std::vector <bool> & visited,std::vector<std::vector<int>> &cc)
{
    // Mark the current node as visited and print it
  //  std::vector <bool> visitedreal =visited;
    visited[v]  =  true;
   // std::vector<std::vector<int>> cc1= reinterpret_cast<const vector<vector<int, allocator<int>>, allocator<vector<int, allocator<int>>>> &>(cc);
    cc[cc.size()-1].push_back(v);
    //cout << v << " "; //to delete

    // Recur for all the vertices
    // adjacent to this vertex

    for (unsigned int i=0;i<g.getEdges().size(); i++)
        if (!visited[i] && g.getEdges()[v][i]==1) {
            DFS_helper(i, visited ,cc );


        }
}


void Session::addAgent(Agent *agent) {


    agents.push_back((Agent *const) agent);



 }

void Session::enqueueInfected(int nodeInd) { //add to infected and we also check if we need to do so

     g.infectNode(nodeInd);

 }






void Session::setGraph(const Graph &graph) {

    g=graph;
    }





std::vector<Agent *> Session::getAgents() const {
    return agents;
}


