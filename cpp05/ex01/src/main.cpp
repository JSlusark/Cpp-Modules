#include <iostream>
#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include "../headers/utils.hpp"

int main()
{
  // std::cout << C_GREEN << "\nBureaucrat form management program starting..." << C_RESET << std::endl;
  try
  {
    logMessage(LOG, "Initialising Bureaucrats...");
    Bureaucrat maria("Maria", 150);
    Bureaucrat charlie("Charlie", 1);
    std::cout << maria << "\n"
              << charlie << std::endl;
    logMessage(LOG, "Initialising forms...");
    Form a("A-form", 3, 3);
    Form b("Another-form", 149, 149);

    testTitle(0, "A-form needs approval");
    logMessage(LOG, "A-form detatils:");
    std::cout << a << std::endl;
    logMessage(LOG, "👩‍💼 Maria attempts to sign A-form with grade 150 but fails");
    maria.signForm(a);
    std::cout << a << std::endl;
    logMessage(LOG, "👨‍💼 Charlie helps by signing the form himself with grade 1 successfully");
    charlie.signForm(a);
    std::cout << a << std::endl;
    logMessage(DEBUG, "👨‍💼 Charlie forgot if he signed A-form and goes back to check");
    logMessage(DEBUG, "👨‍💼 ...");
    if (!a.getSignedStatus())
    {
      logMessage(SUCCESS, "👨‍💼...Charlie finally signed the form");
      charlie.signForm(a);
    }
    else
      logMessage(WARNING, "👨‍💼 ...Charlie notices that he already signed A-form, nothing happens");
    std::cout << a << std::endl;

    std::cout << std::endl;
    testTitle(1, "Another-form needs approval");
    std::cout << b << std::endl;
    logMessage(LOG, "👩‍💼 Maria attempts to sign Another-form with grade 150 but fails");
    maria.signForm(b);
    logMessage(WARNING, "👩‍💼 Maria is tired to rely on Charlie and levels up 🔥"); // comment for sad story
    maria.incrementGrade();                                                                  // comment for sad story
    std::cout << maria << std::endl;                                                         // comment for sad story
    maria.signForm(b);                                                                       // comment for sad story
    std::cout << b << std::endl;                                                             // comment for sad story
    if (!b.getSignedStatus())
    {
      logMessage(WARNING, "👨‍💼 Charlie is annoyed at Maria to have to rely on signing all the forms for her 💨 🔥");
      charlie.signForm(b);
      std::cout << b << std::endl;
      logMessage(WARNING, "👩‍💼Maria might better go find another job 💧");
    }
    else
      logMessage(SUCCESS, "👩‍💼 Maria tells Charlie not to bother with signing Another-form  💅");
    logMessage(LOG, "Exiting program...");
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl; // needed to catch errors in the custuction
  }
}