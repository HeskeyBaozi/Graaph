#include "Test.h"
using namespace std;

vector<vector<int>> createMatrix()
{
	vector<vector<int>> temp = {
		{0,4,4,6,6},
		{4,0,2,0,0},
		{4,2,0,8,0},
		{6,0,8,0,9},
		{6,0,0,9,0}
	};
	return temp;
}