#pragma once
#define NIL -1
#define INF 9999
#include <ostream>

/* the color of the vertex */
enum color
{
	WHITE, GERY, BLACK, NONE
};

/* additional attributes of the vertex */
class baseAttr
{
public:
	/* constructor */
	explicit baseAttr(int v = NIL, int pi = NIL);

	/* members */
	int _getVertex;
	int _parent;
};

/* additional attributes in BFS */
class BFS_Attr
	:public baseAttr
{
public:
	/* constructor */
	explicit BFS_Attr(int v = NIL, int pi = NIL, color mycolor = NONE, int distance = INF);
	/* members */
	color _color;
	int _distance;
};

class DFS_Attr
	:public baseAttr
{
public:
	/* constructor */
	explicit DFS_Attr(int v = NIL, int pi = NIL, color mycolor = NONE);

	/* members */
	color _color;
	int _discovered;
	int _finished;
};

class Prim_Vertex
	:public baseAttr
{
public:
	/* constructor */
	explicit Prim_Vertex(int v = NIL, int pi = NIL, color mycolor = WHITE, int key = INF);

	/* members */
	int _key;
	color _color;
	friend bool operator<(const Prim_Vertex& lhs, const Prim_Vertex& rhs)
	{
		return lhs._key > rhs._key;
	}
};