#include "../headers/fordJohnsonSort.hpp"
#include "../headers/PmergeMe.hpp"

void insertionPhase(PmergeMe &set)
{
    logMessage("", "We move backward in the previous recursion...");
    logMessage(C_CYAN "Recursion level: " C_RESET, asString(set.getRecursionLvl()));
    set.containerStatus();

    logMessage(LOG, "updating pend to main");
    set.updatePend(); // match position of partners in main and pend for easy access
    std::vector<int> stored_main = set.getMain();
    set.containerStatus();

    // showContainer(set.getMain(), "Previous merge", set.getRemainderValue(), set.getRemainderInfo());
    PmergeMe::CountComparisons comparisons(set.getCounter()); // i might need to initialise this somewhere else?
    for (size_t i = 0; i < set.getJacobsthal().size(); i++)
    {
        size_t j = set.getJacobsthal()[i] - 1; // js number - 1 to start from index 0

        // int bigref = set.getMain()[j]

        int value = set.getPend()[j];
        int partner = stored_main[j]; // AS MAIN AND PEND ARE ORDERED BASED FROM PAIRS partner is -1 if pend value is odd
        std::vector<int>::iterator partnerPosition;
        std::cout << "< " << value << " , " << partner << " >" << std::endl;
        // if (partner == -1) // means that the number in pend had no partner and it's not in main chain
        //     partnerPosition = set.getMain().end();
        // else
        partnerPosition = std::find(set.getMain().begin(), set.getMain().end(), partner);
        std::string message;
        // if (partner == -1)
        //     message = "j(" + asString(set.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of odd  <   " + asString(value) + "   > to be inserted in main";
        // else
        message = "j(" + asString(set.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair < " + asString(value) + " , " + asString(partner) + " > to be inserted in main";

        showContainer(set.getMain(), C_GRAY + message + C_RESET, set.getRemainderValue(), set.getRemainderInfo());

        // NOTE: FOUND BUG PERHAPS! number at J(1) should always go at beginning of main chain and i should skip the
        // comparison/binary insertion pat and can just add at beggining

        // need to consider the subrange!
        // if()
        // needs to start from higher bound and then move lower no? here it moves from begin to partner position no?
        std::vector<int>::iterator pos = std::lower_bound(set.getMain().begin(), partnerPosition, value, comparisons);
        set.getMain().insert(pos, value);
    }
    // if (set.getRemainderInfo())
    // {
    //     int value = set.getRemainderValue();
    //     // PmergeMe::CountComparisons comparisons(set.getCounter()); // i might need to initialise this somewhere else?
    //     std::vector<int>::iterator pos = std::lower_bound(set.getMain().begin(), set.getMain().end(), value, comparisons);
    //     set.getMain().insert(pos, value);
    // }

    showContainer(set.getMain(), "Current merge", set.getRemainderValue(), set.getRemainderInfo());
    logMessage("", C_CYAN "Current total count: " C_RESET + asString(set.getCounter()));
    if (set.getRecursionLvl() > 0)
        logMessage(C_GRAY "\n------------ EXITED RECURSION LEVEL:" + asString(set.recursionLvl), "------------\n" C_RESET);
}

void pairingPhase(PmergeMe &set, int &iteration, int &comparisons)
{
    (void)comparisons;
    // logMessage("", "Counter: " + asString(set.getCounter()));
    set.containerStatus();
    if (set.getMain().size() > 1)
    {
        logMessage("", "We move forward in the next recursion...");
        iteration++;
        // logMessage(C_GRAY "\n------------ ENTERED RECURSION LEVEL:" + asString(set.getRecursionLvl()) , "------------\n" C_RESET);
        fordJohnsonSort(set.getMain(), iteration, set.getCounter());
    }
}

void fordJohnsonSort(std::vector<int> &input, int &iteration, int &comparisons)
{
    if (input.size() <= 1) // 1 n does not need to be sorted
        return;
    if (iteration > 0)
        logMessage(C_GRAY "\n------------ ENTERED RECURSION LEVEL:" + asString(iteration), "------------\n" C_RESET);
    logMessage(C_CYAN "Recursion level: " C_RESET, asString(iteration));
    showSequence("Received container", input, input.size());
    PmergeMe set(input, iteration, comparisons);
    pairingPhase(set, iteration, comparisons);
    insertionPhase(set); // if main

    // Updating global input and comparison
    input = set.getMain();
    comparisons = set.getCounter();
}