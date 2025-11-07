#include "./utils.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits> // <--- added

struct CountingCompare {
    int &counter;
    CountingCompare(int &c) : counter(c) {}
    bool operator()(int a, int b) {
        counter++;
        return a < b;
    }
};


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
    /*
        https://mathworld.wolfram.com/JacobsthalNumber.html
        https://www.geeksforgeeks.org/dsa/jacobsthal-and-jacobsthal-lucas-numbers/
    */
    // logMessage(DEBUG, "Generating Jacobsthal sequence for pend[" + asString(pend_size) + "]");
    std::vector<size_t> seq;              // empty vector
    if (pend_size == 0 || pend_size == 1) // means that there are no pending elements, but where does this decrease?!
    {
        seq.push_back(pend_size); // adds 0 or 1 to seq
        printVector(seq, "Jacobsthal seq", -1);
        return seq;
    }
    size_t j = 0;  // i assign this so i can start the loop?
    size_t j1 = 1; // n - 1 (prev)
    size_t j2 = 0; // n - 2 (prev_prev)
    for (size_t i = 0; j < pend_size; i++)
    {
        /* J(n) = J(n-1) + 2 * J(n-2)  */
        //         1    +    0
        j = (j1) + (2 * (j2));
        if (j < pend_size) // adds only if last generated j is < size
        {
            // logMessage("", "J(" + asString(i) + ") = " + asString(j) + C_GRAY "     formula: j = " + asString(j1) + " + (2 * " + asString(j2) + ")" + C_RESET);
            seq.push_back(j);
        }
        j2 = j1;
        j1 = j;
    }
    // logMessage("", "Stoped Jacobstahl collection stopped at " + asString(j));
    // printVector(seq, "Sequence", -1);

    // Fill gaps to reach size n
    std::vector<size_t> filled;
    /*
        https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
        For the Jacobsthal number of 3, we insert 2 elements (3 - 1), b3, b2.
        For the Jacobsthal number of 5, we insert 2 elements (5 - 3), b5, b4.
        For the Jacobsthal number of 11, we insert 6 elements (11 - 5), b11, b10, b9, b8,
    */
    // logMessage(LOG, "Sequence[" + asString(seq.size()) + "] - insert numbers to filled");
    for (size_t i = 0; i < seq.size(); i++)
    {
        // std::cout << "index" << i<< std::endl;
        if (i == 0)
        {
            filled.push_back(seq[i]);
            // logMessage("", "Added:" + asString(seq[i]));
            continue;
        }
        size_t a = seq[i - 1]; // prev
        size_t b = seq[i];     // curr
        // logMessage(LOG, "seq[" + asString(i - 1) + "]:" + asString(a) +
        //                     "    seq[" + asString(i) + "]:" + asString(b));
        //  logMessage(LOG, "Adding from " + asString(b) + " to " + asString(a + 1) );

        for (size_t n = b; n > a; n--)
        {
            // logMessage("", "fill: " + asString(n));
            filled.push_back(n);
            // printVector(filled, "Jacobsthal insertion order", -1);
        }
    }
    if(pend_size > seq.back())
    {
        size_t a = seq.back(); // prev
        size_t b = pend_size;     // curr
        // logMessage(LOG, "last_j:" + asString(a) +
        //                     "    pend_size:" + asString(b));
        //  logMessage(LOG, "Adding from " + asString(b) + " to " + asString(a + 1) );

        for (size_t n = b; n > a; n--)
        {
            // logMessage("", "fill: " + asString(n));
            filled.push_back(n);
            // printVector(filled, "Jacobsthal insertion order", -1);
        }

    }
    // printVector(filled, "Order", -1);
    return filled;
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
    // std::vector<int> mainIndices; // ??? parallel to main, stores original index or pair id
    for (size_t i = 0; i < arr.size(); i += 2) // we proceed by 2 elements at a time
    {
        int a = arr[i];     // first (smallest)
        int b = arr[i + 1]; // second (biggest)
        if (a > b)          // swaps content for ascending order
        {
            std::swap(a, b);
            comparisons++; // increment comparison count from ford-johnson
        }
        std::pair<int, int> keyPair(a, b);
        pairs.push_back(keyPair);

        // from each value in the pair, it adds the smallest(a) to pend and biggest(b) to main chain
        pend.push_back(a);
        main.push_back(b); // to process recursively?
        //  mainIndices.push_back(i/2); // pair ID??
    }

    // Recursively applies the fordJohnson until main chain has only 2 keys
    printPairs(pairs, remainderValue);
    printVector(main, "Main", -1);             //-1 as remainder needs to be printed in pend
    printVector(pend, "Pend", remainderValue); // show remainder as part of pending chain
    if (has_remainder)
    pend.push_back(remainderValue); // adds remainder to pend to be inserted last

    if (main.size() > 2) // recurses until bigchain is 2 numbers
    {
        iteration++;
        logMessage(C_GRAY "\n------------ RECURSION LEVEL:" + asString(iteration), "------------\n" C_RESET);
        fordJohnsonSort(main, iteration, comparisons);
        int iteration_bt = iteration;
        logMessage(C_GRAY "\n------------ END RECURSION LEVEL:" + asString(iteration_bt), "------------\n" C_RESET);
    }
    else if (main.size() == 2)
    {
        if (main[0] > main[1])
        {
            std::swap(main[0], main[1]);
            comparisons++; // increment comparison count also here
        }
    }

    logMessage(DEBUG, "Backtracking...");
    printPairs(pairs, remainderValue);
    printVector(main, "Main", -1); // -1 as remainder needs to be printed in pend
    printVector(pend, "Pend", -1); //  -1 as remainder is already in pend at this point

    std::vector<size_t> jacob = generateJacobsthal(pend.size()); // removed to earlier point as pairing info is lost after recursive sort of main chain
    // size of jacob insertion sequence == size of pend
    // logMessage("", "pend size:" + asString( pend.size()));
    // logMessage("", "jacob size:" + asString( jacob.size()));
    for (size_t i = 0; i < jacob.size(); i++)
    {
        // std::cout << i <<std::endl;
        size_t j = jacob[i] - 1; // js number - 1 to start from index 0
        size_t value = pend[j];
        size_t partner = pairs[j].second; // WHAAAAAAAt
        std::vector<int>::iterator upperBound =std::find(main.begin(), main.end(), partner);

        logMessage("", C_GRAY "j(" + asString(jacob[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair <"+ asString(value) + ", " + asString(partner) + ">" + C_RESET);

       // locates 'upperBoundValue' in main
        CountingCompare comp(comparisons);
        // need to consider the subrange!
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), upperBound, value, comp);
        main.insert(pos, value);

    }
    logMessage(DEBUG, "Current number of comparisons: " + asString(comparisons));

    arr = main;
    printVector(arr, "Sorted main:", -1);

}
