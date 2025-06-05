#include "Zombie.hpp"

std::string ToString(int n)
{
	std::ostringstream string_stream;

	string_stream << n;

	return string_stream.str();
}

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Error: Number of zombies must be greater than 0." << std::endl;
		return NULL;
	}
	Zombie *zombies= new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::string zombieName = name + C_YELLOW "n_" + ToString(i) + C_RESET ;
		zombies[i].SetName(zombieName);
	}
	return zombies;
}