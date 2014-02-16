#include <iostream>
#include <string>
#include <boost/asio.hpp>

int main(void)
{
	boost::asio::io_service io;

	boost::asio::ip::tcp::acceptor acc(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 10101));
	for (;;) {
		boost::asio::ip::tcp::iostream s;

		acc.accept(*s.rdbuf());

		int x, y;
		s >> x >> y;
		s << x+y << std::endl;

		std::cout << x << "+" << y << " = " << x+y << std::endl;
	}
	return 0;
}
