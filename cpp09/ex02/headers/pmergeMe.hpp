#include "./utils.hpp"
#include <iostream>
#include <vector>
#include <deque>

// debugging functions
void printVector(const std::vector<int> &vec)
{
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void printPairs(const std::vector<std::pair<int, int> > &pairs)
{
	std::cout << "[";
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
		if (i < pairs.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}



void fordJohnsonSort(std::vector<int> &arr)
{
    /*
    checking md notes and also link to make sure steps are correct
    https://medium.com/@toukmati2000/cpp09-ford-johnson-algorithm-e6ad43288d4b
    */
    if (arr.size() <= 1) // 1 n does not need to be sorted
        return;

    bool remainder = (arr.size() % 2 != 0); // if array size is not even statement is true ( returns 1 as remainder)
    int remainderValue = 0;                 // may not need inizialization as remainder value is used only if remainder is 1/true
    if (remainder)
        remainderValue = arr.back(); // we take and store the remainder value if it exists

    std::vector<std::pair<int, int> > pairs; // the main pairs
    std::vector<int> pend;                  // holds the small key of each created keyPair
    std::vector<int> main;             // holds the big key of each created keyPair

    // Assigns values to each vector type
    for (size_t i = 0; i < arr.size() - remainder; i += 2) // if remainder exists we leave it out
    {
        // creates key value pairs in ascending order and pushes to pairs
        int small = arr[i];
        int big = arr[i + 1];
        if (small > big) // swap so it follows ascending order
            std::swap(small, big);
        std::pair<int, int> keyPair(small, big);
        pairs.push_back(keyPair);

        // from each value in the pair, it adds the smallest to pend and biggest to main chain
        pend.push_back(small);
        main.push_back(big); // to process recursively?
    }

    logMessage("", C_GREEN "Vector of pairs" C_RESET);
    printPairs(pairs);
    logMessage("", C_CYAN "Pend chain - holds big values from created keyPairs" C_RESET);
    printVector(pend);
    logMessage("", C_YELLOW "Main chain - holds big values from created keyPairs" C_RESET);
    printVector(main);
    std::cout << (remainder ? "Remainder found:" + asString(remainderValue) : "No remainder found") <<std::endl;
}
