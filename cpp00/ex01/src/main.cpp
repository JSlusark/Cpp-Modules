#include "Phonebook.hpp"

int main(void)
{
    Phonebook my_phonebook;
    printHeader();
    std::cout << "Your Awesome Phonebook session started...." << std::endl;
	while (!my_phonebook.isEof())
	{
		std::string input = my_phonebook.getInput("Enter a command: ", my_phonebook.isCommand, ERR_CMD);
		if (input == "ADD")
			my_phonebook.addContact();
		if (input == "SEARCH")
			my_phonebook.searchContact();
		if (input == "EXIT")
			break;
	}
    printFooter();
    return 0;
}