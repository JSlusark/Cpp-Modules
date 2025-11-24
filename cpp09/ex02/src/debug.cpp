#include "../headers/debug.hpp"

/* ------------------------------ARGS CHECK----------------------------- */
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
            logMessage(ERROR, "Arguments should be valid positive intergers.");
            return false;
        }
    }

    long bound = atol(s.c_str());
    if (bound > INT_MAX || bound < 0)
    {
        logMessage(ERROR, "Passed argument bigger thant INT_MAX.");
        return false;
    }
    conversion = bound;
    return true;
}

/* ----------------------------RESULT CHECK------------------------------- */

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

/* ------------------------------PRINTING----------------------------- */

void showPairs(const std::vector<std::pair<int, int> > &pairs, int has_remainder)
{
    std::cout << "Pairs:" << " [";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (has_remainder && pairs[i].second == -1) // the
            std::cout << C_RED " <" << pairs[i].first << "> " C_RESET;
        else
            std::cout << " <" << pairs[i].first << "," << pairs[i].second << "> ";
        if (i < (pairs.size() - 1))
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}