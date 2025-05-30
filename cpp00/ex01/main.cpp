#include <string>
#include <iostream>

int main(void)
{
	std::string input;

	while (1)
	{
		std::cout << "enter something: ";
		if (!(std::cin >> input))
		{
			std::cout << std::endl;
			std::cout << "Were you trying to get me on a neverending loop with that EOF? ;)" << std::endl;
			break;
		}
		if (input == "ADD")
			std::cout << "adding user" << std::endl;
		else if (input == "SEARCH")
			std::cout << "search user" << std::endl;
		else if (input == "EXIT")
		{
			std::cout << "goodbye" << std::endl;
			break;
		}
		else
		{
			std::cout << "Could not find requested action:'" << input << "'" << std::endl;
			std::cout << "Please write the accpted actions: 'ADD', 'SEARCH', EXIT" << std::endl;
		}
	}
	std::cout << "Exiting phonebook..." << std::endl ;
	return 0;
}