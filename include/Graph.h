#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Tuple.h"
#include <functional>
#include <list>

// 二元组
// ( toVertex, Weight )


// 图
class Graph
{
public:
	explicit Graph(int VertexNumber = 0);
	explicit Graph(const std::vector<std::vector<int>>& matrix);

	/* Insert */
	void insertVertex(int from);
	void insertEdge(int from, int to, int weight = 1);
	void insertUndirectedEdge(int from, int to, int weight = 1);

	/* Algorithm */
	void BFS(int s, std::function<void(int)> visit = nullptr) const;
	void DFS(std::function<void(int)> dOrder = nullptr, 
		std::function<void(int)> fOrder = nullptr) const;

	/* display */
	void display() const;

	/* Set Getter */
	std::set<int> _V() const;
	std::set<int> _Adj(const int vertex) const;
	int getWeight(const int u, const int v) const;
	std::set<Tuple> getAdjTuple(const int v) const;
private:
	std::map<int, std::set<Tuple>> _Adj_List;
};

/* 拓扑排序 */
std::list<int> Topological_sort(const Graph& G);

/* 最小生成树 */
//std::map<int, Pair> MST_Kruskal(const Graph& G);
std::set<Tuple> MST_Prim(const Graph& G, const int root);