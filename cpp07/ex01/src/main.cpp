#include "../headers/utils.hpp"

int main()
{
	srand(time(0));
	const float arr_float[] = {1.2f, 2.4f, 3.4f, 4.45f, 5.f};
	char arr_char[] = {'a', 'b', 'c', 'd'};
	int combination[] = {0, 0, 0, 0};

	testTitle(1, "Printing element of array int");
	int size = sizeof(combination) / sizeof(combination[0]);
	logMessage(LOG, "Empty lock combination");
	iter(combination, size, printElement); // iter(combination, size, printElement<int>) if used easier template
	logMessage(LOG, "Give random lock combination");
	iter(combination, size, randomize);
	iter(combination, size, printElement);
	logMessage(LOG, "increasing combination by 1");
	iter(combination, size, increase);
	iter(combination, size, printElement);

	testTitle(2, "Printing element of array float");
	size = sizeof(arr_float) / sizeof(arr_float[0]);
	iter(arr_float, size, printElement);
	// iter(arr_float, size, increase); // <--- compilation error as cannot use  on const

	testTitle(3, "Printing element of array char");
	size = sizeof(arr_char) / sizeof(arr_char[0]);
	iter(arr_char, size, printElement);
	logMessage(LOG, "Increasing each element by 1");
	iter(arr_char, size, increase);
	iter(arr_char, size, printElement);

	testTitle(4, "Testing empty array");
	int emptyArray[] = {};
	size = sizeof(emptyArray) / sizeof(emptyArray[0]);
	logMessage(LOG, "Nothing should change in the array or be printed below as array is empty");
	iter(emptyArray, size, randomize);
	iter(emptyArray, size, printElement);

	testTitle(5, "Testing single-element array");
	int singleElement[] = {42};
	iter(singleElement, 1, printElement);
	logMessage(LOG, "Increased the only element by 1");
	iter(singleElement, 1, increase);
	iter(singleElement, 1, printElement);

	return 0;
}
