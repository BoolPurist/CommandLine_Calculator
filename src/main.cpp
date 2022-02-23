#include <iostream>
#include <sstream>

#include "process.hpp"
#include "math_utility.hpp"
#include "help.hpp"

int main(int argc, char** argv)
{
    bool noUserInLineArguments = argc < 3;

    std::string enteredCommand{};
    std::vector<std::string> arguments{};

    if (noUserInLineArguments)
    {
        std::cout << "Entering interactive mode" << std::endl;
        // User is asked to provide input in an interactive mode.
        std::cout << "Enter the command:" << std::endl;
        std::getline(std::cin, enteredCommand);

        if (requests_help(enteredCommand))
        {
            print_help();
            return 0;
        }

        std::cout << "Enter the numbers:" << std::endl;
        std::string lineOfNumbers{};
        std::getline(std::cin, lineOfNumbers);

        std::istringstream toBeSplitted{std::move(lineOfNumbers)};

        std::string oneNumber{};
        
        // Split line of numbers by space.
        while(std::getline(toBeSplitted, oneNumber, ' '))
        {
            bool isEmptyToken = oneNumber.compare("") == 0;
            if (!isEmptyToken)
            {
                arguments.push_back(oneNumber);
            }
        }
    }    
    else
    {

        // In line arguments are parsed
        arguments = create_from_arguments(argc, argv);
        enteredCommand = arguments.front();

        if (requests_help(enteredCommand))
        {
            print_help();
            return 0;
        }

        arguments.erase(arguments.begin());
    }
    
    
    // Numbers are processed according to a given valid command.
    convert_comma_to_point(arguments);
    std::vector<double> parsedNumbers = create_numbers_from(arguments);

    process_arguments_and_print_result(enteredCommand, parsedNumbers);    

    return 0;
}
