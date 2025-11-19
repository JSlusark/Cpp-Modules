#include "../headers/fordJohnsonSort.hpp"
#include "../headers/PmergeMe.hpp"

void insertionPhase(PmergeMe &set)
{
    logMessage(DEBUG, "Inserting pending elements into main chain via Jacobsthal sequence: " + asString(set.getJacobsthal().size()) + " elements to insert");
    for (size_t i = 0; i < set.getJacobsthal().size(); i++)
    {
        // std::cout << i <<std::endl;
        size_t j = set.getJacobsthal()[i] - 1; // js number - 1 to start from index 0
        int value = set.getPend()[j];
        int partner = set.getPairs()[j].second; // BUG TO FIX: this is invalid if number is odd and not paired!!
        std::vector<int>::iterator partnerPosition;

        if (partner == -1) // means that the number in pend had no partner and it's not in main chain
            partnerPosition = set.getMain().end();
        else
            partnerPosition = std::find(set.getMain().begin(), set.getMain().end(), partner);

        // pair <remainderValue, -1> if it hits remainder value
        logMessage("", C_GRAY "j(" + asString(set.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair <" + asString(value) + ", " + asString(partner) + ">" + C_RESET);

        CountingCompare comp(set.getComparisonCount());
        // need to consider the subrange!
        std::vector<int>::iterator pos = std::lower_bound(set.getMain().begin(), partnerPosition, value, comp);
        set.getMain().insert(pos, value);
    }
    logMessage(DEBUG, "Current number of comparisons: " + asString(set.getComparisonCount()));
    showContainer(set.getMain(), "Sorted:", -1);
    logMessage(C_GRAY "\n------------ EXITED RECURSION LEVEL:" + asString(set.recursionID), "------------\n" C_RESET);
}

void pairingPhase(PmergeMe &set, int &iteration, int &comparisons)
{
    logMessage(C_GRAY "\n------------ ENTERED RECURSION LEVEL:" + asString(set.recursionID), "------------\n" C_RESET);
    set.printStatus();
    if (set.getMain().size() > 2) // recurses until bigchain is 2 numbers - miht p[ut 1?]
    {
        iteration++;
        fordJohnsonSort(set.getMain(), iteration, comparisons);
    }
    else if (set.getMain().size() == 2)
        set.sortPair(); // maybe i do not need this and can call until main is 1 sise and recurse
}

void fordJohnsonSort(std::vector<int> &input, int &iteration, int &comparisons)
{
    // remember to add each set comparisons to the global count
    if (input.size() <= 1) // 1 n does not need to be sorted
        return;

    PmergeMe set(input, iteration, comparisons);
    pairingPhase(set, iteration, comparisons);
    insertionPhase(set);

    // i store and keep the sorted main chain while moving back up the recursion
    input = set.getMain();
    comparisons += set.getComparisonCount();
}