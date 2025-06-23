#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "utils.hpp"

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	void setFirstName(const std::string &input);
	void setLastName(const std::string &input);
	void setPhoneNumber(const std::string &input);
	void setDarkestSecret(const std::string &input);

	const std::string &getFirstName();
	const std::string &getLastName();
	const std::string &getPhoneNumber();
	const std::string &getDarkestSecret();
	bool isEmpty();
};

#endif