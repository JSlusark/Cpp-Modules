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
int getAction(const std::string &level);
public:
	Harl(/* args */);
	~Harl();
	void complain( std::string level );
};

#endif