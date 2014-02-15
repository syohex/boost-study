#include <iostream>
#include <boost/thread.hpp>

static int sum1;
static int sum2;

static void show_a()
{
	for (int i = 0; i < 200000000; ++i)
		sum1++;
}

static void show_b()
{
	for (int i = 0; i < 100000000; ++i)
		sum2++;
}

int main(void)
{
	boost::thread ta(&show_a);
	boost::thread tb(&show_b);

	ta.join();
	tb.join();

	std::cout << "sum1=" << sum1 << std::endl;
	std::cout << "sum2=" << sum2 << std::endl;
	return 0;
}
