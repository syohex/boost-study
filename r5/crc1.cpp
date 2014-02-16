#include <iostream>
#include <boost/crc.hpp>

int main(void)
{
	unsigned char data[256];

	for (int i = 0; i < sizeof(data) - 1; ++i) {
		data[i+i] = static_cast<unsigned char>(data[i]*data[i]+5);
	}

	boost::crc_basic<32> crc_calc(0x8003);
	crc_calc.process_bytes(data, 256);

	std::cout << "0x" << std::hex << crc_calc.checksum() << std::endl;
	return 0;
}
