In this module we approach containers for the first time.
We will learn how to use the most common ones: vector, list, map, set and deque etc..
https://en.cppreference.com/w/cpp/container.html

Here are brief explanations and examples of three commonly used C++ Standard Library containers:
- Vectors: they are dynamic arrays that can resize themselves automatically when an element is added or removed. Example:
```
#include <vector>
std::vector<int> myVector; // initialize an empty vector of integers
myVector.push_back(10); // adds int 10 to the end of the vector
```

- Lists: they are doubly linked lists that allow for efficient insertion and deletion of elements at any position. Example:
```
#include <list>
std::list<int> myList; // initialize an empty double linked list of integers
myList.push_back(10); // adds int 10 to the end of the list
myList.push_back(20);
myList.push_back(30);
for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
{
    std::cout << *it << std::endl; //  iterates
}
```

- Maps: they are associative containers that store elements in key-value pairs, allowing for fast retrieval based on keys. Example:
```
#include <map>
std::map<std::string, int> myMap; // initialize an empty map with string keys and integer values
myMap["age"] = 25; // adds a key-value pair ("age", 25) to the map
int age = myMap["age"]; // retrieves the value associated with the key "age"
```
_______

EX 00  - simple intro to containers and their iterators.

EX 01  - Span class that stores a set of numbers and can provide the shortest and longest span between any two numbers in the set.

Numbers container: i chose vector because it's the easiest and more straightforward to use, it works very similarly to a dynamic array.
Similarly to an array:
	- Elements are stored in one continuous block of memory.
	- Elements can be accessed via indices, so iteration is fast and straightforward.
	- It manages memory automatically (resizing, allocation, deallocation).

Additionally to an array:
	- vector can dynamically resize at runtime, array has a fixed size determined at compile time.
	- vector provides many built-in functions for adding, removing, and managing elements (like push_back, pop_back, insert, erase).
	- std::vector can grow and shrink as needed, making it more flexible for scenarios where the number of elements is not known in advance while arrays have a fixed size and number of elements must be defined at compile time.
	- std::vector manages its own memory, automatically allocating and deallocating as elements are added or removed while with arrays, you have to manage memory manually (especially with dynamic arrays).


What complications would arise if we used std::list or std::deque instead of std::vector:
	- std::list is a doubly linked list, which means each element (node) contains pointers to the next and previous nodes. So,
	it requires more memory per element (for the pointers) and has slower access times since you have to traverse the list through pointers to nodes.
	- std::deque (double-ended queue) allows fast insertions and deletions at both ends,
	but it is typically implemented as a series of fixed-size arrays which means memory management can be more complex.


_____

EX 02  - We are introduced to stack and inheritance from existing STL containers.

Stack a container is an adapter that wraps around other container types and hides their interface to provide the functionality of a stack data structure - specifically, a LIFO (last-in, first-out) data structure.

It is implemented as a class template because it must be able to work with any data type and underlying container type.

```
template <class T, class Container = std::deque<T> >
class stack;

example
std::stack<int, std::deque<int>>  // valid
std::stack<int, std::vector<int>> // valid
std::stack<int, std::deque<float>> // invalid (types differ)
```
1. T - the type of each element stored in the stack.
2. Container - the data structure the stack uses internally to hold its elements


The underlying container may be any of the standard container types or some other specifically designed container class: deque, list, or vector etc

Stack acts as a wrapper to these containers, providing a specific interface for stack operations.
By default, the underlying container is std::deque, but it can be customized by providing a different container type as a second template parameter.

Stack provides the following member functions:
	- empty(): checks if the stack is empty.
	- push(): adds an element to the top of the stack.
	- pop(): removes element from top of the stack.
	- top(): returns a reference to the top element of the stack.
	- size(): returns the number of elements in the stack.
  But does not provide iterators to traverse the elements.

