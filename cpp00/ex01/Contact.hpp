/*
Contact
Stands for a phonebook contact.

Each contact has:
- first name
- last name
- phone number
- darkest secret

cannot be empty
max 10 characters previewd
*/



#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	public:
		void setFirstName();
		void setLastName();
		void setPhoneNumber();
		void setDarkestSecret();

	private:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string darkest_secret;
}

#endif