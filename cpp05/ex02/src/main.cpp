#include <iostream>
#include <cstdlib>
#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/colors.hpp"

int main()
{
    // By using srand(std::time(0)), we take the current system time in seconds as
    // the seed. Since time(0) changes every second, each run of the program will
    // start the random sequence at a different point, making the results appear
    // random between runs.
    //
    // Important: srand() should only be called ONCE at the beginning of the program
    // (e.g. in main). If you call srand() repeatedly (for example, inside a class
    // constructor), and two calls happen within the same second, time(0) returns
    // the same seed, which resets rand() to the same sequence. That causes repeated
    // and non-random results.
    srand(time(0));
    try
    {
        std::cout << C_GREEN << "Constructing bureaucrats..." << C_RESET << std::endl;
        Bureaucrat jane("Jane", 146); // lowest grade
        Bureaucrat carl("Carl", 1);   // top grade
        Bureaucrat tim("Tim", 40);
        std::cout << C_GREEN << "Constructing forms..." << C_RESET << std::endl;
        ShrubberyCreationForm shrub("Shrub");    // 145 sign 137 exec
        RobotomyRequestForm robo("Robo");        // 72 sign 45 exec
        PresidentialPardonForm pardon("Pardon"); // 25 sign 5 exec

        std::cout << C_GREEN << "👩‍💻 Our bureaucrats today:\n"
                  << C_RESET
                  << jane << "\n"
                  << carl << "\n"
                  << tim << std::endl;

        // ----------------- Test 1 -----------------
        std::cout << C_CYAN << "\n--- TEST 1: Jane failes to sign Shrub form, levels up to sign but cannot execute ---" << C_RESET << std::endl;
        jane.signAForm(shrub);
        std::cout << shrub << std::endl;
        // std::cout << C_GRAY << "\n--- Jane increments grade, signs shrub but fails at executing it ---" << C_RESET << std::endl;
        jane.incrementGrade();
        jane.signAForm(shrub);
        std::cout << shrub << std::endl;
        jane.execAForm(shrub);
        jane.execAForm(pardon);

        // ----------------- Test 2 -----------------
        std::cout << C_CYAN << "\n---TEST 2: Tim tried to sign shrub(which was already signed), then executes it which creates file then fails at singing pardon ---" << C_RESET << std::endl;
        tim.signAForm(shrub);
        std::cout << shrub << std::endl;
        tim.execAForm(shrub);
        std::cout << shrub << std::endl;
        tim.signAForm(pardon);

        // ----------------- Test 3 -----------------
        std::cout << C_CYAN << "\n---TEST 3: Tim signs and executes Robotomy 3 times, with 1 chance on 3 for success ---" << C_RESET << std::endl;
        // std::srand(std::time(0));
        tim.execAForm(robo); // should throw FormNotSignedException
        tim.signAForm(robo);
        for (int i = 0; i < 3; i++)
            tim.execAForm(robo); // ~50% chance success each time, at least 1 should end in success

        // ----------------- Test 4 -----------------
        std::cout << C_CYAN << "\n---TEST 4: Carl executes Robotomy which was signed by somebody else ---" << C_RESET << std::endl;
        carl.execAForm(robo); // should throw FormNotSignedException

        // ----------------- Test 5 -----------------
        std::cout << C_CYAN << "\n---TEST 5: Carl signs and executes Pardon and executes it since no one else can ---" << C_RESET << std::endl;
        carl.signAForm(pardon); // should print pardon message
        std::cout << pardon << std::endl;
        tim.execAForm(pardon); // should print pardon message
        jane.execAForm(pardon);
        carl.execAForm(pardon); // should print pardon message

        std::cout << C_GREEN << "\n--- Preparing to exit ---" << C_RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << C_RED << "Fatal exception: " << e.what() << C_RESET << std::endl;
    }
    return 0;
}
