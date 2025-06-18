/*
    std::fstream is a file stream class used to read from and write to files.
    It combines the functionality of:
        - std::ifstream → for input (reading from files, extraction operator (>>) is used to remove values from the stream)
        - std::ofstream → for output (writing to files, insertion operator (<<) is used to put values in the stream)
        - std::fstream can do both reading and writing, depending on how you open it.

    ios is a typedef for std::basic_ios<char> that defines a bunch of stuff that is common to both input and output streams.


*/

#include <iostream> // preprocess statement for input/output stream library
#include <string>   // preprocess statement for input/output stream library
#include <iostream>
#include <fstream>

void replace_word(std::string &line, std::string s1, std::string s2)
{
    if(s1.empty()) // avoids ending loop
        return;

    size_t pos = 0;
    int i = 0;
    while((pos = line.find(s1, i)) !=  std::string::npos)
    {
        line.erase(pos, s1.length());
        if(!s2.empty()) // to avoid adding a space is s2 is ""
            line.insert(pos, s2);
        i = pos + s2.length(); // for recursive replacement cases
    }
}

// int main( std::string file_name, std::string s1, std::string s2)
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: wrong arg count. Please write Usage: ./SedIsForLosers <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string i_file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    // std::ofstream ostream;

    std::ifstream istream(i_file.c_str()); // use constructor to create immediately instead of declaration + .open, also closes file by default
    if(!istream.is_open())
    {
        std::cout << "Error: cannot open i_file" << std::endl;
        return 1;
    }
    std::string file_name = std::string(i_file) + ".replace";
    std::ofstream o_file(file_name);
    if (!o_file.is_open())
    {
        std::cerr << "Error: cannot create output file\n";
        return 1;
    }

    std::string line;
    while (std::getline(istream, line)) // gets the line from the istream
    {
        std::string dup = line;
        replace_word(dup, s1, s2);
        o_file << dup << std::endl;
    }
    return (0);
}