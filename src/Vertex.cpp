#include "Vertex.h"
using namespace std;

Vertex::Vertex(const string& label)
	:__label(label)
{
}

Vertex::Vertex(const Vertex& other)
	:__label(other.getLabel())
{
}

Vertex::~Vertex()
{
}

string Vertex::getLabel() const
{
	return __label;
}

bool operator<(const Vertex& lhs, const Vertex& rhs)
{
	return lhs.getLabel() < rhs.getLabel();
}

bool operator==(const Vertex& lhs, const Vertex& rhs)
{
	return lhs.getLabel() == rhs.getLabel();
}

bool operator!=(const Vertex& lhs, const Vertex& rhs)
{
	return !(lhs == rhs);
}
