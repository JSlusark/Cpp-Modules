#include "./utils.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// debugging functions
template <typename T>
void printVector(T &container)
{
    std::cout << "[";
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i];
        if (i < container.size() - 1)
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

// Function to generate Jacobsthal sequence up to a size
/*
    We use the jacobstah sequence to ensure we make the least number of comparisons/movements
    when binary inserting elements in the vector. So while binary insertion handles the
    "where to insert the value", the sequence handles "the order of numbers to insert" (what to start with first)

    We have to calculate the indexes
*/
std::vector<size_t> generateJacobsthal(size_t n) // n is size of pend_chain
{
    logMessage(C_GRAY "[JACOB]" C_RESET, "Pending_size:" + asString(n));

    std::vector<size_t> sequence; // empty vector
    if (n == 0)        // means that there are no pending elements, but where does this decrease?!
        return sequence;
    sequence.push_back(0); // seq starts always with 0
    size_t n2 = 0;  // previous iteration previous jacobstahl (n - 2)
    size_t n1 = 1;  // current iteration previous jacobstahl (n -1)
    size_t curr_i = 2;
    while (true)
    {
        // if next = a shouldn't we skip it?
        size_t curr = n1 + 2 * n2; // why this calculation, what does it do and why this logic
        logMessage(C_GRAY "[JACOB]" C_RESET, " J(" + asString(curr_i) + "):" + asString(curr) + " = J(" + asString(curr_i - 1)+ "):" + asString(n1) + " * 2 + J(" + asString(curr_i -2) +"):" + asString(n2));
        curr_i++;
        if (curr >= n)
        {
            logMessage(C_GRAY "[JACOB ENDS]" C_RESET, "curr:" + asString(curr) + " >= pending size:" + asString(n));
            break;
        }
        sequence.push_back(curr); // we add number of the jacobstahl sequence to the sequence
        n2 = n1;
        n1 = curr;
    }
    // Fill gaps to reach size n
    std::vector<size_t> full_sequence;
    for (size_t i = 0; i < n; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
        {
            full_sequence.push_back(i); // fills up missing indexes
        }
    }
    sequence.insert(sequence.end(), full_sequence.begin(), full_sequence.end());
    logMessage(C_GRAY "[JACOB SEQUENCE]" C_RESET, "");
    printVector(sequence);
    return sequence;
}

void fordJohnsonSort(std::vector<int> &arr, int &moves)
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

    std::vector<std::pair<int, int> > pairs; // the main_chain pairs
    std::vector<int> pending_chain;         // holds the small key of each created keyPair
    std::vector<int> main_chain;            // holds the big key of each created keyPair

    // Assigns values to each vector type - CREATE CHAINS();
    for (size_t i = 0; i < arr.size() - remainder; i += 2) // if remainder exists we leave it out
    {
        // creates key value pairs in ascending order and pushes to pairs
        int small = arr[i];
        int big = arr[i + 1];
        if (small > big) // swaps content for ascending order
            std::swap(small, big);
        std::pair<int, int> keyPair(small, big);
        pairs.push_back(keyPair);

        // from each value in the pair, it adds the smallest to pending_chain and biggest to main_chain chain
        pending_chain.push_back(small);
        main_chain.push_back(big); // to process recursively?
    }

    // Recursively applies the fordJohnson until main_chain chain has only 2 keys
    int moves_bt = moves;
    logMessage(C_GRAY "------------ START RECURSION N" + asString(moves), "------------" C_RESET);
    logMessage("", C_GREEN "N" + asString(moves) + "_Pairs:" C_RESET);
    std::cout << (remainder ? C_RED "N" + asString(moves) + "_Remainder:" C_RESET + asString(remainderValue) + C_RESET : C_GREEN "No remainder found") + C_RESET << std::endl;
    printPairs(pairs);
    logMessage("", C_CYAN "N" + asString(moves) + "_Main_chain:" C_RESET);
    printVector(main_chain);
    logMessage("", C_CYAN "N" + asString(moves) + "_Pending_chain:" C_RESET);
    printVector(pending_chain);

    if (main_chain.size() > 2) // recurses until bigchain is 2 numbers
    {
        moves++;
        fordJohnsonSort(main_chain, moves);
    }
    else if (main_chain.size() == 2)
    {
        if (main_chain[0] > main_chain[1])
            std::swap(main_chain[0], main_chain[1]);
    }

    /*
        I apply the jacobstall for every iteration, small chain is
        inserted to big chain at every iteraion until end of recursion
    */
    logMessage(C_GRAY "[JACOB]" C_RESET, "calculating for N" + asString(moves_bt) + "_Pending_chain:");
    printVector(pending_chain);
    std::vector<size_t> jacob = generateJacobsthal(pending_chain.size());

    // for (size_t i = 0; i < jacob.size(); i++)
    // {
    //     if(jacob[i] < pending_chain.size())
    //     {
    //         insertSorted(main, pend)
    //     }
    //     /* code */
    // }

    // for (size_t idx : jacob)
    // {
    //     if (idx < pend.size())
    //     {
    //         insertSorted(main, pend[idx]);
    //     }
    // }

    // // Step 5: Handle remainderValue
    // if (remainder)
    // {
    //     insertSorted(main, remainderValue);
    // }

    arr = main_chain;
    logMessage("", C_YELLOW "N" + asString(moves_bt) + "_Final Result:" C_RESET);
    printVector(arr);

    logMessage(C_GRAY "------------ END RECURSION N" + asString(moves_bt), "------------" C_RESET);
}
