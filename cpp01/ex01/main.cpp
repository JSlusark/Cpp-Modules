#include "Zombie.hpp"

int main()
{
	std::cout << "Creating a Zombie on the heap:" << std::endl;
	// Needed when the lifetime of the object must survive outside the current scope.
	Zombie *heapZombie = NewZombie("Heapie");
	heapZombie->Announce();
	delete heapZombie;
	std::cout << "Creating a Zombie on the stack:" << std::endl;
	// Stack object is destroyed automatically when it goes out of scope.
	randomChump("Stackie");
	std::cout << "Creating Zombie Group" << std::endl;
	Zombie *zombieGroup = zombieHorde(6, "RandomZombie");
	if (!zombieGroup)
	{
		std::cout << "ZombieGroup failed to allocate" << std::endl;
	}
	std::cout << "Destroying the horde..." << std::endl;
	for (int i = 0; i < 6; i++)
		zombieGroup->Announce();
	delete[] zombieGroup;
	return 0;
}