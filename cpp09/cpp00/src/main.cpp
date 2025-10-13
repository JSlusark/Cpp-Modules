#include <iostream>
#include "../headers/BitcoinExchange.hpp"

int main(int argc, char const **argv)
{
    if(argc == 2)
    {
        BitcoinExchange(argv[1]);
    }
    else
        logMessage(WARNING, "Program needs a .csv file to convert");
    return 0;
}
