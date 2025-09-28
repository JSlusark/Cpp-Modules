#include <iostream>
#include <cstdlib>
#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/utils.hpp"

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
        logMessage("", "");
        logMessage(LOG, "Constructing bureaucrats...");
        // std::cout << C_GREEN << "Constructing bureaucrats..." << C_RESET << std::endl;
        Bureaucrat jane("Jane", 146); // lowest grade
        Bureaucrat carl("Carl", 1);   // top grade
        Bureaucrat tim("Tim", 40);
        std::cout << jane << "\n"
                  << carl << "\n"
                  << tim << std::endl;
        logMessage(LOG, "Constructing forms...");
        // std::cout << C_GREEN << "Constructing forms..." << C_RESET << std::endl;
        ShrubberyCreationForm shrub("Shrub");    // 145 sign 137 exec
        RobotomyRequestForm robo("Robo");        // 72 sign 45 exec
        PresidentialPardonForm pardon("Pardon"); // 25 sign 5 exec

        // ----------------- Test 1 -----------------
        logMessage("", "");
        testTitle(0, "Jane fails to sign Shrub form, levels up to sign but cannot execute any form");
        jane.signAForm(shrub);
        std::cout << shrub << std::endl;
        jane.incrementGrade();
        jane.signAForm(shrub);
        std::cout << shrub << std::endl;
        jane.execAForm(shrub);
        jane.execAForm(pardon);

        // ----------------- Test 2 -----------------
        logMessage("", "");
        testTitle(1, "Tim tries to sign shrub(which was already signed), then executes it which creates file then fails at singing pardon");
        tim.signAForm(shrub);
        std::cout << shrub << std::endl;
        tim.execAForm(shrub);
        std::cout << shrub << std::endl;
        tim.signAForm(pardon);

        // ----------------- Test 3 -----------------
        logMessage("", "");
        testTitle(2, "Tim fails to esexute unsigned robotomy form, signs and executes 3 times with 1 chance on 3 for success");
        tim.execAForm(robo); // should throw FormNotSignedException
        tim.signAForm(robo);
        for (int i = 0; i < 3; i++)
            tim.execAForm(robo); // ~50% chance success each time, at least 1 should end in success

        // ----------------- Test 4 -----------------
        logMessage("", "");
        testTitle(3, "Carl executes Robotomy which was signed by somebody else ");
        carl.execAForm(robo); // should be executed since signed

        // ----------------- Test 5 -----------------
        logMessage("", "");
        testTitle(4, "Carl signs and executes Pardon and executes it after no one else can");
        carl.signAForm(pardon); // should print pardon message
        std::cout << pardon << std::endl;
        logMessage(WARNING, "Only Carl can execute pardon form!");
        tim.execAForm(pardon); // should print pardon message
        jane.execAForm(pardon);
        carl.execAForm(pardon); // should print pardon message
        logMessage("", "");
        logMessage(LOG,"Preparing to exit..." );
    }
    catch (std::exception &e)
    {
        std::cout << C_RED << "Fatal exception: " << e.what() << C_RESET << std::endl;
    }
    return 0;
}
