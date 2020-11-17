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


/**
 * infect the current node
 *
 * and spread to the lowest node connected to the current node
 *
 *
 */
    int n=getNodeInd();
//session.getGraphRef()->infectNode(n); //infect the current node
session.enqueueInfected(n);
for(int i=0;i<session.getGraph().getEdges().size();i++)
    if (session.getGraph().getEdges()[getNodeInd()][i]==1)
    {
        if(!session.getGraph().isInfected(i))
        {
            for(int j=0;j<session.getAgents().size();j++)
            {
                if(session.getAgents()[j]->getNodeInd()==i)
                {
                    //session.getGraph().infectNode(i);
                   // session.enqueueInfected(i);

                   return;
                }

            }
            Virus * vir  =  new Virus (i);
            session.addAgent(vir);
            //delete vir;
            return;
        }
    }


}

ContactTracer::ContactTracer() {


}

void ContactTracer::act(Session& session){

/**TAKE THE INFECTED QUEUE FROM THE GRAPH FROM SESSION

DO BFS FROM THE TOP OF EVERY INFECTED NODE

NOW WE DO TRACE - PICKING THE NODES WITH THE RIGHT LOGIC OF THE TREE
INSIDE TRACE TREE: WE DELETE THE EDGES OF THIS NODE

*/
//for (int i=0;i<session.getGraph().getinfected_nodes().size();i++)
int i=session.dequeueInfected();
if (i!=-1){
    Tree* tree =BFS(i,session);

    int nodeTodelete=tree->traceTree();
   // Graph gtemp = session.getGraph();
    session.isolateNode(nodeTodelete);

  /*  for (int i=0;i<gtemp.getEdges().size();i++)
    {
        gtemp.getEdges()[nodeTodelete][i]=0;
        gtemp.getEdges()[i][nodeTodelete]=0;

    }
    session.setGraph(gtemp);*/

    delete tree;
}



//do trcace =int

//with the int = change the graph


}

Tree* ContactTracer::BFS(int startVertex,Session& session) {
    int numVertices=session.getGraph().getEdges().size();
    TreeType t = session.getTreeType();
    Tree* tree;
    if (t==MaxRank)
     tree = new MaxRankTree (startVertex);

    else {
        if (t == Root)
            tree = new RootTree(startVertex);
        else {
            //    tree = new CycleTree (startVertex); //TODO: make constructor and disable here

        }

    }
    vector <Tree *> whereVisisted;
    vector<bool> visited ;
        for (int i = 0; i < numVertices; i++){
            visited.push_back(false);
            whereVisisted.push_back(nullptr);
        }
        list<Tree *> queue;
         Tree* tempTree=tree;
         visited[startVertex] = true;
        queue.push_back(tree);
        vector<int>::iterator i;
    Tree *childnew;
        while (!queue.empty()) {
            int currVertex = queue.front()->getNode();
            tempTree= queue.front();
            if(currVertex!=startVertex) {
                //   cout << "Visited " << currVertex << " ";
                ///start check tree type
           /*
                if (t == MaxRank) {
                    childnew = new MaxRankTree(currVertex);
                } else {
                    if (t == Root) {
                        childnew = new RootTree(currVertex);
                    } else {

                        //   childnew =  new CycleTree (currVertex);//TODO: make constructor and disable here
                    }
                }
*/ //try someting new
                ///end check tree type
                //add this vartex to the tree (add child)
                whereVisisted[currVertex]->addChild(*tempTree);
            }
            queue.pop_front();

            for (int i = 0; i < session.getGraph().getEdges()[currVertex].size(); i++) {
         //       int adjVertex = *i;
                if (!visited[i]&&session.getGraph().getEdges()[currVertex][i]==1) {
                    visited[i] = true;
                    //try start

                    if (t == MaxRank) {
                        childnew = new MaxRankTree(i);
                    } else {
                        if (t == Root) {
                            childnew = new RootTree(i);
                        } else {

                            //   childnew =  new CycleTree (i);//TODO: make constructor and disable here
                        }
                    }

                    //try end
                    whereVisisted[i]=tempTree;
                    queue.push_back(childnew);
                }
            }
        }
    whereVisisted.clear();
         visited.clear();
        return tree;
    }






Virus::~Virus()
{
}


// Destructor: "deep delete"

Agent::~Agent()
{
}
/*
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
*/






