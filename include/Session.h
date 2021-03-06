#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"

#include "../include/Agent.h"
using namespace std;
class Agent;
    enum TreeType {
        Cycle,
        MaxRank,
        Root
    };

    class Session {
    public:

 //       Session(); //empty constructor
        Session(const Session &aSession);// copy constructor
        Session(const std::string &path);
        void simulate();
        virtual ~Session();
        void addAgent(Agent *agent);
        std::vector<Agent *> getAgents ();
        void setGraph(const Graph &graph);
        void isolateNode(int node);
        void enqueueInfected(int nodeInd);
        Session* copy(const string &path);
        int dequeueInfected();
        TreeType getTreeType() const;
         Graph getGraph() const;
        Graph getGraph() ;
        Session& operator=(const Session &other);
        Session(Session&& other);
        Session& operator=(Session &&other);
        Graph * getGraphRef() ;
        int getCurriteration();

    private:
        void output();
        Graph g;
        TreeType treeType;
        std::vector<Agent *> agents;
        int curriteration;


        void clear();
        bool is_ConnectedCopOk();
        int indicator;

        void DFS_helper(int v, std::vector <bool> & visited,std::vector<std::vector<int>> &  cc);


        void memoManage();
    };

#endif
