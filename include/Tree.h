#ifndef TREE_H_
#define TREE_H_

#include <vector>

class Session;

class Tree{
public:
    Tree();
    int getNode();
    std::vector<Tree*> getChildren();
    Tree(int rootLabel); //we only add the root node from the infected vector
    void addChild(const Tree& child); //
    ~Tree() ;
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    void setNode(int node);

private:
    int node;
    std::vector<Tree*> children;
    void clear();


    int maxDepthHelper(Tree *node);
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    void setCurrCycle(int currCycle);
    int getCurrCycle();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();

private:
    int maxDepthHelper(Tree* node,std::vector<int> maxint);
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();

};

#endif