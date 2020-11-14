//This is implementation of class Agent
#include "../include/Agent.h"
#include "../include/Session.h"
#include "../include/Tree.h"
#include <iostream>
#include <list>
using namespace std;
Agent::Agent() :nodeInd(-1){
///We need to complete or not

}

void Agent::act(Session& session){
///We need to complete

    }
int Agent::getNodeInd(){

    return nodeInd;
}

int Virus::getNodeInd(){

    return nodeInd;
}
Virus::Virus(int nodeInd):nodeInd(nodeInd) {

}
///We need to complete








void Virus::act(Session & session){
///TODO:We need to complete

/**
 * infect the current node
 *
 * and spread to the lowest node connected to the current node
 *
 *
 */
    int n=getNodeInd();
session.getGraphRef()->infectNode(n); //infect the current node
for(int i=0;i<session.getGraph().getEdges().size();i++)
    if (session.getGraph().getEdges()[getNodeInd()][i]==1)
    {
        if(!session.getGraph().isInfected(i))
        {
            for(int j=0;j<session.getAgents().size();j++)
            {
                if(session.getAgents()[j]->getNodeInd()!=i)
                {
                    session.getGraph().infectNode(i);
                }
            }
        }
    }


}

ContactTracer::ContactTracer() {
///TODO: We need to complete or not

}

void ContactTracer::act(Session& session){
///TODO:We need to complete
/**TAKE THE INFECTED QUEUE FROM THE GRAPH FROM SESSION

DO BFS FROM THE TOP OF EVERY INFECTED NODE

NOW WE DO TRACE - PICKING THE NODES WITH THE RIGHT LOGIC OF THE TREE
INSIDE TRACE TREE: WE DELETE THE EDGES OF THIS NODE

*/
for (int i=0;i<session.getGraph().getinfected_nodes().size();i++)
{
    Tree* tree =BFS(session.getGraph().getinfected_nodes()[i],session);
    int nodeTodelete=tree->traceTree();
    Graph gtemp = session.getGraph();
    for (int i=0;i<gtemp.getEdges().size();i++)
    {
        gtemp.getEdges()[nodeTodelete][i]=0;
        gtemp.getEdges()[i][nodeTodelete]=0;
    }
    delete tree;


}




//do trcace =int

//with the int = change the graph


}

//TODO: Fix and modifiy to our use
Tree* ContactTracer::BFS(int startVertex,Session& session) {
    int numVertices=session.getGraph().getEdges().size();
    TreeType t = session.getTreeType();
    Tree* tree;
    if (t==MaxRank)
     tree = new MaxRankTree (startVertex);

    else
    {
        if (t==Root)
             tree = new RootTree (startVertex);
        else
        {
         //    tree = new CycleTree (startVertex); //TODO: make constructor and disable here

        }
    }
    vector<bool> visited =* new vector<bool> (numVertices);
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        list<int> queue;
         Tree* tempTree=tree;
         visited[startVertex] = true;
        queue.push_back(startVertex);

        vector<int>::iterator i;

        while (!queue.empty()) {
            int currVertex = queue.front();
            if(currVertex!=startVertex) {
                //   cout << "Visited " << currVertex << " ";
                ///start check tree type
                Tree *childnew;
                if (t == MaxRank) {
                    childnew = new MaxRankTree(currVertex);
                } else {
                    if (t == Root) {
                        childnew = new RootTree(currVertex);
                    } else {

                        //   childnew =  new CycleTree (currVertex);//TODO: make constructor and disable here
                    }
                }

                ///end check tree type
                //add this vartex to the tree (add child)
                tempTree->addChild(*const_cast<Tree *>( childnew));
            }
            queue.pop_front();

            for (i = session.getGraph().getEdges()[currVertex].begin(); i != session.getGraph().getEdges()[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
    }









// Destructor: "deep delete"
/**
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

void printAgent(vector<int> adj[], int V)
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




**/



