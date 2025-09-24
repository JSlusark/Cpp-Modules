#include <iostream>
#include <cstdlib>
#include "../headers/colors.hpp"
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
        Bureaucrat jane("Jane", 146); // lowest grade
        Bureaucrat carl("Carl", 1);   // top grade
        Bureaucrat tim("Tim", 40);
        std::cout << C_GREEN << "Constructing Interns..." << C_RESET << std::endl;
        Intern minion1;
        Intern minion2;

        std::cout << C_CYAN << "\n --- 👩‍💻 TEST 0: Interns are creating forms for the team ---" << C_RESET << std::endl;
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

        // ----------------- Test 1 -----------------
        std::cout << C_CYAN << "\n--- TEST 1: Jane failes to sign Shrub form, levels up to sign but cannot execute ---" << C_RESET << std::endl;
        jane.signAForm(*shrub);
        jane.incrementGrade();
        jane.signAForm(*shrub);
        jane.execAForm(*shrub);
        jane.execAForm(*pardon);

        // ----------------- Test 2 -----------------
        std::cout << C_CYAN << "\n---TEST 2: Tim tried to sign shrub(which was already signed), then executes it which creates file then fails at singing pardon ---" << C_RESET << std::endl;
        tim.signAForm(*shrub);
        tim.execAForm(*shrub);
        tim.signAForm(*pardon);

        // ----------------- Test 3 -----------------
        std::cout << C_CYAN << "\n---TEST 3: Tim signs and executes Robotomy 3 times, with 1 chance on 3 for success ---" << C_RESET << std::endl;
        // std::srand(std::time(0));
        tim.execAForm(*robo); // should throw FormNotSignedException
        tim.signAForm(*robo);
        for (int i = 0; i < 3; i++)
            tim.execAForm(*robo); // ~50% chance success each time, at least 1 should end in success

        // ----------------- Test 4 -----------------
        std::cout << C_CYAN << "\n---TEST 4: Carl executes Robotomy which was signed by somebody else ---" << C_RESET << std::endl;
        carl.execAForm(*robo); // should throw FormNotSignedException

        // ----------------- Test 5 -----------------
        std::cout << C_CYAN << "\n---TEST 5: Carl signs and executes Pardon and executes it since no one else can ---" << C_RESET << std::endl;
        carl.signAForm(*pardon); // should print pardon message
        tim.execAForm(*pardon);  // should print pardon message
        jane.execAForm(*pardon);
        carl.execAForm(*pardon); // should print pardon message

        std::cout << C_GREEN << "\n--- Deleting dynamic form allocations ---" << C_RESET << std::endl;
        delete shrub;
        delete robo;
        delete pardon;
        std::cout << C_GREEN << "\n--- Preparing to exit ---" << C_RESET << std::endl;
        // do not need to delete invalid forms as constructor is not called and * is NULL;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
    ;
}
