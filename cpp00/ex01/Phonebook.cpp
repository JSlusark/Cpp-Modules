#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string>

std::string GetInput(const std::string prompt)
{
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	// cannot be empty so should give error and reprompt
	return input;
}

void Phonebook::AddContact()
{
	if (limit > 7)
		limit = 0;
	std::cout << "You are now able to add a new contact, please add the following: first name, last name, phone number and darkect secret" << std::endl;
	this->contact[limit].SetFirstName(GetInput("Add contact's first name: "));
	this->contact[limit].SetLastName(GetInput("Add contact's last name: "));
	this->contact[limit].SetPhoneNumber(GetInput("Add contact's phone number: "));
	this->contact[limit].SetDarkestSecret(GetInput("Add contact's darkest secret: "));
	limit++;
}
void DisplayContact(int i, Contact contact)
{
	// can put that if contact is empty (not created) it should not be displayed
	std::cout << i << " | "
			  << contact.GetFirstName() << " | "
			  << contact.GetLastName() << " | "
			  << contact.GetPhoneNumber() << " | "
			  << contact.GetDarkestSecret() << std::endl;
}

void Phonebook::SearchContact()
{

	std::cout << "Total added contacts:" << std::endl;
	for (int j = 0; j < limit; j++)
	{
		// will go in segfault if no contact was added
		DisplayContact(j, this->contact[j]);
	}
	std::cout << "Add the index of the user you want to search, index should be from 0 to 1" << std::endl;
	std::string input = GetInput("User at input: ");
	int i = std::atoi(input.c_str());
	if (i > -1 && i < this->limit)
		DisplayContact(i, this->contact[i]);
}
void Phonebook::Exit()
{
}