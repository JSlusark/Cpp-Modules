#include "../headers/ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cmath>

static void printConversion(char c, long i, float f, double d)
{
    // ------- CHAR -------
    std::cout << "char: ";
    if (std::isnan(d) || d < CHAR_MIN || d > CHAR_MAX)
        std::cout << "impossible" << std::endl; // < -128 and > 127, no char representation exists for this conversion and is not in range
    else if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl; // not printable
    // ------- INT -------
    std::cout << "int: ";
    if (std::isnan(d) || d < INT_MIN || d > INT_MAX || errno == ERANGE)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
    // ------- FLOAT -------
    std::cout << "float: ";
    if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
    else if (errno == ERANGE || f > FLT_MAX || f < -FLT_MAX)
        std::cout << "impossible" << std::endl;
    else
        // fixed changes outpu format a of floating pony yo fixed decimal instead of scientifi notation
        // set precision sets hpw many digits to print after decimal output(as fixed is there, without fixed it prints the titl significatn
        std::cout << std::fixed << std::setprecision(1)
                  << f << "f" << std::endl;
    // ------- DOUBLE -------
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    else if (errno == ERANGE || d > DBL_MAX || d < -DBL_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

static void convertChar(const std::string &s)
{
    logMessage(C_YELLOW "[CHAR] " C_RESET, s);
    printConversion(s[0],
                    static_cast<int>(s[0]),
                    static_cast<float>(s[0]),
                    static_cast<double>(s[0]));
};
static void convertInt(const std::string &s)
{
    logMessage(C_GREEN "[INT] " C_RESET, s);
    errno = 0; // need to be reset at each call to strtol/strtof/strtod as it can affect subsequent calls
    char *endptr;
    long l = strtol(s.c_str(), &endptr, 10); // when not null will be set to point at the first unparsed char, base 10 for decimal
    if (errno == ERANGE || endptr == s.c_str() || *endptr != '\0') //check for range error, no conversion performed, or extra chars after number
    {
        printConversion(static_cast<char>(CHAR_MAX + 1), // char overflow
                        static_cast<long>(INT_MAX) + 1L, // int overflow
                        FLT_MAX * 2.0f,                  // float overflow
                        DBL_MAX * 2.0);                  // double overflow
        return;
    }
    printConversion(static_cast<char>(l),
                    static_cast<int>(l),
                    static_cast<float>(l),
                    static_cast<double>(l));
};
static void convertFloat(const std::string &s)
{
    logMessage(C_CYAN "[FLOAT] " C_RESET, s);
    errno = 0; // need to be reset at each call to strtol/strtof/strtod as it can affect subsequent calls
    char *endptr;
    // remove trailing 'f' for strtof
    std::string noSuffix = s;
    noSuffix = s.substr(0, s.size() - 1);

    float f = strtof(noSuffix.c_str(), &endptr);
    if (errno == ERANGE || endptr == noSuffix.c_str() || *endptr != '\0')
    {
        printConversion(static_cast<char>(CHAR_MAX + 1),
                        static_cast<long>(INT_MAX) + 1L,
                        FLT_MAX * 2.0f,
                        DBL_MAX * 2.0);
        return;
    }

    printConversion(static_cast<char>(f),
                    static_cast<int>(f),
                    f,
                    static_cast<double>(f));
}
static void convertDouble(const std::string &s)
{
    logMessage(C_PURPLE "[DOUBLE] " C_RESET, s);
    errno = 0; // need to be reset at each call to strtol/strtof/strtod as it can affect subsequent calls
    char *endptr;
    double d = strtod(s.c_str(), &endptr);
    if (errno == ERANGE || endptr == s.c_str() || *endptr != '\0')
    {
        printConversion(static_cast<char>(CHAR_MAX + 1), // char overflow
                        static_cast<long>(INT_MAX) + 1L, // int overflow
                        FLT_MAX * 2.0f,                  // float overflow
                        DBL_MAX * 2.0);                  // double overflow
        return;
    }
    printConversion(static_cast<char>(d),
                    static_cast<int>(d),
                    static_cast<float>(d),
                    static_cast<double>(d));
};
static void convertPseudoLiteral(const std::string &s)
{
    logMessage(C_MAGENTA "[SPEUDOLITERAL] " C_RESET, s);
    double d = strtod(s.c_str(), NULL);
    float f = static_cast<float>(d);
    printConversion(0,
                    0,
                    f,
                    d);
};
static void convertInvalid(const std::string &s)
{
    logMessage(C_RED "[INVALID] " C_RESET, s);
    std::cout << "Invalid literals cannot be converted!" << std::endl;
};

void ScalarConverter::convert(const std::string &literal)
{
    void (*convertType[])(const std::string &) = {
        convertPseudoLiteral,
        convertChar,
        convertInt,
        convertFloat,
        convertDouble,
        convertInvalid};

    // logMessage(LOG, "Received literal: " + literal);
    enum MessageType type = match_type(literal);
    convertType[type](literal); // calls conversion func of enum match
}