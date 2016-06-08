#include "Graph.h"
#define NIL -1
#define INF 999
using namespace std;


Pair::Pair(int to, int w)
	:To(to), Weight(w)
{
}

Graph::Graph(int VertexNumber)
	:AdjList()
{
	for (int i = 0; i != VertexNumber; ++i)
	{
		insertVertex(i);
	}
}

void Graph::insertVertex(int from)
{
	AdjList.insert(make_pair(from, vector<Pair>()));
}

void Graph::insertEdge(int from, int to, int weight)
{
	AdjList[from].push_back(Pair(to, weight));
	AdjList[to].push_back(Pair(from, weight));
}

set<int> Graph::V()
{
	set<int> result;
	for (const auto& pair : AdjList)
	{
		result.insert(pair.first);
	}
	return result;
}

/*
*  Breadth First Search
*  Args:
*           s: 表示源结点, 类型为 int
*       visit: 访问回调函数, 类型为 function<>
*/
void Graph::BFS(int s, function<void(int)> visit)
{
	auto Show = [](const deque<int>& Q)
	{
		cout << "Q = [ ";
		for (const auto& ele : Q)
		{
			cout << ele << " ";
		}
		cout << "]" << endl;
	};

	enum color
	{
		White, Gery, Black
	};

	class MyAttr
	{
	public:
		explicit MyAttr(color mycolor = White,
			int distance = INF,
			int pi = NIL)
			: _color(mycolor), d(distance), parent(pi){}
		color _color;
		int d;
		int parent;
	};

	// init
	map<int, MyAttr> $;
	for(const auto& pair:AdjList)
	{
		$.emplace(pair.first, MyAttr());
	}
	$[s]._color = Gery;
	$[s].d = 0;
	$[s].parent = NIL;
	deque<int> Q;
	Q.push_back(s);

	// loop
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop_front();
		const vector<Pair>& Adj = AdjList[u];
		for (const Pair& tuple : Adj)
		{
			const int& v = tuple.To;
			if ($[v]._color == White)
			{
				visit(v);
				$[v] = MyAttr
					(Gery, $[u].d + 1, u);
				Q.push_back(v);
			}
		}
		$[u]._color = Black;
		Show(Q);
	}
}

void Graph::display() const
{
	for(const auto& pair: AdjList)
	{
		cout << pair.first << " : ";
		for (const auto& tuple : pair.second)
		{
			//cout << "(" << tuple.Weight << ", " << tuple.To << ")";
			cout << tuple.To << " ";
		}
		cout << endl;
	}
}
