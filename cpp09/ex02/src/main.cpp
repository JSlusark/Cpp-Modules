#include "../headers/fordJohnsonSort.hpp"
#include <ctime>      // clock()
#include <sys/time.h> // gettimeofday()

#include <iomanip> // for std::setprecision, std::fixed
#include <sstream> // for std::ostringstream

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
        showSequence("Before", arr, initialSize);
        int iterations = 0;
        int comparisons = 0;

        // timer starts before algo
        // CPU time: benchmark algorithm's computational cost.
        // Wall time: measure user-perceived duration.
        logMessage("", C_YELLOW "FordJohnson Algorythm starts\n" C_RESET);
        struct timeval tv_start;
        gettimeofday(&tv_start, 0);
        std::clock_t cpu_start = std::clock();
        // algo call
        fordJohnsonSort(arr, iterations, comparisons);
        // timer ends here
        std::clock_t cpu_end = std::clock();
        logMessage("", C_YELLOW "\nFordJohnson Algorythm ends" C_RESET);
        showSequence("After", arr, initialSize);

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

                logMessage(SUCCESS, "Container was successfully sorted in " + asString(iterations) + " iterations and in " + asString(comparisons) + "/" + asString(max_comp) + " comparison count." C_RESET);
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
