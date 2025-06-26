#include "../headers/Zombie.hpp"

int main()
{
	int size = 6;
	std::cout << C_YELLOW "Creating Zombie Group" C_RESET << std::endl;
	Zombie *zombieGroup = zombieHorde(size, "Group_Zombie_");
	if (!zombieGroup)
		std::cout << "ZombieGroup failed to allocate" << std::endl;
	for (int i = 0; i < size; i++)
		zombieGroup[i].announce();
	std::cout << C_YELLOW "Destroying the horde..." C_RESET << std::endl;
	delete[] zombieGroup; // deletes the group that was allocated on the heap, while zombies are destructed automatically
	return 0;
}