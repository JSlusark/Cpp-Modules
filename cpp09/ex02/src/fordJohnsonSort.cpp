#include "../headers/fordJohnsonSort.hpp"
#include "../headers/PmergeMe.hpp"

void insertionPhase(PmergeMe &set)
{
    logMessage("", "We backtrack the recursion and use Jacobstahl index and partner info for binary insertion");
    showContainer(set.getMain(), "Previous merge", set.getRemainderValue(), set.getRemainderInfo());
    for (size_t i = 0; i < set.getJacobsthal().size(); i++)
    {
        size_t j = set.getJacobsthal()[i] - 1; // js number - 1 to start from index 0
        int value = set.getPend()[j];
        int partner = set.getPairs()[j].second; // BUG TO FIX: this is invalid if number is odd and not paired!!
        std::vector<int>::iterator partnerPosition;

        if (partner == -1) // means that the number in pend had no partner and it's not in main chain
            partnerPosition = set.getMain().end();
        else
            partnerPosition = std::find(set.getMain().begin(), set.getMain().end(), partner);
        if(partner == -1)
            logMessage("", C_GRAY "j(" + asString(set.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of odd  <   " + asString(value) + "   >" + C_RESET);
        else
            logMessage("", C_GRAY "j(" + asString(set.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair < " + asString(value) + " , " + asString(partner) + " >" + C_RESET);

        PmergeMe::CountComparisons comparisons(set.getComparisonCount());

        // need to consider the subrange!
        std::vector<int>::iterator pos = std::lower_bound(set.getMain().begin(), partnerPosition, value, comparisons);
        set.getMain().insert(pos, value);
    }
    logMessage("", "Comparisons from insertions: " + asString(set.getComparisonCount()));
    showContainer(set.getMain(), "Current merge", set.getRemainderValue(), set.getRemainderInfo());
    logMessage(C_GRAY "\n------------ EXITED RECURSION LEVEL:" + asString(set.recursionID), "------------\n" C_RESET);
}

void pairingPhase(PmergeMe &set, int &iteration, int &comparisons)
{
    logMessage("", "We move forward in the recursion to create pair numbers and divide them in chains");
    logMessage(C_GRAY "\n------------ ENTERED RECURSION LEVEL:" + asString(set.recursionID), "------------\n" C_RESET);
    set.printStatus();
    if (set.getMain().size() > 1)
    {
        iteration++;
        fordJohnsonSort(set.getMain(), iteration, comparisons);
    }
    logMessage("", "Comparisons from pairing: " + asString(set.getComparisonCount()));
}

void fordJohnsonSort(std::vector<int> &input, int &iteration, int &comparisons)
{
    if (input.size() <= 1) // 1 n does not need to be sorted
    return;
    
    PmergeMe set(input, iteration, comparisons);
    pairingPhase(set, iteration, comparisons);
    insertionPhase(set);
    
    // Updating global input and comparison
    input = set.getMain();
    comparisons += set.getComparisonCount();
}