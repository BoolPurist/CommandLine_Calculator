#include <iostream>
#include <sstream>

#include "process.hpp"
#include "math_utility.hpp"
#include "help.hpp"

int main(int argc, char** argv)
{
  bool noUserInLineArguments = argc <= 1;

  std::string enteredCommand{};
  std::vector<std::string> arguments{};

  if (noUserInLineArguments)
  {
    std::cout << "Entering interactive mode" << std::endl;
    // User is asked to provide input in an interactive mode.
    std::cout << "Enter the command:" << std::endl;
    std::string untrimmedCommand{};
    std::getline(std::cin, untrimmedCommand);
    enteredCommand = process::trim_spaces_left_right(untrimmedCommand);

    if (process::requests_help(enteredCommand))
    {
        help::print_help();
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
    arguments = process::create_from_arguments(argc, argv);
    enteredCommand = arguments.front();

    if (process::requests_help(enteredCommand))
    {
        help::print_help();
        return 0;
    }

    // Removes command so only the given numbers are contained.
    arguments.erase(arguments.begin());

    if (arguments.size() == 0)
    {
      std::cout << "no numbers given !" << std::endl;
      return -1;
    }

  }
  
  // Numbers are processed according to a given valid command.
  process::convert_comma_to_point(arguments);
  std::vector<double> parsedNumbers = process::create_numbers_from(arguments);

  process::process_arguments_and_print_result(enteredCommand, parsedNumbers);    

  return 0;
}
