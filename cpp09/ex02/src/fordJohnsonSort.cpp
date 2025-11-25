#include "../headers/fordJohnsonSort.hpp"

// -----------------------------CONSTRUCTORS----------------------------------------

fordJohnsonSort::fordJohnsonSort(int argc, char **argv)
    : iterationResult(0),
      cpu_start(0),
      cpu_end(0),
      comparisonResult(0)
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
    showSequence("Before", result, originalSize);
    sort();
}

fordJohnsonSort::~fordJohnsonSort() {}
// ADD COP AND ASGN CONSTRUCTORS!!

// -----------------------------SORTING FUNCTIONS----------------------------------------

void fordJohnsonSort::sort()
{
    logMessage("", C_YELLOW "FordJohnson Algorythm started" C_RESET);

    // timer starts here - create function?
    gettimeofday(&tv_start, 0);
    cpu_start = std::clock();

    recursion(result);
    // logMessage(LOG, "after sort container!!");

    // timer ends here - create function?
    cpu_end = std::clock();
    gettimeofday(&tv_end, 0);

    logMessage("", C_YELLOW "FordJohnson Algorythm ended" C_RESET);
}

void fordJohnsonSort::recursion(std::vector<int> &recursedSet)
{

    if (recursedSet.size() <= 1) // 1 n does not need to be sorted so recursion stops here
    {
        logMessage(LOG, "???");
        return;
    }
    logMessage(C_GRAY "\n------------ STARTED RECURSION LEVEL:" + asString(iterationResult), "------------\n" C_RESET);


    logMessage(C_YELLOW "Recursion level - moving forward: " C_RESET, asString(iterationResult));
    showSequence("Received container", recursedSet, recursedSet.size());
    PmergeMe currentSet(recursedSet, iterationResult, comparisonResult);
    comparisonResult = currentSet.getCounter(); // update global comparison count as 


    // logMessage("", C_CYAN "FRONT - pair comparison currentSet.count: " C_RESET + asString(currentSet.getCounter()));
    // logMessage("", C_CYAN "FRONT - pair comaprison result: " C_RESET + asString(comparisonResult));
    currentSet.printRecursedSet();

    // currentSet.getContainer() = currentSet.getMain();
    // printChain(currentSet.getContainer(), "CONTAINER AFTER PAIRING:", 0, 0);

    pairingPhase(currentSet);


    insertionPhase(currentSet); // if main

    // Updating global recursedSet and comparison
    recursedSet = currentSet.getMain();
    // currentSet.getContainer() = currentSet.getMain();
    comparisonResult = currentSet.getCounter();
    // printChain(currentSet.getContainer(), "CONTAINER AFTER MERGING:", 0, 0);
}

void fordJohnsonSort::pairingPhase(PmergeMe &recursedSet)
{
    // logMessage("", "Counter: " + asString(recursedSet.getCounter()));

    // recursedSet.printRecursedSet();
    if (recursedSet.getMain().size() > 1)
    {
        logMessage("", "Creating new recursion level..");
        iterationResult++;
        // comparisonResult = recursedSet.getCounter(); // it would not update in other cases, needs to update global

        // logMessage(C_GRAY "\n------------ ENTERED RECURSION LEVEL:" + asString(recursedSet.getRecursionLvl()) , "------------\n" C_RESET);
        recursion(recursedSet.getMain());
    }
    else    
        logMessage("", " -- Recursion stops here! --");

}

void fordJohnsonSort::insertionPhase(PmergeMe &recursedSet)
{
    logMessage(C_YELLOW "Recursion level - moving backward: " C_RESET, asString(recursedSet.getRecursionLvl()));
    std::vector<int> storedMain = recursedSet.getMain(); // storing mainchain to not affect insertion orders
    recursedSet.updatePairing();
    recursedSet.updatePend(); // i use my pairs vector so that pend can match partner from main if it was previously sorted
    recursedSet.getCounter() = comparisonResult; // we need to update based on the previous eneded iteration
    recursedSet.printRecursedSet();
    // logMessage("", C_CYAN "BACK - currentSet count: " C_RESET + asString(recursedSet.getCounter()));
    // logMessage("", C_CYAN "BACK - result count: " C_RESET + asString(comparisonResult));
    // logMessage("", C_CYAN "BACK - currentSet count after: " C_RESET + asString(recursedSet.getCounter()));

    // logMessage(LOG, "updating pend to main");
    // printChain(recursedSet.getContainer(), "CONTANER:", 0, 0);

    // printChain(recursedSet.getMain(), "Previous merge", recursedSet.getRemainderValue(), recursedSet.getRemainderInfo());
    PmergeMe::CountComparisons curr_comparisons(recursedSet.getCounter()); // i might need to initialise this somewhere else?
    for (size_t i = 0; i < recursedSet.getJacobsthal().size(); i++)
    {
        size_t j = recursedSet.getJacobsthal()[i] - 1; // js number - 1 to start from index 0

        // int bigref = recursedSet.getMain()[j]
        std::string message;
        int value = recursedSet.getPend()[j];

        std::vector<int>::iterator partnerPosition;
        int partner;
        
        if (value == recursedSet.getRemainderValue() && j == (recursedSet.getPend().size() - 1))
        {
                //handles test like 5 4 3 1 2 6
                message = "j(" + asString(recursedSet.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of odd < " + asString(value) +  " > to binary insert in mainchain between: " + asString(recursedSet.getMain()[0]) + " to null terminator";
                partnerPosition = recursedSet.getMain().end(); // i pass the null terminator to avoid that 6 is inserted before 5, use this to prove lowerbound function
        }
        else
        {   
            partner = storedMain[j]; // AS MAIN AND PEND ARE ORDERED BASED FROM PAIRS partner is -1 if pend value is odd
            partnerPosition = std::find(recursedSet.getMain().begin(), recursedSet.getMain().end(), partner);
            message = "j(" + asString(recursedSet.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair < " + asString(value) + " , " + asString(partner) + " > to binary insert in mainchain between: " + asString(recursedSet.getMain()[0]) + " to " + asString(partner);
        } // might have a j problem ..

        logMessage("", C_GRAY + message + C_RESET);
        // binary insert checks from the begin of mainchain until partner position(excluded in count as we compare until value < partnerPosition, which is returned by default if value not inserted)
        std::vector<int>::iterator pos = std::lower_bound(recursedSet.getMain().begin(), partnerPosition, value, curr_comparisons);
        recursedSet.getMain().insert(pos, value);
        recursedSet.printChain(recursedSet.getMain(), "Updated Main");
    }
    recursedSet.printChain(recursedSet.getMain(), C_YELLOW "Final sorted Main" C_RESET);
    logMessage(C_GRAY "\n------------ ENDED RECURSION LEVEL:" + asString(recursedSet.recursionLvl), "------------\n" C_RESET);
}

// UTILS

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
    if (!isSorted(result))
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

/* ------------------ Moved former debug utilities ------------------ */

bool isSorted(const std::vector<int> &container)
{
    for (size_t i = 0; i < container.size() - 1; i++)
    {
        if (container[i] > container[i + 1])
            return false;
    }
    return true;
}

bool fordJohnsonSort::isValidNumber(std::string &s, int &conversion)
{
    if (s.empty())
    {
        logMessage(ERROR, "Found empty argument");
        return false;
    }
    if (s[0] == '+') // erases the initial + so that isdigit does not throw error for valid +n numbers
        s.erase(0, 1);

    for (size_t i = 0; i < s.length(); i++) // runs loop inside the string (after first + if found)
    {
        if (!isdigit(s[i])) //
        {
            logMessage(ERROR, "Arguments should be valid positive intergers.");
            return false;
        }
    }

    long bound = atol(s.c_str());
    if (bound > INT_MAX || bound < 0)
    {
        logMessage(ERROR, "Passed argument bigger thant INT_MAX.");
        return false;
    }
    conversion = bound;
    return true;
}

bool fordJohnsonSort::isSorted(const std::vector<int> &container)
{
    for (size_t i = 0; i < container.size() - 1; i++)
    {
        if (container[i] > container[i + 1])
            return false;
    }
    return true;
}

int fordJohnsonSort::maxComparisons(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k)
    {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

void fordJohnsonSort::showSequence(const std::string &state, const std::vector<int> &container, size_t containerSize)
{
    std::cout << state << ": ";
    for (size_t i = 0; i < containerSize; ++i)
    {
        std::cout << container[i];
        if (i < (container.size() - 1))
            std::cout << ", ";
    }
    std::cout << std::endl;
}
