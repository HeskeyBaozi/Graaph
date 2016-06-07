#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include <vector>
using namespace std;
typedef Vertex V;

void TestVertex()
{
	Vertex A("A");
	cout << A.getLabel() << endl;
}

void TestEdge()
{
	Vertex A("A"), B("B");
	Edge e1(A, B, 13);
	cout << e1.getWeight() << endl;
}

void TestGraph()
{
	Graph G;
	vector<Vertex> set = { V("A") ,V("B") ,V("C") ,V("D") };

	for (auto& vertex : set)
	{
		G.addVertex(vertex);
	}

	G.insertEdge(V("A"), V("B"), 4);
	G.insertEdge(V("A"), V("C"), 4);
	G.insertEdge(V("A"), V("D"), 4);

	auto te = G.getAdj(V("A"));
	for(auto& t:te)
	{
		cout << t.getLabel() << endl;
	}
	cout << endl;
	G.display();
}

int main()
{
	TestGraph();
}