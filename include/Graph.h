#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>


class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
   Graph(); /// Please notice - I added it manually
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
private:
    std::vector<std::vector<int>> edges;
    std::vector<int> infected_nodes;
};

#endif
