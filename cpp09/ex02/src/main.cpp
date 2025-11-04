#include "../headers/utils.hpp"
#include "../headers/pmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib> // For atol

bool isValidNumber(std::string &s, int &conversion)
{
    if (s.empty())
    {
        logMessage(ERROR, "Found empty argument");
        return false;
    }
    if (s[0] == '+') // erases the initial + so that isdigit does not throw error for valid +n numbers
        s.erase(0, 1);

    for (size_t i = 0; i < s.length(); i++) // runs loop inside the string (after first + if found)
    {
        if (!isdigit(s[i])) //
        {
            logMessage(ERROR, "Arguments should be valid positive intergers. Invalid argument:'" + s + "'");
            return false;
        }
    }

    long bound = atol(s.c_str());
    if (bound > INT_MAX || bound < 0)
    {
        logMessage(ERROR, "Passed argument bigger thant INT_MAX:'" + s + "'");
        return false;
    }
    conversion = bound;
    return true;
}

/* ./PmergeMe $(shuf -i 1-10 -n 3000 | tr "\n" " ") */
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        logMessage(ERROR, "./PmergeMe needs at least one argument");
        return 1;
    }
    else
    {
        std::vector<int> arr;
        for (int i = 1; i < argc; ++i)
        {
            int conversion;
            std::string s = argv[i];
            if (!isValidNumber(s, conversion))
                return 1;
            arr.push_back(conversion);
        }

        logMessage(LOG, "Unsorted arguments");
        for (size_t i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n" << std::endl;

        int iterations = 0;
        int steps = 0;
        fordJohnsonSort(arr, iterations);

        logMessage(LOG, "Final sort completed in " + asString(iterations) + " iterations and in"+  asString(steps) + " steps.");
        for (size_t i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        if(std::is_sorted(arr.begin(), arr.end()))
        {
            logMessage(SUCCESS, C_GREEN "Array was successfully sorted" C_RESET);
        }
        else
        {
            logMessage(ERROR, C_RED "Array is was not sorted correctly!" C_RESET);
        }
    }

    return 0;
}
