#include "../headers/Serializer.hpp"

/* Default constructor */
Serializer::Serializer()
{
	logMessage(NULL, "Serializer created by default constructor");
}

/* Copy constructor: constructs new object as a copy of an object */
Serializer::Serializer(const Serializer &other) // : _attr1(other.attr1), _attr2(other.attr2)
{
	(void)other;
	logMessage(NULL, "Serializer created by copy constructor");
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		// no attributes to copy
	}
	logMessage(NULL, "Serializer assigned by copy assignment operator");
	return *this;
}

/* Destructor */
Serializer::~Serializer()
{
	logMessage(NULL, "Serializer destroyed by destructor ");
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr); // unsigned integer type capable of holding a pointer
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
