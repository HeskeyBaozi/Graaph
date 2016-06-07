#pragma once
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include <map>
class Graph
{
public:
	Graph();
	~Graph();

	/* Vertex */
	void addVertex(const Vertex& v);

	/* Edge */
	void insertEdge(const Edge& e);
	void insertEdge(const Vertex a, const Vertex b, int weight = 0);
	
	/* get Adj */
	std::vector<Vertex> getAdj(const Vertex& v);

	/* display */
	void display() const;
private:
	std::map<Vertex, std::vector<Edge> > __map;
};

