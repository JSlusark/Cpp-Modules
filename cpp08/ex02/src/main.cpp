#include <iostream>
#include "../headers/MutantStack.hpp"
#include "../headers/utils.hpp"

int main()
{
  {
    testTitle(1, "42 Example");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top number of the stack:" << mstack.top() << std::endl; // prints the top element (17)
    mstack.pop();                                                         // removes the top element (17)
    std::cout << "Stack size:" << mstack.size() << std::endl;             // size is now 1 with only 5
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack); // copy constructor from MutantStack to std::stack
  }

  {
    testTitle(2, "Reverse iterators");
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; i++)
      mstack.push(i * 10); // Push multiples of 10 onto the stack
    std::cout << "Printing stack elements top to bottom" << std::endl;
    MutantStack<int>::iterator top = mstack.begin();
    MutantStack<int>::iterator bottom = mstack.end();
    while (top != bottom)
    {
      std::cout << *top << std::endl; // Print elements from top to bottom
      ++top;
    }
  }

  {
    testTitle(3, "Const iterators");
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; i++)
      mstack.push(i * 100); // Push multiples of 10 onto the stack
    std::cout << "Stack elements using const iterators:" << std::endl;
    MutantStack<int>::iterator start = mstack.begin();
    MutantStack<int>::iterator end = mstack.end();
    while (start != end)
    {
      std::cout << *start << std::endl; // Print elements from bottom to top
      ++start;
    }
  }

  {
    testTitle(4, "Coping and assignment");
    MutantStack<int> original;
    for (int i = 1; i <= 5; i++)
      original.push(i * 1000);        // Push multiples of 10 onto the stack
    MutantStack<int> dup(original); // dup constructor
    logMessage(LOG, "Popping dup elements from top to bottom:");
    while (!dup.empty())
    {
      std::cout << dup.top() << std::endl; // Print elements from bottom to top
      dup.pop();                              // instead of iterating
    }
    if (dup.empty())
      logMessage(SUCCESS, "dup stack is empty after popping all elements");
    else
      logMessage(ERROR, "dup stack is not empty after popping all elements");
    dup = original; // assignment operator
    logMessage(LOG, "Printing assigned  dup elements from bottom to top");
    MutantStack<int>::iterator start = dup.begin();
    MutantStack<int>::iterator end = dup.end();
    while (start != end)
    {
      std::cout << *start << std::endl; // Print elements from bottom to top
      *start++;                         // instead of iterating
    }
  }

  return 0;
}