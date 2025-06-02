#include "Contact.hpp"

void Contact::SetFirstName(const std::string &input) // Passing by reference is faster (no copy) and const safer (can't change the caller’s value).
{
	while (input == "")
	{
		std::cout << "input missing" << std::endl;
	}

	this->first_name = input;
}
void Contact::SetLastName(const std::string &input)
{
	this->last_name = input;
}
void Contact::SetPhoneNumber(const std::string &input)
{
	this->phone_number = input;
}
void Contact::SetDarkestSecret(const std::string &input)
{
	this->darkest_secret = input;
}
const std::string &Contact::GetFirstName()
{
	return (this->first_name);
}
const std::string &Contact::GetLastName()
{
	return (this->last_name);
}
const std::string &Contact::GetPhoneNumber()
{
	return (this->phone_number);
}
const std::string &Contact::GetDarkestSecret()
{
	return (this->darkest_secret);
}
bool Contact::IsEmpty()
{
	if (this->GetFirstName().empty() &&
		this->GetLastName().empty() &&
		this->GetPhoneNumber().empty() &&
		this->GetDarkestSecret().empty())
	{
		return true;
	}
	return false;
}