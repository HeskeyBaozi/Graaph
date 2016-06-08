#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <functional>

struct Pair
{
	Pair(int to, int w);
	int To;
	int Weight;
};

class Graph
{
public:
	explicit Graph(int VertexNumber);

	/* Insert */
	void insertVertex(int from);
	void insertEdge(int from, int to, int weight);

	/* Getter */
	std::set<int> V();

	/* Algorithm */
	//void BFS(int s, std::function<void>(int vertex));
private:
	std::map<int, std::vector<Pair>> AdjList;
};