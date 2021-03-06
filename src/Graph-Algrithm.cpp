﻿#include "Graph.h"
#include <deque>
#include <queue>
#include "Attr.h"
using namespace std;

/*
*  Breadth First Search
*  Args:
*           s: 表示源结点, 类型为 int
*       visit: 访问回调函数, 类型为 function<>
*/
void Graph::BFS(int s, function<void(int)> visit) const
{
	// ****************************
	//        inittalization
	// ****************************

	map<int, BFS_Attr> $;
	const set<int> V = _V();
	for (const auto& each_vertex : V)
	{
		$[each_vertex] = BFS_Attr(each_vertex, NIL, WHITE, INF);
	}
	$[s] = BFS_Attr(s, NIL, GERY, 0);

	deque<int> Q;
	visit(s);
	Q.push_back(s);

	// ****************************
	//            loop
	// ****************************
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop_front();
#ifndef WEIGHT_GRAPH
		// 距离不包含权重
		set<int> V_Adj = _Adj(u);
		for (const int& v : V_Adj)
		{
			if ($[v]._color == WHITE)
			{
				visit(v);
				$[v] = BFS_Attr
					(v, u, GERY, $[u]._distance + 1);
				Q.push_back(v);
			}
		}
#endif
		$[u]._color = BLACK;
	}

#ifdef PRINT_PATH

	// ****************************
	//      打印一颗广度优先树
	// ****************************
	function<void(int,int)> Print_Path 
		= [&](int source, int des)
	{
		if (source == des)
			cout << source << endl;
		else if ($[des]._parent == NIL)
			cout << "No path from " << source << " to " << des << " exists." << endl;
		else
		{
			/* 关键步骤 */
			/* 打印完所有的前驱顶点才打印目标结点 */
			Print_Path(source, $[des]._parent);
			cout << des << endl;
			cout << "距离为" << $[des]._distance << endl;
		}
		return;
	};

	// Test Print
	cout << "\n测试打印路径: " << endl;
	Print_Path(s, 2);
#endif
}


/*
*  Depth First Search
*  Args:
*           s: 表示源结点, 类型为 int
*       visit: 访问回调函数, 类型为 function<>
*/
void Graph::DFS(function<void(int)> dOrder, function<void(int)> fOrder) const
{

	map<int, DFS_Attr> $;

	/*
	* 初始化: 结点涂白, 前驱节点为空
	*/
	const set<int> V = _V();
	for (const int& each_vertex : V)
	{
		$[each_vertex] = DFS_Attr(each_vertex, NIL, WHITE);
	}

	/*
	* 全局时间计数器复位
	*/
	int time = 0;

	function<void(int)> DFS_Visit = [&](const int u)
	{
		++time; // white vertex u has just been discovered
		$[u]._discovered = time;
		$[u]._color = GERY; // 灰色代表已经访问但未到头的点
		cout << "(" << u << " ";
		dOrder(u);
		set<int> V_Adj = _Adj(u);
		for (const int& v : V_Adj) // explore edge (u -> v)
		{
			if ($[v]._color == WHITE)
			{
				$[v]._parent = u; // 一次递归对应着一次前向边的建立
				DFS_Visit(v);
			}
		}
		$[u]._color = BLACK; // blacken u; it's finished
		++time;
		$[u]._finished = time;
		fOrder(u);
		cout << " " << u << ")";		
	};


	/*
	* 依次对每个结点进行检查
	*/
	for (const int& u : V)
	{
		if ($[u]._color == WHITE)
		{
			/*
			* 每次调用DFS_Visit时, 结点u便成为
			* 深度优先森林中一颗新的深度优先树的根结点
			*/
			cout << "root " << u << " :" << endl;
			DFS_Visit(u);
			cout << endl;
		}
	}
}

set<Tuple> BFS(const Graph& G, const int source)
{
	set<int> BFS_Tree_V;
	set<Tuple> BSF_Tree_E;
	queue<int> Q;
	Q.push(source);
	BFS_Tree_V.insert(source);

	while(!Q.empty()) // Q is a normal queue;
	{
		int u = Q.front(); Q.pop();
		set<int> neighboor_vertice_of_u = G._Adj(u);
		for (const int& v : neighboor_vertice_of_u)
		{
			// if v is unvisited
			if (BFS_Tree_V.find(v) == BFS_Tree_V.end())
			{
				// visit v;
				BFS_Tree_V.insert(v);
				BSF_Tree_E.insert(Tuple(u, v, G.getWeight(u, v)));
				Q.push(v);
			}
		}
	}
	return BSF_Tree_E;
}

set<Tuple> DFS(const Graph& G, const int source)
{
	set<int> DFS_Tree_V;
	set<Tuple> DFS_Tree_E;
	function<void(int)> _DFS =[&](int u)
	{
		cout << '(' << u << ' ';
		set<Tuple> Adj_Edges_Of_u = G.getAdjTuple(u);
		for (const Tuple& adj_Edge : Adj_Edges_Of_u)
		{
			int v = adj_Edge.To;
			// if v is unvisited, (u, v) is a tree edge;
			if (DFS_Tree_V.find(v) == DFS_Tree_V.end())
			{
				// visit v;
				DFS_Tree_V.insert(v);
				DFS_Tree_E.insert(adj_Edge);
				_DFS(v);
			}
			// if v is explored, bidirectional/back edge
			// if v is visited, forward / cross edge
		}
		cout << ' ' << u << ')';
	};
	_DFS(source);
	return DFS_Tree_E;
}

list<int> Topological_sort(const Graph& G)
{
	list<int> result;
	auto nothing = [](int u) {};
	G.DFS(nothing, [&](int u)
	{
		result.push_front(u);
	});
	return result;
}

set<Tuple> MST_Prim(const Graph& G, const int root)
{
	set<Tuple> Tree_E;
	set<int> Tree_V;
	Tree_V.insert(root);

	// PQ: by inc weight
	priority_queue<Tuple, vector<Tuple>, greater<Tuple>> PQ;

	set<Tuple> Adj_Edge_Set_Of_Root = G.getAdjTuple(root);
	for (const Tuple& edge : Adj_Edge_Set_Of_Root)
	{
		PQ.push(edge);
	}

	while(!PQ.empty())
	{
		Tuple minWeightEdge = PQ.top(); PQ.pop();
		if (Tree_V.find(minWeightEdge.To) == Tree_V.end())
		{
			Tree_V.insert(minWeightEdge.To);
			Tree_E.insert(minWeightEdge);
			for (const Tuple& edge : G.getAdjTuple(minWeightEdge.To))
			{
				PQ.push(edge);
			}
		}
	}
	return Tree_E;
}

int Ford_Fulkerson(const Graph&, const int s, const int t)
{
	// init Max Flow
	return 1;
}
