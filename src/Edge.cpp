#include "Edge.h"
using namespace std;


Edge::Edge(const Vertex& v, const Vertex& u, int weight): from(v), to(u), __weight(weight)
{
}


Edge::~Edge()
{
}

double Edge::getWeight() const
{
	return __weight;
}

bool operator<(const Edge& lhs, const Edge& rhs)
{
	return lhs.getWeight() < rhs.getWeight();
}

bool operator==(const Edge& lhs, const Edge& rhs)
{
	bool labelFrom = lhs.from.getLabel() == rhs.from.getLabel();
	bool labelTo = lhs.to.getLabel() == rhs.to.getLabel();
	bool weight = lhs.getWeight() == rhs.getWeight();
	return labelFrom&&labelTo&&weight;
}

bool operator!=(const Edge& lhs, const Edge& rhs)
{
	return !(lhs == rhs);
}
