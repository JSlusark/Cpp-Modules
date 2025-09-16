#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/colors.hpp"

int main()
{
  std::cout << C_GRAY << "---TEST 0: Valid construction and getters---" << C_RESET << std::endl;
  try
  {
    Bureaucrat b("Mark", 75);
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << C_GRAY << "\n---TEST 1: Exception at construction (grade:151, too low) ---" << C_RESET << std::endl;
  try
  {
    Bureaucrat b("Jane", 151);
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << C_GRAY << "\n---TEST 2: Exception at construction (grade: 0, too high)---" << C_RESET << std::endl;
  try
  {
    Bureaucrat b("Sam", 0);
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << C_GRAY << "\n---TEST 3: constant grade increment(with --) until expection hit (TOO HIGH) ---" << C_RESET << std::endl;
  try
  {
    Bureaucrat b("Lola", 3);
    std::cout << b << std::endl; // 3
    b.decrementGrade();
    std::cout << b << std::endl; // 2
    b.decrementGrade();
    std::cout << b << std::endl; // 1
    b.decrementGrade();
    std::cout << b << std::endl; // catch called
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << C_GRAY << "\n---TEST 3: constant decrement(with ++) until expection hit (TOO LOW) ---" << C_RESET << std::endl;
  try
  {
    Bureaucrat b("Tim", 149);
    std::cout << b << std::endl; // 149
    b.incrementGrade();
    std::cout << b << std::endl; // 150
    b.incrementGrade();          // catch
    std::cout << b << std::endl; // ---------- ends here
    b.incrementGrade();
    std::cout << b << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
