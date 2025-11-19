#pragma once
#include "./debug.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits> // <--- added

struct CountingCompare
{
    int &counter;
    CountingCompare(int &c) : counter(c) {}
    bool operator()(int a, int b)
    {
        counter++;
        return a < b;
    }
};


std::vector<size_t> generateJacobsthal(size_t pend_size);
void fordJohnsonSort(std::vector<int> &arr, int &iteration, int &comparisons);