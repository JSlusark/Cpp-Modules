#include "../headers/BitcoinExchange.hpp"


/* --------------------------- CONSTRUCTORS --------------------------- */

BitcoinExchange::BitcoinExchange(const std::string &input_file) : ref_file("data.csv"), input_file(input_file)
{
    try
    {
        storeData(ref_file, ref_data);
        storeData(input_file, input_data);
        logMessage(SUCCESS, "BitcoinExchange data was stored in the map");
        // printData(ref_data, ref_file);     // For debugging purposes
        printData(input_data, input_file); // For debugging purposes
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &o)
{
    input_data = o.input_data; // Properly copy the data map
    ref_data = o.ref_data;     // Properly copy the data map
    ref_file = o.ref_file;
    input_file = o.input_file;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &o)
{
    if (this != &o)
    {
        input_data = o.input_data; // Properly copy the data map
        ref_data = o.ref_data;     // Properly copy the data map
        ref_file = o.ref_file;
        input_file = o.input_file;
    }
    // logMessage(ASSIGN_OP, "Span attributes assigned");
    return *this;
};

BitcoinExchange::~BitcoinExchange() {
    // logMessage(DESTRUCTOR, "Span object destroyed");
};

/* --------------------------- MAIN FUNCTIONS --------------------------- */

void BitcoinExchange::storeData(const std::string &fileName, std::map<std::string, float> &data)
{
    std::ifstream fileStream(fileName.c_str());
    logMessage(LOG, "Initiating data from file: " C_YELLOW  +  fileName + C_RESET);
    checkFile(fileName, fileStream); // checks reference file);
    std::string line, date, exchangeRate;
    float rate;
    std::getline(fileStream, line); // skips header
    while (std::getline(fileStream, line))
    {
        if (line.empty())
            continue; // ignores blank lines and goes to next iteration
        std::stringstream lineStream(line);
        if (skipEntry(lineStream, line, date, exchangeRate, rate))
            continue;
        else
        {
            // trim white space for date
            date.erase(0, date.find_first_not_of(" \t\r"));
            date.erase(date.find_last_not_of(" \t\r") + 1);
            addEntry(data, date, rate, line);// adds entry to map if date is valid or overwrites if date already exists
        }
    }
    if (data.empty())
        throw std::invalid_argument(ERROR "No valid data found in file");
}



/* --------------------------- HELPER FUNCTIONS --------------------------- */

/* IN STORE DATA - used to check if the file is valid and exists  */
void BitcoinExchange::checkFile(const std::string &fileName, std::ifstream &fileStream)
{
    checkExtension(fileName);
    if (!fileStream.is_open()) // it closes automatically
        throw std::invalid_argument(ERROR "An error occurred while opening the file");
    logMessage(SUCCESS, "file opened successfully");
}

void BitcoinExchange::checkExtension(const std::string &fileName)
{
    std::string ext = fileName.substr(fileName.find_last_of(".") + 1);
    if (ext != "csv")
        throw std::invalid_argument(ERROR "Invalid extension, please use .csv");
    logMessage(SUCCESS, "file uses correct file extension");
}

/* IN STORE DATA - used in main loop that checks entries on each line of the file  */
bool BitcoinExchange::skipEntry(std::stringstream &lineStream, std::string &line, std::string &date, std::string &exchangeRate, float &rate)
{
    if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, exchangeRate))
    {
        logMessage(ERROR, C_CYAN "Invalid line found, date and/or rate field are empty:'" C_RESET + line);
        return true;
    }
    if (!convertToFloat(exchangeRate, rate))
    {
        logMessage(ERROR, C_YELLOW "Invalid line found, rate is not a float:'" C_RESET + line);
        return true; // skip this line and continue to the next
    }
    return false;
}

void BitcoinExchange::addEntry(std::map<std::string, float> &data, const std::string &date, float rate, const std::string &line)
{

    // std::cout << date << C_CYAN "|" C_RESET << rate << std::endl; // Debug: printing the parsed values
    if (data.find(date) != data.end()) // if date already exists in map, warn user
        logMessage(WARNING, "Duplicate date entry found, overwriting rate:" C_RESET + line);
    data[date] = rate;
}

bool BitcoinExchange::convertToFloat(const std::string &exchangeRate, float &rate)
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

/* PRINT DEBUGGING */
void BitcoinExchange::printData(std::map<std::string, float> &data, const std::string &fileName) const
{
    // std::map<std::string, float> data = getData();
    logMessage(DEBUG, "Printing data map contents for: " + fileName);
    std::map<std::string, float>::const_iterator it;
    for (it = data.begin(); it != data.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}