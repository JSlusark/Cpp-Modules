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
	static const int MAX_N = 2; //<----------------------- remove this
	Contact contact[MAX_N];
	std::string GetInput(const std::string prompt, std::string required_type);
	void DisplayContactInfo(int i, Contact contact);
	void DisplayContactList();
	void RequestContactView();


public:
	int total_contacts;
	int index;
	void AddContact();
	void SearchContact();
	void Exit();
};

#endif