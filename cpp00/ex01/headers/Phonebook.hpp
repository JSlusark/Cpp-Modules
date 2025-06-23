#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "utils.hpp"


#define ERR_ALPHA C_RED "ERROR:" C_WHITE " only letters and spaces are accepted for this field.\n" C_WHITE
#define ERR_DIGIT C_RED "ERROR:" C_WHITE " only digits are accepted for this field.\n" C_WHITE
#define ERR_INDEX C_RED "ERROR:" C_WHITE " only digits from 0 to 7 are accepted for this field.\n" C_WHITE
#define ERR_EMPTY C_RED "ERROR:" C_WHITE " field cannot be empty!\n" C_WHITE
#define ERR_TOO_LONG C_RED "ERROR:" C_WHITE " input is longer than its 50 characters limit.\n" C_WHITE
#define ERR_CMD C_RED "ERROR:" C_WHITE " Only 'ADD', 'SEARCH' and 'EXIT' are accepted as commands.\n" C_WHITE
#define ERR_INDEX_NOT_FOUND C_RED "ERROR:" C_WHITE " no contact was added at this index\n" C_WHITE
#define ERR_INDEX_INVALID_RANGE C_RED "ERROR:" C_WHITE " phonebook is limited to a total of 0 to " << MAX_CONTACTS - 1 << " contacts.\n" C_WHITE
#define ERR_INDEX_INVALID_INDEX C_RED "ERROR:" C_WHITE " phonebook input need to be one single digit\n" C_WHITE
#define ERR_PHONEBOOK_IS_EMPTY C_RED "ERROR:" C_WHITE " your phonebook is empty, add at least one contact to use this command.\n" C_WHITE
#define EOF_MESSAGE C_RED "EOF detected: " C_WHITE " Exiting Your Awesome Phonebook...\n" C_WHITE
#define EXIT_MESSAGE C_RED ">" C_WHITE " Exiting Your Awesome Phonebook...\n" C_WHITE

class Phonebook
{

private:
	int total_contacts;
	int index;
	bool eof_flag;
	/*
	 Non-static members can’t be used in constant expressions,
	 and does not need to depend on object instantiation
	 */
	static const int MAX_CONTACTS = 8;
	Contact contact[MAX_CONTACTS];
	void displayContactInfo(Contact contact);
	void displayContactList();
	void requestContactView();
	bool getAndSetField(const std::string &prompt, bool (*isValid)(const std::string &), const std::string &error_message, void (Contact::*setter)(const std::string &));

public:
	Phonebook();
	~Phonebook();
	static bool isCommand(const std::string &s); /* because passing it as a function parameter */
	std::string formatField(const std::string &str);
	std::string getInput(const std::string prompt, bool (*isValid)(const std::string &), std::string error_message);
	bool isEof();
	void setEof(bool val) { eof_flag = val; }
	void addContact();
	void searchContact();
	void exit();
};

#endif