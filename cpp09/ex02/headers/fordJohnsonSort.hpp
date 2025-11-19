#pragma once
#include "./debug.hpp"
#include "./fordJohnsonSort.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits> // <--- added

void fordJohnsonSort(std::vector<int> &arr, int &iteration, int &comparisons);

