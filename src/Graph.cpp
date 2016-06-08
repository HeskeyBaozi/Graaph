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
	_Adj_List[to].insert(Pair(from, weight));
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

set<int> Graph::_Adj(const int vertex)
{
	set<int> result;
	for(const auto& tuple:_Adj_List[vertex])
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


