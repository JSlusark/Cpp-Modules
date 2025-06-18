#ifndef HARL_HPP
#define HARL_HPP

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