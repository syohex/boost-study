#include <iostream>
#include <boost/multi_array.hpp>

int main(void)
{
	boost::multi_array<int, 3> a(boost::extents[2][3][4]);

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 4; ++k) {
				a[i][j][k] = i + j + k;
			}
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 4; ++k) {
				std::cout << a[i][j][k] << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
