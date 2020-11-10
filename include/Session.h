#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"

#include "Agent.h"
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
   //     Session operator()(Session ss);
        void setGraph(const Graph &graph);
      //  Session operator()(int ss);
        void enqueueInfected(int nodeInd);
        Session* Session::copy(const string &path);
        int dequeueInfected();
        TreeType getTreeType() const;
         Graph getGraph() const;
        Session& operator=(const Session &other);
        Session::Session(Session&& other);
        Session& Session::operator=(Session &&other);

    private:
        Graph g;
        TreeType treeType;
        std::vector<Agent *> agents;
     // TREE OBJECT maybe? TODO: to understand that
     void Session::DFS_helper(int v, bool visited[])
        void Session::clear();
        bool Session::is_ConnectedCopOk();


        void DFS_helper(int i, bool *pBoolean,std::vector<std::vector<int>> cc);

        void clear();

        void DFS_helper(int v, bool *visited, vector <vector<int>> cc);
    };

#endif
