//This is implementation of class Graph
#include "../include/Graph.h"
#include <iostream>
using namespace std;

//Graph::Vector(): {std::vector<std::vector<int>> matrix(0)}
Graph::Graph(){} //Constructor empty
Graph::Graph(std::vector<std::vector<int>> matrix){ //constructor not empty


        for (int i = 0; i < matrix.size(); i++){
            for (int j= 0; j < matrix[i].size(); i++)
            {

                edges[i].push_back((matrix[i])[j]);
            }
    }

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
void Graph::infectNode(int nodeInd)
{
    int indexi= nodeInd/edges.size();
    int indexj= nodeInd%edges.size();
    (edges[indexi])[indexj]=1;
}
bool Graph::isInfected(int nodeInd)
{
    int indexi= nodeInd/edges.size();
    int indexj= nodeInd%edges.size();
    if ((edges[indexi])[indexj]==1)
    return true;
    else
        return false;


}





