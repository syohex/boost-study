#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

static void handler(const boost::system::error_code& e)
{
	if (!e)
		std::cout << "Take 3 seconds" << std::endl;
}

int main(void)
{
	boost::asio::io_service io;

	boost::asio::deadline_timer timer(io, boost::posix_time::seconds(3));
	timer.async_wait(&handler);

	io.run();

	return 0;
}
