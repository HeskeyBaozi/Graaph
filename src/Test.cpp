#include "Test.h"
using namespace std;

vector<vector<int>> createMatrix()
{
	vector<vector<int>> temp = {
		{ 0,4,4,6,6 },
		{ 4,0,2,0,0 },
		{ 4,2,0,8,0 },
		{ 6,0,8,0,9 },
		{ 6,0,0,9,0 }
	};
	return temp;
}

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

void testTopo()
{
	Graph a({
		{ 0,1,0,0,0,0,0,1,0 },
		{ 0,0,1,0,0,0,0,1,0 },
		{ 0,0,0,0,0,1,0,0,0 },

		{ 0,0,1,0,1,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0 },

		{ 0,0,0,0,0,0,0,1,0 },
		{ 0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0 }
	});

	map<int, string> m = {
		{ 0,"内裤" },
		{ 1,"裤子" },
		{ 2,"腰带" },
		{ 3,"衬衣" },
		{ 4,"领带" },
		{ 5,"夹克" },
		{ 6,"袜子" },
		{ 7,"鞋子" },
		{ 8,"手表" }

	};
	auto lst = Topological_sort(a);
	cout << "Topo Sort:" << endl;
	cout << "Start";
	for (const int& v : lst)
	{
		cout << " -> " << m[v];
	}
	cout << endl;
}

void testPrim()
{
	Graph a(9);
	a.insertUndirectedEdge(1, 2, 4);
	a.insertUndirectedEdge(1, 8, 8);
	a.insertUndirectedEdge(2, 8, 11);
	a.insertUndirectedEdge(2, 3, 8);
	a.insertUndirectedEdge(8, 9, 7);
	a.insertUndirectedEdge(8, 7, 1);
	a.insertUndirectedEdge(7, 9, 6);
	a.insertUndirectedEdge(3, 9, 2);
	a.insertUndirectedEdge(3, 6, 4);
	a.insertUndirectedEdge(7, 6, 2);
	a.insertUndirectedEdge(4, 6, 14);
	a.insertUndirectedEdge(4, 5, 9);
	a.insertUndirectedEdge(5, 6, 10);
	a.insertUndirectedEdge(3, 4, 7);

	a.display();
	map<int, char> m;
	for (int i = 0; i != 8; ++i)
	{
		m.emplace(i + 1, 'a' + i);
	}
	auto r = MST_Prim(a, 1);
	for (const auto& v : r)
	{
		cout << v;
	}
}
