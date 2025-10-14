#pragma once
#include "../headers/utils.hpp"
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

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
    void checkExtension(const std::string &filename);                       // Changed to const std::string &
    bool convertToFloat(const std::string &exchangeRate, float &rate);
    bool skipEntry(std::stringstream &lineStream, std::string &line, std::string &date, std::string &exchangeRate, float &rate);
    void addEntry(std::map<std::string, float> &data, const std::string &date, float rate, const std::string &line);

    void printData(std::map<std::string, float> &data, const std::string &fileName) const; // For debugging purposes

};