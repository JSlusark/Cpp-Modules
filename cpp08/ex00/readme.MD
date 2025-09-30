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
