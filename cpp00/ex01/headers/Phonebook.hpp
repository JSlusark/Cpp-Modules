#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "Utils.hpp"
#include <string>
#include <cstdlib>
#include <cstring>

#define ERR_ALPHA C_RED "ERROR:" C_WHITE " only letters and spaces are accepted for this field." C_WHITE
#define ERR_DIGIT C_RED "ERROR:" C_WHITE " only digits are accepted for this field." C_WHITE
#define ERR_INDEX C_RED "ERROR:" C_WHITE " only digits from 0 to 7 are accepted for this field." C_WHITE
#define ERR_EMPTY C_RED "ERROR:" C_WHITE " field cannot be empty!" C_WHITE
#define ERR_TOO_LONG C_RED "ERROR:" C_WHITE " input is longer than its 50 characters limit." C_WHITE
#define ERR_CMD C_RED "ERROR:" C_WHITE " Only 'ADD', 'SEARCH' and 'EXIT' are accepted as commands." C_WHITE
#define ERR_INDEX_NOT_FOUND C_RED "ERROR:" C_WHITE " no contact was added at this index" C_WHITE
#define ERR_INDEX_INVALID_RANGE C_RED "ERROR:" C_WHITE " phonebook is limited to a total of 0 to " << MAX_CONTACTS - 1 << " contacts." C_WHITE
#define ERR_INDEX_INVALID_INDEX C_RED "ERROR:" C_WHITE " phonebook input need to be one single digit" C_WHITE
#define ERR_PHONEBOOK_IS_EMPTY C_RED "ERROR:" C_WHITE " your phonebook is empty, add at least one contact to use this command." C_WHITE
#define EXIT_MESSAGE C_RED ">" C_WHITE " Exiting Your Awesome Phonebook..." C_WHITE

class Phonebook
{

private:
	int total_contacts;
	int index;
	static const int MAX_CONTACTS = 8;
	Contact contact[MAX_CONTACTS];
	void DisplayContactInfo(Contact contact);
	void DisplayContactList();
	void RequestContactView();

public:
	Phonebook();
	~Phonebook();
	std::string GetInput(const std::string prompt, bool (*isValid)(const std::string &), std::string error_message);
	void AddContact();
	void SearchContact();
	void Exit();
};

#endif