#include "../headers/Array.hpp"

/* Default constructor */
template <typename T>
Array<T>::Array() : _data(NULL), _n(0)
{
	logMessage(NULL, "Array created by default constructor");
}

/* Parametarised constructor */
template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n) // initialised by default
{
	logMessage(NULL, "Array created by parametarised constructor");
	if (_size) // allocate only if size is not 0
		_data = new T[_size]();
}

/* Copy constructor: constructs new object as a copy of an object */
template <typename T>
Array<T>::Array(const Array &other) : _data(new[other._size]), _size(other._size)
{
	(void)other;
	logMessage(NULL, "Array created by copy constructor");
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete _data;
		_size = other._size;
		_data = new T[other._size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	logMessage(NULL, "Array assigned by copy assignment operator");
	return *this;
}

/* Destructor */
template <typename T>
Array<T>::~Array()
{
	logMessage(NULL, "Array destroyed by destructor ");
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range(logMessage(ERROR, "Array index out of bounds"));
	return _data[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const // Const version
{
	if (i >= _size)
		throw std::out_of_range(logMessage(ERROR, "Array index out of bounds"));
	return _data[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}