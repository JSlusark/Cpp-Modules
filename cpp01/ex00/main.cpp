#include "Zombie.hpp"

int main()
{
	std::cout << C_MAGENTA "Creating a Zombie on the heap:" C_RESET << std::endl;
	//Needed when the lifetime of the object must survive outside the current scope.
	Zombie* heapZombie = NewZombie(C_MAGENTA "Heapie" C_RESET);
	heapZombie->Announce();
	delete heapZombie;
	std::cout << C_RED "Creating a Zombie on the stack:" C_RESET << std::endl;
	// Stack object is destroyed automatically when it goes out of scope.
	randomChump(C_RED "Stackie" C_RESET);
	return 0;
}