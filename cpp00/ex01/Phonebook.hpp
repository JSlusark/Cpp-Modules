#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "Utils.hpp"
#include <string>
#include <cstdlib>
#include <cstring>

class Phonebook
{

	private:
	static const int MAX_I = 8;
	Contact contact[MAX_I];
	std::string GetInput(const std::string prompt, std::string required_type);
	void DisplayContactInfo(int i, Contact contact);
	void DisplayContactList();
	void RequestContactView();


public:
	int total_i; // check if i can do a macro instead
	int added_contacts;
	void AddContact();
	void SearchContact(); // search for a user
	void Exit();
};

#endif