#include "OutputView.hpp"
#include "Colors.hpp"

void PrintHeader()
{
    /*     std::cout << C_GREEN " -------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                                                                           |" << std::endl;
        std::cout << "|                                                                                           |" << std::endl;
        std::cout << "|      ,==.-----------.     ▗▖  ▗▖▄▄▄  █  ▐▌ ▄▄▄   ▗▄▖ ▄   ▄ ▗▞▀▚▖ ▄▄▄  ▄▄▄  ▄▄▄▄  ▗▞▀▚▖    |" << std::endl;
        std::cout << "|     (    ) ====     |      ▝▚▞▘█   █ ▀▄▄▞▘█     ▐▌ ▐▌█ ▄ █ ▐▛▀▀▘▀▄▄  █   █ █ █ █ ▐▛▀▀▘    |" << std::endl;
        std::cout << "|     ||  | [1][2][3] |       ▐▌ ▀▄▄▄▀      █     ▐▛▀▜▌█▄█▄█ ▝▚▄▄▖▄▄▄▀ ▀▄▄▄▀ █   █ ▝▚▄▄▖    |" << std::endl;
        std::cout << "|   ,-||  | [4][5][6] |       ▐▌                  ▐▌ ▐▌                                     |" << std::endl;
        std::cout << "|   . ||  | [7][8][9] |       ▗▄▄▖ ▐▌    ▄▄▄  ▄▄▄▄  ▗▞▀▚▖▗▄▄▖  ▄▄▄   ▄▄▄  █  ▄              |" << std::endl;
        std::cout << "|   . (    )[*][O][#] /       ▐▌ ▐▌▐▌   █   █ █   █ ▐▛▀▀▘▐▌ ▐▌█   █ █   █ █▄▀               |" << std::endl;
        std::cout << "|   ._-`=='----------'        ▐▛▀▘ ▐▛▀▚▖▀▄▄▄▀ █   █ ▝▚▄▄▖▐▛▀▚▖▀▄▄▄▀ ▀▄▄▄▀ █ ▀▄              |" << std::endl;
        std::cout << "|                             ▐▌   ▐▌ ▐▌                 ▐▙▄▞▘            █  █              |" << std::endl;
        std::cout << "|                                                                                           |" << std::endl;
        std::cout << "|                                                                                           |" << std::endl;
        std::cout << " -------------------------------------------------------------------------------------------" C_RESET<< std::endl; */

    std::cout << C_MAGENTA "╔═══════════════════════════════════════════════════════════════════════════════════════════╗" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET << "                                                                                           " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET << C_PURPLE "                                     WELCOME TO...                                         " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET << "                                                                                           " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "      ,==.-----------." << C_YELLOW "     ▗▖  ▗▖▄▄▄  █  ▐▌ ▄▄▄   ▗▄▖ ▄   ▄ ▗▞▀▚▖ ▄▄▄  ▄▄▄  ▄▄▄▄  ▗▞▀▚▖    " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "     (    ) ====     |" << C_YELLOW "      ▝▚▞▘█   █ ▀▄▄▞▘█     ▐▌ ▐▌█ ▄ █ ▐▛▀▀▘▀▄▄  █   █ █ █ █ ▐▛▀▀▘    " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "     ||  | [1][2][3] |" << C_YELLOW "       ▐▌ ▀▄▄▄▀      █     ▐▛▀▜▌█▄█▄█ ▝▚▄▄▖▄▄▄▀ ▀▄▄▄▀ █   █ ▝▚▄▄▖    " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "   ,-||  | [4][5][6] |" << C_YELLOW "       ▐▌                  ▐▌ ▐▌                                     " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "   . ||  | [7][8][9] |" << C_YELLOW "       ▗▄▄▖ ▐▌    ▄▄▄  ▄▄▄▄  ▗▞▀▚▖▗▄▄▖  ▄▄▄   ▄▄▄  █  ▄              " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "   . (    )[*][O][#] /" << C_YELLOW "       ▐▌ ▐▌▐▌   █   █ █   █ ▐▛▀▀▘▐▌ ▐▌█   █ █   █ █▄▀               " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "   ._-`=='----------' " << C_YELLOW "       ▐▛▀▘ ▐▛▀▚▖▀▄▄▄▀ █   █ ▝▚▄▄▖▐▛▀▚▖▀▄▄▄▀ ▀▄▄▄▀ █ ▀▄              " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET "                      " << C_YELLOW "       ▐▌   ▐▌ ▐▌                 ▐▙▄▞▘            █  █              " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET << "                                                                                           " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "║" << C_RESET << "                                                                                           " << C_MAGENTA "║" << C_RESET << std::endl;
    std::cout << C_MAGENTA "╚═══════════════════════════════════════════════════════════════════════════════════════════╝" << C_RESET << std::endl;

    std::cout << "This Phonebook allows you to use the following commands:" << std::endl;
    std::cout << "  - ADD:    Add a new contact to your phonebook" << std::endl;
    std::cout << "  - SEARCH: Search and display existing contacts" << std::endl;
    std::cout << "  - EXIT:   Quit the program and lose all your contacts" << std::endl;
    std::cout << "If you enter invalid input you the phonebook will ask you to write again." << std::endl;
    std::cout << C_GREEN "Creator's note:" C_RESET << std::endl;
    std::cout << "      I dare you to break it with Ctrl+D 🔥" << std::endl
              << std::endl
              << std::endl;
}

void PrintFooter()
{
    std::cout << C_MAGENTA "                     ____________________________________________________" << C_RESET << std::endl;
    std::cout << "                        " << C_YELLOW << "Thanks for testing out Your Awesome Phonebook!" << C_RESET << std::endl;
    std::cout << "                               " << C_GREEN << "Made with " << C_RED << "♥" << C_GREEN << " by " << C_CYAN << "github.com/jslusark" << C_RESET << std::endl << std::endl;
}
