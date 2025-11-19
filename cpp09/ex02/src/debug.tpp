#include "../headers/pmergeMe.hpp"

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
        std::cout << container[i] << ", ";
    std::cout << "\n"
              << std::endl;
}

template <typename T> // for pend and main chains
void showContainer(const T &container, const std::string &name, int remainder)
{
    std::cout << C_PURPLE << name << ":" << C_RESET << " [";
    for (size_t i = 0; i < container.size(); ++i)
    {
        bool isRem = (container[i] == static_cast<typename T::value_type>(remainder));
        if (isRem) std::cout << C_RED;
        else       std::cout << C_RESET;

        std::cout << container[i] << C_RESET;

        if (i + 1 < container.size())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}