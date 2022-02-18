#ifndef header_process
#define header_process

#include <vector>
#include <string>

std::vector<std::string> create_from_arguments(char** args, const int& argv);

void convert_comma_to_point(std::vector<std::string>& toConvert);

#endif