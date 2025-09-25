#pragma once

#include "../headers/utils.hpp"

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
	T *_data;
	unsigned int _size;

	public:
	Array();							  // Default constructor
	Array(unsigned int n);				  // parametarised
	Array(const Array &other);			  // Copy constructor
	Array &operator=(const Array &other); // Copy assignment operator
	~Array();							  // Destructor

	T &operator[](unsigned int i);			   // Subscript operator
	const T &operator[](unsigned int i) const; // Const overload

	unsigned int size() const; // Size getter
};
#include "../src/Array.tpp"
