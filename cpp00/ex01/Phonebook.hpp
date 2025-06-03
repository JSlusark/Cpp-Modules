#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "Utils.hpp"
#include <string>
#include <cstdlib>
#include <cstring>

#define ERR_ALPHA "Input accepts letters only"
#define ERR_DIGIT "Input accepts digits only"
#define ERR_EMPTY "Input cannot be empty"

class Phonebook
{

private:
	int total_contacts;
	int index;
	static const int MAX_CONTACTS = 2; //<----------------------- remove this
	Contact contact[MAX_CONTACTS];
	std::string GetInput(const std::string prompt, bool (*isValid)(const std::string &), std::string error_message);
	void DisplayContactInfo(int i, Contact contact);
	void DisplayContactList();
	void RequestContactView();

public:
	Phonebook();
	void AddContact();
	void SearchContact();
	void Exit();
};

#endif