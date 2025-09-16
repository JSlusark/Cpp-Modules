#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include "../headers/colors.hpp"

int main()
{
  // std::cout << C_GRAY << "---TEST 0: Valid Form construction and getters---" << C_RESET << std::endl;
  // try
  // {
  //   Form f("TaxForm", 50, 25);
  //   std::cout << f << std::endl;
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << e.what() << std::endl;
  // }

  // std::cout << C_GRAY << "\n---TEST 1: Exception at Form construction (sign grade too low, 151)---" << C_RESET << std::endl;
  // try
  // {
  //   Form f("LowForm", 151, 20);
  //   std::cout << f << std::endl;
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << e.what() << std::endl;
  // }

  // std::cout << C_GRAY << "\n---TEST 2: Exception at Form construction (exec grade too high, 0)---" << C_RESET << std::endl;
  // try
  // {
  //   Form f("HighForm", 10, 0);
  //   std::cout << f << std::endl;
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << e.what() << std::endl;
  // }

  std::cout << C_GRAY << "\n---TEST 3: Bureaucrat successfully signs Form---" << C_RESET << std::endl;
  try
  {
    Bureaucrat b1("Sam", 40);
    Bureaucrat b2("Charlie", 1);
    Form f("SecurityForm", 3, 3);

    std::cout
        << b1
        << std::endl;
    std::cout << b2
              << std::endl;
    std::cout
        << f
        << std::endl;
    b1.signForm(f);
    std::cout << f
              << std::endl;
    b2.signForm(f);
    std::cout
        << f
        << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  //   std::cout << C_GRAY << "\n---TEST 4: Bureaucrat too low to sign Form---" << C_RESET << std::endl;
  //   try
  //   {
  //     Bureaucrat b("Bob", 120);
  //     Form f("TopSecretForm", 100, 50);
  //     std::cout << b << std::endl;
  //     std::cout << f << std::endl;
  //     // f.beSigned(b); // should throw
  //     std::cout << f << std::endl;
  //   }
  //   catch (std::exception &e)
  //   {
  //     std::cout << e.what() << std::endl;
  //   }

  //   return 0;
}
