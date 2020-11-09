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
void Graph::infectNode(int nodeInd)
{/*
    int indexi= nodeInd/edges.size();
    int indexj= nodeInd%edges.size();
    (edges[indexi])[indexj]=1;*/

infected_nodes.push_back(nodeInd);
}
bool Graph::isInfected(int nodeInd)
{/*
    int indexi= nodeInd/edges.size();
    int indexj= nodeInd%edges.size();
    if ((edges[indexi])[indexj].GetIsInfected(())
    return true;
    else
        return false;

*/

for(int i=0;i<infected_nodes.size();i++)
    if (infected_nodes[i]==nodeInd)
    {
        return true;
    }
    return false;
}



 vector<vector<int>> Graph::getEdges ()
{
    return edges;
}





