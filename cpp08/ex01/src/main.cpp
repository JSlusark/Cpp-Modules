#include <iostream>
#include "../headers/Span.hpp"
#include "../headers/utils.hpp"

int main()
{

  testTitle(0, "42 test");
  try
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    /* code */
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  testTitle(1, "My basic test");
  try
  {
    Span span(5);
    span.addNumber(1);
    span.addNumber(3);
    span.addNumber(5);
    span.addNumber(7);
    span.addNumber(9);
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(2, "Test with negative values");
  try
  {
    Span span(4);
    span.addNumber(-5);
    span.addNumber(-1);
    span.addNumber(0);
    span.addNumber(3);
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(3, "Test with one value (should throw exception)");
  try
  {
    Span span(1);
    span.addNumber(42);
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(4, "Test with empty span (should throw exception)");
  try
  {
    Span span(0);
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(5, "Test with duplicate values");
  try
  {
    Span span(5);
    span.addNumber(2);
    span.addNumber(2);
    span.addNumber(4);
    span.addNumber(4);
    span.addNumber(6);
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(6, "Test exceeding capacity (should throw exception)");
  try
  {
    Span span(3);
    span.addNumber(1);
    span.addNumber(2);
    span.addNumber(3);
    span.addNumber(4); // This should throw
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  testTitle(7, "Test with 10k random numbers");
  try
  {
    Span span(10000);
    std::vector<int> tenK(10000);
    for (size_t i = 0; i < tenK.size(); ++i)
    {
      tenK[i] = 1 * i; // adds exactly from 0 to 9999
    }
    span.addNumber(tenK);
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl; // should be 1
    std::cout << "Longest span: " << span.longestSpan() << std::endl; // should be 9999
  }
  catch (const std::exception &e)
  {
    std::cerr << C_RED "[ERROR] " C_RESET << e.what() << std::endl;
  }

  return 0;
}

/*

temst empty
test with negative vals
test with chars
test with one val

*/