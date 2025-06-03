#include "OutputView.hpp"
#include "Colors.hpp"


void PrintHeader()
{
    std::cout << std::endl 
              << C_YELLOW "                        Welcome to:                         " << std::endl;
    std::cout << C_GREEN " --------------------------------------------------------------" << std::endl;
    std::cout << "| ▗▖  ▗▖▄▄▄  █  ▐▌ ▄▄▄   ▗▄▖ ▄   ▄ ▗▞▀▚▖ ▄▄▄  ▄▄▄  ▄▄▄▄  ▗▞▀▚▖ |" << std::endl;
    std::cout << "|  ▝▚▞▘█   █ ▀▄▄▞▘█     ▐▌ ▐▌█ ▄ █ ▐▛▀▀▘▀▄▄  █   █ █ █ █ ▐▛▀▀▘ |" << std::endl;
    std::cout << "|   ▐▌ ▀▄▄▄▀      █     ▐▛▀▜▌█▄█▄█ ▝▚▄▄▖▄▄▄▀ ▀▄▄▄▀ █   █ ▝▚▄▄▖ |" << std::endl;
    std::cout << "|   ▐▌                  ▐▌ ▐▌                                  |" << std::endl;
    std::cout << "|       ▗▄▄▖ ▐▌    ▄▄▄  ▄▄▄▄  ▗▞▀▚▖▗▄▄▖  ▄▄▄   ▄▄▄  █  ▄       |" << std::endl;
    std::cout << "|       ▐▌ ▐▌▐▌   █   █ █   █ ▐▛▀▀▘▐▌ ▐▌█   █ █   █ █▄▀        |" << std::endl;
    std::cout << "|       ▐▛▀▘ ▐▛▀▚▖▀▄▄▄▀ █   █ ▝▚▄▄▖▐▛▀▚▖▀▄▄▄▀ ▀▄▄▄▀ █ ▀▄       |" << std::endl;
    std::cout << "|       ▐▌   ▐▌ ▐▌                 ▐▙▄▞▘            █  █       |" << std::endl;
    std::cout << " --------------------------------------------------------------" C_RESET<< std::endl;
    std::cout << "This Phonebook allows you to use the following commands:" << std::endl;
    std::cout << "  - ADD:    Add a new contact to your phonebook" << std::endl;
    std::cout << "  - SEARCH: Search and display existing contacts" << std::endl;
    std::cout << "  - EXIT:   Quit the program and lose all your contacts" << std::endl;
    std::cout << "If you enter invalid input you the phonebook will ask you to write again." << std::endl;
    std::cout << C_GREEN"Creator's note:" C_RESET<< std::endl;
    std::cout << "      I dare you to break it with Ctrl+D 🔥" << std::endl << std::endl << std::endl;
}

void PrintFooter()
{
	std::cout << std::endl;
	std::cout << " ============================================================== " << std::endl;
	std::cout << "|  Thanks for testing out Your Awesome Phonebook!              |" << std::endl;
	std::cout << "|           Made with ♥ by Jessica Slusark                     |" << std::endl;
	std::cout << " ============================================================== " << std::endl;
	std::cout << std::endl;
}
