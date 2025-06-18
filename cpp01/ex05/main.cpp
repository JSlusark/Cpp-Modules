#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("error");
	harl.complain("BLABLABLA");
	harl.complain("");

	return 0;
}
