#include "Graph.h"
#include "Test.h"
using namespace std;

void testBFS()
{
	Graph a(createMatrix());
	a.display();
	cout << endl;
	a.BFS(4, [](int v)
	{
		cout << v << " ";
	});
}

void testDFS()
{
	Graph a(createMatrix());
	a.DFS([](int v)
	{
		cout << v << " ";
	});
}

int main()
{
	testDFS();
	return 0;
}