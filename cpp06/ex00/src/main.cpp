#include <iostream>
#include "../headers/ScalarConverter.hpp"
int main(int argc, char **argv)
{

  // ScalarConverter convertor =  new ScalarConverter; // you can see inaccessibility nhere
  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      ScalarConverter::convert(argv[i]);
    }
  }
  else
  {
    const char *testLiterals[] = {
        // char
        // "a",
        // // int
        "-1",
        "1-1",
        "1+1",
        "11+",
        "+",
        "-",
        // "42",
        // "-42",
        // // float
        // "3.14f",
        ".3",
        ".14f",
        "1.1f.f",
        "0",
        "3.f",
        "3.554322332323233f",
        // // double
        ".3",
        ".14f",
        "3.f",
        "3.5543223323232345454545",
        // "2.71828",
        // // undefined
        // "nan",
        // "nanf",
        // "+inf",
        // "-inf",
        // "+inff",
        // "-inff",
        // // invalid
        // "hello",
        // "123abc",
        // "12.34.56",
        // "++42",
    };
    const int testCount = sizeof(testLiterals) / sizeof(testLiterals[0]);

    for (int i = 0; i < testCount; i++)
    {
      // testHeader(i, std::string("coverting ") + testLiterals[i]);
      // std::cout << C_YELLOW<< "Literal: " << testLiterals[i] << " "<< C_RESET;
      ScalarConverter::convert(testLiterals[i]);
      // std::cout << std::endl;
    }
  }

  return 0;
}
