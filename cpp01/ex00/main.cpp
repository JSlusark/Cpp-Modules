#include "Zombie.hpp"

int main()
{
	std::cout << "Creating a Zombie on the heap:" << std::endl;
	//Needed when the lifetime of the object must survive outside the current scope.
	Zombie* heapZombie = NewZombie("Heapie");
	heapZombie->Announce();
	delete heapZombie;
	std::cout << "Creating a Zombie on the stack:" << std::endl;
	// Stack object is destroyed automatically when it goes out of scope.
	randomChump("Stackie");
	return 0;
}