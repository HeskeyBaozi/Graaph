#include "Graph.h"
using namespace std;

int k(int t, int o)
{
	return t + o;
}
int main()
{
	Graph a(6);
	a.insertEdge(0, 3, 1);
	a.insertEdge(0, 5, 1);
	a.insertEdge(0, 1, 1);
	a.insertEdge(1, 5, 1);
	a.insertEdge(1, 4, 1);
	a.insertEdge(5, 4, 1);
	a.insertEdge(4, 3, 1);
	a.insertEdge(2, 3, 1);
	a.insertEdge(2, 4, 1);
	a.insertEdge(3, 5, 1);
	a.insertEdge(2, 5, 1);
	a.insertEdge(2, 0, 1);
	a.display();
	a.BFS(0,[](int v)
	{
		cout << v << " ";
	});
	return 0;
}