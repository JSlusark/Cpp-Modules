#include "./utils.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> // For std::sort, std::lower_bound
#include <cctype>    // If needed for parsing


// Function to generate Jacobsthal sequence up to a size
std::vector<size_t> generateJacobsthal(size_t n)
{
    std::vector<size_t> seq;
    if (n == 0)
        return seq;
    seq.push_back(0);
    size_t a = 0, b = 1;
    while (true)
    {
        size_t next = b * 2 + a;
        if (next >= n)
            break;
        seq.push_back(next);
        a = b;
        b = next;
    }
    // Fill gaps to reach size n
    std::vector<size_t> full_seq;
    for (size_t i = 0; i < n; ++i)
    {
        if (std::find(seq.begin(), seq.end(), i) == seq.end())
        {
            full_seq.push_back(i);
        }
    }
    seq.insert(seq.end(), full_seq.begin(), full_seq.end());
    return seq;
}

// Helper: Binary search insert into sorted vector
void insertSorted(std::vector<int> &main, int value)
{
    std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
    main.insert(it, value);
}

// Main Ford-Johnson sort function
// Main Ford-Johnson sort function
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

    std::vector<std::pair<int, int>> pairs; // the main pairs
    std::vector<int> pend;                  // holds the small key of each created keyPair
    std::vector<int> main;                  // holds the big key of each created keyPair

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

    // logMessage("", C_GREEN "Vector of pairs" C_RESET);
    // printPairs(pairs);
    // logMessage("", C_CYAN "Pend chain - holds big values from created keyPairs" C_RESET);
    // printVector(pend);
    // logMessage("", C_YELLOW "Main chain - holds big values from created keyPairs" C_RESET);
    // printVector(main);
    // std::cout << (remainder ? "Remainder found:" + asString(remainderValue) : "No remainder found") << std::endl;

    // USELESS
    // // Step 2: Main chain from largest
    // std::vector<int> main;
    // for (size_t i = 0; i < pairs.size(); ++i)
    // {
    //     main.push_back(pairs[i].second);
    // }

    // // Step 3: Recursively sort main (base case: size 1 or 2)
    // if (main.size() > 2)
    // {
    //     fordJohnsonSort(main);
    // }
    // else if (main.size() == 2)
    // {
    //     if (main[0] > main[1])
    //         std::swap(main[0], main[1]);
    // }

    // // // Step 4: Insert pend using Jacobsthal order
    // std::vector<size_t> jacob = generateJacobsthal(pend.size());
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

    // // Copy back to arr
    // arr = main;
}
