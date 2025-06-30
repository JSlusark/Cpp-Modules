#include "../headers/ClapTrap.hpp"

int main()
{
		ClapTrap c1("Clappie");
		ClapTrap c2("Baddie");
		c1.attack("Baddie");
		c1.takeDamage(0); // 0 damage edgecase
		c1.takeDamage(-110); // 0 damage edgecase
		c1.takeDamage(-100); // 0 damage edgecase
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
		c1.attack("Baddie");
		c1.attack("Baddie");
		// energy is depleted from here (ep <= 0) so cant attack or get repaired
		c1.attack("Baddie");
		c1.beRepaired(50);
		// takes final attack that leads to death (hp <= 0), so it cant do any actions
		c1.takeDamage(200);
		c1.takeDamage(50);
		c1.attack("Baddie");
		c1.beRepaired(50);

	return 0;
}
