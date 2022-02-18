#include <iostream>
#include "process.hpp"

int main(int argc, char** argv)
{
    auto result = create_from_arguments(argv, argc);
    convert_comma_to_point(result);
    
    for (const auto& argument: result)
    {
        std::cout << argument << std::endl;
    }
}