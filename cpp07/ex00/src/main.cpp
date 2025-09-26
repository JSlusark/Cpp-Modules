#include "../headers/utils.hpp"

int main()
{
	testTitle(1, "Typical case with swapping and comparing");
	int a = 2;
	int b = 3;
	logMessage(LOG, "Original A and B");
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b); // :: global scope resolution operator (used to avoid calling the origianl swap, min and max function)
	logMessage(LOG, "Swapped A and B");
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	testTitle(2, "First and second are equal, second is returned when comapring");
	logMessage(LOG, "First and second are equal (2), the second must be returned so we check if addresses match");
	int first = 2;
	int second = 2;
	std::cout << "first address:" << C_CYAN << &first << C_RESET << ",  second address:" << C_YELLOW << &second << C_RESET << std::endl;
	std::cout << "min:" << C_YELLOW << &::min(first, second) << C_RESET << std::endl;
	std::cout << "max:" << C_YELLOW << &::max(first, second) << C_RESET << std::endl;
	if (&second == &::min(first, second) && &second == &::max(first, second))
		logMessage(SUCCESS, "Address match!");
	else
		logMessage(ERROR, "Address don't match!");

	testTitle(3, "Strings as arguments");
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	logMessage(LOG, "Swapped C and D");
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	testTitle(4, "Strings with different lengths");
	std::string one = "abc";
	std::string two = "abcd";
	std::cout << "one = " << one << ", two = " << two << std::endl;
	std::cout << "min( one, two ) = " << ::min(one, two) << std::endl;
	std::cout << "max( one, two ) = " << ::max(one, two) << std::endl;

	// argument with different types won't work
	// std::cout << "min( f, i ) = " << ::min(2.3, 2) << std::endl;
	// std::cout << "max( f, i ) = " << ::max(2.3f, 2.5) << std::endl;

	return 0;
}
