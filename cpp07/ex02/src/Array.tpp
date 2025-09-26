#include "../headers/Array.hpp"

/* Default constructor */
template <typename T>
Array<T>::Array() : _data(0), _size(0)
{
	logMessage(DEFAULT_C, "Array created by default constructor");
}

/* Parameterized constructor */
template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _size(n)
{
	logMessage(COPY_C, "Array created by parametarised constructor");
	if (_size) // allocate only if size is not 0
		_data = new T[_size]();
}

/* Copy constructor */
template <typename T>
Array<T>::Array(const Array &other)
	: _data(0), _size(other._size)
{ // init in declaration order
	logMessage(COPY_C, "Array created by copy constructor");
	if (_size)
	{
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
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
	logMessage(ASSIGN_OP, "Array assigned by copy assignment operator");
	return *this;
}

/* Destructor */
template <typename T>
Array<T>::~Array()
{
	logMessage(DESTRUCTOR, "Array destroyed by destructor");
	delete[] _data;
}

/* operator[] (non-const) */
template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range(C_RED "Array index out of bounds" C_RESET);
	return _data[i];
}

/* operator[] (const) */
template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range(C_RED "Array index out of bounds" C_RESET);
	return _data[i];
}

/* size() */
template <typename T>
unsigned int Array<T>::size() const { return _size; }
