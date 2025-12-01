/* ------------------ CONSTRUCTORS ------------------ */
template <template<typename, typename> class Container>
FordJohnsonSort<Container>::FordJohnsonSort(int argc, char **argv, Container<int, std::allocator<int> > container)
    :cpu_start(0),
    cpu_end(0),
    result(container),
    comparisonResult(0),
    iterationResult(0)
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
    printResult("Before", result, originalSize);
    sort();
}

template <template<typename, typename> class Container>
FordJohnsonSort<Container>::FordJohnsonSort(const FordJohnsonSort<Container> &other)
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

template <template<typename, typename> class Container>
FordJohnsonSort<Container> &FordJohnsonSort<Container>::operator=(const FordJohnsonSort<Container> &other)
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

template <template<typename, typename> class Container>
FordJohnsonSort<Container>::~FordJohnsonSort() {}

/* ------------------ SORTING: SORTS THE IN RECURSIVE SETS ------------------ */

template <template<typename, typename> class Container>
void FordJohnsonSort<Container>::sort()
{
    #if DEBUG_ACTIVE
    logMessage("", C_YELLOW "FordJohnson Algorythm started" C_RESET);
    #endif

    gettimeofday(&tv_start, 0);
    cpu_start = std::clock();

    recursion(result);

    cpu_end = std::clock();
    gettimeofday(&tv_end, 0);
    
    #if DEBUG_ACTIVE
    logMessage("", C_YELLOW "FordJohnson Algorythm ended" C_RESET);
    #endif
    
    checkResult();
}

template <template<typename, typename> class Container>
void FordJohnsonSort<Container>::recursion(Container<int, std::allocator<int> > &recursedSet)
{
    if (recursedSet.size() <= 1) // recursion stops here
        return;

    #if DEBUG_ACTIVE
    logMessage(C_LGRAY "\n------------ STARTED RECURSION LEVEL:" + asString(iterationResult), "------------\n" C_RESET);
    logMessage(C_YELLOW "Moving forward (Recursion level ", asString(iterationResult) + ")" C_RESET);
    printResult("Received container", recursedSet, recursedSet.size());
    #endif

    PmergeMe<Container> newSet(recursedSet, iterationResult, comparisonResult);
    
    if (newSet.getMain().size() > 1)
    {
        #if DEBUG_ACTIVE
        logMessage("", "Creating new recursion level..");
        #endif
        iterationResult++;
        recursion(newSet.getMain());
    }
    else    
    {
        #if DEBUG_ACTIVE
        logMessage("", C_GRAY "Recursion nesting stops here" C_RESET);
        #endif
    }
    
    newSet.pleaseMergeMe();
}

/* ------------------ UTILITY FUNCTIONS ------------------ */

template <template<typename, typename> class Container>
void FordJohnsonSort<Container>::checkResult()
{
    resultSize = result.size(); // to make sure the insertion part did not skip any number in the way
    printResult("After", result, resultSize);
    if (wrongResult())
            throw std::runtime_error("Wrong result: " + errorMessage);
    else
    {
        double cpu_micro_double = (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC * 1e6;
        std::ostringstream cpuFmt;
        cpuFmt.setf(std::ios::fixed);
        cpuFmt << std::setprecision(5) << cpu_micro_double;

        logMessage(LOG,  "Time taken to process " + asString(resultSize) +
                            " elements: " + cpuFmt.str() + " us" );
        logMessage(SUCCESS, "Container was successfully sorted in " + asString(iterationResult) + " iterationResult and in " + C_GREEN + asString(comparisonResult) + C_RESET + "/" + asString(comparisonLimit) + " comparison count." C_RESET);
    }
}

template <template<typename, typename> class Container>
bool FordJohnsonSort<Container>::wrongResult()
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

template <template<typename, typename> class Container>
bool FordJohnsonSort<Container>::isSorted(const Container<int, std::allocator<int> > &container)
{
    for (size_t i = 0; i < container.size() - 1; i++)
    {
        if (container[i] > container[i + 1])
            return false;
    }
    return true;
}

template <template<typename, typename> class Container>
int FordJohnsonSort<Container>::maxComparisons(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k)
    {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

/* ------------------ ARG CHECKING ------------------ */
template <template<typename, typename> class Container>
bool FordJohnsonSort<Container>::isValidNumber(std::string &s, int &conversion)
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

/* ------------------ PRINT DEBUG ------------------ */

template <template<typename, typename> class Container>
void FordJohnsonSort<Container>::printResult(const std::string &state, const Container<int, std::allocator<int> > &container, size_t containerSize)
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