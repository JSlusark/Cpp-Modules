#ifndef HARL_HPP
#define HARL_HPP

#define C_RESET "\033[0m"
#define C_RED "\033[38;2;255;85;85m"

#include <string>
#include <iostream>



class Harl
{
private:
void debug(void);
void info(void);
void warning(void);
void error(void);
struct FunctionLevels
{
	const char *name;
	void (Harl::*func)();
};
public:
	Harl(/* args */);
	~Harl();
	void complain( std::string level );
};

#endif