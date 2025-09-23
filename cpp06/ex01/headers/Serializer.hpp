#pragma once
#include <string>
# include <iostream>
# include <stdint.h>
# include <iostream>


#include "../headers/utils.hpp"

struct Data {
    int id;
    std::string name;
};

class Serializer
{
private:
	Serializer();										// Default constructor
	Serializer(const Serializer &other);			// Copy constructor
	Serializer &operator=(const Serializer &other); // Copy assignment operator
	~Serializer();									// Destructor

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
