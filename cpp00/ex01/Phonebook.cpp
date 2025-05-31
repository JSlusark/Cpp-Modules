#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string>

std::string GetInput(const std::string prompt)
{
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}

void Phonebook::AddContact()
{
	if(limit > 7)
		limit = 0;
	std::cout << "You are now able to add a new contact, please add the following: first name, last name, phone number and darkect secret" << std::endl;
	this->contact[limit].SetFirstName(GetInput("Add contact's first name: "));
	this->contact[limit].SetLastName(GetInput("Add contact's last name: "));
	this->contact[limit].SetPhoneNumber(GetInput("Add contact's phone number: "));
	this->contact[limit].SetDarkestSecret(GetInput("Add contact's darkest secret: "));
	limit++;
}
void Phonebook::SearchContact()
{
}
void Phonebook::Exit()
{
}