#include <iostream>
#include <boost/filesystem.hpp>

int main(void)
{
	boost::filesystem::path backup_dir("backup");
	boost::filesystem::create_directory(backup_dir);

	boost::filesystem::path work_file("readme.txt");
	if (boost::filesystem::exists(work_file))
		boost::filesystem::copy_file(work_file, backup_dir / "readme.bak");

	boost::filesystem::remove_all(backup_dir);
	return 0;
}
