#include "Graph.h"
using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addVertex(const Vertex& v)
{
	__map.emplace(v, vector<Edge>());
}

void Graph::insertEdge(const Edge& e)
{
	__map[e.from].push_back(e);
}

void Graph::insertEdge(const Vertex a, const Vertex b, int weight)
{
	cout << a.getLabel() << b.getLabel() << weight << endl;
	__map[a].push_back(Edge(a, b, weight));
	cout << __map[a].size() << endl;
	__map[b].push_back(Edge(b, a, weight));
}

vector<Vertex> Graph::getAdj(const Vertex& v)
{
	vector<Vertex> temp;
	for (const Edge& edge : __map[v])
	{
		temp.push_back(edge.to);
	}
	return temp;
}

void Graph::display() const
{
	for (const auto& pair : __map)
	{
		cout << pair.first.getLabel() << " : ";
		for (const auto& edge : pair.second)
		{
			cout << "(" << edge.from.getLabel() << ", " << edge.to.getLabel() << ", " << edge.getWeight() << ")  ";
		}
		cout << endl;
	}
}
