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
        Session();

        Session(const std::string &path,std::vector<std::vector<int>> );
        void simulate();

        void addAgent(const Agent &agent);
   //     Session operator()(Session ss);
        void setGraph(const Graph &graph);
        Session operator()(int ss);
        void enqueueInfected(int);

        int dequeueInfected();

        TreeType getTreeType() const;

    private:
        Graph g;
        TreeType treeType;
     //   std::vector<Agent *> agents;
     // TREE OBJECT maybe? TODO: to understand that
    };

#endif
