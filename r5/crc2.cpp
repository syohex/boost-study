#include <iostream>
#include <boost/crc.hpp>

int main(void)
{
	boost::crc_basic<8> crc_calc(0x96);

	crc_calc.process_bit(1);
	crc_calc.process_bit(1);
	crc_calc.process_bit(0);
	crc_calc.process_bit(1);

	std::cout << "0x" << std::hex
		  << static_cast<unsigned long>(crc_calc.checksum())
		  << std::endl;
	return 0;
}
