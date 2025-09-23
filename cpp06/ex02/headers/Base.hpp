#pragma once
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "../headers/utils.hpp"

class Base {
public:
    virtual ~Base() {} // virtual destructor ensures proper cleanup of derived classes when deleting via a Base pointer
};

// derived classes
class A : public Base {};
class B : public Base {};
class C : public Base {};