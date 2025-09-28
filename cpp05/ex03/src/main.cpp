#include <iostream>
#include <cstdlib>
#include "../headers/utils.hpp"
#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/Intern.hpp"

int main()
{
    srand(time(0));
    try
    {
        std::cout << C_GREEN << "Constructing bureaucrats..." << C_RESET << std::endl;
        logMessage(LOG, "Initialising Bureaucrats...");
        Bureaucrat jane("Jane", 146); // lowest grade
        Bureaucrat carl("Carl", 1);   // top grade
        Bureaucrat tim("Tim", 40);
        std::cout << jane << "\n"
                  << carl << "\n"
                  << tim << std::endl;
        logMessage(LOG, "Initialising Interns...");
        Intern minion1;
        Intern minion2;

        testTitle(0, "Interns are creating forms for the team");
        AForm *shrub = minion1.makeForm("shrubbery creation", "Garden"); // 145 sign 137 exec
        std::cout << std::endl;
        AForm *robo = minion1.makeForm("robotomy request", "Wall E"); // 72 sign 45 exec
        std::cout << std::endl;
        AForm *pardon = minion1.makeForm("presidential pardon", "Andy"); // 25 sign 5 exec
        std::cout << std::endl;
        AForm *invalid1 = minion1.makeForm("SHRUBBERY CREATON", "failure");
        std::cout << std::endl;
        AForm *invalid2 = minion1.makeForm("inexisting", "buggy");
        (void)invalid1;
        (void)invalid2;
        std::cout << std::endl;

        // // ----------------- Test 1 -----------------
        // logMessage("", "");
        // testTitle(0, "Jane fails to sign Shrub form, levels up to sign but cannot execute any form");
        // jane.signAForm(*shrub);
        // jane.incrementGrade();
        // jane.signAForm(*shrub);
        // jane.execAForm(*shrub);
        // jane.execAForm(*pardon);

        // // ----------------- Test 2 -----------------
        // logMessage("", "");
        // testTitle(1, "Tim tries to sign shrub(which was already signed), then executes it which creates file then fails at singing pardon");
        // tim.signAForm(*shrub);
        // tim.execAForm(*shrub);
        // tim.signAForm(*pardon);

        // // ----------------- Test 3 -----------------
        // logMessage("", "");
        // testTitle(2, "Tim fails to esexute unsigned robotomy form, signs and executes 3 times with 1 chance on 3 for success");
        // // std::srand(std::time(0));
        // tim.execAForm(*robo); // should throw FormNotSignedException
        // tim.signAForm(*robo);
        // for (int i = 0; i < 3; i++)
        //     tim.execAForm(*robo); // ~50% chance success each time, at least 1 should end in success

        // // ----------------- Test 4 -----------------
        // logMessage("", "");
        // testTitle(3, "Carl executes Robotomy which was signed by somebody else ");
        // carl.execAForm(*robo);

        // // ----------------- Test 5 -----------------
        // logMessage("", "");
        // testTitle(4, "Carl signs and executes Pardon and executes it after no one else can");
        // carl.signAForm(*pardon);
        // tim.execAForm(*pardon);  // should print pardon message
        // jane.execAForm(*pardon); // should print pardon message
        // carl.execAForm(*pardon); // should print pardon message

        logMessage(LOG, "Deleting dynamic form allocations...");
        std::cout << C_GREEN << "\n--- Deleting dynamic form allocations ---" << C_RESET << std::endl;
        delete shrub;
        delete robo;
        delete pardon;
        logMessage(LOG, "Preparing to exit...");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
    ;
}
