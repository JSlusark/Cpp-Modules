#include "../headers/debug.hpp"

/* ----------------------------RESULT CHECK------------------------------- */
template <typename T>
bool is_sorted(const T &container)
{
    for (size_t i = 0; i < container.size() - 1; i++)
    {
        if (container[i] > container[i + 1])
            return false;
    }
    return true;
}

/* ------------------------------PRINTING----------------------------- */
template <typename T> // for initial and final sequences
void showSequence(std::string state, const T &container, size_t containerSize)
{
    std::cout << state << ": ";
    for (size_t i = 0; i < containerSize; ++i)
    {
        std::cout << container[i];
        if (i < (container.size() - 1))
            std::cout << ", ";
    }
    std::cout << std::endl;
}

// template <typename T> // for pend and main chains
// void printChain(const T &container, const std::string &name, int remainderValue, int hasRemainder)
// {
//     // logMessage(DEBUG, "remainderValue:'" + asString(remainderValue) + "'   hasRemainder:'" + asString(hasRemainder) + "' ");
//     std::cout << name << ":" << C_RESET << " [ ";
//     for (size_t i = 0; i < container.size(); ++i)
//     {
//         if (hasRemainder && (container[i] == remainderValue))
//             std::cout << C_RED << container[i] << C_RESET;
//         else
//             std::cout << container[i];

//         if (i < (container.size() - 1))
//             std::cout << ", ";

//         // if (i + 1 < container.size())
//         //     std::cout << ", ";
//     }
//     std::cout << " ]" << std::endl;
// }