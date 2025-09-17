#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include "../headers/colors.hpp"

int main()
{
  std::cout << C_GREEN << "\nBureaucrat form management program starting..." << C_RESET << std::endl;
  try
  {
    Bureaucrat maria("Maria", 150);
    Bureaucrat charlie("Charlie", 1);
    // Bureaucrat sam("Sam", 151); // test this to see how the catch stops the program
    // Bureaucrat sandra("Sandra", 1); // test this to see how the catch stops the program
    Form a("A-form", 3, 3);
    Form b("Another-form", 149, 149);
    // Form c("Invalid signature", 151, 3); //  test this to see how the catch stops the program
    // Form d("Invalid execution", 150, 0); //  test this to see how the catch stops the program

    std::cout << "\n 👩‍💻 Welcome to the 42 company, we are now assigning some bureaucrats for your program:\n"
              << maria << "\n"
              << charlie << std::endl;

    std::cout << "\n📋 The 42 company received a form that needs approval (A) " << std::endl;
    std::cout << a << std::endl;

    std::cout << "\n👩‍💼 Maria tries to sign A-form with grade 151 but fails" << std::endl;
    maria.signForm(a);
    std::cout << a << std::endl;

    std::cout << "\n👨‍💼 Charlie helps by signing the form himself with grade 1 " << std::endl;
    charlie.signForm(a);
    std::cout << a << std::endl;
    std::cout << "\n👨‍💼 Charlie forgot if he signed A-form and goes to check" << std::endl;
    std::cout << "👨‍💼 ..." << std::endl;
    if (!a.getSignedStatus())
    {
      std::cout << "\n👨‍💼 ...Charlie finally signs the form" << std::endl;
      charlie.signForm(a);
    }
    else
      std::cout << "👨‍💼 ...Charlie notices that he already signed A-form!" << std::endl;
    std::cout << a << std::endl;

    std::cout << "\n\n📋 The 42 company received Another-form " << std::endl;
    std::cout << b << std::endl;
    std::cout << "\n👩‍💼 Maria tries to  sign Another-form but fails" << std::endl;
    maria.signForm(b);
    std::cout << "\n👩‍💼 Maria is tired to rely on Charlies and levels up 🔥" << std::endl; // comment for sad story
    maria.incrementGrade();                                                                          // comment for sad story
    maria.signForm(b);
    std::cout << b << std::endl;
    if (!b.getSignedStatus())
    {
      std::cout << "\n👨‍💼 Charlie is annoyed at Maria to have to rely on signing all the forms for her 💨" << std::endl;
      charlie.signForm(b);
      std::cout << b << std::endl;
      std::cout << "👩‍💼 Maria might better go find another job 💧\n"
                << std::endl;
    }
    else
      std::cout << "👩‍💼 Maria tells Charlie not to bother with signing Another-form as she was able to do it on her own 💅 \n " << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl; // needed to catch errors in the custuction
  }
  std::cout << C_GREEN << "Bureaucrat form management program exiting..." << C_RESET << std::endl;
}