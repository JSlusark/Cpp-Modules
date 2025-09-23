EX 02
Dynamic cast means that the cast is checked at runtime, not at compile time.
This means that the cast can fail and we need to handle potential failures in code.

The operation can be applied to pointers and references to classes.
When applied to pointers, if the cast is not possible, a null pointer is returned.
When applied to references, if the cast is not possible, a std::bad_cast exception is thrown.


In this exercise, we will create a class Base and three classes A, B and C that will inherit from Base.
We will then create a function that will randomly generate instances of A, B or C and return a pointer to Base.
We will also create two functions that will identify the actual type of the instance pointed to by the Base pointer:
- one function will take a pointer as an argument and use dynamic_cast to identify the type
- the other function will take a reference as an argument and use dynamic_cast to identify the type and handle the potential exception.
- 