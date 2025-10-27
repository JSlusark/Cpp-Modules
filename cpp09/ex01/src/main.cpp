#include "../headers/utils.hpp"
#include "../headers/rpn.hpp"

int main(int argc, char **argv)
{
    if (argc > 1 && argc < 10) // invalid, numers should be 10 + operations
    {
        logMessage(LOG, "Processing RPN");
        printResult(argc, argv);
    }
    else
        std::cerr << "Error: RPN should receive 1 up to 9 arguments arguments added where " << argc - 1 << std::endl;

    return 0;
}