#include <iostream>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " src dest" << std::endl;
		return -1;
	}

	boost::filesystem::path src = argv[1];
	boost::filesystem::path dest = argv[2];

	if (boost::filesystem::exists(dest)) {
		if (boost::filesystem::is_directory(dest)) {
			dest = dest / src.leaf();
		}

		if (boost::filesystem::exists(dest)) {
			if (boost::filesystem::is_directory(dest)) {
				std::cout << "Can't override directory" << std::endl;
				return -1;
			} else {
				char ch;

				do {
					std::cout << "Override(Y/N) ";
					std::cin >> ch;

					if (ch == 'N')
						return -1;
				} while(ch != 'Y');
				boost::filesystem::remove(dest);
			}
		}
	}

	boost::filesystem::rename(src, dest);
	return 0;
}
