#include "./utils.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits> // <--- added

// debugging functions
template <typename T>
void printVector(T &container, size_t remainder, bool show)
{
    std::cout << "[";
    for (size_t i = 0; i < container.size(); ++i)
    {
        // cast element to size_t to avoid signed/unsigned comparison warning
        std::cout << (((static_cast<size_t>(container[i]) == remainder) && (show)) ? C_RED : "") << container[i] << C_RESET;
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

// new: print first `highlightCount` elements in yellow, rest normally
template <typename T>
void printAnch(const T &container, size_t highlightCount)
{
    std::cout << "[";
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (i < highlightCount)
            std::cout << C_YELLOW << container[i] << C_RESET;
        else
            std::cout << container[i];
        if (i < container.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

/*
    We use the jacobstah sequence to ensure we make the least number of comparisons/movements
    when binary inserting elements in the vector. So while binary insertion handles the
    "where to insert the value", the sequence handles "the order of numbers to insert" (what to start with first)

    We have to calculate the indexes
*/
std::vector<size_t> generateJacobsthal(size_t pend_size) // n is size of pend_chain
{
    std::vector<size_t> sequence; // empty vector
    if (pend_size == 0)           // means that there are no pending elements, but where does this decrease?!
        return sequence;
    size_t n2 = 0; // previous iteration previous jacobstahl (n - 2)
    size_t n1 = 1; // current iteration previous jacobstahl (n -1)

    // might start at base 1 and remove the 0 all together <------ remember
    logMessage("", C_YELLOW "Added to sequence:" C_RESET);
    logMessage("", "J(0)=" + asString(n2) + C_GRAY "       Base case" C_RESET);
    sequence.push_back(n2); // seq starts always with 0
    logMessage("", "J(1)=" + asString(n1) + C_GRAY "       Base case" C_RESET);
    // we skip adding 1 as that is already in the sequence

    size_t n = 2;
    while (true)
    {
        /*
         https://mathworld.wolfram.com/JacobsthalNumber.html
         */
        size_t curr = n1 + 2 * n2; // (J_(n)= J(n-1) + 2+ J(n-2)
        if (curr >= pend_size)
        {
            logMessage("", "Stopped adding. Curr(" + asString(curr) + ") reached pend_size(" + asString(n) + ")");
            break;
        }
        logMessage("", "J(" + asString(n) + ")=" + asString(curr) + C_GRAY "       J(" + asString(n - 1) + "):" + asString(n1) + " + 2 * J(" + asString(n - 2) + "):" + asString(n2) + C_RESET);
        n++;
        sequence.push_back(curr); // we add number of the jacobstahl sequence to the sequence
        n2 = n1;
        n1 = curr;
    }
    size_t initial_generated = sequence.size(); // save how many were originally generated

    // Fill gaps to reach size n
    std::vector<size_t> full_sequence;
    // must scan all pending indexes [0 .. pend_size-1]
    for (size_t i = 0; i < pend_size; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
        {
            full_sequence.push_back(i); // fills up missing indexes
        }
    }
    sequence.insert(sequence.end(), full_sequence.begin(), full_sequence.end());
    logMessage(C_YELLOW "Jacob sequence created:" C_RESET, "");
    // print full sequence, highlighting the originally generated items in yellow
    printAnch(sequence, initial_generated);
    return sequence;
}

void fordJohnsonSort(std::vector<int> &arr, int &moves, int &comparisons)
{
    /*
    checking md notes and also link to make sure comparisons are correct
    https://medium.com/@toukmati2000/cpp09-ford-johnson-algorithm-e6ad43288d4b
    */
    if (arr.size() <= 1) // 1 n does not need to be sorted
        return;

    bool has_remainder = (arr.size() % 2 != 0); // if array size is not even statement is true ( returns 1 as remainder)
    std::vector<std::pair<int, int> > pairs; // the main_chain pairs
    std::vector<int> pending_chain;         // holds the small key of each created keyPair
    std::vector<int> main_chain;            // holds the big key of each created keyPair

    // Assigns values to each vector type - CREATE CHAINS();
    for (size_t i = 0; i < arr.size() - has_remainder; i += 2) // if remainder exists we leave it out
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
    logMessage(C_GRAY "------------ START ITERATION N" + asString(moves), "------------" C_RESET);
    logMessage("", C_PURPLE "Created Pairs:" C_RESET);
    printPairs(pairs);
    int remainderValue;
    if (has_remainder)
    {
        // If there's a remainder element, add it to the pending chain and print it
        remainderValue = arr.back();
        std::cout << C_RED << "Remainder: " << C_RESET << asString(remainderValue) << C_RESET << std::endl;
        pending_chain.push_back(remainderValue);
    }
    else
    {
        std::cout << C_GREEN << "No remainder found in this iteration" << C_RESET << std::endl;
    }
    logMessage("", C_MAGENTA "Extracted Main chain:" C_RESET);
    printVector(main_chain, has_remainder ? static_cast<size_t>(remainderValue) : std::numeric_limits<size_t>::max(), false);
    logMessage("", C_MAGENTA "Extracted Pending chain:" C_RESET);
    printVector(pending_chain, has_remainder ? static_cast<size_t>(remainderValue) : std::numeric_limits<size_t>::max(), true); // pass actual remainder value when present

    if (main_chain.size() > 2) // recurses until bigchain is 2 numbers
    {
        moves++;
        fordJohnsonSort(main_chain, moves, comparisons);
    }

    /*
        I apply the jacobstall for every iteration, small chain is
        inserted to big chain at every iteraion until end of ITERATION
    */
    logMessage("", C_YELLOW "Creating Jacobstyle sequence from extracted pending chain of size " + asString(pending_chain.size()) + ":" + C_RESET);
    printVector(pending_chain, has_remainder ? static_cast<size_t>(remainderValue) : std::numeric_limits<size_t>::max(), true);
    logMessage("", C_YELLOW "To be binary inserted to main_chain " C_RESET);
    printVector(main_chain, has_remainder ? static_cast<size_t>(remainderValue) : std::numeric_limits<size_t>::max(), false);

    std::vector<size_t> jacob = generateJacobsthal(pending_chain.size());

    int jacob_insertions = 0;
    for (size_t i = 0; i < jacob.size(); i++)
    {
        if (jacob[i] < pending_chain.size())
        {
            // insertSorted(main, pend)
            std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pending_chain[jacob[i]]);
            main_chain.insert(it, pending_chain[jacob[i]]);
            jacob_insertions++;
            comparisons++; // count each insertion as a step/comparison movement
        }
    }

    arr = main_chain;
    logMessage("", C_MAGENTA "Sorted main chain of iteration_" + asString(moves_bt) + " with " + asString(jacob_insertions) +   " comparisons" C_RESET);
    printVector(arr, has_remainder ? static_cast<size_t>(remainderValue) : std::numeric_limits<size_t>::max(), true);

    logMessage(C_GRAY "------------ END ITERATION N" + asString(moves_bt), "------------" C_RESET);
}
