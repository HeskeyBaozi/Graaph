#include "Graph.h"
using namespace std;
#define DEBUG



Graph::Graph(int VertexNumber)
	:_Adj_List()
{
	for (int i = 0; i != VertexNumber; ++i)
	{
		insertVertex(i);
	}
}

Graph::Graph(const vector<vector<int>>& matrix)
	:_Adj_List()
{
	int size = matrix.size();
	for (int i = 0; i != size; ++i)
	{
		for (int j = 0; j != size; ++j)
		{
			if (matrix[i][j] != 0)
			{
				insertEdge(i, j, matrix[i][j]);
			}
		}
	}
}

void Graph::insertVertex(int from)
{
	_Adj_List.insert(make_pair(from, set<Pair>()));
}

void Graph::insertEdge(int from, int to, int weight)
{
	_Adj_List[from].insert(Pair(to, weight));
}

set<int> Graph::_V() const
{
	set<int> result;
	for (const auto& pair : _Adj_List)
	{
		result.insert(pair.first);
	}
	return result;
}

set<int> Graph::_Adj(const int vertex) const
{
	set<int> result;
	set<Pair> tupleset;
	if (_Adj_List.find(vertex) != _Adj_List.end())
		tupleset = _Adj_List.at(vertex);
	for(const auto& tuple: tupleset)
	{
		result.insert(tuple.To);
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

list<int> Topological_sort(const Graph& G)
{
	list<int> result;
	auto nothing = [](int u) {};
	G.DFS(nothing, [&](int u)
	{
		result.push_front(u);
	});
	return result;
}
