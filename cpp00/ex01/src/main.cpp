#include <string>
#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"
#include "OutputView.hpp"

int main(void)
{
    Phonebook my_phonebook;
    PrintHeader();
    std::cout << "Your Awesome Phonebook session started...." << std::endl;
	while (!my_phonebook.IsEof())
	{
		std::string input = my_phonebook.GetInput("Enter a command: ", isCommand, ERR_CMD);
		if (input == "ADD")
			my_phonebook.AddContact();
		if (input == "SEARCH")
			my_phonebook.SearchContact();
		if (input == "EXIT")
			break;
	}
    PrintFooter();
    return 0;
}