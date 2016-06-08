#include "Graph.h"
using namespace std;

void k(int t)
{
	cout << t << endl;
}
int main()
{
	function<int> a(k);
	return 0;
}