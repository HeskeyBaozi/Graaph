#include "Graph.h"
#define NIL -1
#define INF 9999
using namespace std;

/*
*  Breadth First Search
*  Args:
*           s: ��ʾԴ���, ����Ϊ int
*       visit: ���ʻص�����, ����Ϊ function<>
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

	// �����������Կ�
	map<int, MyAttr> $;

	// ��ʼ�����ж���
	for (const auto& pair : _Adj_List)
	{
		$.emplace(pair.first, MyAttr());
	}

	// ��ʼ��Դ����
	$[s] = MyAttr
		(Gery, 0, NIL);

	// ��������Q
	deque<int> Q;

	// Դ������
	Q.push_back(s);


	// ****************************
	//            loop
	// ****************************
	//  ����Q����������Ľ�㶼�� Gery ��
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