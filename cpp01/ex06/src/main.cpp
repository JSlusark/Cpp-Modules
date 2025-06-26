#include "../headers/Harl.hpp"


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error: you need to pass 1 argument to start Harl" << std::endl;
		return 1;
	}
	Harl harl;

	harl.complain(argv[1]);

	return 0;
}
