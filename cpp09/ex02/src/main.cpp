#include "../headers/FordJohnsonSort.hpp"
#include <sstream> // for std::ostringstream

/*
FOR TESTING PURPOSES:
bash:
./PmergeMe $(shuf -i 1-10 -n 3000 | tr "\n" " ")

fish:
./PmergeMe (shuf -i 1-10 -n 3000)
descending order:
./PmergeMe (seq 3000 -1 1)

To be added under checkResult( make public) if using bashTester:
./myTester.sh 1 2 3 4 5
std::cout << "comparisons=" << vector.comparisonResult << std::endl;

*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        logMessage(ERROR, "./PmergeMe needs at least one argument");
        return 1;
    }
    else
    {
        try
        {
            std::vector<int> vec;
            std::deque<int> deq;

            FordJohnsonSort<std::vector> sorted_vec(argc, argv, vec);
            FordJohnsonSort<std::deque> sorted_deq(argc, argv, deq);
        }
        catch (const std::exception &e)
        {
            logMessage(ERROR, e.what());
            return 1;
        }
    }

    return 0;
}
