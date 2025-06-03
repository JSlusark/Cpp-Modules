#include <string>
#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

bool isCommand(const std::string &s)
	{
		return s == "ADD" || s == "SEARCH" || s == "EXIT";
	}

int main(void)
{
	Phonebook my_phonebook;
	std::string input;
	std::cout << "Welcome to my awesome phonebook!" << std::endl;
	while (1)
	{
		std::string input = my_phonebook.GetInput("Enter a command: ", isCommand, ERR_CMD);
		if (input == "ADD")
			my_phonebook.AddContact();
		else if (input == "SEARCH")
			my_phonebook.SearchContact();
		else if (input == "EXIT")
			my_phonebook.Exit();	
	}
	return 0;
}