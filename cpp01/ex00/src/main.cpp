#include "Zombie.hpp"

int main()
{
	std::cout << C_MAGENTA "--- Creating a Zombie on the heap 'Heapie' ---" << C_RESET << std::endl;
	std::cout << "Zombie class is allocated dyncamically which means that it won't destruct when out of scope, therefore we have to destruct it manully in order to free the memory" C_RESET << std::endl;
	Zombie *heapZombie = NewZombie(C_MAGENTA "Heapie" C_RESET);
	heapZombie->announce();
	delete heapZombie;
	std::cout << C_RED "--- Creating a Zombie on the stack 'Stackie' ---" << C_RESET << std::endl;
	std::cout << "Zombie class is created statically which means that it will destruct automatically when out of scope." << std::endl;
	randomChump(C_RED "Stackie" C_RESET);
	return 0;
}