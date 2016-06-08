#include "Graph.h"
#define NIL -1
#define INF 9999
using namespace std;

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
			: _color(mycolor), _d(distance), _parent(pi)
		{
		}
		color _color;
		int _d;
		int _parent;
	};

	// ****************************
	//        inittalization
	// ****************************

	// 顶点额外的属性库
	map<int, MyAttr> $;

	// 初始化所有顶点
	for (const auto& pair : _Adj_List)
	{
		$.emplace(pair.first, MyAttr());
	}

	// 初始化源顶点
	$[s] = MyAttr
		(Gery, 0, NIL);

	// 正常队列Q
	deque<int> Q;

	// 源点入列
	Q.push_back(s);


	// ****************************
	//            loop
	// ****************************
	//  队列Q中里面包含的结点都是 Gery 的
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop_front();
		set<int> V = _V();
		for (const int& v : V)
		{
			if ($[v]._color == White)
			{
				visit(v);
				$[v] = MyAttr
					(Gery, $[u]._d + 1, u);
				Q.push_back(v);
			}
		}
		$[u]._color = Black;
		Show(Q);
	}
}