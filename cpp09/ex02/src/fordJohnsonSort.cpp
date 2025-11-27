#include "../headers/fordJohnsonSort.hpp"

/* ------------------ CONSTRUCTORS ------------------ */
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

fordJohnsonSort::fordJohnsonSort(const fordJohnsonSort &other)
    : iterationResult(other.iterationResult),
      result(other.result),
      originalSize(other.originalSize),
      resultSize(other.resultSize),
      cpu_start(other.cpu_start),
      cpu_end(other.cpu_end),
      tv_start(other.tv_start),
      tv_end(other.tv_end),
      comparisonLimit(other.comparisonLimit),
      comparisonResult(other.comparisonResult),
      errorMessage(other.errorMessage)
{
}

fordJohnsonSort &fordJohnsonSort::operator=(const fordJohnsonSort &other)
{
    if (this != &other)
    {
        iterationResult   = other.iterationResult;
        result            = other.result;
        originalSize      = other.originalSize;
        resultSize        = other.resultSize;
        cpu_start         = other.cpu_start;
        cpu_end           = other.cpu_end;
        tv_start          = other.tv_start;
        tv_end            = other.tv_end;
        comparisonLimit   = other.comparisonLimit;
        comparisonResult  = other.comparisonResult;
        errorMessage      = other.errorMessage;
    }
    return *this;
}

fordJohnsonSort::~fordJohnsonSort() {}

/* ------------------ SORTING FUNCTIONS ------------------ */

void fordJohnsonSort::sort()
{
    logMessage("", C_YELLOW "FordJohnson Algorythm started" C_RESET);
    gettimeofday(&tv_start, 0);
    cpu_start = std::clock();

    recursion(result);

    cpu_end = std::clock();
    gettimeofday(&tv_end, 0);
    logMessage("", C_YELLOW "FordJohnson Algorythm ended" C_RESET);
}

void fordJohnsonSort::recursion(std::vector<int> &recursedSet)
{
    if (recursedSet.size() <= 1) // recursion stops here
        return;

    logMessage(C_LGRAY "\n------------ STARTED RECURSION LEVEL:" + asString(iterationResult), "------------\n" C_RESET);
    logMessage(C_YELLOW "Moving forward (Recursion level ", asString(iterationResult) + ")" C_RESET);
    showSequence("Received container", recursedSet, recursedSet.size());

    PmergeMe currentSet(recursedSet, iterationResult, comparisonResult);
    comparisonResult = currentSet.getCounter(); // update global comparison count as 



    pairingPhase(currentSet);
    insertionPhase(currentSet); 

    // Updating global recursedSet and comparison
    recursedSet = currentSet.getMain();
    comparisonResult = currentSet.getCounter();
}

void fordJohnsonSort::pairingPhase(PmergeMe &recursedSet)
{
    if (recursedSet.getMain().size() > 1)
    {
        logMessage("", "Creating new recursion level..");
        iterationResult++;
        recursion(recursedSet.getMain());
    }
    else    
        logMessage("", C_GRAY "Recursion nesting stops here" C_RESET);

}

void fordJohnsonSort::insertionPhase(PmergeMe &recursedSet)
{
    logMessage(C_YELLOW "Moving backward (Recursion level ", asString(recursedSet.getRecursionLvl()) + ")" + C_RESET);
    std::vector<int> storedMain = recursedSet.getMain(); // storing mainchain to not affect insertion orders
    recursedSet.getCounter() = comparisonResult; // we need to update based on the previous eneded iteration
    recursedSet.printChain(storedMain, C_YELLOW "Main:" C_RESET);
    recursedSet.printInsertionOrder();
    PmergeMe::CountComparisons curr_comparisons(recursedSet.getCounter()); // i might need to initialise this somewhere else?

    for (size_t i = 0; i < recursedSet.getJacobsthal().size(); i++)
    {
        size_t j = recursedSet.getJacobsthal()[i] - 1; // js number - 1 to start from index 0
        std::pair<int,int> ref = recursedSet.getPairInfo(j, storedMain);
        int value = ref.first;
        int partner = ref.second;
        std::vector<int>::iterator partnerPosition;
        std::string message;

        if (partner == -1)
        {
                //handles test like 5 4 3 1 2 6
                message = "j(" + asString(recursedSet.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of odd < " + asString(value) +  " > to binary insert in mainchain between " + asString(recursedSet.getMain()[0]) + " to end of chain";
                partnerPosition = recursedSet.getMain().end(); // i pass the null terminator to avoid that 6 is inserted before 5, use this to prove lowerbound function
        }
        else
        {   
            partnerPosition = std::find(recursedSet.getMain().begin(), recursedSet.getMain().end(), partner);
            message = "j(" + asString(recursedSet.getJacobsthal()[i]) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair < " + asString(value) + " , " + asString(partner) + " > to binary insert in mainchain between " + asString(recursedSet.getMain()[0]) + " to " + asString(partner);
        } // might have a j problem, check later!!

        logMessage("", C_GRAY + message + C_RESET);
        // binary insert checks from the begin of mainchain until partner position(excluded in count as we compare until value < partnerPosition, which is returned by default if value not inserted)
        std::vector<int>::iterator pos = std::lower_bound(recursedSet.getMain().begin(), partnerPosition, value, curr_comparisons);
        recursedSet.getMain().insert(pos, value);
        recursedSet.printChain(recursedSet.getMain(), C_YELLOW "Updated Main" C_RESET);
    }
    
    logMessage("", C_GRAY "Insertion stops here - all pend numbers are now ordered in main!" C_RESET);
    recursedSet.printChain(recursedSet.getMain(), C_GREEN "Sorted Main (Recursion level " + asString(recursedSet.recursionLvl) +")" C_RESET);
    logMessage(C_LGRAY "\n------------ ENDED RECURSION LEVEL:" + asString(recursedSet.recursionLvl), "------------\n" C_RESET);
}



/* ------------------ PRINT DEBUG ------------------ */


void fordJohnsonSort::showSequence(const std::string &state, const std::vector<int> &container, size_t containerSize)
{
    std::cout << state << ": [ ";
    for (size_t i = 0; i < containerSize; ++i)
    {
        std::cout << container[i];
        if (i < (container.size() - 1))
            std::cout << ", ";
    }   
    std::cout << " ]" << std::endl;
}


/* ------------------ RESULT CHECKING ------------------ */

void fordJohnsonSort::showResult()
{
    resultSize = result.size(); // to make sure the insertion part did not skip any number in the way
    showSequence("After", result, resultSize);
    if (wrongResult())
    {
            // std::cout << "comparisons=" << comparisonResult << std::endl; // uncomment for tester
            throw std::runtime_error("Wrong result: " + errorMessage);
    }
    else
    {
        double cpu_micro_double = (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC * 1e6;
        std::ostringstream cpuFmt;
        cpuFmt.setf(std::ios::fixed);
        cpuFmt << std::setprecision(5) << cpu_micro_double;

        logMessage(SUCCESS, "Container was successfully sorted in " + asString(iterationResult) + " iterationResult and in " + C_GREEN + asString(comparisonResult) + C_RESET + "/" + asString(comparisonLimit) + " comparison count." C_RESET);
        logMessage(LOG, C_CYAN "Time taken to process " + asString(resultSize) +
                            " elements: " + cpuFmt.str() + " us" C_RESET);
    }
}

bool fordJohnsonSort::wrongResult()
{
    if (originalSize != resultSize)
    {
        errorMessage = "Container size was not preserved after sorting! Size before sort: " + asString(resultSize) + ", Size after sort: " + asString(resultSize);
        return true;
    }
    if (comparisonResult > comparisonLimit)
    {
        errorMessage = "Container was sorted but exceeded comparison limit for container of " + asString(resultSize) + " numbers: " C_RED + asString(comparisonResult) + C_RESET + "/" + asString(comparisonLimit) + ")!";
        return true;
    }
    if (!isSorted(result))
    {
        errorMessage = "Container is was not sorted correctly!";
        return true;
    }

    return 0;
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

/* ------------------ RESULT CHECKING ------------------ */
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