#pragma once
#include "../headers/utils.hpp"
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>  // For assert
#include <typeinfo> // For typeid (C++98)

class BitcoinExchange
{
private:
    std::string ref_file;
    std::string input_file;
    std::map<std::string, float> input_data;
    std::map<std::string, float> ref_data;

public:
    BitcoinExchange(const std::string &filename);
    BitcoinExchange(BitcoinExchange &o);
    BitcoinExchange &operator=(BitcoinExchange &o);
    ~BitcoinExchange();

    void storeData(const std::string &fileName, std::map<std::string, float> &data); // Changed to const std::string &

    /* Helper functiosn used in storeData */
    void checkFile(const std::string &filename, std::ifstream &fileStream); // Changed to take ifstream reference
    void checkExtension(const std::string &filename);
    bool isValidDate(const std::string &date, const std::string &line, int line_i);
    bool skipEntry(std::stringstream &lineStream, std::string &line, std::string &date, std::string &exchangeRate, float &rate, int line_i);
    void addEntry(std::map<std::string, float> &data, const std::string &date, float rate, const std::string &line, int line_i);

    template <typename Num>
    bool convertToNumber(const std::string &str, Num &conversion);

    void printData() const;
};