#include "../headers/BitcoinExchange.hpp"

/* --------------------------- CONSTRUCTORS --------------------------- */

BitcoinExchange::BitcoinExchange(const std::string &input_file) : ref_file("data.csv"), input_file(input_file)
{
    try
    {
        storeData(ref_file, ref_data);
        storeData(input_file, input_data);

        // logMessage(SUCCESS, "BitcoinExchange inputdata was stored in the map");
        // printData(ref_data, ref_file);     // For debugging purposes
        // printData(input_data, input_file); // For debugging purposes
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
    logMessage(LOG, "Initiating data from file: " C_YELLOW + fileName + C_RESET);
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
            addEntry(data, date, rate); // adds entry to map if date is valid or overwrites if date already exists
            if(fileName == input_file)
                printConversion(date);
        }
        // logMessage(C_GREEN "[ADDED]" C_RESET, " '" + line + "'" C_RESET);
    }
    if (data.empty())
        throw std::invalid_argument(EXCEPTION "No valid data found in file");
    if (fileName == ref_file)
        logMessage(SUCCESS, fileName + "was mapped successfully into BitcoinExchange exchange object");
    else
        logMessage(SUCCESS, fileName + " converted successfully");
}

/*_________________________________________________________ HELPER FUNCTIONS_________________________________________________________ */

/**********************************************************************/
/************************** USED IN convert PRICES**************************/
/**********************************************************************/

/* converts and  Prints */
void BitcoinExchange::printConversion(std::string date)
{
    std::map<std::string, float>::const_iterator ref_it = ref_data.find(date);
    if (ref_it != ref_data.end()) // If date found in ref_data ref_it->second matches input_data[date]
    {
        std::string ref_date = ref_it->first;
        float ref_rate = ref_it->second;
        logMessage("", date + " , " + asString(input_data[date]) + " => " + asString(ref_rate));
    }
    else
    {
        ref_it = ref_data.lower_bound(date); // If input_date not found in ref_data is overwritten with closest earlier date
        if (ref_it != ref_data.end())
        {
            std::string closest_date = ref_it->first;
            float closest_rate = ref_it->second;
            logMessage("", date + " , " + asString(input_data[date]) + " => " + asString(closest_rate));
        }
        else
        {
            logMessage(ERROR, "No earliest date found:" + date + " , " + asString(input_data[date]) );
        }
    }
}

/**********************************************************************/
/************************** USED IN STORE DATA**************************/
/**********************************************************************/

/* Nested functions to check file format and existence*/
void BitcoinExchange::checkFile(const std::string &fileName, std::ifstream &fileStream)
{
    checkExtension(fileName);
    if (!fileStream.is_open()) // it closes automatically
        throw std::invalid_argument(EXCEPTION "An error occurred while opening the file");
    logMessage(SUCCESS, "file opened successfully");
}

void BitcoinExchange::checkExtension(const std::string &fileName)
{
    std::string ext = fileName.substr(fileName.find_last_of(".") + 1);
    if (ext != "csv")
        throw std::invalid_argument(EXCEPTION "Invalid extension, please use .csv");
    logMessage(SUCCESS, "file uses correct file extension");
}

/* Nested functions to check file entry lines in main loop, skips or add based on conditions */
bool BitcoinExchange::skipEntry(std::stringstream &lineStream, std::string &line, std::string &date, std::string &exchangeRate, float &rate)
{
    // trim white space for date
    date.erase(0, date.find_first_not_of(" \t\r"));
    date.erase(date.find_last_not_of(" \t\r") + 1);
    if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, exchangeRate))
    {
        logMessage(ERROR, "Found empty field: " + line);
        return true;
    }
    if (!isValidDate(date, line))
    {
        // logMessage(ERROR, "Invalid date: " + line);
        return true;
    }
    if (!convertToNumber(exchangeRate, rate))
    {
        logMessage(ERROR, "Invalid rate number: " + line);
        return true; // skip this line and continue to the next
    }
    if (rate < 0 || rate > 1000)
    {
        logMessage(ERROR, "Invalid rate range: " + line);
        return true; // skip this line and continue to the next
    }
    if (input_data.find(date) != input_data.end()) // if date already exists in map, warn user
    {
        logMessage(ERROR, "Duplicate found: " + line);
        return true;
        // logMessage(WARNING, "Duplicate date entry found.\n          Overwriting with: " C_YELLOW " <line " + asString(line_i) + "> " C_RESET + line);
    }
    return false;
}

void BitcoinExchange::addEntry(std::map<std::string, float> &data, const std::string &date, float rate)
{

    // std::cout << date << C_CYAN "|" C_RESET << rate << std::endl; // Debug: printing the parsed values

    data[date] = rate;
}

/* Helper functions to check date and rate numbers*/
bool BitcoinExchange::isValidDate(const std::string &date, const std::string &line)
{
    // make sure that olnly - and numbers are used
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        logMessage(ERROR, "Date is wrong format " + line);
        return false;
    }

    // Extract and convert to int for numeric checks
    int year, month, day;
    if (!convertToNumber(date.substr(0, 4), year) ||
        !convertToNumber(date.substr(5, 2), month) ||
        !convertToNumber(date.substr(8, 2), day))
    {
        logMessage(ERROR, "Date is not numeric " + line);
        return false;
    }

    // Days in month - 0 to 11
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // February has 28 days normally, but 29 in leap years (every 4 year vy approxiamtion)
    bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); // execept for century years (unless divisble by 400)
    if (leapYear)
        daysInMonth[1] = 29; // feb  changes
    // Numeric range checks
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1])
    {
        logMessage(ERROR, "Date out of range: " + line);
        return false;
    }
    return true;
}

template <typename Num>
bool BitcoinExchange::convertToNumber(const std::string &s, Num &type)
{
    // Basic check: ensure Num is not std::string (using typeid)
    assert(typeid(Num) != typeid(std::string) && "convertToNumber: Num must be a numeric type, not std::string");

    std::stringstream stream(s); // stream adapts based on the num type passed
    stream >> std::ws;           // skips leading spaces
    if (!(stream >> type))       // extraction to type fails
        return false;
    stream >> std::ws; // skips trailing spaces
    if (!stream.eof()) // if something  is left (letters, extra chars)
        return false;
    return true;
}
