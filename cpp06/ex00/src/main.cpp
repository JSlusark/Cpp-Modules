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

      // char - unprintable
        "\0",   // NUL
        "\a",   // BEL
        "\b",   // backspace
        "\t",   // tab
        "\n",   // newline
        "\v",   // vertical tab
        "\f",   // form feed
        "\r",   // carriage return
        "\x1B", // ESC
        "\x7F", // DEL
        "a\r", "\th", "\x1B ", "a\n", "\r5", // ❌ invalid mix
        "",
        // char
         " ","a", "Z", "?", "!", "9", // ✅ valid char candidates
        "hellO WORld!!?", "??", "^!#@$%^*&()+-{}\\|][]'\";:.,/`~", // ❌ invalid as char (too long)

        // // int
        // "1", "1234", "12345", "42", "-42",   // ✅ valid ints
        // "+1", "-1",                          // ✅ valid signed ints
        // "1+1", "11+", "++1",                 // ❌ invalid
        // "1-1", "11-", "--1",                 // ❌ invalid
        // "+", "-", "+-1", "-+1", "1-+1", "11+-", // ❌ invalid

        // // float
        // "3.14f", "-1f", "0f", "3f", ".3f", "3.f", "2e3f", "5e-2f",  // ✅ valid floats
        // "-.3f", "-3.f", "+.14f", "-.14f",                          // ✅ valid with sign
        // "3.554322332323233f",                                       // ✅ valid (precision ignored)
        // "f", "f.", ".f", "+f", "f.0",                              // ❌ invalid
        // "1f.", "1.1.1f", "3.113.f", "1.1f09f",                     // ❌ invalid malformed
        // "++1f", "1f+", "1+f", "1f++", "--1f", "1f-", "1-f", "1f-", // ❌ invalid
        // "1+1f", "1-f",                                             // ❌ invalid mixed ops

        // // double
        // "3.14", "-1.0", "0", "3.", ".3", ".14", "2e3", "5e-2",     // ✅ valid doubles
        // "-.3", "-3.", "+.14", "-.14",                              // ✅ valid signed doubles
        // "3.554322332323233",                                       // ✅ valid
        // "1.", "1.109",                                             // ✅ valid
        // ".", "1.1.1", "3.113.", "1-.", "+1.", "-1.", "1.2+",       // ❌ invalid malformed
        // "+1.1.1", "",                                              // ❌ invalid

        // // pseudo literals (special values)
        // "nan", "nanf", "+inf", "-inf", "+inff", "-inff",           // ✅ valid pseudo literals
        // "--inff", "-+inff", "nan0",                                // ❌ invalid pseudo
        // // note: duplicate "nanf" at end removed to avoid confusion

        // // invalid catch-all
        // "hello", "123abc", "0a", "dhdh1adsdd",                     // ❌ invalid
        // "27484e838383"                                             // ❌ not parsing scientific in your exercise
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
