#include "../headers/ClapTrap.hpp"

int main()
{
	std::cout << "\n- Testing istantiation of classes" << std::endl;
	ClapTrap c1("Clappie");
	ClapTrap c2("Baddie");

	std::cout << "\n- Testing attack message with energy" << std::endl;
	c1.attack("Baddie");

	std::cout << "\n- Testing message damage with 0 or below " << std::endl;
	c1.takeDamage(0); // 0 damage edgecase
	c1.takeDamage(-110); // 0 damage edgecase
	c1.takeDamage(-100); // 0 damage edgecase

	std::cout << "\n- Testing damage, repair and depleting energy" << std::endl;
	c1.takeDamage(3);
	c1.beRepaired(100);
	c1.beRepaired(-110); // 0 damage edgecase
	c1.beRepaired(-100); // 0 damage edgecase
	c1.takeDamage(100);
	c1.attack("Baddie");
	c1.attack("Baddie");
	c1.attack("Baddie");
	c1.attack("Baddie");
	c1.attack("Baddie");
	c1.attack("Baddie");

	std::cout << "\n- Testing depleted energy messages" << std::endl;
	c1.attack("Baddie");
	c1.attack("Baddie");
	c1.attack("Baddie");
	c1.beRepaired(50);

	std::cout << "\n- Testing final damage and messages after death" << std::endl;
	c1.takeDamage(200);
	c1.takeDamage(50);
	c1.attack("Baddie");
	c1.beRepaired(50);

	std::cout << "\n- Testing destructor calls order" << std::endl;
	return 0;
}
