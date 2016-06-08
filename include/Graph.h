#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Pair.h"
#include <functional>
#include <list>

// ถþิชื้
// ( toVertex, Weight )


// อผ
class Graph
{
public:
	explicit Graph(int VertexNumber = 0);
	explicit Graph(const std::vector<std::vector<int>>& matrix);

	/* Insert */
	void insertVertex(int from);
	void insertEdge(int from, int to, int weight = 1);

	/* Algorithm */
	void BFS(int s, std::function<void(int)> visit = nullptr) const;
	void DFS(std::function<void(int)> dOrder = nullptr, 
		std::function<void(int)> fOrder = nullptr) const;

	/* display */
	void display() const;
private:
	std::map<int, std::set<Pair>> _Adj_List;
	std::set<int> _V() const;
	std::set<int> _Adj(const int vertex) const;
};

std::list<int> Topological_sort(const Graph& G);