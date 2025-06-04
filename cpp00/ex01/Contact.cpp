#include "Contact.hpp"

void Contact::SetFirstName(const std::string &input)
{
	while (input == "")
	{
		std::cout << "input missing" << std::endl;
	}

	first_name = input;
}
void Contact::SetLastName(const std::string &input)
{
	last_name = input;
}
void Contact::SetPhoneNumber(const std::string &input)
{
	phone_number = input;
}
void Contact::SetDarkestSecret(const std::string &input)
{
	darkest_secret = input;
}
const std::string &Contact::GetFirstName()
{
	return (first_name);
}
const std::string &Contact::GetLastName()
{
	return (last_name);
}
const std::string &Contact::GetPhoneNumber()
{
	return (phone_number);
}
const std::string &Contact::GetDarkestSecret()
{
	return (darkest_secret);
}
bool Contact::IsEmpty()
{
	if (GetFirstName().empty() &&
		GetLastName().empty() &&
		GetPhoneNumber().empty() &&
		GetDarkestSecret().empty())
	{
		return true;
	}
	return false;
}