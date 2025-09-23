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
        std::cout << "impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    // ------- INT -------
    std::cout << "int: ";
    if (std::isnan(d) || d < INT_MIN || d > INT_MAX || errno == ERANGE)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
    // ------- FLOAT -------
    std::cout << "float: ";
    if (errno == ERANGE || f > FLT_MAX || f < -FLT_MAX) // for float
    std::cout << "impossible" << std::endl;
    else
    // fixed changes outpu format a of floating pony yo fixed decimal instead of scientifi notation
    // set precision sets hpw many digits to print after decimal output(as fixed is there, without fixed it prints the titl significatn
        std::cout << std::fixed << std::setprecision(1)
                  << f << "f" << std::endl;
    // ------- DOUBLE -------
    std::cout << "double: ";
    if (errno == ERANGE || d > DBL_MAX || d < -DBL_MAX) // for double
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
                  << d << std::endl;
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
    errno = 0;
    char *endptr;
    long l = strtol(s.c_str(), NULL, 10); // when not null will be set to point at th first uparsed char, base 10 for decimal
    if (errno == ERANGE || endptr == s.c_str() || *endptr != '\0')
        printConversion(0, 0, 0.0f, static_cast<double>(INT_MAX) + 1.0); // triggers impossible for each int cast
    printConversion(static_cast<char>(l),
                    static_cast<int>(l),
                    static_cast<float>(l),
                    static_cast<double>(l));
};
static void convertFloat(const std::string &s)
{
    logMessage(C_CYAN "[FLOAT] " C_RESET, s);
    float f = strtof(s.c_str(), NULL); // it reutnr o.o if no valid conversion could be performed
    errno = 0;
    char *endptr;
    if (errno == ERANGE || endptr == s.c_str() || *endptr != '\0')
        printConversion(0, 0, 0.0f, static_cast<double>(INT_MAX) + 1.0); // triggers impossible for each int cast

    printConversion(static_cast<char>(f),
                    static_cast<int>(f),
                    static_cast<float>(f),
                    static_cast<double>(f));
};
static void convertDouble(const std::string &s)
{
    logMessage(C_PURPLE "[DOUBLE] " C_RESET, s);
    double d = strtod(s.c_str(), NULL);
    errno = 0;
    char *endptr;
    if (errno == ERANGE || endptr == s.c_str() || *endptr != '\0')
        printConversion(0, 0, 0.0f, static_cast<double>(INT_MAX) + 1.0); // triggers impossible for each int cast
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