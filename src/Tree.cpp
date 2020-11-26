//
// Created by Milky on 10/11/2020.
//


//This is implementation of class Graph
#include "../include/Graph.h"
#include "../include/Tree.h"
#include "../include/Session.h"
#include <vector>

using namespace std;

Tree::Tree() {
    node=0;

}
Tree::Tree(int rootLabel)
    {
    node=rootLabel;
    }

Tree::~Tree() {
    clear();
}
Tree* Tree::createTree(const Session& session, int rootLabel)
{
    Session& session1 = const_cast< Session&>(session);
    return ContactTracer::BFS(rootLabel, session1);


}
void Tree::addChild(const Tree& child)
{

children.push_back(const_cast<Tree *>(&child));

}
std::vector<Tree*> Tree::getChildren() {
return children;
}

void Tree::setNode(int node){

    this->node=node;

}
int Tree::getNode() {
    return node;
}
void Tree::clear() {
    node=0;

    for (auto p : children)
    {
        delete p;
    }
    children.clear();
}







RootTree::RootTree(int rootLabel){

    this->setNode(rootLabel);
}


int RootTree::traceTree(){

    /**
     * we choose the next node by the type of the tree
     *
     * than we delete all the connected edges of the current one
     *
     * return the chosen one
     *
     */
    int root = this->getNode();


    return root;

}





MaxRankTree::~MaxRankTree() {
    clear();
}

    MaxRankTree::MaxRankTree(int rootLabel){

           this->setNode(rootLabel);
    }


/**
 * we choose the next node by the type of the tree
 *
 * than we delete all the connected edges of the current one
 *
 * return the chosen one
 *
 */

     int MaxRankTree::traceTree(){

    int  max=-1;
    vector<int> maxint;
    maxint = traceTreeIteration(this, maxint,max);
    if (maxint.size()==1) {
        return maxint[0];
    }
    if (maxint.size()==0)
    {
    return getNode();
    }
    /// here we start to check for the trips for max
    vector<vector<int>> trip_maxint;
    trip_maxint.resize(maxint.size());
    vector<int> vecytor;
    traceTree_TripForMax(this,maxint,trip_maxint,vecytor);


    int lowest_trip=trip_maxint[0].size();
    vector <int> lowest_trip_index;
    lowest_trip_index.push_back(0);
    for (int i=1;i<trip_maxint.size();i++)
    {
        if ((trip_maxint[i].size())==lowest_trip)
        {
            lowest_trip_index.push_back(i);
        }

        if (lowest_trip<trip_maxint[i].size())
        {
            lowest_trip=trip_maxint[i].size();
            lowest_trip_index.clear();
            lowest_trip_index.push_back(i);
        }
    }
    if (lowest_trip_index.size()==1)
        return  lowest_trip_index[0];
    else{
        ///here we check who is the most left one
        return traceTree_Leftest(this, maxint,trip_maxint);
    }




}


int MaxRankTree::traceTree_Leftest(Tree * node, vector<int> maxint,  vector<vector<int>> trip_maxint) {
        bool b=true; int currnode=node->getNode();
         int step=-1; 
         while(b)   {

        for (int i=0;i<trip_maxint.size();i++)
         {
             if(maxint[i]==this->getNode())  ///TODO NOTICE THIS ADD
             return this->getNode(); ///TODO NOTICE THIS ADD

         else{
            if(trip_maxint[i].size()>=step){

        if (currnode!=trip_maxint[i][step])
        {
            if(trip_maxint[i][step]>currnode)
            {
              return  maxint[i];
            }
            else{

                return  maxint[0];
                ///choose the first int
            }
        }

        }

         } ///go to the next node
        for (int i=0;i<node->getChildren().size();i++){
            if (((node->getChildren())[i]->getNode() == (trip_maxint[0])[step + 1])){
            node=node->getChildren()[i];
                    break;
            }
        }
             step++;

         }
             return  node->getNode();
         }

    return  node->getNode();
}

    void MaxRankTree::traceTree_TripForMax(Tree* node,std::vector<int>  maxint,std::vector<std::vector<int>> & trip_maxint, std::vector<int>  currentPath)
    {
         for (int i=0;i<maxint.size();i++)
         {
             if (maxint[i]==node->getNode())
             {
                 trip_maxint[i]=currentPath;
                 break;
             }
         }

         currentPath.push_back(node->getNode());
        for (int i = 0; i < node->getChildren().size(); i++) {
          traceTree_TripForMax(node->getChildren()[i], maxint , trip_maxint,currentPath);
        }


    }








std::vector<int> MaxRankTree::traceTreeIteration(Tree* node,std::vector<int> & maxint,int & max) {
         int size =node->getChildren().size();
   if (size!=0){
       if (size> max) {
           max = size;
           maxint.clear();
           maxint.push_back(node->getNode());
       } else {
           if (size == max) {
               maxint.push_back(node->getNode());
           }
       }

    for (int i = 0; i < node->getChildren().size(); i++) {



        maxint = traceTreeIteration(node->getChildren()[i], maxint, max);

    }
   }
    return maxint;

}



void CycleTree::setCurrCycle(int currCycle) {
    this->currCycle = currCycle;
}
int CycleTree::getCurrCycle() {
    return currCycle;
}


CycleTree::CycleTree(int rootLabel, int currCycle) {

    this->setNode(rootLabel);
    this->setCurrCycle(currCycle);
}
///WE NEED TO CHANGE HERE BUT FOR NOW I WON'T DO NOTHING
int CycleTree::traceTree() {

    //create a vector trip that start with the root (node) and continue with the left-most child of this node (from the children vector the 0 index and etc) . check if the trip vector is c length or more and than return the c's index in the vector trip ' if not return the last index.
    //delete the edges of the node we returned

    vector<int> cycleTrip;  //TODO CHANGE
    cycleTrip.clear();
    cycleTrip.push_back(this->getNode());
    Tree * temp;
    temp=this;

  //  int tempcurrCycle=currCycle;
    if(temp->getChildren().size()!=0){

        while (temp->getChildren().size()!=0){
        //for (int i = 1; i <= tempcurrCycle; i++) { // i want that only this node childs will enter the trip vector   this->getChildren()[this->getNode()]->getChildren().size()
        temp=temp->getChildren()[0];
        cycleTrip.push_back(temp->getNode());
        //tempcurrCycle=this->getCurrCycle();
    }
    }

    int n = this->getCurrCycle();
 if(cycleTrip.size()>n+1){

    return cycleTrip[n+1];
 }
 return cycleTrip[cycleTrip.size()-1];


}

