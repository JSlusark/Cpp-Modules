#include "../headers/BitcoinExchange.hpp"

/* --------------------------- CONSTRUCTORS --------------------------- */

BitcoinExchange::BitcoinExchange(const std::string &input_file) : ref_file("data.csv"), input_file(input_file)
{
    try
    {
        storeData(ref_file, ref_data, REF_TYPE);
        storeData(input_file, input_data, INPUT_TYPE);

        // logMessage(SUCCESS, input_file + "was stored as a BitcoinExchange exchange object");
        // logMessage(LOG, "Converting "+ input_file + "rates from "+ ref_file+" rates");

        // logMessage(SUCCESS, input_file + " rates converted");

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

void BitcoinExchange::storeData(const std::string &fileName, std::map<std::string, float> &data, const std::string type)
{
    std::ifstream fileStream(fileName.c_str());
    logMessage(LOG, "Initiating data from " + type + " file: " C_YELLOW + fileName + C_RESET);
    checkFile(fileName, fileStream); // checks .csv and openable , triggers catch if error occurs
    // collectkeys();
    std::string line, date, exchangeRate;
    float rate;
    std::getline(fileStream, line); // skips header
    while (std::getline(fileStream, line))
    {
        if (line.empty())
            continue; // ignores blank lines and goes to next iteration
        std::stringstream lineStream(line);
        if (skipEntry(lineStream, line, date, exchangeRate, rate, type))
        {
            if (type == INPUT_TYPE)
                logMessage(ERROR, error_message);
            continue;
        }
        else
        {
            addEntry(data, date, rate); // adds entry to map if date is valid or overwrites if date already exists
            if (type == INPUT_TYPE)
                printConversion(date); // not separating converts due to the exercise printing req
        }
        // logMessage(C_GREEN "[ADDED]" C_RESET, " '" + line + "'" C_RESET);
    }
    // ends here
    if (data.empty())
        throw std::invalid_argument(EXCEPTION "No valid data found in file, mapped data is empty");
    logMessage(SUCCESS, fileName + " was stored as a " + INPUT_TYPE + " BitcoinExchange exchange object");
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
        logMessage("", date + " => " + asString(input_data[date]) + " = " + asString(ref_rate * input_data[date]));
    }
    else
    {
        ref_it = ref_data.lower_bound(date); // If input_date not found in ref_data is overwritten with closest earlier date
        if (ref_it != ref_data.end())
        {
            std::string closest_date = ref_it->first;
            float closest_rate = ref_it->second;
            logMessage("", date + " => " + asString(input_data[date]) + " = " + asString(closest_rate * input_data[date]));
        }
        else
        {
            logMessage(ERROR, "No earliest date found:" + date + " => " + asString(input_data[date]));
        }
    }
}

/**********************************************************************/
/************************** USED IN STORE DATA**************************/
/**********************************************************************/

void BitcoinExchange::addEntry(std::map<std::string, float> &data, const std::string &date, float rate)
{

    // std::cout << date << C_CYAN "|" C_RESET << rate << std::endl; // Debug: printing the parsed values
    data[date] = rate;
}
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
bool BitcoinExchange::skipEntry(std::stringstream &lineStream, std::string &line, std::string &date, std::string &exchangeRate, float &rate, const std::string &type)
{
    std::map<std::string, float> mapped_data;
    type != REF_TYPE ? mapped_data = input_data : mapped_data = ref_data;

    if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, exchangeRate))
    {
        error_message = "Invalid format: " + line;
        return true;
    }
    // trim white space for date
    // date.erase(0, date.find_first_not_of(" \t\r"));
    // date.erase(date.find_last_not_of(" \t\r") + 1);
    if (!isValidDate(date, line))
        return true;
    if (!convertToNumber(exchangeRate, rate))
    {
        error_message = "Invalid rate number: " + line;
        return true; // skip this line and continue to the next
    }
    if (rate < 0 || rate > 1000)
    {
        error_message = "Invalid rate range: " + line;
        return true; // skip this line and continue to the next
    }
    if (mapped_data.find(date) != mapped_data.end()) // i need to use the map based on what file i use
    {
        // decided to not save dups
        error_message = "Duplicate found: '" + line + "'";
        return true;
    }
    return false;
}

/* Helper functions to check date and rate numbers*/
bool BitcoinExchange::isValidDate(const std::string &date, const std::string &line)
{
    // make sure that olnly - and numbers are used
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        error_message = "Date is wrong format " + line;
        return false;
    }

    // Extract and convert to int for numeric checks
    int year, month, day;
    if (!convertToNumber(date.substr(0, 4), year) ||
        !convertToNumber(date.substr(5, 2), month) ||
        !convertToNumber(date.substr(8, 2), day))
        return false;

    // Days in month - 0 to 11
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // February has 28 days normally, but 29 in leap years (every 4 year vy approxiamtion)
    bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); // execept for century years (unless divisble by 400)
    if (leapYear)
        daysInMonth[1] = 29; // feb  changes
    // Numeric range checks
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1])
    {
        error_message = "Date out of range: " + line;
        return false;
    }
    return true;
}

template <typename Num>
bool BitcoinExchange::convertToNumber(const std::string &s, Num &type)
{
    // Basic check: ensure Num is not std::string (using typeid)
    assert(typeid(Num) != typeid(std::string) && "convertToNumber: Num must be a numeric type, not std::string");

    if (s.empty())
    {
        error_message = "Rate is empty: " + s;
        return false;
    }
    if (::isspace(s[0]))
    {
        error_message = "Rate starts with space (invalid format): " + s;
        return false;
    }
    std::stringstream stream(s); // stream adapts based on the num type passed
    stream >> std::ws;           // skips leading spaces
    if (!(stream >> type))       // extraction to type fails
    {
        error_message = "Float stream extraction failed at line:" + s;
        return false;
    }
    stream >> std::ws; // skips trailing spaces
    if (!stream.eof()) // if something  is left (letters, extra chars)
    {
        error_message = "Found non_digit types at line:" + s;
        return false;
    }
    return true;
}
