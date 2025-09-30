#include <iostream>
#include "../headers/Span.hpp"
int main() {
  Span span(5);
  span.addNumber(1);
  span.addNumber(3);
  span.addNumber(5);
  span.addNumber(7);
  span.addNumber(9);

  try {
      std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
      std::cout << "Longest span: " << span.longestSpan() << std::endl;
  } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
