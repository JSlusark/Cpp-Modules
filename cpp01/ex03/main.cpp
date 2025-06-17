// #include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
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
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.Attack();
		club.setType("some other type of club");
		bob.Attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.SetWeapon(club);
		jim.Attack();
		club.setType("some other type of club");
		jim.Attack();
	}
	{
		HumanB unarmed("Sarah");
		unarmed.Attack();
	}
	return 0;
}