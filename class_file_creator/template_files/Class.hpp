#ifndef CLASS_HPP
#define CLASS_HPP

class Class
{
private:
public:
	Class();							  // Default constructor
	Class(const Class &other);			  // Copy constructor
	Class &operator=(const Class &other); // Copy assignment operator
	~Class();							  // Destructor
};

#endif
