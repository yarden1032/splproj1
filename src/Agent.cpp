//This is implementation of class Agent
#include "../include/Agent.h"
#include "../include/Session.h"
#include <iostream>
using namespace std;
Agent::Agent() {
///We need to complete




}

void Agent::act(Session& session){
///We need to complete

    }




Virus::Virus(int nodeInd) : nodeInd(-1) {
///TODO:We need to complete



}

void Virus::act(Session & session){
///TODO:We need to complete

}

ContactTracer::ContactTracer() {
///TODO: We need to complete




}

void ContactTracer::act(Session& session){
///TODO:We need to complete

}














/*
//constructor not empty
class Virus: public Agent{
    Virus(int sestempl, int nodeInd, int &session) : Agent(sestempl) {
        session=nodeInd;
        nodeInd=6;
    }
};
/* Destructor: "deep delete"

Agent::~Agent()
{
    clear();
}

void Agent::clear()
{
    while (head_ != nullptr) {
        removeFirst();
    }
}

class ContactTracer: public Agent{
public:
    ContactTracer(int sestempl, int session) : Agent(sestempl) {
        sestempl=0;
        session=55;
    }

    virtual void act();
};
}

/*void printAgent(vector<int> adj[], int V)
{
for (int v = 0; v < V; ++v)
{
    cout << "\n Adjacency list of vertex "
         << v << "\n head ";
    for (auto x : adj[v])
        cout << "-> " << x;
    printf("\n");
}
}
*/







