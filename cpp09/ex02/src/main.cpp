#include "../headers/fordJohnsonSort.hpp"
#include <ctime>      // clock()
#include <sys/time.h> // gettimeofday()

#include <iomanip> // for std::setprecision, std::fixed
#include <sstream> // for std::ostringstream

/*

bash:
./PmergeMe $(shuf -i 1-10 -n 3000 | tr "\n" " ")

fish:
./PmergeMe (shuf -i 1-10 -n 3000)
descending order:
./PmergeMe (seq 3000 -1 1)

To be added under showResult( make public) if using bashTester:
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
            fordJohnsonSort vector(argc, argv); // vect will me a template later
            vector.showResult();
        }
        catch (const std::exception &e)
        {
            logMessage(ERROR, e.what());
            return 1;
        }
    }

    return 0;
}
