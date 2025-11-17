#include "../headers/utils.hpp"
#include "../headers/pmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib> // For atol
#include <algorithm>
#include <cmath>

#include <ctime>      // clock()
#include <sys/time.h> // gettimeofday()

#include <iomanip> // for std::setprecision, std::fixed
#include <sstream> // for std::ostringstream

int maxComparisons(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k)
    {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

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

template <typename T>
void printContainer(std::string state, const T &container, size_t containerSize)
{
    std::cout << state << ": ";
    for (size_t i = 0; i < containerSize; ++i)
        std::cout << container[i] << ", ";
    std::cout << "\n"
              << std::endl;
}

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
        size_t initialSize = arr.size();
        printContainer("Before", arr, initialSize);
        int iterations = 0;
        int comparisons = 0;

        // timer starts before algo
        // CPU time: benchmark algorithm's computational cost.
        // Wall time: measure user-perceived duration.
        struct timeval tv_start;
        gettimeofday(&tv_start, 0);
        std::clock_t cpu_start = std::clock();
        // algo call
        fordJohnsonSort(arr, iterations, comparisons);
        // timer ends here
        std::clock_t cpu_end = std::clock();
        printContainer("After", arr, initialSize);

        size_t endSize = arr.size();
        if (!is_sorted(arr))
        {
            logMessage(ERROR, C_RED "Container is was not sorted correctly!" C_RESET);
            return 1;
        }
        else
        {
            if (initialSize != endSize)
            {
                logMessage(ERROR, C_RED "Container size was not preserved after sorting! Size before sort: " + asString(initialSize) + ", Size after sort: " + asString(endSize) + C_RESET);
                return 1;
            }
            int max_comp = maxComparisons(endSize);
            if (comparisons <= max_comp)
            {
                double cpu_micro_double = (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC * 1e6;
                std::ostringstream cpuFmt;
                cpuFmt.setf(std::ios::fixed);
                cpuFmt << std::setprecision(5) << cpu_micro_double;

                logMessage(SUCCESS, C_GREEN "Container was successfully sorted in " + asString(iterations) + " iterations and in " + asString(comparisons) + " comparisons (within limit " + asString(max_comp) + ")." C_RESET);
                logMessage(LOG, C_CYAN "Time taken to process " + asString(initialSize) +
                                    " elements: " + cpuFmt.str() + " us" C_RESET);
            }
            else
            {
                logMessage(ERROR, C_RED "Container was sorted but exceeded comparison limit (" + asString(comparisons) + " > " + asString(max_comp) + ")!" C_RESET);
                return 1;
            }
        }
    }

    return 0;
}
