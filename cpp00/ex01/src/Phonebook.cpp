#include "Phonebook.hpp"

Phonebook::Phonebook() : total_contacts(0), index(0), eof_flag(false) {}
Phonebook::~Phonebook() {} // we do not instantiate phonebook dynamically, but adding this anyway

bool Phonebook::isCommand(const std::string &s)
{
	return s == "ADD" || s == "SEARCH" || s == "EXIT";
}

std::string Phonebook::formatField(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}
bool Phonebook::isEof()
{
	if (eof_flag)
		std::cout << EOF_MESSAGE << std::endl;
	return eof_flag;
}

std::string Phonebook::getInput(const std::string &prompt, bool (*isValid)(const std::string &), const std::string &error_message)
{
	std::string input;
	while (true)
	{
		std::cout << C_GREEN << prompt << C_WHITE;
		if (!std::getline(std::cin, input))
		{
			// SetEof(true);
			eof_flag = true;
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
	std::string input = getInput(prompt, isValid, error_message);
	if (eof_flag)
		return true;
	(contact[index].*setter)(input);
	return false;
}

void Phonebook::addContact()
{
	if (index >= MAX_CONTACTS)
		index = 0;
	std::cout << "You are now able to add a new contact and provide its details." << std::endl;
	if (getAndSetField("First name: ", stringIsAlphaSpace, ERR_ALPHA, &Contact::setFirstName))
		return;
	if (getAndSetField("Last name: ", stringIsAlphaSpace, ERR_ALPHA, &Contact::setLastName))
		return;
	if (getAndSetField("Phone number: ", stringIsDigits, ERR_DIGIT, &Contact::setPhoneNumber))
		return;
	if (getAndSetField("Darkest secret: ", stringIsAlphaSpace, ERR_ALPHA, &Contact::setDarkestSecret))
		return;
	if (total_contacts < MAX_CONTACTS)
		total_contacts++;
	index++;
}

void Phonebook::displayContactInfo(Contact &contact)
{
	std::cout << C_YELLOW << std::setw(16) << "First Name:" << C_WHITE << " " << contact.getFirstName() << std::endl;
	std::cout << C_YELLOW << std::setw(16) << "Last Name:" << C_WHITE << " " << contact.getLastName() << std::endl;
	std::cout << C_YELLOW << std::setw(16) << "Phone Number:" << C_WHITE << " " << contact.getPhoneNumber() << std::endl;
	std::cout << C_YELLOW << std::setw(16) << "Darkest Secret:" << C_WHITE << " " << contact.getDarkestSecret() << std::endl;
}

void Phonebook::displayContactList()
{
	std::cout << "Total contacts saved in your phonebook: "
			  << C_GREEN << total_contacts << C_WHITE << std::endl;
	for (int i = 0; i < total_contacts; i++)
	{
		std::cout << C_YELLOW << std::setw(10) << i << C_WHITE << " | "
				  << formatField(contact[i].getFirstName()) << " | "
				  << formatField(contact[i].getLastName()) << " | "
				  << formatField(contact[i].getPhoneNumber()) << std::endl;
	}
}

void Phonebook::requestContactView()
{
	while (true)
	{
		std::string input = getInput("User at input: ", stringIsDigits, ERR_INDEX);
		if (eof_flag)
			return;
		if (input.length() > 1) // if 2 digit number
		{
			std::cout << ERR_INDEX_INVALID_INDEX << std::endl;
			continue;
		}
		int i = std::atoi(input.c_str());
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
			displayContactInfo(contact[i]);
			break;
		}
	}
}

void Phonebook::searchContact()
{
	if (total_contacts == 0)
		std::cout << ERR_PHONEBOOK_IS_EMPTY << std::endl;
	else
	{
		displayContactList();
		requestContactView();
	}
}

void Phonebook::exit()
{
	std::cout << EXIT_MESSAGE << std::endl;
}
