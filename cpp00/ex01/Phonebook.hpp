#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook
{

private:
	Contact contact[8];

public:
	int limit;
	void AddContact();
	void SearchContact(); // search for a user
	void Exit();
};

#endif