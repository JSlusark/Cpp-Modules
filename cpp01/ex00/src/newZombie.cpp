#include "../headers/Zombie.hpp"

Zombie* NewZombie( std::string name ){
	return new Zombie(name);
}