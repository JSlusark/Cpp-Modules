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
        "--------------------CHAR (✅)--------------------",
        " ", "a", "Z", "?", "!", "f", "+", "-", ".",
        "--------------------INT (✅)--------------------",
        "0", "-0", "1", "1234", "12345", "42", "-42",
        "+1", "-1",
        "--------------------FLOAT (✅)--------------------",
        "3.14f",
        "-1f",
        "0f",
        "3f",
        ".3f",
        "3.f",
        "2e3f",
        "5e-2f",
        "-.3f",
        "-3.f",
        "+.14f",
        "-.14f",
        "3.554322332323233f",
        "--------------------DOUBLE (✅)--------------------",
        "3.14", "-1.0", "3.", ".3", ".14", "2e3", "5e-2",
        "-.3", "-3.", "+.14", "-.14", "+1.", "-1.",
        "3.554322332323233",
        "1.", "1.109",
        "--------------------NAN (✅)--------------------",
        "nan", "nanf", "+inf", "-inf", "+inff", "-inff",
        "--------------------UNPRINTABLE (❌)--------------------",
        "\0",
        "\a",
        "\b",
        "\t",
        "\n",
        "\v",
        "\f",
        "\r",
        "\x1B",
        "\x7F",
        "a\r", "\th", "\x1B ", "a\n", "\r5",
        "",
        "--------------------CHAR (❌)--------------------",
        "hellO WORld!!?", "??", "^!#@$%^*&()+-{}\\|][]'\";:.,/`~",
        "--------------------INT (❌)--------------------",
        "1+1", "11+", "++1",
        "1-1", "11-", "--1",
        "+-1", "-+1", "1-+1", "11+-",
        "--------------------FLOAT (❌)--------------------",
        "f.",
        ".f",
        ".ff",
        "+f",
        "f.0",
        "1f.",
        "1.1.1f",
        "3.113.f",
        "1.1f09f",
        "1f1f1",
        "1f11f",
        "++1f",
        "1f+",
        "1+f",
        "1f++",
        "--1f",
        "1f-",
        "1-f",
        "1f-",
        "1+1f",
        "1-f",
        "--------------------DOUBLE (❌)--------------------",
        "1.1.1", "3.113.", "1-.", "1.2+",
        "+1.1.1", "",
        "--------------------NAN (❌)--------------------",
        "--inff", "-+inff", "nan0",
        "--------------------INVALID (❌)--------------------",
        "hello", "123abc", "0a", "dhdh1adsdd",
        "27484e838383"

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
