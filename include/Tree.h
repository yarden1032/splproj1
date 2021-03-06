#ifndef TREE_H_
#define TREE_H_

#include <vector>
using namespace std;

class Session;

class Tree{
public:
    Tree();
    int getNode();
    std::vector<Tree*> getChildren();
    Tree(int rootLabel);
    void addChild(const Tree& child);
   virtual ~Tree() ;
    static Tree* createTree(const Session& session, int rootLabel); //TODO IMPORTANT
    virtual int traceTree()=0;
    void setNode(int node);
    void clear();

private:
    int node;
    std::vector<Tree*> children;



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
    ~MaxRankTree();
    MaxRankTree(int rootLabel);
    virtual int traceTree();
private:
    int   minDepthHelperIteration(Tree* node);
    int  minDepthHelper(Tree* node, std::vector<int> maxint);
    std::vector<int> traceTreeIteration(Tree* node,std::vector<int> & maxint,int & max);

  void

    traceTree_TripForMax(Tree *node, std::vector<int> maxint, std::vector<std::vector<int>> &trip_maxint,
                         std::vector<int> currentPath);

    int traceTree_Leftest(Tree * node, std::vector<int> maxint, std:: vector<std::vector<int>> trip_maxint);
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();

};

#endif