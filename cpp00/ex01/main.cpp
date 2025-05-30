#include <string>
#include <iostream>

int main(void)
{
	std::string input;
	std::cout << "Welcome to my awesome phonebook!" << std::endl;
	while (1)
	{
		std::cout << "Enter a command: ";
		if (!(std::getline(std::cin, input)))
		{
			std::cout << std::endl;
			std::cout << "Were you trying to get me on a neverending loop with that EOF? ;)" << std::endl;
			break;
		}
		if (input == "ADD")
		{
			std::cout << "First name: " << std::endl;
			std::cout << "Last name: " << std::endl;
			std::cout << "Nickname: " << std::endl;
			std::cout << "Phone Number: " << std::endl;
			std::cout << "Darkest Secret: " << std::endl;
		}
		else if (input == "SEARCH")
		{
			std::cout << "search user" << std::endl;
		}
		else if (input == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Please write the accpted actions: 'ADD', 'SEARCH', EXIT" << std::endl;
		}
	}
	std::cout << "Exiting phonebook..." << std::endl;
	return 0;
}