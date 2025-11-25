#include "../headers/fordJohnsonSort.hpp"
#include <ctime>      // clock()
#include <sys/time.h> // gettimeofday()

#include <iomanip> // for std::setprecision, std::fixed
#include <sstream> // for std::ostringstream

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
            std::vector<int> container;
            fordJohnsonSort vector(argc, argv, container); // vect will me a template later
            vector.sort();
            vector.showResult();
            // fordJohnsonSort my_algo(argc, argv, "vector");
        }
        catch (const std::exception &e)
        {
            logMessage(ERROR, e.what());
            return 1;
        }
    }

    return 0;
}
