
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <sstream>

class Graph
{
	int vertices;
	std::map<int, std::vector<std::pair<int,int> > > graphList;

public :
	Graph(int vertices);
	void addEdge(int s, int d, int weight);
	void print();
};



Graph::Graph(int v):vertices(v)
{}


void Graph::addEdge(int s, int d, int weight)
{

	std::pair<int, int> pair = std::make_pair(d,weight);
	if(graphList.find(s) == graphList.end())
	{
		// add the element

		// make list
		std::vector<std::pair<int,int> > list;
		list.push_back(pair);
		graphList[s] = list;
	}
	else
	{
		//get the list and insert pair
		std::vector<std::pair<int, int > > list = graphList[s];
		list.push_back(pair);
	}
}

void Graph::print()
{
        
        std::stringstream s;
    for(auto itr = graphList.begin(); itr != graphList.end(); itr++)
    {
        s<<"vertex "<<itr->first;
        for(auto ele: itr->second)
        {
            s<<" neighbors "<<ele.first<< " weight "<<ele.second;   
        }
        s<<"\n";
    }
    std::cout<<s.str();
}

int main()
{
    Graph graph(3);
    graph.addEdge(1,2,11);
    graph.addEdge(2,3,12);
    graph.addEdge(3,1,21);
    
    graph.print();
    return 0;
}
