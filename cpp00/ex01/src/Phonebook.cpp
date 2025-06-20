#include "Phonebook.hpp"
#include "Contact.hpp"
#include "OutputView.hpp"
#include <iomanip>

static std::string FormatField(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

Phonebook::Phonebook() : total_contacts(0), index(0), eof_flag(false) {}
Phonebook::~Phonebook() {}

bool Phonebook::IsEof()
{
	if (eof_flag)
		std::cout << EOF_MESSAGE << std::endl;
	return eof_flag;
}

std::string Phonebook::GetInput(const std::string prompt, bool (*isValid)(const std::string &), std::string error_message)
{
	std::string input;
	while (true)
	{
		std::cout << C_GREEN << prompt << C_WHITE;
		if (!std::getline(std::cin, input))
		{
			SetEof(true);
			std::cout << std::endl;
			break;
		}
		else
		{
			input = trim(input);
			if (input.length() > 50)
			{
				std::cout << ERR_TOO_LONG << std::endl;
				continue;
			}
			if (!isValid(input))
			{
				std::cout << error_message << std::endl;
				continue;
			}
			return input;
		}
	}
	return "";
}

bool Phonebook::getAndSetField(const std::string &prompt, bool (*isValid)(const std::string &), const std::string &error_message, void (Contact::*setter)(const std::string &))
{
	std::string input = GetInput(prompt, isValid, error_message);
	if (eof_flag)
		return true;
	(contact[index].*setter)(input);
	return false;
}

void Phonebook::AddContact()
{
	if (index >= MAX_CONTACTS)
		index = 0;
	std::cout << "You are now able to add a new contact and provide its details." << std::endl;
	if (getAndSetField("First name: ", stringIsAlphaSpace, ERR_ALPHA, &Contact::SetFirstName))
		return;
	if (getAndSetField("Last name: ", stringIsAlphaSpace, ERR_ALPHA, &Contact::SetLastName))
		return;
	if (getAndSetField("Phone number: ", StringIsDigits, ERR_DIGIT, &Contact::SetPhoneNumber))
		return;
	if (getAndSetField("Darkest secret: ", stringIsAlphaSpace, ERR_ALPHA, &Contact::SetDarkestSecret))
		return;
	if (total_contacts < MAX_CONTACTS)
		total_contacts++;
	index++;
}

void Phonebook::DisplayContactInfo(Contact contact)
{
	std::cout << C_YELLOW << std::setw(16) << "First Name:" << C_WHITE << " " << contact.GetFirstName() << std::endl;
	std::cout << C_YELLOW << std::setw(16) << "Last Name:" << C_WHITE << " " << contact.GetLastName() << std::endl;
	std::cout << C_YELLOW << std::setw(16) << "Phone Number:" << C_WHITE << " " << contact.GetPhoneNumber() << std::endl;
	std::cout << C_YELLOW << std::setw(16) << "Darkest Secret:" << C_WHITE << " " << contact.GetDarkestSecret() << std::endl;
}

void Phonebook::DisplayContactList()
{
	std::cout << "Total contacts saved in your phonebook: "
			  << C_GREEN << total_contacts << C_WHITE << std::endl;
	for (int i = 0; i < total_contacts; i++)
	{
		std::cout << C_YELLOW << std::setw(10) << i << C_WHITE << " | "
				  << FormatField(contact[i].GetFirstName()) << " | "
				  << FormatField(contact[i].GetLastName()) << " | "
				  << FormatField(contact[i].GetPhoneNumber()) << std::endl;
	}
}

void Phonebook::RequestContactView()
{
	while (true)
	{
		std::string input = GetInput("User at input: ", StringIsDigits, ERR_INDEX);
		if (eof_flag)
			return;
		if (input.length() > 1)
		{
			std::cout << ERR_INDEX_INVALID_INDEX << std::endl;
			continue;
		}
		int i = std::atoi(input.c_str()); // check int overflow
		if (i < 0 || i >= total_contacts)
		{
			if (i >= MAX_CONTACTS || i < 0)
				std::cout << ERR_INDEX_INVALID_RANGE << std::endl;
			else
				std::cout << ERR_INDEX_NOT_FOUND << std::endl;
			continue;
		}
		else
		{
			DisplayContactInfo(contact[i]);
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
}
