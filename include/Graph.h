#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>


class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
   Graph(); /// Please notice - I added it manually
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    std::vector<int> getinfected_nodes();
     std::vector<std::vector<int>> getEdges();
    Graph & operator=(const Graph &aGraph);
     std::vector<std::vector<int>> getEdges  () const ;
    void isolate(int nodeInd);
    ~Graph();
   void clear();
private:
    std::vector<std::vector<int>> edges;
    std::vector<int> infected_nodes;

};

#endif
