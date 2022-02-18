#include <iostream>
#include "process.hpp"

std::vector<std::string> create_from_arguments(char** args, const int& argv)
{
    std::vector<std::string> extracted_arguments{};
    extracted_arguments.assign(args, args + argv);
    return extracted_arguments;
}

void convert_comma_to_point(std::vector<std::string>& toConvert)
{
    for (auto& nextToConvert: toConvert)
    {
        int found_i = -1;
        int next_i = 0;
        const int count = nextToConvert.size();
        
        do
        {
            found_i = nextToConvert.find(",");
            if (found_i == -1)
            {
                break;
            }

            nextToConvert.replace(found_i, 1, ".");
            next_i = found_i + 1;
        } while(next_i != count);
    }
}



