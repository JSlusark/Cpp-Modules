#include "../headers/fordJohnsonSort.hpp"

void fordJohnsonSort::insertionPhase(PmergeMe &recursed_container)
{
    logMessage("", "We move backward in the previous recursion...");
    logMessage(C_CYAN "Recursion level: " C_RESET, asString(recursed_container.getRecursionLvl()));
    recursed_container.containerStatus();

    logMessage(LOG, "updating pend to main");
    recursed_container.updatePend(); // match position of partners in main and pend for easy access
    std::vector<int> stored_main = recursed_container.getMain();
    recursed_container.containerStatus();

    // showContainer(recursed_container.getMain(), "Previous merge", recursed_container.getRemainderValue(), recursed_container.getRemainderInfo());
    PmergeMe::CountComparisons curr_comparisons(recursed_container.getCounter()); // i might need to initialise this somewhere else?
    for (size_t i = 0; i < recursed_container.getJacobsthal().size(); i++)
    {
        size_t j = recursed_container.getJacobsthal()[i] - 1; // js number - 1 to start from index 0

        // int bigref = recursed_container.getMain()[j]

        int value = recursed_container.getPend()[j];
        int partner = stored_main[j]; // AS MAIN AND PEND ARE ORDERED BASED FROM PAIRS partner is -1 if pend value is odd
        std::vector<int>::iterator partnerPosition;
        std::cout << "< " << value << " , " << partner << " >" << std::endl;
        // if (partner == -1) // means that the number in pend had no partner and it's not in main chain
        //     partnerPosition = recursed_container.getMain().end();
        // else
        partnerPosition = std::find(recursed_container.getMain().begin(), recursed_container.getMain().end(), partner);
        std::string message;
        // if (partner == -1)
        //     message = "j(" + asString(recursed_container.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of odd  <   " + asString(value) + "   > to be inserted in main";
        // else
        message = "j(" + asString(recursed_container.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair < " + asString(value) + " , " + asString(partner) + " > to be inserted in main";

        showContainer(recursed_container.getMain(), C_GRAY + message + C_RESET, recursed_container.getRemainderValue(), recursed_container.getRemainderInfo());

        // NOTE: FOUND BUG PERHAPS! number at J(1) should always go at beginning of main chain and i should skip the
        // comparison/binary insertion pat and can just add at beggining

        // need to consider the subrange!
        // if()
        // needs to start from higher bound and then move lower no? here it moves from begin to partner position no?
        std::vector<int>::iterator pos = std::lower_bound(recursed_container.getMain().begin(), partnerPosition, value, curr_comparisons);
        recursed_container.getMain().insert(pos, value);
    }
    // if (recursed_container.getRemainderInfo())
    // {
    //     int value = recursed_container.getRemainderValue();
    //     // PmergeMe::CountComparisons curr_comparisons(recursed_container.getCounter()); // i might need to initialise this somewhere else?
    //     std::vector<int>::iterator pos = std::lower_bound(recursed_container.getMain().begin(), recursed_container.getMain().end(), value, curr_comparisons);
    //     recursed_container.getMain().insert(pos, value);
    // }

    showContainer(recursed_container.getMain(), "Current merge", recursed_container.getRemainderValue(), recursed_container.getRemainderInfo());
    logMessage("", C_CYAN "Current total count: " C_RESET + asString(recursed_container.getCounter()));
    if (recursed_container.getRecursionLvl() > 0)
        logMessage(C_GRAY "\n------------ EXITED RECURSION LEVEL:" + asString(recursed_container.recursionLvl), "------------\n" C_RESET);
}

void fordJohnsonSort::pairingPhase(PmergeMe &recursed_container, int &recursed_iteration, int &recursed_count)
{
    (void)recursed_count;
    logMessage("", "Counter: " + asString(recursed_container.getCounter()));
    recursed_container.containerStatus();
    if (recursed_container.getMain().size() > 1)
    {
        logMessage("", "We move forward in the next recursion...");
        recursed_iteration++;
        // logMessage(C_GRAY "\n------------ ENTERED RECURSION LEVEL:" + asString(recursed_container.getRecursionLvl()) , "------------\n" C_RESET);
        sortContainer(recursed_container.getMain(), recursed_iteration, recursed_container.getCounter());
    }
}

void fordJohnsonSort::sortContainer(std::vector<int> &recursed_container, int &recursed_iteration, int &recursed_count)
{
    if (recursed_container.size() <= 1) // 1 n does not need to be sorted
    {
        logMessage(LOG, "???");
        return;
    }
    if (recursed_iteration > 0)
        logMessage(C_GRAY "\n------------ ENTERED RECURSION LEVEL:" + asString(recursed_iteration), "------------\n" C_RESET);
    logMessage(C_CYAN "Recursion level: " C_RESET, asString(recursed_iteration));
    showSequence("Received container", recursed_container, recursed_container.size());
    PmergeMe set(recursed_container, recursed_iteration, recursed_count);
    pairingPhase(set, recursed_iteration, recursed_count);
    insertionPhase(set); // if main

    // Updating global recursed_container and comparison
    recursed_container = set.getMain();
    recursed_count = set.getCounter();
}


// -----------------------------CLASS FUNCTION-----------------------------------------

fordJohnsonSort::fordJohnsonSort(int argc, char **argv, std::vector<int> received_container) // vect will me a template later
    : iterationResult(0),
      comparisonResult(0),
      result(received_container),
      cpu_start(0),
      cpu_end(0)
{
    for (int i = 1; i < argc; ++i)
    {
        int conversion;
        std::string s = argv[i];
        if (!isValidNumber(s, conversion))
            throw std::runtime_error("Invalid argument: " + s);
        result.push_back(conversion);
    }
    originalSize = result.size();
    comparisonLimit = maxComparisons(originalSize);
    comparisonLimit = maxComparisons(originalSize);
    showSequence("Before", result, originalSize);
}

fordJohnsonSort::~fordJohnsonSort() {}

void fordJohnsonSort::startSorting()
{
    logMessage("", C_YELLOW "FordJohnson Algorythm started" C_RESET);

    // timer starts here - create function?
    gettimeofday(&tv_start, 0);
    cpu_start = std::clock();

    showSequence("before sort", result, originalSize);
    sortContainer(result, iterationResult, comparisonResult);
    // logMessage(LOG, "after sort container!!");


    // timer ends here - create function?
    cpu_end = std::clock();
    gettimeofday(&tv_end, 0);

    logMessage("", C_YELLOW "FordJohnson Algorythm ended" C_RESET);
}

int fordJohnsonSort::wrongResult()
{
    if (originalSize != resultSize)
    {
        errorMessage = "Container size was not preserved after sorting! Size before sort: " + asString(resultSize) + ", Size after sort: " + asString(resultSize);
        return 1;
    }
    if (comparisonResult > comparisonLimit)
    {
        errorMessage = "Container was sorted but exceeded comparison limit for container of " + asString(resultSize) + " numbers: " C_RED + asString(comparisonResult) + C_RESET + "/" + asString(comparisonLimit) + ")!";
        return 1;
    }
    if (!is_sorted(result))
    {
        errorMessage = "Container is was not sorted correctly!";
        return 1;
    }

    return 0;
}

void fordJohnsonSort::showResult()
{
    resultSize = result.size(); // to make sure the insertion part did not skip any number in the way
    showSequence("After", result, resultSize);
    if (wrongResult()) // i dont want to trhow error as the code went as expected but if this hits it means that the algo failed
        logMessage(ERROR, errorMessage);
    else
    {
        // convert time?
        double cpu_micro_double = (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC * 1e6;
        std::ostringstream cpuFmt;
        cpuFmt.setf(std::ios::fixed);
        cpuFmt << std::setprecision(5) << cpu_micro_double;

        logMessage(SUCCESS, "Container was successfully sorted in " + asString(iterationResult) + " iterationResult and in " + C_GREEN + asString(comparisonResult) + C_RESET + "/" + asString(comparisonLimit) + " comparison count." C_RESET);
        logMessage(LOG, C_CYAN "Time taken to process " + asString(resultSize) +
                            " elements: " + cpuFmt.str() + " us" C_RESET);
    }
}
