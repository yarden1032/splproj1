//This is implementation of class Graph
#include "../include/Graph.h"
#include <iostream>
#include <vector>
using namespace std;
#include <vector>
//Graph::Vector(): {std::vector<std::vector<int>> matrix(0)}
Graph::Graph(){

} //Constructor empty
Graph::Graph(std::vector<std::vector<int>> matrix){ //constructor not empty



    for (int i = 0; i <matrix.size(); i++){
        vector <int>* vecy= new vector<int>();
        edges.push_back(*vecy);
        for (int j= 0; j < matrix[i].size(); j++)
        {

            edges[i].push_back(((matrix[i])[j]));
        }
    }
/*
        for (int i = 0; i < matrix.size(); i++){
            for (int j= 0; j < matrix[i].size();  j++)
            {

                edges[i].push_back((matrix[i])[j]);
            }
    }
*/
}



/*void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}
*/
void Graph::isolate(int nodeInd)
{
    for (int i=0;i<edges.size();i++)
    {
        edges[nodeInd][i]=0;
        edges[i][nodeInd]=0;
        }
    }




void Graph::infectNode(int nodeInd)
{
    for (int i= 0;i< infected_nodes.size();i++)
    {
        if (infected_nodes[i]==nodeInd)
        {
            return;
        }
    }
infected_nodes.push_back(nodeInd);
  //  infected_nodes_deque.push_back(nodeInd);

}
/* std::vector<int> Graph::getinfected_nodes_deque(){

    return  infected_nodes_deque;

}
*/
 bool Graph::isInfected(int nodeInd)
{/*
    int indexi= nodeInd/edges.size();
    int indexj= nodeInd%edges.size();
    if ((edges[indexi])[indexj].GetIsInfected(())
    return true;
    else
        return false;

*/

for(int i=0;i<infected_nodes.size();i++){
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
        edges.resize(size);
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
