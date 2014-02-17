#include <iostream>
#include <boost/dynamic_bitset.hpp>

static int number_of_primes_under(int N)
{
	boost::dynamic_bitset<> primes(N+1);
	primes.set();
	primes[0] = primes[1] = 0;

	for (int p = 2; p < N; ++p) {
		if (primes[p] != 0) {
			for (int i = p+p; i < N; i += p) {
				primes[i] = 0;
			}
		}
	}

	return primes.count();
}

int main(void)
{
	std::cout << number_of_primes_under(120) << std::endl;
	return 0;
}
