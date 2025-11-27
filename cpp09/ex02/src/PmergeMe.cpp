#include "../headers/PmergeMe.hpp"

/* ------------------------------ CONSTRUCTORS --------------------------------- */
PmergeMe::PmergeMe(std::vector<int> numbers, int &iteration, int &comparisons)
    : storedValues(numbers),
      remainderValue(-1),
      has_remainder(0),
      counter(comparisons),
      recursionLvl(iteration)
{
    has_remainder = (storedValues.size() % 2 != 0); // if remainder is not 0 has_remainder is true
    if (has_remainder)
        remainderValue = storedValues.back();
    // this->storedValuesStatus();
    createChains();
    pendSize = pend.size();
    generateJacobsthal();

    printSetData();
};

PmergeMe::PmergeMe(const PmergeMe &other)
    : storedValues(other.storedValues),
      pairs(other.pairs),
      main(other.main),
      pend(other.pend),
      pendSize(other.pendSize),
      jacobsthal(other.jacobsthal),
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
        storedValues   = other.storedValues;
        pairs          = other.pairs;
        main           = other.main;
        pend           = other.pend;
        pendSize       = other.pendSize;
        jacobsthal     = other.jacobsthal;
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
        looplength = storedValues.size() - 1;
    else
        looplength = storedValues.size();
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

    min = storedValues[i];
    max = storedValues[i + 1];
    counter++;     // comparison increases whenever comapring every number, not only at switch!!!
    if (min > max) // swaps content for ascending order
        std::swap(min, max); // could do the swap later?
    logMessage("", C_GRAY "Created and compared pair < " + asString(min) + ", " + asString(max) + " >" + C_CYAN + "    Counter:" C_RESET + asString(counter) + C_RESET);
    return (std::make_pair(min, max));
}

/* ------------------------------JACOBSTAHL SEQUENCE FUNCTIONS--------------------------------- */
void PmergeMe::generateJacobsthal() // n is size of pend_chain
{
    findNumbers();
    completeSequence();
}

void PmergeMe::findNumbers()
{
    if (pendSize == 0 || pendSize == 1) // added it to avoid weird behavioru in loop (0 - 1 or 1 - 2)
    {
        jacobsthal.push_back(pendSize); // starts with 0 or 1 depending on pend size
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
            jacobsthal.push_back(j);
        j2 = j1;
        j1 = j;
    }
}

void PmergeMe::completeSequence()
{
    std::vector<size_t> fill;
    for (size_t i = 0; i < jacobsthal.size(); i++)
    {
        if (i == 0)
        {
            fill.push_back(jacobsthal[i]);
            continue;
        }
        size_t a = jacobsthal[i - 1]; // prev
        size_t b = jacobsthal[i];     // curr

        for (size_t n = b; n > a; n--)
            fill.push_back(n);
    }
    if (pendSize > jacobsthal.back())
    {
        size_t a = jacobsthal.back(); // prev
        size_t b = pendSize;          // curr
        for (size_t n = b; n > a; n--)
            fill.push_back(n);
    }
    // printChain(fill, "Order", -1);
    jacobsthal = fill; // overwrite the jacobstahl with the filled
}

/* ------------------------------ GETTERS AND SETTERS --------------------------------- */
std::vector<int> &PmergeMe::getContainer()
{
    return storedValues;
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
    return jacobsthal;
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

std::pair<int, int> PmergeMe::getPairInfo(size_t jacob, std::vector<int> orderedMain)
{
    // std::cout << "Ordered size:" << orderedMain.size() << " Jacob index:" << jacob << " Main found:" << orderedMain[jacob] << std::endl;
    if (jacob < orderedMain.size()) // if main[j] does not exist, it means we have to call the remainder if exists
    {
        int to_search = orderedMain[jacob]; // main[j] will call the main number based on jacobstahl

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
    printJacobstahl();
}

void PmergeMe::printJacobstahl()
{
    std::cout << "Jacobstahl sequence: [ ";
    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        std::cout << jacobsthal[i];
        if (i < (jacobsthal.size() - 1))
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
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
