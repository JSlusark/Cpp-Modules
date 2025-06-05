#include "Zombie.hpp"

int main()
{
	std::cout << C_YELLOW "Creating Zombie Group" C_RESET << std::endl;
	Zombie *zombieGroup = zombieHorde(6, "Group_Zombie_");
	if (!zombieGroup)
	{
		std::cout << "ZombieGroup failed to allocate" << std::endl;
	}
	for (int i = 0; i < 6; i++)
		zombieGroup[i].Announce();

	std::cout << C_YELLOW "Destroying the horde..." C_RESET << std::endl;
	delete[] zombieGroup; // deletes the group
	return 0;
}