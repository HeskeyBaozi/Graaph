#pragma once
#define NIL -1
#define INF 9999

/* the color of the vertex */
enum color
{
	WHITE, GERY, BLACK
};

/* additional attributes of the vertex */
class baseAttr
{
public:
	/* constructor */
	explicit baseAttr(color mycolor = WHITE, int pi = NIL);

	/* members */
	color _color;
	int _parent;
};

/* additional attributes in BFS */
class BFS_Attr
	:public baseAttr
{
public:
	/* constructor */
	explicit BFS_Attr(color mycolor = WHITE,
		int pi = NIL,
		int distance = INF);
	/* members */
	int _distance;
};

class DFS_Attr
	:public baseAttr
{
public:
	/* constructor */
	explicit DFS_Attr(color mycolor = WHITE,
		int pi = NIL);

	/* members */
	int _discovered;
	int _finished;
};
