#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook() : total_contacts(0), index(0) {};

std::string Phonebook::GetInput(const std::string prompt, bool (*isValid)(const std::string &), std::string error_message)
{
	while (true)
	{
		std::string input;
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl
					  << "EOF detected. Exiting..." << std::endl;
			exit(0);
		}
		if (!isValid(input))
		{
			std::cout << error_message << std::endl;
			continue;
		}
		return input;
	}
}

void Phonebook::AddContact()
{
	if (index >= MAX_CONTACTS)
		index = 0;
	std::cout << "You are now able to add a new contact, please add the following: first name, last name, phone number and darkect secret" << std::endl;
	this->contact[index].SetFirstName(GetInput("Add contact's first name: ", stringIsAlphas, ERR_ALPHA));
	this->contact[index].SetLastName(GetInput("Add contact's last name: ", stringIsAlphas, ERR_ALPHA));
	this->contact[index].SetPhoneNumber(GetInput("Add contact's phone number: ", StringIsDigits, ERR_DIGIT));
	this->contact[index].SetDarkestSecret(GetInput("Add contact's darkest secret: ", stringIsAlphas, ERR_ALPHA));
	if (total_contacts < MAX_CONTACTS)
		total_contacts++;
	index++;
}
void Phonebook::DisplayContactInfo(int i, Contact contact)
{
	std::cout << i << " | "
			  << contact.GetFirstName() << " | "
			  << contact.GetLastName() << " | "
			  << contact.GetPhoneNumber() << " | "
			  << contact.GetDarkestSecret() << std::endl;
}

void Phonebook::DisplayContactList()
{
	std::cout << "Total contacts saved in your phonebook: "
			  << C_GREEN << total_contacts << C_RESET << std::endl;
	for (int i = 0; i < total_contacts; i++)
		DisplayContactInfo(i, this->contact[i]);
}

void Phonebook::RequestContactView()
{
	while (true)
	{
		std::cout << "Add the index of the user you want to search, index should be from 0 to 7" << std::endl;
		std::string input = GetInput("User at input: ", StringIsDigits, ERR_DIGIT);
		int i = std::atoi(input.c_str()); // check int overflow
		if (i < 0 || i >= total_contacts)
		{
			if (i >= MAX_CONTACTS)
				std::cout << "Phonebook is limited to a total of " << MAX_CONTACTS << " contacts." << std::endl
						  << "Please write an index from 0 to " << MAX_CONTACTS << std::endl;
			else
				std::cout << "No contact was added at index " << i << std::endl;
			continue;
		}
		else
		{
			DisplayContactInfo(i, this->contact[i]);
			break;
		}
	}
}

void Phonebook::SearchContact()
{
	if (total_contacts == 0)
		std::cout << "Phonebook is empty: you need to add at least one contact to view the list of contacts" << std::endl;
	else
	{
		DisplayContactList();
		RequestContactView();
	}
}
void Phonebook::Exit()
{
	std::cout << "Exiting phonebook" << std::endl;
	exit(0);
}