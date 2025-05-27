### Resources

- [Library](https://devdocs.io/cpp/io/basic_ostream/operator_ltlt2)
- [Learning](https://www.learncpp.com)
- [Best practices](https://github.com/cpp-best-practices)

### Notes:

- As in C cpp has libraries need to be included and main ends with return 0

Glossary:
- **namespace std**:  means that we can use names for objects and variables from the standard library
- **std::cout**: is used to output to the console when namespace is not added
- **<iostream\>** library used for working with input and output objects. Part of the std namespace:
1. cout (std::cout):
- means character-output
- used to display output to the console (standard output) with << (insertion operator, inserts data into the output stream)
- cpp is case sensitive so cout and Cout are different

2. Cin (std:cin):
- means character-input
- used to receive input from the user/keyboard  (standard input) with >> (extraction operator, extracts data from the input stream)
- Out of the I/O context << and >> are just bitwise operators (like in c).


Operator Chaining: when multiple << or >> operators are used in a single statement, the output/input is chained together. With chaining cout is overloaded to return a reference to the output stream itself:
For example:

cout << "Hello" << " World" << endl;

- endl: used to insert a new line and flush the output buffer. It is a manipulator function that is part of the std namespace. It is equivalent to "\n" but also flushes the output buffer, ensuring that all output is displayed immediately.


cout and cin used together in a calculator app:

int x, y;
int sum;
cout << "Type a number: ";
cin >> x;
cout << "Type another number: ";
cin >> y;
sum = x + y;
cout << "Sum is: " << sum;



Cpp best practices:

Naming:
- camelCase: used for variables and functions (e.g., myVariable, calculateSum)
- snake_case: used for constants (e.g., MAX_VALUE, PI)
- PascalCase: used for class names (e.g., MyClass)
- _ and -m prefixes: used for member variables (e.g., _myVariable, -mMyVariable)

- always use const when a variable is not going to be changed and has to be read-only (since it will make your code more safe and easier to read)

___

CPP00

New concepts:
- class: a blueprint for creating objects. It defines the properties (data members) and behaviors (member functions) of the objects. It is a user-defined data type that can contain variables, functions, and other classes. It is defined using the class keyword followed by the class name and a pair of curly braces.
- object: an instance of a class. It is created using the class name followed by the object name and a pair of parentheses. It can access the properties and behaviors defined in the class.
- constructor: a special member function of a class that is called when an object of the class is created. It has the same name as the class and does not have a return type. It is used to initialize the object's properties. It can be overloaded to create multiple constructors with different parameters.
- destructor: a special member function of a class that is called when an object of the class is destroyed. It has the same name as the class preceded by a tilde (~) and does not have a return type. It is used to release any resources allocated by the object. It can also be overloaded to create multiple destructors with different parameters.
- member function: a function that is defined inside a class and can access the class's properties. It is called using the object name followed by the dot operator (.) and the function name. It can be overloaded to create multiple functions with different parameters.
- access specifiers: keywords that define the visibility of class members. The three access specifiers are:
  - public: members are accessible from outside the class
  - private: members are accessible only from within the class
  - protected: members are accessible from within the class and its derived classes
- encapsulation: the concept of bundling data and methods that operate on that data within a single unit (class). It restricts direct access to some of the object's components and can prevent the accidental modification of data. It is achieved using access specifiers.
- inheritance: the mechanism by which one class (derived class) can inherit properties and behaviors from another class (base class). It allows for code reusability and the creation of a hierarchical relationship between classes. It is defined using the : symbol followed by the access specifier and the base class name.
- polymorphism: the ability of different classes to be treated as instances of the same class through a common interface. It allows for method overriding and dynamic binding. It is achieved using virtual functions and inheritance.
- operator overloading: the ability to redefine the behavior of operators (e.g., +, -, *, /) for user-defined types (classes). It allows for more intuitive and readable code when working with objects. It is achieved by defining a member function or a friend function with the same name as the operator.
- friend function: a function that is not a member of a class but has access to its private and protected members. It is declared using the friend keyword inside the class. It allows for more flexibility in accessing class members without breaking encapsulation.
- static member: a member of a class that is shared among all instances of the class. It is declared using the static keyword and can be accessed using the class name or the object name. It is used to keep track of a value that needs to be shared among all instances of the class.
- static member function: a member function that can be called without creating an instance of the class. It is declared using the static keyword and can only access static members of the class. It is used to perform operations that do not require an instance of the class.
- static data member: a data member that is shared among all instances of the class. It is declared using the static keyword and can be accessed using the class name or the object name. It is used to keep track of a value that needs to be shared among all instances of the class.
- static function: a function that is limited to the file in which it is declared. It is declared using the static keyword and can only be accessed within that file. It is used to limit the scope of a function to a single file.
- static local variable: a variable that retains its value between function calls. It is declared using the static keyword and is initialized only once. It is used to keep track of a value that needs to be preserved across function calls.
- static variable: a variable that retains its value between function calls. It is initialized only once and its lifetime is the entire program execution. It is declared with the static keyword. It's shared between all instances of the class. It is not destroyed when the function exits, but it is not visible outside the function. It is used to keep track of a value that needs to be preserved across function calls.

RULES
No printf, malloc, or free:
- std::cout: used for outputting data to the console (instead of printf)
- new: used for dynamic memory allocation (instead of malloc)
- delete: used for deallocating memory (instead of free)

No STL containers (e.g., vector, map) until Module 08


contructor: a special function called when an object is created (Contact()), to initialised fields
deconstructor: a special function called when an object is destroyed (~Contact()), to clean up resources
private: members only accessible within the class
public: members accessible from outside the class