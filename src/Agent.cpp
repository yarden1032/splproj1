//This is implementation of class Agent
#include "../include/Agent.h"
#include <iostream>
#include <list>
using namespace std;
Agent::Agent() :nodeInd(-1){
///We need to complete or not

}



ContactTracer::~ContactTracer() {
}
void Agent::act(Session& session){

    }
int Agent::getNodeInd(){

    return nodeInd;
}

int Virus::getNodeInd(){

    return nodeInd;
}
Virus::Virus(int nodeInd):nodeInd(nodeInd) {

}


void Virus::act(Session & session){


/**
 * infect the current node
 *
 * and spread to the lowest node connected to the current node
 *
 *
 */
    int n=getNodeInd();
        if (!session.getGraph().isInfected(n)) //if not, don't enqueue it because it already infected
        session.enqueueInfected(n);

for(unsigned int i=0;i<session.getGraph().getEdges().size();i++)
    if (session.getGraph().getEdges()[getNodeInd()][i]==1)
    {
        if(!session.getGraph().isInfected(i))
        {bool skip=false;
            for(unsigned int j=0;j<session.getAgents().size();j++)
            {
                unsigned int compare= session.getAgents()[j]->getNodeInd();
                if(compare==i)
                {

                /////    it means we dont infect a node that already have virus
                    //session.getGraph().infectNode(i);
                   // session.enqueueInfected(i);

                    skip=true;   //TODO tried to change from return
                }

            }
            if(!skip){
            Virus * vir  =  new Virus (i);
            session.addAgent(vir);
            //delete vir;
            return;
            }
        }
    }


}

ContactTracer::ContactTracer() =default;

void ContactTracer::act(Session& session){

/**TAKE THE INFECTED QUEUE FROM THE GRAPH FROM SESSION

DO BFS FROM THE TOP OF EVERY INFECTED NODE

NOW WE DO TRACE - PICKING THE NODES WITH THE RIGHT LOGIC OF THE TREE
INSIDE TRACE TREE: WE DELETE THE EDGES OF THIS NODE

*/

int i=session.dequeueInfected();
if (i!=-1){
    Tree* tree =BFS(i,session);
    if (session.getTreeType()==Cycle)
    {
      CycleTree * treeCyc= dynamic_cast<CycleTree *>(tree);
      treeCyc->setCurrCycle(session.getCurriteration()-1);
    }
    int nodeTodelete=tree->traceTree();

    session.isolateNode(nodeTodelete);



    delete tree;
    tree=nullptr;
}



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
                tree = new CycleTree (startVertex,0); //TODO: make constructor and disable here

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
       // vector<int>::iterator i;
    Tree *childnew;
        while (!queue.empty()) {
            int currVertex = queue.front()->getNode();
            tempTree= queue.front();
            if(currVertex!=startVertex) {
                ///end check tree type
                //add this vartex to the tree (add child)
                whereVisisted[currVertex]->addChild(*tempTree);
            }
            queue.pop_front();

            for (unsigned int i = 0; i < session.getGraph().getEdges()[currVertex].size(); i++) {

                if (!visited[i]&&session.getGraph().getEdges()[currVertex][i]==1) {
                    visited[i] = true;

                    if (t == MaxRank) {
                        childnew = new MaxRankTree(i);

                    } else {
                        if (t == Root) {
                            childnew = new RootTree(i);

                        } else {
                            CycleTree * tempCycle = dynamic_cast<CycleTree *>(tempTree);
                           int currcy = tempCycle->getCurrCycle();
                               childnew =  new CycleTree (i,currcy+1);//TODO: make constructor and disable here
                        }
                    }

                    whereVisisted[i]=tempTree;
                    queue.push_back(childnew);

                }
            }
        }
    whereVisisted.clear();
         visited.clear();

        return tree;
    }






Virus::~Virus()=default;



// Destructor: "deep delete"

Agent::~Agent()=default;








