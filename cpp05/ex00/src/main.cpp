#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/utils.hpp"

int main()
{
  testTitle(0, "Valid construction and getters");
  try
  {
    logMessage(LOG, "Creating burocrat...");
    Bureaucrat b("Mark", 75);
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  testTitle(1, "Exception at construction (grade:151, too low)"); // creation fails and no destruction
  try
  {
    logMessage(LOG, "Creating burocrat...");
    Bureaucrat b("Jane", 151);
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  testTitle(2, "Exception at construction (grade: 0, too high)"); // creation fails and no destruction
  try
  {
    logMessage(LOG, "Creating burocrat...");
    Bureaucrat b("Sam", 0);
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  testTitle(3, "constant grade increment(with --) until expection hit (TOO HIGH))");
  try
  {
    logMessage(LOG, "Creating burocrat...");
    Bureaucrat b("Lola", 3);
    std::cout << b << std::endl; // 3
    b.incrementGrade();
    std::cout << b << std::endl; // 2
    b.incrementGrade();
    std::cout << b << std::endl; // 1
    b.incrementGrade();
    std::cout << b << std::endl; // catch called
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  testTitle(4, "constant decrement(++) until expection hit (TOO LOW)");
  try
  {
    logMessage(LOG, "Creating burocrat...");
    Bureaucrat b("Tim", 149);
    std::cout << b << std::endl; // 149
    b.decrementGrade();
    std::cout << b << std::endl; // 150
    b.decrementGrade();          // catch
    std::cout << b << std::endl; // ---------- ends here
    b.decrementGrade();
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
