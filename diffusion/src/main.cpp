#include <core/core.h>
#include <stdexcept>

int main(void)
{
	try
	{
		App app;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
}