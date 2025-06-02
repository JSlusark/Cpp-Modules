#include "Phonebook.hpp"
#include "Contact.hpp"

std::string Phonebook::GetInput(const std::string prompt, std::string required_type) // if number or string
{
	while (true)
	{
		std::string input;
		std::cout << prompt;
		std::getline(std::cin, input);
		if (required_type == "string" && !stringIsAlphas(input))
		{
			std::cout << "Input accepts letters only" << std::endl; // allow space between names
			continue;
		}
		else if (required_type == "number" && !StringIsDigits(input))
		{
			std::cout << "Input accepts digits only" << std::endl;
			continue;
		}
		return input;
	}
}

void Phonebook::AddContact()
{
	if (added_n == MAX_N)
		added_n = 0;
	std::cout << "You are now able to add a new contact, please add the following: first name, last name, phone number and darkect secret" << std::endl;
	this->contact[added_n].SetFirstName(GetInput("Add contact's first name: ", "string"));
	this->contact[added_n].SetLastName(GetInput("Add contact's last name: ", "string"));
	this->contact[added_n].SetPhoneNumber(GetInput("Add contact's phone number: ", "number"));
	this->contact[added_n].SetDarkestSecret(GetInput("Add contact's darkest secret: ", "string"));
	added_n++;
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
			  << C_GREEN << added_n << C_RESET << std::endl;
	for (int i = 0; i < added_n; i++)
		DisplayContactInfo(i, this->contact[i]);
}

void Phonebook::RequestContactView()
{
	std::cout << "Add the index of the user you want to search, index should be from 0 to 7" << std::endl;
	std::string input = GetInput("User at input: ", "number");
	int i = std::atoi(input.c_str());
	// might add repromting here
	if (i < 0 || i >= added_n)
	{
		if (i >= MAX_N)
			std::cout << "Phonebook is limited to 8 contacts. Please write an index from 0 to 7" << std::endl;
		else
			std::cout << "No contact was added at index " << i << std::endl;
	}
	else
		DisplayContactInfo(i, this->contact[i]);
}

void Phonebook::SearchContact()
{
	if (added_n == 0)
		std::cout << "Phonebook is empty: you need to add at least one contact to view the list of contacts" << std::endl;
	else
	{
		DisplayContactList();
		RequestContactView();
	}
}
void Phonebook::Exit()
{
}