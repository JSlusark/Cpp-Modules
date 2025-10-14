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
    std::map<std::string, double> data;

public:
    BitcoinExchange(const std::string &filename);
    BitcoinExchange(BitcoinExchange &o);
    BitcoinExchange &operator=(BitcoinExchange &o);
    ~BitcoinExchange();

    bool dataCollected(const std::string &fileName, std::string &error);  // Changed to const std::string &
    bool hasCSVExtension(const std::string &filename, std::string &error);  // Changed to const std::string &
    void printData() const; // For debugging purposes

    // getters
    const std::map<std::string, double> &getData() const;// Getter for data map

};