#pragma once
#include "../headers/utils.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>


class BitcoinExchange{

    private:
    std::map<std::string, double> data;


    public:
    BitcoinExchange(const std::string &filename);
    BitcoinExchange(BitcoinExchange &o);
    BitcoinExchange &operator=(BitcoinExchange &o);
    ~BitcoinExchange();

    bool dataCollected(const std::string &fileName, std::string &error);
    bool hasCSVExtension(const std::string &filename, std::string &error);


    // function that checks the file extension
};