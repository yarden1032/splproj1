//
// Created by Milky on 10/11/2020.
//


//This is implementation of class Graph
#include "../include/Graph.h"
#include "../include/Tree.h"
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
        Tree *ptr = children[i];
        delete ptr;
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
return 0;
    }







    MaxRankTree::MaxRankTree(int rootLabel){

           this->setNode(rootLabel);
    }


     int MaxRankTree::traceTree(){

         int max=0;
         vector<int> maxint =*new vector<int> ();
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

        return getChildren()[maxDepthHelper(this)]->getNode();
    }
        /**
         * we choose the next node by the type of the tree
         *
         * than we delete all the connected edges of the current one
         *
         * return the chosen one
         *
         */

    }

        int MaxRankTree::maxDepthHelper(Tree* node) {
    if (node == NULL)
        return 0;
    else {
        ///start
        int i;
        vector<int> maxintdepth = *new vector<int>(node->getChildren().size());
        int maxint = -1;
        for (i = 0; i < node->getChildren().size(); i++) {
            //call to itself with the children

            maxintdepth[i] = maxDepthHelper(node->getChildren()[i]) + 1;
        }
        int j = -1;
        int max=-1;
        for (j=0;j<maxintdepth.size();j++) {
            if (max < maxintdepth[j]) {
                max = maxintdepth[j];

            }
        }
        for(int k=0;k< node->getChildren().size(); k++) {
            if (max == maxintdepth[k])
            {
                delete node->getChildren()[k];
                return  k;

            }


        }

    }

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







