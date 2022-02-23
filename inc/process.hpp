#ifndef header_process
#define header_process

#include <vector>
#include <string>

namespace process
{

    std::vector<std::string> create_from_arguments(const int& argc, char** argv);

    void convert_comma_to_point(std::vector<std::string>& toConvert);

    /// Can throw invalid_argument if one element of paramete toCreateFrom 
    /// is not convertible to a double value. It prints out the value to console 
    /// which is not convertible to a number
    std::vector<double> create_numbers_from(std::vector<std::string>& toCreateFrom);

    void process_arguments_and_print_result(const std::string& command, const std::vector<double>& numbers);
    void print_result(const std::string& message, double result);
    void print_sequence_onLine(const std::string& message, const std::vector<double> sequence);
    std::string trim_spaces_left_right(const std::string& toTrim);
    bool requests_help(const std::string& givenCommand);

}
#endif