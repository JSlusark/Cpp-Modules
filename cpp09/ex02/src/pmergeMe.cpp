#include "../headers/pmergeMe.hpp"


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
        showContainer(seq, "Jacobsthal seq", -1);
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
    std::vector<std::pair<int, int> > pairs;    // pair container IS PROBLEMATIC WHEN ODD SIZE!!!
    std::vector<int> pend;                     // smaller values container
    std::vector<int> main;                     // bigger values container
    int has_remainder = (arr.size() % 2 != 0); // if even it's false(0), if odd it's true(1)
    int remainderValue = -1;                   // inexisting value, gets overwritten if remainder exists
    if (has_remainder)
    {
        remainderValue = arr.back();
        //     // arr.pop_back(); // store and removes last element to allow pairing of elements in loop
        //     arr.push_back(-1); // ADDING NEGATIVE NUMBER AS A FLAG TO INDICATE PAIR HAS NO PARTNER (-1)
    }
    // Assigns values to each container
    // std::vector<int> mainIndices; // ??? parallel to main, stores original index or pair id
    for (size_t i = 0; i < arr.size(); i += 2) // we proceed by 2 elements at a time
    {
        int a;
        int b;
        // creates the fake pair for the remainder
        if (arr[i] == remainderValue && i == (arr.size() - 1)) // checking arr.size ensure we don't select duplicate values if present
        {
            a = remainderValue;
            b = -1;
        }
        else
        {
            // creates and sorts the real pairs before pusing to pairs
            a = arr[i];     // first (smallest)
            b = arr[i + 1]; // second (biggest) // wthis segfaults, and needs to be used only on non-paired
            if (a > b)          // swaps content for ascending order
            {
                std::swap(a, b);
                comparisons++; // increment comparison count from ford-johnson
            }
        }

        std::pair<int, int> keyPair(a, b);
        pairs.push_back(keyPair);
        if(b != -1) // avoid dummy value gets pushed to main chain
            main.push_back(b); // only true values are pushed to chain
        pend.push_back(a); // adds all small numbers + odd one to the pend
    }

    // Recursively applies the fordJohnson until main chain has only 2 keys
    showPairs(pairs, remainderValue);
    showContainer(main, "Main", -1);             //-1 as remainder needs to be printed in pend
    showContainer(pend, "Pend", remainderValue); // show remainder as part of pending chain
    // if (has_remainder)
    //     pend.push_back(remainderValue); // adds remainder to pend to be inserted last

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
    showPairs(pairs, remainderValue);
    showContainer(main, "Main", -1); // -1 as remainder needs to be printed in pend
    showContainer(pend, "Pend", -1); //  -1 as remainder is already in pend at this point

    std::vector<size_t> jacob = generateJacobsthal(pend.size()); // removed to earlier point as pairing info is lost after recursive sort of main chain
    // size of jacob insertion sequence == size of pend
    // logMessage("", "pend size:" + asString( pend.size()));
    // logMessage("", "jacob size:" + asString( jacob.size()));
    logMessage(DEBUG, "Inserting pending elements into main chain via Jacobsthal sequence");
    for (size_t i = 0; i < jacob.size(); i++)
    {
        // std::cout << i <<std::endl;
        size_t j = jacob[i] - 1; // js number - 1 to start from index 0
        int value = pend[j];
        int partner = pairs[j].second; // BUG TO FIX: this is invalid if number is odd and not paired!!
        std::vector<int>::iterator partnerPosition;

        if (partner == -1) // means that the number in pend had no partner and it's not in main chain
            partnerPosition = main.end();
        else
            partnerPosition = std::find(main.begin(), main.end(), partner);

        // pair <remainderValue, -1> if it hits remainder value
        logMessage("", C_GRAY "j(" + asString(jacob[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair <" + asString(value) + ", " + asString(partner) + ">" + C_RESET);

        CountingCompare comp(comparisons);
        // need to consider the subrange!
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), partnerPosition, value, comp);
        main.insert(pos, value);
    }
    logMessage(DEBUG, "Current number of comparisons: " + asString(comparisons));

    arr = main;
    showContainer(arr, "Sorted main:", -1);
}
