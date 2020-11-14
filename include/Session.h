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

        void enqueueInfected(int nodeInd);
        Session* copy(const string &path);
        int dequeueInfected();
        TreeType getTreeType() const;
         Graph getGraph() const;
        Session& operator=(const Session &other);
        Session(Session&& other);
        Session& operator=(Session &&other);

    private:
        Graph g;
        TreeType treeType;
        std::vector<Agent *> agents;
     // TREE OBJECT maybe? TODO: to understand that
   //  void DFS_helper(int v, bool visited[])
        void clear();
        bool is_ConnectedCopOk();


        void DFS_helper(int v, bool visited[],std::vector<std::vector<int>> cc);

        //void clear();

       // void DFS_helper(int v, bool *visited, vector <vector<int>> cc);
    };

#endif
