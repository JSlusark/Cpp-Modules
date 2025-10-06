#include <iostream>
#include "../headers/Span.hpp"
#include "../headers/utils.hpp"



int main()
{

  testTitle(0, "42 test");
  try
  {
    Span span = Span(5);
    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);
    span.printAll(); // Debug print
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl; // 11-9
    std::cout << "Longest span: " << span.longestSpan() << std::endl; // 17-3
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  testTitle(1, "Negative values");
  try
  {
    int arr[] = {-5, -1, -2, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    Span span(size);
    span.addNumber(arr, size);
    span.printAll(); // Debug print
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl; // -2 - -3 = 1
    std::cout << "Longest span: " << span.longestSpan() << std::endl; // -1 - -5 = 4
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(2, "1-10k range");
  try
  {
    Span span(10000);
    span.addNumber(1, 10000);                                                     // adding range from 1 to 10000
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;           // should be 1 (2 - 1 = 1)
    std::cout << "Longest span: " << span.longestSpan() << std::endl;             // should be 9999 (10000 - 1 = 9999)
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }


  testTitle(3, "ERROR: limit reached");
  try
  {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    Span span(size);
    span.addNumber(arr, size);
    span.printAll(); // Debug print
    span.addNumber(12);           // overflow
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

    testTitle(4, "ERROR: single value ");
  try
  {
    Span span(1);
    std::vector<int> nums;
    nums.push_back(42);
    span.addNumber(nums);
    span.printAll(); // Debug print
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(4, "ERROR: empty span");
  try
  {
    Span span(0);
    std::vector<int> nums; // Empty vector
    span.addNumber(nums);
    span.printAll(); // Debug print
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  return 0;
}