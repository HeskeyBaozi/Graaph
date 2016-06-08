#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Pair.h"
#include <functional>

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
	void BFS(int s, std::function<void(int)> visit);
	void DFS(std::function<void(int)> visit);

	/* display */
	void display() const;
private:
	std::map<int, std::set<Pair>> _Adj_List;
	std::set<int> _V();
	std::set<int> _Adj(const int vertex);
};