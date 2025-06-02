#include <string>
#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	Phonebook my_phonebook;
	my_phonebook.added_n = 0;
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
			my_phonebook.AddContact();
		}
		else if (input == "SEARCH")
		{
			my_phonebook.SearchContact();
		}
		else if (input == "EXIT")
		{
			break;
		}
		else
		{
			// any other input is ignored
			std::cout << "Please write the accpted actions: 'ADD', 'SEARCH', EXIT" << std::endl;
		}
	}
	std::cout << "Exiting phonebook..." << std::endl;
	return 0;
}