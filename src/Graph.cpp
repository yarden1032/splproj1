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
{
    for (int i= 0; infected_nodes.size();i++)
    {
        if (infected_nodes[i]==nodeInd)
        {
            return;
        }
    }
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


Graph & Graph::operator=(const Graph &aGraph) //TODO: Finished but need to be tested
{
    // check for "self assignment" and do nothing in that case
///////= there is issue here- follow the debugger
    int size= aGraph.getEdges().size();
    if (this == &aGraph) {
        return *this;
    }
    for (int i = 0; i <size; i++){

        if (i<=edges.size())
        {
            edges.push_back(*new vector<int>);
        }
        for (int j = 0; j <size; j++){
            if (j<=edges[j].size())
            {
                edges[i].push_back(aGraph.getEdges()[i][j]);
            }
            else{
                (edges[i])[j]=aGraph.getEdges()[i][j];
            }


    }

        if (edges.size()>aGraph.getEdges().size())
        {
            edges.resize(aGraph.getEdges().size());
        }
        edges[i].resize(aGraph.getEdges()[i].size());
    }

    return *this;

}

