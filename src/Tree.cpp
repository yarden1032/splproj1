//
// Created by Milky on 10/11/2020.
//


//This is implementation of class Graph
#include "../include/Graph.h"
#include "../include/Tree.h"
#include "../include/Session.h"
#include <iostream>
#include <vector>
using namespace std;
#include <vector>
//Graph::Vector(): {std::vector<std::vector<int>> matrix(0)}
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

void Tree::addChild(const Tree& child)
{
 //   Tree * tempChild = const_cast<Tree *>(&child); //TODO:tocheck
children.push_back(const_cast<Tree *>(&child));
//delete tempChild;
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
    for(int i=0 ; i<children.size();i++) {
        children[i]=nullptr;

    }
    node=0;
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
/*
         int max=0;
         vector<int> maxint;
         int i;
         for (i=0;i<this->getChildren().size();i++)
    {
        if (this->getChildren()[i]->getChildren().size()>max)
        {
            max=getChildren()[i]->getChildren().size();
            maxint.clear();
           maxint.push_back(i);
        }
        else {
            if (this->getChildren()[i]->getChildren().size() == max) {
                maxint.push_back(i);
            }
        }

    }
    if(maxint.size()==1)
    {
       // int max= ;

     //   delete this->[max];    //TODO: think about it we have issue here for now
        return this->getChildren()[(maxint[0])]->getNode();
    }if (maxint.size()==0)
         {
        return getNode();
         }

    else
    {
    //    int max=;
int iti = minDepthHelper(this, maxint);
        return getChildren()[iti]->getNode();
    }*/
/**
 * for max tree we need to searrch the node with the most children - easy - we can do iteration to all of nodes
 *
 * if we find 2 with the same size - return them as vector
 *          we will check from them who is the closest one to the root - iteration?
 *
 *
 */
    int  max=0;
    vector<int> maxint;
    int i;
    MaxRankTree * temp=this;
    maxint = traceTreeIteration(this, maxint,max);



    }
std::vector<int> MaxRankTree::traceTreeIteration(Tree* node,std::vector<int> & maxint,int & max) {

   if (node->getChildren().size()!=0){
       if (node->getChildren().size() > max) {
           max = getChildren().size();
           maxint.clear();
           maxint.push_back(node->getNode());
       } else {
           if (node->getChildren().size() == max) {
               maxint.push_back(node->getNode());
           }
       }

    for (int i = 0; i < node->getChildren().size(); i++) {



        maxint = traceTreeIteration(getChildren()[i], maxint, max);

    }
   }
    return maxint;
}

//TODO fix here - important for config4.JSON
      /*  int MaxRankTree::minDepthHelper(Tree* node, vector<int> maxint,  vector<int> * minintdepth) {
    if (node == NULL)
        return 0;
    else {
        ///start
        int i;
    //    vector<int> minintdepth = *new vector<int>(node->getChildren().size());
      //  int maxint = -1;
        for (i = 0; i < node->getChildren().size(); i++) {
            //call to itself with the children

            (*minintdepth)[i] = minDepthHelper(node->getChildren()[i], maxint,minintdepth) + 1;
        }
        int j = -1;
        int min=-5;
        for (j=0; j < minintdepth->size(); j++) {
            if (min < (*minintdepth)[j]||min<0) {
                min =   (*minintdepth)[j];

            }
        }
        for(int k=0;k< node->getChildren().size(); k++) {
            if (min == (*minintdepth)[k])
            {
                delete node->getChildren()[k];
                return  k;

            }


        }
        return 0;


    }

}

*/
/*here we wrote how to get depth in recursion - it works for sure
 *
 */

     int  MaxRankTree::minDepthHelperIteration(Tree* node) {

             if (node->getChildren().size() == 0)
                 return 1;
             else
             {
                 /* compute the depth of each subtree */
                 vector<int> vecy;
                 for (int i = 0; i < node->getChildren().size(); i++) {
                     vecy.push_back(minDepthHelperIteration(node->getChildren()[i]));

                 }

          //       int lDepth = maxDepth(node->left);
       //          int rDepth = maxDepth(node->right);

                 /* use the larger one */
                 int max=-1;
          for (int i = 0; i < node->getChildren().size(); i++)
          {
              if (max<=vecy[i])
              {
                  max=vecy[i];
              }
          }
          return max;
             }
      }


/**
 * we use here the iteration above
 * @param node
 * @param maxint
 * @return min depth
 */




         int  MaxRankTree::minDepthHelper(Tree* node, vector<int> maxint) { //we return the index

    vector<int>  vecy; //vector of all the maxint's depth - we will use the iteration to do so
   int min =-5; int minpos=-1;
    int counterchecker=0;

    for (int j = 0; j < maxint.size(); j++) {

    for (int i = 0; i < node->getChildren().size(); i++){

        if (i==maxint[j]) {
            vecy.push_back(minDepthHelperIteration(node->getChildren()[i]));
            break;
        }
                     }

                 }


    for (int j = 0; j < maxint.size(); j++){
   if (vecy[j]==min)
   {
       counterchecker++;
   }

        if (min==-5 ||vecy[j]<min)
        {
            min=vecy[j];
            counterchecker=1;
            minpos=j;
        }
             }

    if (counterchecker>1)
    {
        return 0;
    }

    return minpos;
         }

/*
    int maxDepth(Tree* node)

    {
        for (i=0;i<node->getChildren().size();i++) {

            if (node->getChildren()[i]->getChildren().size()>max)
            {
                max=getChildren()[i]->getChildren().size();
                maxintdepth.clear();
                maxintdepth.push_back(i); //call to itself
            }
            if (node->getChildren()[i]->getChildren().size()==max)
            {
                maxintdepth.push_back(i); //call to itself
            }


        }

        ////end
        /* compute the depth of each subtree
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
*/






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

    int tempcurrCycle=currCycle;
    if(temp->getChildren().size()!=0){

        while (temp->getChildren().size()!=0){
        //for (int i = 1; i <= tempcurrCycle; i++) { // i want that only this node childs will enter the trip vector   this->getChildren()[this->getNode()]->getChildren().size()
        temp=temp->getChildren()[0];
        cycleTrip.push_back(temp->getNode());
        //tempcurrCycle=this->getCurrCycle();
    }
    }
    temp= nullptr;
 //   delete temp;
 if(cycleTrip.size()>=this->getCurrCycle()){
    return cycleTrip[this->getCurrCycle()];
 }
 return cycleTrip[cycleTrip.size()-1];

/*
    int CurrCycle=this->getCurrCycle();

    int lastindex = cycleTrip[cycleTrip.size()-1];

    if (cycleTrip.size()<CurrCycle) {
      /*  for (int i = 0; i < this->getChildren().size(); i++) {
            delete this->getChildren()[lastindex];
        }
        return (cycleTrip[lastindex]);

    }
   /* for (int i = 0; i < this->getChildren().size(); i++) {
        delete this->getChildren()[CurrCycle];
    }
    return cycleTrip[CurrCycle];

*/



    /**
     * we choose the next node by the type of the tree
     *
     * than we delete all the connected edges of the current one
     *
     * return the chosen one
     *
     */

}

