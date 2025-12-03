/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:03:15 by jslusark          #+#    #+#             */
/*   Updated: 2025/12/03 13:03:17 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ------------------------------ CONSTRUCTORS --------------------------------- */

template <template<typename, typename> class Container>
PmergeMe<Container>::PmergeMe(Container<int, std::allocator<int> > &recursedSet,
                              int &iteration,
                              int &comparisons)
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

template <template<typename, typename> class Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container> &other)
    : mergedChains(other.mergedChains),
      pairs(other.pairs),
      main(other.main),
      pend(other.pend),
      jacobsthalAnchors(other.jacobsthalAnchors),
      jacobsthalSequence(other.jacobsthalSequence),
      remainderValue(other.remainderValue),
      has_remainder(other.has_remainder),
      counter(other.counter),
      recursionLvl(other.recursionLvl)
{
}

template <template<typename, typename> class Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &other)
{
    if (this != &other)
    {
        mergedChains       = other.mergedChains;
        pairs              = other.pairs;
        main               = other.main;
        pend               = other.pend;
        jacobsthalAnchors  = other.jacobsthalAnchors;
        jacobsthalSequence = other.jacobsthalSequence;
        remainderValue     = other.remainderValue;
        has_remainder      = other.has_remainder;
        counter            = other.counter;
        recursionLvl       = other.recursionLvl;
    }
    return *this;
}

template <template<typename, typename> class Container>
PmergeMe<Container>::~PmergeMe() {}

/* ------------------------------ PAIR AND CHAIN CREATION --------------------------------- */

template <template<typename, typename> class Container>
void PmergeMe<Container>::createChains()
{
    size_t looplength;
    if (has_remainder)
        looplength = mergedChains.size() - 1;
    else
        looplength = mergedChains.size();
    #if DEBUG_ACTIVE
    logMessage("", C_GRAY "Creating sorted pair info and assigning each partner to its own chain" C_RESET);
    #endif
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

template <template<typename, typename> class Container>
std::pair<int,int> PmergeMe<Container>::orderPair(size_t i)
{
    int min;
    int max;

    min = mergedChains[i];
    max = mergedChains[i + 1];
    counter++;     // comparison increases whenever comparing every number (indipendently if switch is needed or not)
    if (min > max) // swaps content for ascending order
        std::swap(min, max);
    #if DEBUG_ACTIVE
    logMessage("", C_GRAY "Created and compared pair < " + asString(min) + ", " + asString(max) + " >" + C_CYAN + "    Counter:" C_RESET + asString(counter) + C_RESET);
    #endif
    return (std::make_pair(min, max));
}

/* ------------------------------JACOBSTAHL SEQUENCE FUNCTIONS--------------------------------- */

template <template<typename, typename> class Container>
void PmergeMe<Container>::generateJacobsthal() // n is size of pend_chain
{
    size_t pendSize = pend.size();
    findNumbers(pendSize);
    completeSequence(pendSize);
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::findNumbers(size_t pendSize)
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

template <template<typename, typename> class Container>
void PmergeMe<Container>::completeSequence(size_t pendSize)
{
    Container<size_t, std::allocator<size_t> > fill;
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

template <template<typename, typename> class Container>
void PmergeMe<Container>::printJacobstahl(const Container<size_t, std::allocator<size_t> > &jacob)
{
    #if DEBUG_ACTIVE
    std::cout << "Jacobstahl sequence: [ ";
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        std::cout << jacob[i];
        if (i < (jacob.size() - 1))
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
    #else
    (void) jacob;
    #endif
}

/* ------------------------------ JACOBSTAHL BINARY INSERT--------------------------------- */

template <template<typename, typename> class Container>
void PmergeMe<Container>::pleaseMergeMe()
{
    mergedChains = main; // mergedChain will start with the ordered Main, in which we insert the pend numbers 
    #if DEBUG_ACTIVE
    logMessage(C_YELLOW "Moving backward (Recursion level ", asString(recursionLvl) + ")" + C_RESET);
    printChain(mergedChains,"Ordered main");
    printInsertionOrder();
    #endif

    CountComparisons curr_comparisons(counter);

    for (size_t i = 0; i < jacobsthalSequence.size(); i++)
    {
        size_t j = jacobsthalSequence[i] - 1; // js number - 1 as index number starts with 0 
        std::pair<int,int> ref = getPairInfo(j);
        int value = ref.first;
        int partner = ref.second;
        typename Container<int, std::allocator<int> >::iterator partnerPosition = getPartnerPosition(value, partner, jacobsthalSequence[i], j);
        typename Container<int, std::allocator<int> >::iterator insertPosition = std::lower_bound(mergedChains.begin(), partnerPosition, value, curr_comparisons);
        mergedChains.insert(insertPosition, value);
        printChain(mergedChains, C_YELLOW "Merged Chains" C_RESET);
    }

    #if DEBUG_ACTIVE
    logMessage("", C_GRAY "Insertion stops here - all pend numbers are now ordered in main!" C_RESET);
    printChain(mergedChains, C_GREEN "Result (Recursion level " + asString(recursionLvl) +")" C_RESET);
    logMessage(C_LGRAY "\n------------ ENDED RECURSION LEVEL:" + asString(recursionLvl), "------------\n" C_RESET);
    #endif
}



template <template<typename, typename> class Container>
typename Container<int, std::allocator<int> >::iterator
PmergeMe<Container>::getPartnerPosition(int value,
                                        int partner,
                                        int jacobNumber,
                                        int j)
{
    typename Container<int, std::allocator<int> >::iterator partnerPosition;
    std::string message;
    if (partner == -1)
    {
                //handles test like 5 4 3 1 2 6
                message = "j(" + asString(jacobNumber) + ") at pend[" + asString(j) + "]:" + asString(value) + " of odd < " + asString(value) +  " > to binary insert in mainchain between " + asString(main[0]) + " to end of chain";
                partnerPosition = mergedChains.end(); // i pass the null terminator so that all numbers are included in the binary comparison/insert
    }
    else
    {
        partnerPosition = std::find(mergedChains.begin(), mergedChains.end(), partner);
        message = "j(" + asString(jacobNumber) + ") at pend[" + asString(j) + "]:" + asString(value) + " of pair < " + asString(value) + " , " + asString(partner) + " > to binary insert in mainchain between " + asString(main[0]) + " to " + asString(partner);
    }
    #if DEBUG_ACTIVE
    logMessage("", C_GRAY + message + C_RESET);
    #endif
    return partnerPosition;
}


/* ------------------------------ GETTERS AND SETTERS --------------------------------- */

template <template<typename, typename> class Container>
Container<int, std::allocator<int> > &PmergeMe<Container>::getContainer()
{
    return mergedChains;
}

template <template<typename, typename> class Container>
Container<int, std::allocator<int> > &PmergeMe<Container>::getMain()
{
    return main;
}

template <template<typename, typename> class Container>
Container<int, std::allocator<int> > &PmergeMe<Container>::getPend()
{
    return pend;
}

template <template<typename, typename> class Container>
Container<std::pair<int,int>, std::allocator<std::pair<int,int> > > &PmergeMe<Container>::getPairs()
{
    return pairs;
}

template <template<typename, typename> class Container>
Container<size_t, std::allocator<size_t> > &PmergeMe<Container>::getJacobsthal()
{
    return jacobsthalSequence;
}

template <template<typename, typename> class Container>
int &PmergeMe<Container>::getRemainderInfo()
{
    return has_remainder;
}

template <template<typename, typename> class Container>
int &PmergeMe<Container>::getRemainderValue()
{
    return remainderValue;
}

template <template<typename, typename> class Container>
int &PmergeMe<Container>::getCounter()
{
    return counter;
}

template <template<typename, typename> class Container>
int &PmergeMe<Container>::getRecursionLvl()
{
    return recursionLvl;
}

/* ------------------------------ PAIR INFO USED FOR INSERTION --------------------------------- */

template <template<typename, typename> class Container>
std::pair<int,int> PmergeMe<Container>::getPairInfo(size_t jacob)
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

template <template<typename, typename> class Container>
void PmergeMe<Container>::printSetData()
{
    printChain(pend, "Pend Chain");
    printChain(main, "Main Chain");
    printPairs();
    printJacobstahl(jacobsthalAnchors);
    printJacobstahl(jacobsthalSequence);
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::printPairs() const
{
    #if DEBUG_ACTIVE
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
    #endif
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::printChain(const Container<int, std::allocator<int> > &container,
                                     const std::string &name) const
{
    #if DEBUG_ACTIVE
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
    #else
    (void) container;
    (void) name;
    #endif
}

template <template<typename, typename> class Container>
void PmergeMe<Container>::printInsertionOrder()
{
    std::cout << "Pend reference: [";
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
