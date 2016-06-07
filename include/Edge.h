#pragma once
#include "Vertex.h"
class Edge
{
public:
	Edge(const Vertex&, const Vertex&, int weight = 0);
	~Edge();

	/* operation */
	friend bool operator<(const Edge& lhs, const Edge& rhs);
	friend bool operator==(const Edge& lhs, const Edge& rhs);
	friend bool operator!=(const Edge& lhs, const Edge& rhs);

	/* Getter */
	double getWeight() const;
	const Vertex from;
	const Vertex to;
private:	
	int __weight;
};

