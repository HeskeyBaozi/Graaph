#include "Graph.h"
using namespace std;

Pair::Pair(int to, int w)
	:To(to), Weight(w)
{
}

Graph::Graph(int VertexNumber)
	:AdjList()
{
	for (int i = 0; i != VertexNumber; ++i)
	{
		insertVertex(i);
	}
}

void Graph::insertVertex(int from)
{
	AdjList.insert(make_pair(from, vector<Pair>()));
}

void Graph::insertEdge(int from, int to, int weight)
{
	AdjList[from].push_back(Pair(to, weight));
}

set<int> Graph::V()
{
	set<int> result;
	for (const auto& pair : AdjList)
	{
		result.insert(pair.first);
	}
	return result;
}
