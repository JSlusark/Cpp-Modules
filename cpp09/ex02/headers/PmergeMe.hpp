#pragma once
#include "./fordJohnsonSort.hpp"
#include "./debug.hpp"

class PmergeMe
{
private: // private per recursion?
    std::vector<int> input;
    std::vector<std::pair<int, int> > pairs; // pair container IS PROBLEMATIC WHEN ODD SIZE!!!
    std::vector<int> pend;                  // smaller values container
    std::vector<int> main;                  // bigger values container
    std::vector<size_t> jacobsthal;

    int comparisonCount;
    int remainderValue;
    int has_remainder;

    std::vector<size_t> generateJacobsthal() // n is size of pend_chain
    {
        size_t pend_size = pend.size();
        // std::cout << "hello" << std::endl;
        /*
            https://mathworld.wolfram.com/JacobsthalNumber.html
            https://www.geeksforgeeks.org/dsa/jacobsthal-and-jacobsthal-lucas-numbers/
        */
        // logMessage(DEBUG, "Generating Jacobsthal sequence for pend[" + asString(pend_size) + "]");
        std::vector<size_t> seq;              // empty vector
        if (pend_size == 0 || pend_size == 1) // means that there are no pending elements, but where does this decrease?!
        {
            seq.push_back(pend_size); // adds 0 or 1 to seq depending on size
            // showContainer(seq, "Jacobsthal seq", -1);
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
        // showContainer(seq, "Sequence", -1);

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
                // showContainer(filled, "Jacobsthal insertion order", -1);
            }
        }
        if (pend_size > seq.back())
        {
            size_t a = seq.back(); // prev
            size_t b = pend_size;  // curr
            // logMessage(LOG, "last_j:" + asString(a) +
            //                     "    pend_size:" + asString(b));
            //  logMessage(LOG, "Adding from " + asString(b) + " to " + asString(a + 1) );

            for (size_t n = b; n > a; n--)
            {
                // logMessage("", "fill: " + asString(n));
                filled.push_back(n);
                // showContainer(filled, "Jacobsthal insertion order", -1);
            }
        }
        // showContainer(filled, "Order", -1);
        return filled;
    }

    void createChains()
    {
        for (size_t i = 0; i < input.size(); i += 2) // we proceed by 2 input at a time
        {
            int a;
            int b;
            // creates the fake pair for the remainder
            if (input[i] == remainderValue && i == (input.size() - 1)) // checking input.size ensure we don't select duplicate values if present
            {
                a = remainderValue;
                b = -1;
            }
            else
            {
                // creates and sorts the real pairs before pusing to pairs
                a = input[i];     // first (smallest)
                b = input[i + 1]; // second (biggest) // wthis segfaults, and needs to be used only on non-paired
                if (a > b)        // swaps content for ascending order
                {
                    std::swap(a, b);
                    comparisonCount++; // increment comparison count from ford-johnson
                }
            }

            std::pair<int, int> keyPair(a, b);
            pairs.push_back(keyPair);
            if (b != -1)           // avoid dummy value gets pushed to main chain
                main.push_back(b); // only true values are pushed to chain
            pend.push_back(a);     // adds all small numbers + odd one to the pend
        }
    }

public:
    int recursionID;

    PmergeMe(std::vector<int> input, int &iteration, int &comparisons)
        : input(input),
          comparisonCount(comparisons),
          remainderValue(-1),
          has_remainder(0),
          recursionID(iteration)
    {
        has_remainder = (input.size() % 2 != 0); // if even it's false(0), if odd it's true(1)
        if (has_remainder)
            remainderValue = input.back();
        createChains();
        jacobsthal = generateJacobsthal();
        // std::cout << "Jacobsthal insertion order for pend[" << pend.size() << "]:" << std::endl;
    };
    ~PmergeMe() {};

    // getters
    std::vector<int> &getMain()
    {
        return main;
    }

    std::vector<int> &getPend()
    {
        return pend;
    }

    std::vector<std::pair<int, int> > &getPairs()
    {
        return pairs;
    }

    std::vector<size_t> &getJacobsthal()
    {
        return jacobsthal;
    }

    int &getComparisonCount()
    {
        return comparisonCount;
    }
    // const int getRecursionID() const
    // {
    //     return recursionID;
    // }

    void printStatus()
    {
        logMessage(C_CYAN "Recursion level: " C_RESET, asString(recursionID));
        showPairs(pairs, remainderValue);
        showContainer(main, "Main", -1); // -1 as remainder needs to be printed in pend
        showContainer(pend, "Pend", -1); //  -1 as remainder is already in pend at this point
    }

    // change with sort pair
    void sortPair()
    {
        if (main[0] > main[1])
        {
            std::swap(main[0], main[1]);
            comparisonCount++; // increment comparison count also here
        }
    }
};
