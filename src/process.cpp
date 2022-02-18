#include <iostream>
#include <set>
#include "process.hpp"

std::vector<std::string> create_from_arguments(const int& argc, char** argv)
{
    std::vector<std::string> extracted_arguments{};
    // argv + 1 strips name program from names.
    extracted_arguments.assign(argv + 1, argv + argc);
    return extracted_arguments;
}

void convert_comma_to_point(std::vector<std::string>& toConvert)
{
    for (auto& nextToConvert: toConvert)
    {
        int found_i {-1};
        int next_i {0};
        
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

std::vector<double> create_numbers_from(std::vector<std::string>& toCreateFrom)
{
    std::vector<double> createdNumbers(toCreateFrom.size(), 0.0);
    for(size_t i = 0; i < toCreateFrom.size(); i++)
    {
        double extractedNumber {0.0};

        try
        {
            extractedNumber = std::stod(toCreateFrom.at(i));
            createdNumbers.at(i) = extractedNumber;
        }
        catch(std::invalid_argument& exception)
        {
            std::cout << "value (" << toCreateFrom.at(i) << ") is not number" << std::endl;
            throw exception;
        }
                
    }

    return createdNumbers;
}