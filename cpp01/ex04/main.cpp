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
    size_t pos = 0;
    // std::cout << "ORIGINAL:" << std::endl;
    // std::cout << line << std::endl;
    while(line.find(s1, pos) !=  std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    // std::cout << "REPLACEMENT:" << std::endl;
    // std::cout << line << std::endl;
}

// int main( std::string file_name, std::string s1, std::string s2)
int main(int argc, char **argv)
{
    std::ifstream istream;
    // std::ofstream ostream;

    if (argc < 4 || argc > 4)
    {
        printf("Error: wrong arg count. Please write './program_name file arg2 arg3' \n");
        return (1);
    }
    char *file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    istream.open(file, std::ios::in); // extrapulates file content in the istream
    std::ofstream new_file("new_file.txt");
    std::string line;
    std::cout << "String1: " << s1 << std::endl;
    std::cout << "String2: " << s2 << std::endl;
    while (std::getline(istream, line)) // gets the line from the istream
    {
        std::string dup = line;
        replace_word(dup, s1, s2);
        // std::cout << "NL:" << std::endl;
        // std::cout << line << std::endl;
        new_file << dup << std::endl;
    }

    // std::cout << file << std::endl;
    // // swap s1 with s2 and vice versa
    // std::cout << s1 << std::endl;
    // std::cout << s2 << std::endl;
    // s1.swap(s2);
    // std::cout << s1 << std::endl;
    // std::cout << s2 << std::endl;
    // // int fd =

    return (0);
}