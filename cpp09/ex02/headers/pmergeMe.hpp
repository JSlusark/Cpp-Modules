#include "./utils.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits> // <--- added

// debugging functions
template <typename T>
void printVector(T &container, const std::string &name, int remainder)
{
    std::cout << C_PURPLE << name << ":" << C_RESET " [";
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i];
        if (i < container.size() - 1)
            std::cout << ", ";
    }
    remainder > -1 ? std::cout << ", " << C_RED << remainder << C_RESET << "]" << std::endl : std::cout << "]" << std::endl;
}

void printPairs(const std::vector<std::pair<int, int> > &pairs, int remainder)
{
    std::cout << C_YELLOW "Pairs:" << C_RESET " [";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
        if (i < pairs.size() - 1)
            std::cout << ", ";
    }
    remainder > -1 ? std::cout << ", (" << C_RED << remainder << C_RESET << ")" : std::cout << "";
    std::cout << "]" << std::endl;
}

std::vector<size_t> generateJacobsthal(size_t pend_size) // n is size of pend_chain
{
    logMessage(DEBUG, "Generating Jacobsthal sequence for pend[" + asString(pend_size) + "]");
    std::vector<size_t> sequence; // empty vector
    if (pend_size == 0)           // means that there are no pending elements, but where does this decrease?!
        return sequence;

    size_t n2 = 0; // previous iteration previous jacobstahl (n - 2)
    size_t n1 = 1; // current iteration previous jacobstahl (n -1)
    logMessage("", "J(0)=" + asString(n2) + C_GRAY "       Base case" C_RESET);
    sequence.push_back(n2); // seq starts always with 0
    logMessage("", "J(1)=" + asString(n1) + C_GRAY "       Base case" C_RESET);
    size_t n = 2;
    while (true)
    {
        /* https://mathworld.wolfram.com/JacobsthalNumber.html */
        size_t curr = n1 + 2 * n2; // (J(n)= J(n-1) + 2+ J(n-2)
        if (curr >= pend_size)
        {
            logMessage("", "Stopped sequence at " + asString(curr) + ")");
            break;
        }
        logMessage("", "J(" + asString(n) + ")=" + asString(curr) + C_GRAY "       J(" + asString(n - 1) + "):" + asString(n1) + " + 2 * J(" + asString(n - 2) + "):" + asString(n2) + C_RESET);
        n++;
        sequence.push_back(curr); // we add jacobstahl number to sequence
        n2 = n1;
        n1 = curr;
    }
    printVector(sequence, "Jacobsthal sequence", -1);

    // Fill gaps to reach size n
    std::vector<size_t> full_sequence;
    for (size_t i = 0; i < n; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
            full_sequence.push_back(i); // fills up missing indexes
    }
    sequence.insert(sequence.end(), full_sequence.begin(), full_sequence.end());
    printVector(sequence, "Final Jacobsthal sequence", -1);
    return sequence;
}

/*
PROBLEMS:
- i have problems when container size is 2
- the jacobstahl sequence should be generated before the main chain is sorted so that we keep pairing info???
*/
void fordJohnsonSort(std::vector<int> &arr, int &iteration, int &comparisons)
{
    if (arr.size() <= 1) // 1 n does not need to be sorted
        return;
    int iteration_bt = iteration;

    logMessage(C_GRAY "------------ START ITERATION N" + asString(iteration), "------------\n" C_RESET);

    logMessage(DEBUG, "Created containers");
    std::vector<std::pair<int, int> > pairs;    // pair container
    std::vector<int> pend;                     // smaller values container
    std::vector<int> main;                     // bigger values container
    int has_remainder = (arr.size() % 2 != 0); // if even it's false(0), if odd it's true(1)
    int remainderValue = -1;                   // inexisting value, gets overwritten if remainder exists
    if (has_remainder)
    {
        remainderValue = arr.back();
        arr.pop_back(); // store and removes last element to allow pairing of elements in loop
    }
    // Assigns values to each container
    for (size_t i = 0; i < arr.size(); i += 2) // we proceed by 2 elements at a time
    {
        int a = arr[i];     // first (smallest)
        int b = arr[i + 1]; // second (biggest)
        if (a > b)          // swaps content for ascending order
        {
            std::swap(a, b);
            comparisons++; // increment comparison count
        }
        std::pair<int, int> keyPair(a, b);
        pairs.push_back(keyPair);

        // from each value in the pair, it adds the smallest(a) to pend and biggest(b) to main chain
        pend.push_back(a);
        main.push_back(b); // to process recursively?
    }

    // Recursively applies the fordJohnson until main chain has only 2 keys
    printPairs(pairs, remainderValue);
    printVector(main, "Main", -1);             //-1 as remainder needs to be printed in pend
    printVector(pend, "Pend", remainderValue); // show remainder as part of pending chain
    if (has_remainder)
        pend.push_back(remainderValue); // adds remainder to pend to be inserted last
    if (main.size() > 2)                // recurses until bigchain is 2 numbers
    {
        iteration++;
        fordJohnsonSort(main, iteration, comparisons);
    }
    else if (main.size() == 2)
    {
        if (main[0] > main[1])
            std::swap(main[0], main[1]);
    }

    logMessage(DEBUG, "Current containers on backtrack:");
    printPairs(pairs, remainderValue);
    printVector(main, "Main", -1); // -1 as remainder needs to be printed in pend
    printVector(pend, "Pend", -1); //  -1 as remainder is already in pend at this point
    std::vector<size_t> jacob = generateJacobsthal(pend.size());

    logMessage(DEBUG, "Binary insert of pend into main via Jacobsthal sequence");
    for (size_t i = 0; i < jacob.size(); i++)
    {
        size_t n = jacob[i]; // index of number chosen to insert from pend to main
        if (n < pend.size()) // to avoid out of bounds
        {
            // main = [3, 5, 8, 9] (sorted)
            // pend = [6, 7, 1, 4]
            // jacob = [0, 2, 1, 3]

            // Easy Binary insert: returns the position where to insert the pend[jacob[i]] value but does not count comparisons
            // std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), pend[n]); 
            // main.insert(it, pend[n]);

            // Custom binary search to count comparisons
            size_t left = 0;
            size_t right = main.size();
            while (left < right)
            {
                size_t mid = left + (right - left) / 2;
                comparisons++; // Count each comparison
                if (pend[n] > main[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            // Insert at the found position
            main.insert(main.begin() + left, pend[n]);
            logMessage("", C_GRAY "Inserted pend[" + asString(n) + "]:" + asString(pend[n]) + C_RESET);
        }
    }

    arr = main;
    printVector(arr, "Sorted main:", -1);

    logMessage(C_GRAY "\n------------ END ITERATION N" + asString(iteration_bt), "------------\n" C_RESET);
}
