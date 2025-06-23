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
const std::string &Contact::getFirstName()
{
	return (first_name);
}
const std::string &Contact::getLastName()
{
	return (last_name);
}
const std::string &Contact::getPhoneNumber()
{
	return (phone_number);
}
const std::string &Contact::getDarkestSecret()
{
	return (darkest_secret);
}
bool Contact::isEmpty()
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