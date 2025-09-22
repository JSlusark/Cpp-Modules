#include "../headers/ScalarConverter.hpp"

// static void print(const std::string &output)
// {
//     logMessage(LOG, "char: output");
//     logMessage(LOG, "int: output");
//     logMessage(LOG, "float: output");
//     logMessage(LOG, "double: output");
// }

static void convertChar(const std::string &s)
{
    logMessage(C_YELLOW "[CHAR] " C_RESET, s);
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