#include "./headers/BitcoinExchange.hpp"

bool BitcoinExchange::hasCSVExtension(const std::string &filename, std::string &error)
{
    std::string ext = filename.substr(filename.find_last_of(".") + 1);
    if (ext != "csv")
    {
        error = "Invalid extension, please use .csv";
        return false;
    }
    logMessage(LOG, "Correct file extension used");
    return true;
}

bool BitcoinExchange::dataCollected(const std::string &fileName, std::string &error)
{
    // create inputFile
    std::ifstream fileStream(fileName.c_str()); // ifstream opens and reads from filename, needs cstr of path, it stores *fd, buffer to read data in chuncks and state flags
    if (!fileStream.is_open())                   // still need to check if open
    {
        error = "An error occured while opeing the file";
        return false;
    }
    std::string exchangeRate;
    std::string line, date;
    while (std::getline(fileStream, line))
    {
        std::stringstream lineStream(line);
        if (getline(lineStream, date, ',') && getline(lineStream, exchangeRate))
        {
            if (date.empty() && exchangeRate.empty())
            {
                data[date] = std::stod(exchangeRate);
            }
            else
            {
                error = "Found empty date or exchangeRate in file";
                return false;
            }
        }
    }
    logMessage(LOG, "File was opened successfully");
    return true;
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{

    std::string error;
    if (!hasCSVExtension(filename, error) || !dataCollected(filename, error) || data.empty())
        throw std::invalid_argument(error);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &o) {
    // logMessage(COPY_C, "Span object created");
};
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &o)
{
    if (this != &o)
    {
    }
    // logMessage(ASSIGN_OP, "Span attributes assigned");
    return *this;
};
BitcoinExchange::~BitcoinExchange() {
    // logMessage(DESTRUCTOR, "Span object destroyed");
};