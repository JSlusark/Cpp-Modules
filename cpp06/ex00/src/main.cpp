#include <iostream>
#include "../headers/ScalarConverter.hpp"
int main(int argc, char **argv)
{

  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      ScalarConverter::convert(argv[i]);
    }
  }

  // ScalarConverter convertor =  new ScalarConverter; // you can see inaccessibility nhere
  const char *testLiterals[] = {
      "a", "42", "-42", "3.14f", "2.71828",
      "nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
  const int testCount = sizeof(testLiterals) / sizeof(testLiterals[0]);

  for (int i = 0; i < testCount; i++)
  {
    testHeader(i, std::string("coverting ") + testLiterals[i]);
    ScalarConverter::convert(testLiterals[i]);
    std::cout << std::endl;
  }
  return 0;
}
