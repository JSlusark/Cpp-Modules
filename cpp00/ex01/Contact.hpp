#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
public:
	void SetFirstName(const std::string& input);
	void SetLastName(const std::string& input);
	void SetPhoneNumber(const std::string& input);
	void SetDarkestSecret(const std::string& input);
	const std::string& GetFirstName();
	const std::string& GetLastName();
	const std::string& GetPhoneNumber();
	const std::string& GetDarkestSecret();

private:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string darkest_secret;
};
#endif