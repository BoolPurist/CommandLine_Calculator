#include <iostream>
#include "process.hpp"

int main(int argc, char** argv)
{
    
    auto result = create_from_arguments(argc, argv);
    convert_comma_to_point(result);
    std::vector<double> numbers = create_numbers_from(result);
    
    for (const auto& argument: numbers)
    {
        std::cout << argument << std::endl;
    }
}