#include "Graph.h"
#include <Attr.h>
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
	_Adj_List.insert(make_pair(from, set<Tuple>()));
}

void Graph::insertEdge(int from, int to, int weight)
{
	cout << "Tuple: " << Tuple(from, to, weight) << endl;
	_Adj_List[from].insert(Tuple(from, to, weight));
	cout << "["<<from<<"] result:" << endl;
	for(const auto& t:_Adj_List[from])
	{
		cout << t;
	}
	cout << endl << endl;
}

void Graph::insertUndirectedEdge(int from, int to, int weight)
{
	_Adj_List[from].insert(Tuple(from, to, weight));
	_Adj_List[to].insert(Tuple(to, from, weight));
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
	set<Tuple> tupleset;
	if (_Adj_List.find(vertex) != _Adj_List.end())
		tupleset = _Adj_List.at(vertex);
	for(const auto& tuple: tupleset)
	{
		result.insert(tuple.To);
	}
	return result;
}

int Graph::getWeight(const int u, const int v) const
{
	try
	{
		for (const auto& tuple : _Adj_List.at(u))
		{
			if (tuple.To == v)
				return tuple.Weight;
		}
		return INF;
	}
	catch(out_of_range ex)
	{
		cerr << ex.what() << ". No path from " << u << " to " << v << endl;
		return INF;
	}

}

set<Tuple> Graph::getAdjTuple(const int v) const
{
	set<Tuple> result = _Adj_List.at(v);
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

