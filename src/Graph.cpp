#include "Graph.h"
using namespace std;
#define DEBUG

Pair::Pair(int to, int w)
	:To(to), Weight(w)
{
}

Graph::Graph(int VertexNumber)
	:_Adj_List()
{
	for (int i = 0; i != VertexNumber; ++i)
	{
		insertVertex(i);
	}
}

void Graph::insertVertex(int from)
{
	_Adj_List.insert(make_pair(from, vector<Pair>()));
}

void Graph::insertEdge(int from, int to, int weight)
{
	_Adj_List[from].push_back(Pair(to, weight));
	_Adj_List[to].push_back(Pair(from, weight));
}

set<int> Graph::_V()
{
	set<int> result;
	for (const auto& pair : _Adj_List)
	{
		result.insert(pair.first);
	}
	return result;
}

void Graph::display() const
{
	for(const auto& pair: _Adj_List)
	{
		cout << pair.first << " : ";
		for (const auto& tuple : pair.second)
		{
#ifndef DEBUG
			cout << "(" << tuple.Weight << ", " << tuple.To << ")";
#endif
			cout << tuple.To << " ";
		}
		cout << endl;
	}
}
