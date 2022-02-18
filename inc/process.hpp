#ifndef header_process
#define header_process

#include <vector>
#include <string>

std::vector<std::string> create_from_arguments(const int& argc, char** argv);

void convert_comma_to_point(std::vector<std::string>& toConvert);

/// Can throw invalid_argument if one element of paramete toCreateFrom 
/// is not convertible to a double value. It prints out the value to console 
/// which is not convertible to a number
std::vector<double> create_numbers_from(std::vector<std::string>& toCreateFrom);

#endif