#include "Graph.h"
#include "Test.h"
#include <string>
using namespace std;

int main()
{
	Graph a({
		{0,1,1,1,0},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,0,0}
	});
	auto k = DFS(a, 0);
	for(const auto& t:k)
	{
		cout << t << endl;
	}
	return 0;
}