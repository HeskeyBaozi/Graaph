#include "Pair.h"

Pair::Pair(int to, int w)
	:To(to), Weight(w)
{
}

bool operator<(const Pair& lhs, const Pair& rhs)
{
	if (lhs.To < rhs.To)return true;
	//if (lhs.Weight < rhs.Weight)return true;
	return false;
}