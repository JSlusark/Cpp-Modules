#include "../headers/Zombie.hpp"

std::string ToString(int n)
{
	std::ostringstream string_stream; // output stream writes to string instead 

	string_stream << n; // instertion operator is used to convert int to text  and store in stream

	return string_stream.str(); // extracts contents of the stream as a string
}

Zombie *zombieHorde(int N, std::string name)
{
	int safeLimit = 1000000;
	if (N <= 0 || N > safeLimit)
	{
		std::cerr << "Error: Number of zombies must be greater than 0, but not beyond limit (1000000)." << std::endl;
		return NULL;
	}
	Zombie *zombies= new Zombie[N]; // allocates Zombie N to the heap

	for (int i = 0; i < N; i++)
	{
		std::string zombieName = name + C_YELLOW "n_" + ToString(i) + C_RESET ;
		zombies[i].SetName(zombieName);
	}
	return zombies; // pointer to the first zombie
}