#include "../headers/utils.hpp"
#include "../headers/Array.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

#define MAX_VAL 750 // Define MAX_VAL as required

int main()
{
        testTitle(0, "Testing default constructor constructs 0 size array");
        Array<int> empty;
        std::cout << "Size of empty is:" << empty.size() << "\n";
        // no memory was allocated here as null

    testTitle(1, "Testing parameterized constructor with size 5 and operator[]");
    Array<int> array(5);
    logMessage(LOG, "array(f) class default values");
    for (unsigned int i = 0; i < array.size(); ++i)
        std::cout << array[i] << " ";
    std::cout << "\n";

    logMessage(LOG, "array(f) class modified values");
    for (unsigned int i = 0; i < array.size(); ++i)
        array[i] = i * 10;
    for (unsigned int i = 0; i < array.size(); ++i)
        std::cout << array[i] << " ";
    std::cout << "\n";

    testTitle(2, "Testing copy constructor with size 5 and operator[]");
    logMessage(LOG, "copyArray will be created with the same values as array(5)");
    Array<int> copyArray(array); // copy constructor
    for (unsigned int i = 0; i < array.size(); ++i)
        std::cout << "array[" << i << "]=" << array[i] << " copyArray[" << i << "]=" << copyArray[i] << "\n";
    logMessage(LOG, "modified copyArray[0] to 999");
    copyArray[0] = 999;
    for (unsigned int i = 0; i < array.size(); ++i)
        std::cout << "array[" << i << "]=" << array[i] << " copyArray[" << i << "]=" << copyArray[i] << "\n";

    testTitle(3, "Testing assignment operator with deep copy");
    logMessage(LOG, "phrase will be created with size 3");
    Array<std::string> phrase(3);
    phrase[0] = "hi";
    phrase[1] = "there";
    phrase[2] = "!";
    logMessage(LOG, "Constructing anotherPhrase and assigning phrase props to it");
    Array<std::string> anotherPhrase;
    anotherPhrase = phrase; // assignment operator
    anotherPhrase[1] = "world";
    logMessage(LOG, "Changed anotherPhrase[1] to 'world'");
    std::cout << "Phrase: " << phrase[0] << " " << phrase[1] << " " << phrase[2] << "\n";
    std::cout << "Another Phrase: " << anotherPhrase[0] << " " << anotherPhrase[1] << " " << anotherPhrase[2] << "\n";

    testTitle(4, "Testing [] operator out of bounds");
    try
    {
        std::cout << array[array.size()] << "\n"; // should be [array.size - 1]
    }
    catch (const std::exception &e)
    {
        std::cout << "caught: " << e.what() << "\n";
    }

    testTitle(5, "42 Test sample");
    logMessage(LOG, "Creating an numbers of MAX_VAL(750) and a mirror array");
    Array<int> numbers(MAX_VAL);
    logMessage(LOG, "Dynamically creating a mirror array with new int[MAX_VAL] using [] operator");
    int *mirror = new int[MAX_VAL]; // shouldnt this print a log message? 
    srand(time(NULL));
    logMessage(LOG, "Filling both arrays with random values within bounds of [] operator");
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // SCOPE
    {
        logMessage(LOG, "copy constructor and assignment operator called for tmp");
        Array<int> tmp = numbers;
        logMessage(LOG, "copy constructor called for test array");
        Array<int> test(tmp);
    }

    logMessage(LOG, "Verifying the values are the same between mirro and numbers array");
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror; // Clean up before returning
            return 1;
        }
    }

    logMessage(LOG, "Testing out of bounds for [] operator");
    try
    {
        numbers[-2] = 0; // Out of bounds
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[MAX_VAL] = 0; // Out of bounds
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    logMessage(LOG, "Automatically cleaning up dynamically allocated memory");
    delete[] mirror; // Clean up dynamically allocated memory
    return 0;
}
