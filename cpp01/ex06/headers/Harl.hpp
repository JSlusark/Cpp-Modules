#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#define C_RESET "\033[0m"
#define C_RED "\033[38;2;255;85;85m"



class Harl
{
private:
void debug(void);
void info(void);
void warning(void);
void error(void);
int getAction(const std::string &level);
public:
	Harl(/* args */);
	~Harl();
	void complain( std::string level );
};

#endif