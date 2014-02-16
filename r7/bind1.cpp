#include <iostream>
#include <algorithm>
#include <boost/bind.hpp>

static bool less_int(int x, int y)
{
	return x < y;
}

int main(void)
{
	int v[5] = {500, 100, 50, 10, 5};
	int N = 100;

	int *i = std::find_if(v, v+5, bind(&less_int, _1, N));
	std::cout << *i << std::endl;

	return 0;
}
