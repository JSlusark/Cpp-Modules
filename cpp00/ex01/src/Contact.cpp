#include "Contact.hpp"

void Contact::setFirstName(const std::string &input)
{
	if (input == "")
	{
		std::cout << "input missing" << std::endl;
	}

	first_name = input;
}
void Contact::setLastName(const std::string &input)
{
	last_name = input;
}
void Contact::setPhoneNumber(const std::string &input)
{
	phone_number = input;
}
void Contact::setDarkestSecret(const std::string &input)
{
	darkest_secret = input;
}
const std::string &Contact::getFirstName() const
{
	return (first_name);
}
const std::string &Contact::getLastName() const
{
	return (last_name);
}
const std::string &Contact::getPhoneNumber() const
{
	return (phone_number);
}
const std::string &Contact::getDarkestSecret() const
{
	return (darkest_secret);
}
bool Contact::isEmpty() const // error handling in case getters return the wrong data or setters do not work
{
	if (getFirstName().empty() &&
		getLastName().empty() &&
		getPhoneNumber().empty() &&
		getDarkestSecret().empty())
	{
		return true;
	}
	return false;
}