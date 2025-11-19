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


void showPairs(const std::vector<std::pair<int, int> > &pairs, int remainder)
{
    std::cout << C_YELLOW "Pairs:" << C_RESET << " [";
    bool first = true;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (!first) std::cout << ", ";
        first = false;

        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
    }

    if (remainder > -1)
    {
        if (!first) std::cout << ", ";
        std::cout << "(" << C_RED << remainder << C_RESET << ")";
        first = false;
    }

    std::cout << "]" << std::endl;
}