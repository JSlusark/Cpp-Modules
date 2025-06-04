#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Error: Number of zombies must be greater than 0." << std::endl;
		return NULL;
	}
	Zombie* zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::string zombieName = name+std::to_string(i);
		zombies[i] = Zombie(zombieName);
	}
	return zombies;
}