//This is implementation of class Graph
#include "../include/Graph.h"
using namespace std;

//Graph::Vector(): {std::vector<std::vector<int>> matrix(0)}
Graph::Graph(){

} //Constructor empty
Graph::Graph(std::vector<std::vector<int>> matrix){ //constructor not empty



    for (unsigned int i = 0; i <matrix.size(); i++){
        vector <int>* vecy= new vector<int>();
        edges.push_back(*vecy);
        for (unsigned int j= 0; j < matrix[i].size(); j++)
        {

            edges[i].push_back(((matrix[i])[j]));
        }
        delete vecy;
    }

}


void Graph::isolate(int nodeInd)
{
    for ( unsigned int i=0;i<edges.size();i++)
    {
        edges[nodeInd][i]=0;
        edges[i][nodeInd]=0;
        }
    }




void Graph::infectNode(int nodeInd)
{
    for (unsigned int i= 0;i< infected_nodes.size();i++)
    {
        if (infected_nodes[i]==nodeInd)
        {
            return;
        }
    }
infected_nodes.push_back(nodeInd);
  //  infected_nodes_deque.push_back(nodeInd);

}

 bool Graph::isInfected(int nodeInd)
{

for(unsigned int i=0;i<infected_nodes.size();i++){
    if (infected_nodes[i]==nodeInd)
    {
        return true;
    }
}
    return false;
}



 vector<vector<int>> Graph::getEdges ()
{
    return edges;
}


 vector<vector<int>> Graph::getEdges  () const
{
    return edges;
}

std::vector<int> Graph::getinfected_nodes(){

    return  infected_nodes;
}


Graph & Graph::operator=(const Graph &aGraph) // Finished but need to be tested
{
    // check for "self assignment" and do nothing in that case

    int size = aGraph.getEdges().size();
    if (this == &aGraph) {
        return *this;
    }
    if (size != edges.size()) {
        if(size < edges.size())
        {
            for (int i=size;i<edges.size();i++)
            {
                for(int j=size;i<edges.size();j++)
                {
                    edges [i][j]=0;
                }
            }
        }
        edges.resize(size); //TODO: check this - It's ok
    }
    for (int i = 0; i < size; i++) {
        if (size != edges[i].size()) {
            edges[i].resize(size);
        }
        for (int j = 0; j < size; j++) {
            
            (edges[i])[j] = aGraph.getEdges()[i][j];
        }
    }

    return *this;

}

Graph::~Graph()
{

}