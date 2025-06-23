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
/* 	1stconst caller cannot modify the return
	2nd cost the function cannot modify the param*/ 
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getPhoneNumber() const;
	const std::string &getDarkestSecret() const;
	bool isEmpty()const;
};

#endif