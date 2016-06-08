struct Pair
{
	Pair(int to, int w);
	int To;
	int Weight;
	friend bool operator<(const Pair& lhs, const Pair& rhs);
};