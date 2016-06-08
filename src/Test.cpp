#include "Test.h"
using namespace std;

vector<vector<int>> createMatrix()
{
	vector<vector<int>> temp = {
		{0,4,4,6,6},
		{4,0,2,0,0},
		{4,2,0,8,0},
		{6,0,8,0,9},
		{6,0,0,9,0}
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
		{ 0,"�ڿ�" },
		{ 1,"����" },
		{ 2,"����" },
		{ 3,"����" },
		{ 4,"���" },
		{ 5,"�п�" },
		{ 6,"����" },
		{ 7,"Ь��" },
		{ 8,"�ֱ�" }

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
