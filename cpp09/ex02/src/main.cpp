#include "../headers/utils.hpp"
#include "../headers/pmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>


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
            arr.push_back(atoi(argv[i]));

        logMessage(LOG, "Program arguments before applying algorithm");
        for (size_t i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
}
