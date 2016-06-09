#include "Graph.h"
#include <deque>
#include <queue>
#include "Attr.h"
using namespace std;

/*
*  Breadth First Search
*  Args:
*           s: ��ʾԴ���, ����Ϊ int
*       visit: ���ʻص�����, ����Ϊ function<>
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
		// ���벻����Ȩ��
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
	//      ��ӡһ�Ź��������
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
			/* �ؼ����� */
			/* ��ӡ�����е�ǰ������Ŵ�ӡĿ���� */
			Print_Path(source, $[des]._parent);
			cout << des << endl;
			cout << "����Ϊ" << $[des]._distance << endl;
		}
		return;
	};

	// Test Print
	cout << "\n���Դ�ӡ·��: " << endl;
	Print_Path(s, 2);
#endif
}


/*
*  Depth First Search
*  Args:
*           s: ��ʾԴ���, ����Ϊ int
*       visit: ���ʻص�����, ����Ϊ function<>
*/
void Graph::DFS(function<void(int)> dOrder, function<void(int)> fOrder) const
{

	map<int, DFS_Attr> $;

	/*
	* ��ʼ��: ���Ϳ��, ǰ���ڵ�Ϊ��
	*/
	const set<int> V = _V();
	for (const int& each_vertex : V)
	{
		$[each_vertex] = DFS_Attr(each_vertex, NIL, WHITE);
	}

	/*
	* ȫ��ʱ���������λ
	*/
	int time = 0;

	function<void(int)> DFS_Visit = [&](const int u)
	{
		++time; // white vertex u has just been discovered
		$[u]._discovered = time;
		$[u]._color = GERY; // ��ɫ�����Ѿ����ʵ�δ��ͷ�ĵ�
		cout << "(" << u << " ";
		dOrder(u);
		set<int> V_Adj = _Adj(u);
		for (const int& v : V_Adj) // explore edge (u -> v)
		{
			if ($[v]._color == WHITE)
			{
				$[v]._parent = u; // һ�εݹ��Ӧ��һ��ǰ��ߵĽ���
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
	* ���ζ�ÿ�������м��
	*/
	for (const int& u : V)
	{
		if ($[u]._color == WHITE)
		{
			/*
			* ÿ�ε���DFS_Visitʱ, ���u���Ϊ
			* �������ɭ����һ���µ�����������ĸ����
			*/
			cout << "root " << u << " :" << endl;
			DFS_Visit(u);
			cout << endl;
		}
	}
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

	auto adjtuple = G.getAdjTuple(root);
	for (const Tuple& edge : adjtuple)
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
