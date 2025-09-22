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
    const char *valid[] = {
        "nan",
        "nanf",
        "+inf",
        "-inf",
        "+inff",
        "-inff",
        " ",
        "a",
        "Z",
        "?",
        "!",
        "f",
        "+",
        "-",
        ".",
        "0",
        "-0",
        "1",
        "1234",
        "12345",
        "42",
        "-42",
        "+1",
        "-1",
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
        "3.14",
        "-1.0",
        "3.",
        ".3",
        ".14",
        "2e3",
        "5e-2",
        "-.3",
        "-3.",
        "+.14",
        "-.14",
        "+1.",
        "-1.",
        "3.554322332323233",
        "1.",
        "1.109",
    };
    const char *invalid[] = {
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
        "hellO WORld!!?", "??", "^!#@$%^*&()+-{}\\|][]'\";:.,/`~",
        "1+1", "11+", "++1",
        "1-1", "11-", "--1",
        "+-1", "-+1", "1-+1", "11+-",
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
        "1.1.1", "3.113.", "1-.", "1.2+",
        "+1.1.1", "",
        "--inff", "-+inff", "nan0",
        "hello", "123abc", "0a", "dhdh1adsdd",
        "27484e838383"};
    testHeader(1, "Valid ");
    int count = sizeof(valid) / sizeof(valid[0]);
    for (int i = 0; i < count; i++)
      ScalarConverter::convert(valid[i]);
    testHeader(2,  "Invalid");
    count = sizeof(valid) / sizeof(valid[0]);
    for (int i = 0; i < count; i++)
      ScalarConverter::convert(invalid[i]);
  }

  return 0;
}
