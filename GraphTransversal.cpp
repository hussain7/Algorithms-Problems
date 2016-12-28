// A C++ program to demonstrate operations of KD tree

#include "stdafx.h"
#include <iostream>
#include <map>
#include <list>
#include <array>
#include <vector>

// creat graph
class Graph
{
    std::map<int, std::vector<int> > adjList;
    int vertices;

    void dfsUtil(int startnode, std::map<int, bool> visitedNode, std::vector<int>& output);

public :
     Graph(int vertices)
     {
        this->vertices = vertices;
     }

     int getVertices()
     {
        return vertices;
     }

     void addEdge(int src, int des )
     {
         (adjList[src]).push_back(des);
     }

     std::vector<int> dfs(int startnode);
     void bfs();

};

std::vector<int> Graph::dfs(int startnode)
{
    std::map<int , bool> visitedNodes;
    std::vector<int> output;
    dfsUtil(startnode, visitedNodes, output);
    return output;
}

void Graph::dfsUtil(int startnode, std::map<int, bool> visitedNode, std::vector<int>& output)
{
    // get the neighbors
    if(visitedNode[startnode]  != NULL )
        return;
    visitedNode[startnode] = true;
    // put it to the output
    output.push_back(startnode);

    auto nlist = adjList[startnode];
    for(auto element:nlist)
    {
        dfsUtil(element, visitedNode,output);
    }
}

int main()
{
    // build graph
    int n= 5;
    auto  graph = new Graph(n);

    for(int i=0; i< graph->getVertices(); i++)
    {
        // create neighbor for each node
        graph->addEdge(i, (i+2)%n);
    }

    auto nodes = graph->dfs(0);
    for(auto node:nodes)
    {
        std::cout<< " Node " <<node<<std::endl;
    }

    return 0;
}
