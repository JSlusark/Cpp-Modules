#include "../headers/HumanA.hpp"
#include "../headers/HumanB.hpp"

/*
HumanA uses a reference to Weapon because the weapon must always exist and never change after construction.
In C++, references must be initialized when declared and can never be null or reseated to refer to something else.
This makes the code safer and simpler when we want to enforce that HumanA is always armed — it removes the need for null checks.

HumanB uses a pointer to Weapon because the weapon is optional and might not be set at construction.
Unlike references, pointers in C++ can be null, which means we can safely represent the absence of a weapon.
They can also be reassigned later, allowing us to give HumanB a weapon at runtime or remove it entirely.
This gives us flexibility, but we must handle the case where the pointer is null (e.g., check before using).
*/

int main()
{
	std::cout << std::endl;
	std::cout << "Human A example with weapon type in constructor" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.Attack();
		club.setType("some other type of club");
		bob.Attack();
	}
	std::cout << std::endl;
	std::cout << "Human B example with weapon set after instantiation" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.SetWeapon(club);
		jim.Attack();
		club.setType("some other type of club");
		jim.Attack();
	}
	std::cout << std::endl;
	std::cout << "Human A example with weapon empty string passed in constructor" << std::endl;
	{
		Weapon emptyWeaponName = Weapon("");
		HumanA sara("Sara", emptyWeaponName);
		sara.Attack();
		emptyWeaponName.setType("");
		sara.Attack();
		emptyWeaponName.setType("named weapon");
		sara.Attack();
	}
	std::cout << std::endl;
	std::cout << "Human B example with no weapon set" << std::endl;
	{
		Weapon emptyWeaponName = Weapon("");
		HumanB janet("Janet");
		janet.Attack();
		janet.SetWeapon(emptyWeaponName);
		janet.Attack();
	}
	std::cout << std::endl;
	return 0;
}