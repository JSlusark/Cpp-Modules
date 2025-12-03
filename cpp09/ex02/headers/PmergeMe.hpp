/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:02:11 by jslusark          #+#    #+#             */
/*   Updated: 2025/12/03 13:02:33 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "./debug.hpp"
#include <vector>
#include <deque>
#include <utility>
#include <stdexcept>

/* 
    Pmerge me is a class that stores each recursion info of the FordJohnson class.
    A new class object is created at everr recursion level and destoyed
    once the level ended its course (passing it's data on its preceeding recursion level until its copied
    to the final result of its corresponding FordJohnson initiator)
*/

template <template<typename, typename> class Container>
class PmergeMe
{
private:
    Container<int, std::allocator<int> > &mergedChains; // container to sort, passed as ref and changes
    Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > pairs; // preserve relationship between pairs
    Container<int, std::allocator<int> > main;   // bigger values container
    Container<int, std::allocator<int> > pend;   // smaller values container
    Container<size_t, std::allocator<size_t> > jacobsthalAnchors;
    Container<size_t, std::allocator<size_t> > jacobsthalSequence;

    int remainderValue;
    int has_remainder;
    int &counter; // counts amount of comparisons

    void createChains();
    std::pair<int, int> orderPair(size_t i);

    /* ------------------------------JACOBSTHAL SEQUENCE FUNCTIONS--------------------------------- */
    void generateJacobsthal();
    void findNumbers(size_t pendSize);
    void completeSequence(size_t pendSize);

public:
    int recursionLvl;

    struct CountComparisons
    {
        int &counter;
        CountComparisons(int &c) : counter(c) {}
        bool operator()(int a, int b)
        {
            counter++;
            #if DEBUG_ACTIVE
            logMessage("", C_GRAY "Compared " + asString(b) + " with " + asString(a) + C_CYAN "   Counter: " C_RESET + asString(counter));
            #endif
            return a < b;
        }
    };

    /* ------------------ CONSTRUCTORS ------------------ */
    PmergeMe(Container<int, std::allocator<int> > &recursedSet, int &iteration, int &comparisons);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    /* ------------------------------ MERGE INSERTION --------------------------------- */
    void pleaseMergeMe();

    typename Container<int, std::allocator<int> >::iterator
    getPartnerPosition(int value, int partner, int jacobNumber, int j);

    /* ------------------------------ GETTERS AND SETTERS --------------------------------- */
    Container<int, std::allocator<int> > &getContainer();
    Container<int, std::allocator<int> > &getMain();
    Container<int, std::allocator<int> > &getPend();
    Container<std::pair<int,int>, std::allocator<std::pair<int,int> > > &getPairs();
    Container<size_t, std::allocator<size_t> > &getJacobsthal();
    int &getRemainderInfo();
    int &getRemainderValue();
    int &getCounter();
    int &getRecursionLvl();

    /* ------------------------------ SHOW SET INFO --------------------------------- */
    void printSetData();
    void printPairs() const;
    void printChain(const Container<int, std::allocator<int> > &container, const std::string &name) const;
    void printJacobstahl(const Container<size_t, std::allocator<size_t> > &jacob);
    void printInsertionOrder();

    /* ------------------------------ PAIR INFO USED FOR INSERTION --------------------------------- */
    std::pair<int,int> getPairInfo(size_t jacob);
};

#include "../src/PmergeMe.tpp"
