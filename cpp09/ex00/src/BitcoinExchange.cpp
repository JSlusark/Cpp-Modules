#include "../headers/BitcoinExchange.hpp"

/* --------------------------- CONSTRUCTORS --------------------------- */

BitcoinExchange::BitcoinExchange(const std::string &input_file) : ref_file("data.csv"), input_file(input_file)
{
    try
    {
        storeData(ref_file, ref_data);
        storeData(input_file, input_data);
        printConversion();

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
    int line_i = 1;
    logMessage(LOG, "Initiating data from file: " C_YELLOW + fileName + C_RESET);
    checkFile(fileName, fileStream); // checks reference file);
    std::string line, date, exchangeRate;
    float rate;
    std::getline(fileStream, line); // skips header
    while (std::getline(fileStream, line))
    {
        line_i++;
        if (line.empty())
            continue; // ignores blank lines and goes to next iteration
        std::stringstream lineStream(line);
        if (skipEntry(lineStream, line, date, exchangeRate, rate, line_i))
            continue;
        else
            addEntry(data, date, rate, line, line_i); // adds entry to map if date is valid or overwrites if date already exists
        logMessage(C_GREEN "[ADDED]" C_RESET, " '" + date + " , " + asString(rate) + "'" C_RESET);
    }
    if (data.empty())
        throw std::invalid_argument(EXCEPTION "No valid data found in file");
    logMessage(SUCCESS, fileName + " mapped data was stored successfully into BitcoinExchange exchange object");
}

/*_________________________________________________________ HELPER FUNCTIONS_________________________________________________________ */

/**********************************************************************/
/************************** USED IN convert PRICES**************************/
/**********************************************************************/

/* converts and  Prints */
void BitcoinExchange::printConversion()
{
    // std::map<std::string, float> data = getData();
    // std::map<std::string, float> converted_data;
    logMessage(DEBUG, "Converting " C_YELLOW + input_file + C_RESET " exchange rates based on data from " C_YELLOW + ref_file + C_RESET);
    std::map<std::string, float>::const_iterator input_it;

    // Iterates through input_data until it is not end
    for (input_it = input_data.begin(); input_it != input_data.end(); ++input_it) // why pre? does it skip something?
    {
        // finds date in map
        // std::string date = input_it->first;
        std::map<std::string, float>::const_iterator ref_it = ref_data.find(input_it->first);
        // float conversion = input_it->second * ref_it->second;

        if (ref_it != ref_data.end()) // If input_data date found in ref_data
        {
            input_data[input_it->first] *= ref_it->second; // stores multiplied input[date]'s rate * ref[date]'s rate and stores
            logMessage(C_GREEN "[CONVERTED]" C_RESET, " '" + input_it->first + " , " + asString(input_data[input_it->first]) + "'" C_RESET);
        }
        else // If input_date not found in ref_data
        {
            // Find the closest earlier date in ref_data
            ref_it = ref_data.lower_bound(input_it->first);
            // if (ref_it != ref_data.begin())
            //     --ref_it; // Move to the closest earlier date
            if (ref_it != ref_data.end())
            {
                input_data[input_it->first] *= ref_it->second; // stores multiplied input[date]'s rate * ref[closest_date]'s rate and stores
                logMessage(C_GREEN "[CONVERTED]" C_RESET, " '" + input_it->first + " , " + asString(input_data[input_it->first]) + "'" C_RESET);
            }
            else
            {
                logMessage(ERROR, "No closest date found from ref_file for " + input_file + C_RED "\n        Found at <line " + "asString(line_i)" + ">:" C_RESET + "'" + input_it->first + " , " + asString(input_data[input_it->first]) + "'");

                // logMessage(ERROR, "No earlier date found in " C_YELLOW + ref_file + C_RESET " for input date " C_YELLOW + input_it->first + C_RESET ", skipping entry.");
                continue; // Skip this entry if no earlier date is found
            }
        }
        // Else If input_date is not found i need to use the closest date from ref and
        // input_it->first = closest_ref->first  <--- need to overwrite input_it date with closeset rate
        // input_it->second = closest_ref->second
        // possibly add a flag in the print that alerts user of this?
    }

    // for (std::map<std::string, float>::const_iterator it = converted_data.begin(); it != converted_data.end(); ++it)
    // {
    //     std::cout << it->first << " => " << it->second << std::endl;
    // }
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
bool BitcoinExchange::skipEntry(std::stringstream &lineStream, std::string &line, std::string &date, std::string &exchangeRate, float &rate, int line_i)
{
    // trim white space for date
    date.erase(0, date.find_first_not_of(" \t\r"));
    date.erase(date.find_last_not_of(" \t\r") + 1);
    if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, exchangeRate))
    {
        logMessage(ERROR, "Invalid line found, date and/or rate field are empty.   \n        " C_RED "Found at <line " + asString(line_i) + ">:" C_RESET + "'" + line + "'");
        return true;
    }
    if (!isValidDate(date, line, line_i))
        return true;
    if (!convertToNumber(exchangeRate, rate))
    {
        logMessage(ERROR, "Invalid line found, rate is not a float.\n        " C_RED "Found at <line " + asString(line_i) + ">:" C_RESET + "'" + line + "'");
        return true; // skip this line and continue to the next
    }
    if(rate < 0 || rate > 1000)
    {
        logMessage(ERROR, "Invalid line found, rate is < 0 or > 1000.\n        " C_RED "Found at <line " + asString(line_i) + ">:" C_RESET + "'" + line + "'");
        return true; // skip this line and continue to the next
    }
    return false;
}

void BitcoinExchange::addEntry(std::map<std::string, float> &data, const std::string &date, float rate, const std::string &line, int line_i)
{

    // std::cout << date << C_CYAN "|" C_RESET << rate << std::endl; // Debug: printing the parsed values
    if (data.find(date) != data.end()) // if date already exists in map, warn user
        logMessage(WARNING, "Duplicate date entry found.\n          Overwriting with: " C_YELLOW " <line " + asString(line_i) + "> " C_RESET + line);
    data[date] = rate;
}

/* Helper functions to check date and rate numbers*/
bool BitcoinExchange::isValidDate(const std::string &date, const std::string &line, int line_i)
{
    // make sure that olnly - and numbers are used
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        logMessage(ERROR, "Invalid date format, line is not YYYY-MM-DD.\n        " C_RED "Found at <line " + asString(line_i) + ">:" C_RESET + "'" + line + "'");
        return false;
    }

    // Extract and convert to int for numeric checks
    int year, month, day;
    if (!convertToNumber(date.substr(0, 4), year) ||
        !convertToNumber(date.substr(5, 2), month) ||
        !convertToNumber(date.substr(8, 2), day))
    {
        logMessage(ERROR, "Invalid date, non-numeric parts.\n        " C_RED "Found at <line " + asString(line_i) + ">:" C_RESET + "'" + line + "'");
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
        logMessage(ERROR, "Date out of range.  \n        " C_RED "Found at <line " + asString(line_i) + ">:" C_RESET + "'" + line + "'");
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
