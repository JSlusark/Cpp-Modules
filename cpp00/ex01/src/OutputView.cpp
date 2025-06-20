#include "OutputView.hpp"
#include "Colors.hpp"

void PrintHeader()
{
    std::cout << std::endl
              << "      " << BG_DARK_PURPLE << C_MAGENTA << "╔═══════════════════════════════════════════════════════════════════════════════════════════╗" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_WHITE << "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_PURPLE << "                                     WELCOME TO...                                         " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_WHITE << "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "      ,==.-----------." << C_YELLOW << "     ▗▖  ▗▖▄▄▄  █  ▐▌ ▄▄▄   ▗▄▖ ▄   ▄ ▗▞▀▚▖ ▄▄▄  ▄▄▄  ▄▄▄▄  ▗▞▀▚▖    " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "     (    ) ====     |" << C_YELLOW << "      ▝▚▞▘█   █ ▀▄▄▞▘█     ▐▌ ▐▌█ ▄ █ ▐▛▀▀▘▀▄▄  █   █ █ █ █ ▐▛▀▀▘    " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "     ||  | [1][2][3] |" << C_YELLOW << "       ▐▌ ▀▄▄▄▀      █     ▐▛▀▜▌█▄█▄█ ▝▚▄▄▖▄▄▄▀ ▀▄▄▄▀ █   █ ▝▚▄▄▖    " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "   ,-||  | [4][5][6] |" << C_YELLOW << "       ▐▌                  ▐▌ ▐▌                                     " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "   . ||  | [7][8][9] |" << C_YELLOW << "       ▗▄▄▖ ▐▌    ▄▄▄  ▄▄▄▄  ▗▞▀▚▖▗▄▄▖  ▄▄▄   ▄▄▄  █  ▄              " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "   . (    )[*][O][#] /" << C_YELLOW << "       ▐▌ ▐▌▐▌   █   █ █   █ ▐▛▀▀▘▐▌ ▐▌█   █ █   █ █▄▀               " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "   ._-`=='----------' " << C_YELLOW << "       ▐▛▀▘ ▐▛▀▚▖▀▄▄▄▀ █   █ ▝▚▄▄▖▐▛▀▚▖▀▄▄▄▀ ▀▄▄▄▀ █ ▀▄              " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_BOLD_WHITE << "                      " << C_YELLOW << "       ▐▌   ▐▌ ▐▌                 ▐▙▄▞▘            █  █              " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_WHITE << "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║" << C_WHITE << "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << BG_DARK_PURPLE << C_MAGENTA << "║-------------------------------------------------------------------------------------------" << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA << "║                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE " This Phonebook allows you to use the following commands:                                  " << C_MAGENTA << "║" << C_WHITE << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_GREEN " - ADD:" << C_WHITE << "     Adds a new contact to the phonebook and asks to fill                           " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_WHITE "            - First name:                                                                  " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_WHITE "            - Last name:                                                                   " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_WHITE "            - Phone Number:                                                                " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_WHITE "            - Darkest Secret:                                                              " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_WHITE "            The phonebook can store up to " << C_RED << "8" << C_WHITE << " contacts.                                      " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_RED "            If you add more it will overwrite the oldest contact                           " << C_MAGENTA << "║" << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_GREEN "  - SEARCH:" << C_WHITE << "  Searches for contact information. It will preview a list of total added       " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_WHITE "             contacts and ask to write the index of the contact you need more info on.     " << C_MAGENTA << "║" << std::endl
              << "      " << C_MAGENTA << "║" C_RED "             Only indexes between 0 to 7 are accepted                                      " << C_MAGENTA << "║" << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_GREEN "  - EXIT:" << C_WHITE << "    Quits the app and deletes all your contacts                                   " << C_MAGENTA << "║" << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "  - The Phonebook will ask you to write again if something is written incorrectly          " << C_MAGENTA << "║" << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_GREEN "  Creator’s note:                                                                          " << C_MAGENTA << "║" << C_WHITE << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "      I dare you to break it with Ctrl+D and see what happens 👀                           " << C_MAGENTA << "║" << std::endl;
    std::cout << "      " << C_MAGENTA << "║" C_WHITE "                                                                                           " << C_MAGENTA << "║" << C_RESET << std::endl;
    std::cout << "      " << C_MAGENTA "╚═══════════════════════════════════════════════════════════════════════════════════════════╝" << C_RESET << std::endl
              << std::endl;
}

void PrintFooter()
{
    std::cout << C_MAGENTA << "\n             ~~~~~~~~~~~~✶✦✧ Thanks for texting \"Your Awesome Phonebook\"! ✧✦✶~~~~~~~~~~~~" << C_WHITE << std::endl;
    // std::cout << C_MAGENTA << std::endl << "                        _____________________________________________________                       " C_WHITE << std::endl << std::endl;
    // std::cout << "                           " << "Thanks for testing out Your Awesome Phonebook!" << std::endl;
    std::cout << "                                  Made with " << C_RED << "♥" << C_WHITE << " by " << C_GREEN << "github.com/jslusark" << C_WHITE << std::endl
              << std::endl;
}
