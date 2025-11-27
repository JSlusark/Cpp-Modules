#include "../headers/PmergeMe.hpp"

/* ------------------------------ CONSTRUCTORS --------------------------------- */
PmergeMe::PmergeMe(std::vector<int> &recursedSet, int &iteration, int &comparisons)
    : mergedChains(recursedSet),
      remainderValue(-1),
      has_remainder(0),
      counter(comparisons),
      recursionLvl(iteration)
{
    has_remainder = (mergedChains.size() % 2 != 0); // if remainder is not 0 has_remainder is true
    if (has_remainder)
        remainderValue = mergedChains.back();
    createChains();
    generateJacobsthal();
    printSetData();
};

PmergeMe::PmergeMe(const PmergeMe &other)
    : mergedChains(other.mergedChains),
      pairs(other.pairs),
      main(other.main),
      pend(other.pend),
      jacobsthalSequence(other.jacobsthalSequence),
      remainderValue(other.remainderValue),
      has_remainder(other.has_remainder),
      counter(other.counter),
      recursionLvl(other.recursionLvl)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        mergedChains   = other.mergedChains;
        pairs          = other.pairs;
        main           = other.main;
        pend           = other.pend;
        jacobsthalSequence     = other.jacobsthalSequence;
        remainderValue = other.remainderValue;
        has_remainder  = other.has_remainder;
        counter        = other.counter;
        recursionLvl   = other.recursionLvl;
    }
    return *this;
}


PmergeMe::~PmergeMe() {};

/* ------------------------------PAIR AND CHAIN CREATION--------------------------------- */
void PmergeMe::createChains()
{
    size_t looplength;
    if (has_remainder)
        looplength = mergedChains.size() - 1;
    else
        looplength = mergedChains.size();
    logMessage("", C_GRAY "Creating sorted pair info and assigning each partner to its own chain" C_RESET);
    for (size_t i = 0; i < looplength; i += 2) // we proceed by 2n at a time (pairs duh)
    {
        std::pair<int, int> newPair = orderPair(i);
        pairs.push_back(newPair);
        main.push_back(newPair.second);
        pend.push_back(newPair.first); // adding all min value, including odd number
    }
    if (has_remainder)
        pend.push_back(remainderValue); // adding all min value, including odd number
}

std::pair<int, int> PmergeMe::orderPair(size_t i)
{
    int min;
    int max;

    min = mergedChains[i];
    max = mergedChains[i + 1];
    counter++;     // comparison increases whenever comapring every number, not only at switch!!!
    if (min > max) // swaps content for ascending order
        std::swap(min, max); // could do the swap later?
    logMessage("", C_GRAY "Created and compared pair < " + asString(min) + ", " + asString(max) + " >" + C_CYAN + "    Counter:" C_RESET + asString(counter) + C_RESET);
    return (std::make_pair(min, max));
}

/* ------------------------------JACOBSTAHL SEQUENCE FUNCTIONS--------------------------------- */
void PmergeMe::generateJacobsthal() // n is size of pend_chain
{
    size_t pendSize = pend.size();
    findNumbers(pendSize);
    completeSequence(pendSize);
}

void PmergeMe::findNumbers(size_t pendSize)
{
    if (pendSize == 0 || pendSize == 1) // added it to avoid weird behavioru in loop (0 - 1 or 1 - 2)
    {
        jacobsthalSequence.push_back(pendSize); // starts/ends with 0 or 1 depending on pend size
        return;
    }
    size_t j = 0;
    size_t j1 = 1;                        // n - 1 (prev)
    size_t j2 = 0;                        // n - 2 (prev_prev)
    for (size_t i = 0; j < pendSize; i++) // jacobstahl number has to be < than pendSize
    {
        /* J(n) = J(n-1) + 2 * J(n-2)  */
        j = (j1) + (2 * (j2));
        if (j < pendSize) // adds only if result of j number is < size
            jacobsthalSequence.push_back(j);
        j2 = j1;
        j1 = j;
    }
    jacobsthalAnchors = jacobsthalSequence; // stored for printing 
}

void PmergeMe::completeSequence(size_t pendSize)
{
    std::vector<size_t> fill;
    for (size_t i = 0; i < jacobsthalSequence.size(); i++)
    {
        if (i == 0)
        {
            fill.push_back(jacobsthalSequence[i]);
            continue;
        }
        size_t a = jacobsthalSequence[i - 1]; // prev
        size_t b = jacobsthalSequence[i];     // curr

        for (size_t n = b; n > a; n--)
            fill.push_back(n);
    }
    if (pendSize > jacobsthalSequence.back())
    {
        size_t a = jacobsthalSequence.back(); // prev
        size_t b = pendSize;          // curr
        for (size_t n = b; n > a; n--)
            fill.push_back(n);
    }
    jacobsthalSequence = fill; // overwrite the jacobstahl with the filled
}

void PmergeMe::printJacobstahl(std::vector<size_t> jacob)
{
    std::cout << "Jacobstahl sequence: [ ";
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        std::cout << jacob[i];
        if (i < (jacob.size() - 1))
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

/* ------------------------------ JACOBSTAHL BINARY INSERT--------------------------------- */

void PmergeMe::pleaseMergeMe()
{
    logMessage(C_YELLOW "Moving backward (Recursion level ", asString(recursionLvl) + ")" + C_RESET);
    mergedChains = main; // as main will not change we make sortedvalues as a copy and insert in there
    printChain(mergedChains, C_YELLOW "Sorted main" C_RESET);
    printInsertionOrder();
    PmergeMe::CountComparisons curr_comparisons(counter); // i might need to initialise this somewhere else?

    for (size_t i = 0; i < jacobsthalSequence.size(); i++)
    {
        size_t j = jacobsthalSequence[i] - 1; // js number - 1 to start from index 0
        std::pair<int,int> ref = getPairInfo(j);
        int value = ref.first;
        int partner = ref.second;
        std::vector<int>::iterator partnerPosition = getPartnerPosition(value, partner, jacobsthalSequence[i], j);
        std::vector<int>::iterator insertPosition = std::lower_bound(mergedChains.begin(), partnerPosition, value, curr_comparisons);
        mergedChains.insert(insertPosition, value);
        printChain(mergedChains, C_YELLOW "Merged Chains" C_RESET);
    }
    
    logMessage("", C_GRAY "Insertion stops here - all pend numbers are now ordered in main!" C_RESET);
    printChain(mergedChains, C_GREEN "Sorted Main (Recursion level " + asString(recursionLvl) +")" C_RESET);
    logMessage(C_LGRAY "\n------------ ENDED RECURSION LEVEL:" + asString(recursionLvl), "------------\n" C_RESET);
}


std::vector<int>::iterator PmergeMe::getPartnerPosition(int value, int partner, int jacobNumber, int j)
{
        std::vector<int>::iterator partnerPosition;
        std::string message;
        if (partner == -1)
        {
                //handles test like 5 4 3 1 2 6
                message = "j(" + asString(jacobNumber) + ") at pend[" + asString(j) + "]:" + asString(value) + " of odd < " + asString(value) +  " > to binary insert in mainchain between " + asString(main[0]) + " to end of chain";
                partnerPosition = mergedChains.end(); // i pass the null terminator to avoid that 6 is inserted before 5, use this to prove lowerbound function
        }
        else
        {   
            partnerPosition = std::find(mergedChains.begin(), mergedChains.end(), partner);
            message = "j(" + asString(jacobNumber) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair < " + asString(value) + " , " + asString(partner) + " > to binary insert in mainchain between " + asString(main[0]) + " to " + asString(partner);
        } // might have a j problem, check later!!
        logMessage("", C_GRAY + message + C_RESET);
        return partnerPosition;
}


/* ------------------------------ GETTERS AND SETTERS --------------------------------- */
std::vector<int> &PmergeMe::getContainer()
{
    return mergedChains;
}

std::vector<int> &PmergeMe::getMain()
{
    return main;
}

std::vector<int> &PmergeMe::getPend()
{
    return pend;
}

std::vector<std::pair<int, int> > &PmergeMe::getPairs()
{
    return pairs;
}

std::vector<size_t> &PmergeMe::getJacobsthal()
{
    return jacobsthalSequence;
}

int &PmergeMe::getRemainderInfo()
{
    return has_remainder;
}

int &PmergeMe::getRemainderValue()
{
    return remainderValue;
}

int &PmergeMe::getCounter()
{
    return counter;
}
int &PmergeMe::getRecursionLvl()
{
    return recursionLvl;
}

/* ------------------------------ PAIR INFO USED FOR INSERTION --------------------------------- */

std::pair<int, int> PmergeMe::getPairInfo(size_t jacob)
{
    // std::cout << "Ordered size:" << main.size() << " Jacob index:" << jacob << " Main found:" << main[jacob] << std::endl;
    if (jacob < main.size()) // if main[j] does not exist, it means we have to call the remainder if exists
    {
        int to_search = main[jacob]; // main[j] will call the main number based on jacobstahl

        for (size_t i = 0; i < pairs.size(); ++i)
        {
            if (pairs[i].second == to_search)
                return pairs[i]; // returns the pair info so we can insert the correct pend
        }
    }
    else
    {
        if (has_remainder) // if remainder exists we return it with dummy value
            return std::make_pair(remainderValue, -1);
        throw std::runtime_error(ERROR " getPairInfo(): Jacob index out of range and no remainder"); // else we have an aeeror
    }
    throw std::runtime_error(ERROR " getPairInfo(): No matching pair found");
}

/* ------------------------------ SHOW SET INFO --------------------------------- */

void PmergeMe::printSetData()
{
    printChain(pend, "Pend Chain");
    printChain(main, "Main Chain");
    printPairs();
    printJacobstahl(jacobsthalAnchors);
    printJacobstahl(jacobsthalSequence);
}


void PmergeMe::printPairs() const
{
    std::cout << "Pairs data:" << " [";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << " <" << /* C_MAGENTA  <<*/ pairs[i].first << C_RESET << "," << pairs[i].second << "> ";
        if (i < (pairs.size() - 1))
            std::cout << ",";
    }
    if (has_remainder) // just printing for view but it is not included in pairing as useless there
        std::cout << ", " C_RED "<" << remainderValue << "> " C_RESET;
    std::cout << "]" << std::endl;
}

void PmergeMe::printChain(const std::vector<int> &container, const std::string &name) const
{
    // logMessage(DEBUG, "remainderValue:'" + asString(remainderValue) + "'   hasRemainder:'" + asString(has_remainder) + "' ");
    std::cout << name << ":" << C_RESET << " [ ";
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (has_remainder && (container[i] == remainderValue))
            std::cout << C_RED << container[i] << C_RESET;
        else
            std::cout << container[i];

        if (i < (container.size() - 1))
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

// instead should i just update it after new pairs are sorted?
void PmergeMe::printInsertionOrder()
{
    std::cout << "Pend Reference: [";
    for (size_t i = 0; i < main.size(); ++i)
    {
        int big = main[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == big)
                std::cout << pairs[j].first;
            };
        if (i < (pairs.size() -1))
            std::cout << ", ";
    }

    if (has_remainder)
                std::cout << ", " C_RED<< remainderValue << C_RESET;
    std::cout << "]" <<std::endl;

    std::vector<std::pair<int, int> > updatedPairs;
    // Rebuild pairs in the order of the updated main chain
    std::cout << "Pairs reference: [ ";
    for (size_t i = 0; i < main.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == main[i])
            {
                std::cout << "< " << pairs[j].first << "," << pairs[j].second << " >";
            }
        }
        if (i < (main.size() - 1))
            std::cout << ", ";
    }
    if (has_remainder)
        std::cout << ", < " C_RED << remainderValue << C_RESET" >";
    std::cout << " ]" << std::endl;
}
