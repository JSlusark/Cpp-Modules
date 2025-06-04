#include "Phonebook.hpp"
#include "Contact.hpp"
#include "OutputView.hpp"

Phonebook::Phonebook() : total_contacts(0), index(0) {};

std::string Phonebook::GetInput(const std::string prompt, bool (*isValid)(const std::string &), std::string error_message)
{
	while (true)
	{
		std::string input;
		std::cout << C_GREEN << prompt << C_WHITE;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl
					  << C_RED << "EOF detected: " C_WHITE "Exiting Your Awesome Phoneboo..." << C_WHITE << std::endl;
			PrintFooter();
			exit(0);
		}
		input = trim(input);
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
	std::cout << "You are now able to add a new contact and provide its details." << std::endl;
	contact[index].SetFirstName(GetInput("First name: ", stringIsAlphaSpace, ERR_ALPHA));
	contact[index].SetLastName(GetInput("Last name: ", stringIsAlphaSpace, ERR_ALPHA));
	contact[index].SetPhoneNumber(GetInput("Phone number: ", StringIsDigits, ERR_DIGIT));
	contact[index].SetDarkestSecret(GetInput("Darkest secret: ", stringIsAlphaSpace, ERR_ALPHA));
	if (total_contacts < MAX_CONTACTS)
		total_contacts++;
	index++;
}
void Phonebook::DisplayContactInfo(int i, Contact contact)
{
	std::cout << C_YELLOW << i << C_WHITE << " | "
			  << contact.GetFirstName() << " | "
			  << contact.GetLastName() << " | "
			  << contact.GetPhoneNumber() << " | "
			  << contact.GetDarkestSecret() << std::endl;
}

void Phonebook::DisplayContactList()
{
	std::cout << "Total contacts saved in your phonebook: "
			  << C_GREEN << total_contacts << C_WHITE << std::endl;
	for (int i = 0; i < total_contacts; i++)
		DisplayContactInfo(i, contact[i]);
}

void Phonebook::RequestContactView()
{
	while (true)
	{
		std::string input = GetInput("User at input: ", StringIsDigits, ERR_INDEX);
		int i = std::atoi(input.c_str()); // check int overflow
		if (i < 0 || i >= total_contacts)
		{
			if (i >= MAX_CONTACTS)
				std::cout << ERR_INDEX_INVALID_RANGE << std::endl;
			else if (i < 0)
				std::cout << ERR_INDEX_INVALID_RANGE << std::endl;
			else
				std::cout << ERR_INDEX_NOT_FOUND << std::endl;
			continue;
		}
		else
		{
			DisplayContactInfo(i, contact[i]);
			break;
		}
	}
}

void Phonebook::SearchContact()
{
	if (total_contacts == 0)
		std::cout << ERR_PHONEBOOK_IS_EMPTY << std::endl;
	else
	{
		DisplayContactList();
		RequestContactView();
	}
}
void Phonebook::Exit()
{
	std::cout << EXIT_MESSAGE << std::endl;
	PrintFooter();
	exit(0);
}