#include "../headers/ScalarConverter.hpp"

static void printConversion(const char c, const int i, const float f, const double d)
{
    logMessage(LOG, "char: " + std::to_string(c));
    logMessage(LOG, "int: " + std::to_string(i));
    logMessage(LOG, "float: " + std::to_string(f));
    logMessage(LOG, "double: " + std::to_string(d));
}

static void convertChar(const std::string &s)
{
    logMessage(C_YELLOW "[CHAR] " C_RESET, s);
    printConversion(s[0], static_cast<int>(s[0]), static_cast<float>(s[0]), static_cast<double>(s[0]));
    // std::cout << "char: " << s[0] << std::endl;
    // std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
    // std::cout << "float: " << std::fixed << std::setprecision(1)
    //           << static_cast<float>(s[0]) << "f" << std::endl;
    // std::cout << "double: " << std::fixed << std::setprecision(1)
    //           << static_cast<double>(s[0]) << std::endl;
};
static void convertInt(const std::string &s)
{
    logMessage(C_GREEN "[INT] " C_RESET, s);
};
static void convertFloat(const std::string &s)
{
    logMessage(C_CYAN "[FLOAT] " C_RESET, s);
};
static void convertDouble(const std::string &s)
{
    logMessage(C_PURPLE "[DOUBLE] " C_RESET, s);
};
static void convertPseudoLiteral(const std::string &s)
{
    logMessage(C_MAGENTA "[SPEUDOLITERAL] " C_RESET, s);
    logMessage(LOG, "char: impossible");
    logMessage(LOG, "int: impossible");
    // logMessage(LOG, "float: impossible");
    // logMessage(LOG, "double: impossible");
};
static void convertInvalid(const std::string &s)
{
    logMessage(C_RED "[INVALID] " C_RESET, s);
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