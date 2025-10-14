#include "../headers/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename)
{

    std::string error;
    if (!hasCSVExtension(filename, error) || !dataCollected(filename, error))
        throw std::invalid_argument(error);
    if (data.empty())
    {
        // logMessage(WARNING, "File was empty or no valid data found");
        throw std::invalid_argument(C_RED "No valid data found in file" C_RESET);
    }
    logMessage(SUCCESS, "BitcoinExchange data was stored in the map");
    printData(); // For debugging purposes

    try
    {
        /* code */
        // collect data
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &o)
{
    data = o.data; // Properly copy the data map
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &o)
{
    if (this != &o)
    {
        data = o.data;
    }
    // logMessage(ASSIGN_OP, "Span attributes assigned");
    return *this;
};

BitcoinExchange::~BitcoinExchange() {
    // logMessage(DESTRUCTOR, "Span object destroyed");
};

// HELPERS

bool BitcoinExchange::hasCSVExtension(const std::string &filename, std::string &error)
{
    std::string ext = filename.substr(filename.find_last_of(".") + 1);
    if (ext != "csv")
    {
        error = "Invalid extension, please use .csv";
        return false;
    }
    logMessage(SUCCESS, "Correct file extension used");
    return true;
}

bool convertToDouble(const std::string &exchangeRate, double &rate)
{
    std::stringstream stream(exchangeRate);
    stream >> std::ws;     // skips leading spaces
    if (!(stream >> rate)) // float extraction fails
        return false;
    stream >> std::ws; // skips trailing spaces
    if (!stream.eof()) // if something  is left (letters, extra chars)
        return false;
    return true;
}


bool BitcoinExchange::dataCollected(const std::string &fileName, std::string &error)
{
    // create inputFile
    std::ifstream fileStream(fileName.c_str()); // ifstream opens and reads from filename, needs cstr of path, it stores *fd, buffer to read data in chuncks and state flags
    if (!fileStream.is_open())                  // still need to check if open
    {
        error = "An error occurred while opening the file";
        return false;
    }
    logMessage(SUCCESS, "File was opened successfully");
    std::string date;
    std::string exchangeRate;
    std::string line;
    std::getline(fileStream, line); // skips header
    while (std::getline(fileStream, line))
    {
        if (line.empty())
            continue; // ignores blank lines and goes to next iteration

        std::stringstream lineStream(line);
        if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, exchangeRate))
        {
            // error = "Invalid line format:'" + line + "'\nExpected 'date,exchange_rate'";
            logMessage(ERROR, C_CYAN "Invalid line format:'" C_RESET + line);
            continue;
        }
        else
        {
            if (date.empty()) // add this to save space in map and not save
            {
                logMessage(ERROR, C_RED "Invalid date found:'" C_RESET + line);
                continue;
            }
            double rate;
            if (!convertToDouble(exchangeRate, rate))
            {
                logMessage(ERROR, C_YELLOW "Invalid exchange rate found:'" C_RESET + line);
                continue; // skip this line and continue to the next
                //  continue; // reject non-numeric "abddc"
            }
            // trim white space for date and warns of rate overwriting
            date.erase(0, date.find_first_not_of(" \t\r"));
            date.erase(date.find_last_not_of(" \t\r") + 1);
            std::cout << date << C_CYAN "|" C_RESET << rate << std::endl; // Debug: print the parsed values
            if (data.find(date) != data.end())                            // if date already exists in map
            {
                logMessage(WARNING, "Found new rate for previously logged date, overwriting:" C_RESET + line);
            }
            data[date] = rate;
        }
    }
    return true;
}

const std::map<std::string, double> &BitcoinExchange::getData() const { return data; }

void BitcoinExchange::printData() const
{
    // std::map<std::string, double> data = getData();
    logMessage(DEBUG, "Printing data map contents:");
    std::map<std::string, double>::const_iterator it;
    for (it = data.begin(); it != data.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}
