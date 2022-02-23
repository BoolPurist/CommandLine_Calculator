#include <iostream>
#include <set>
#include <string>

#include "math_utility.hpp"
#include "help.hpp"

#include "process.hpp"

namespace
{
  bool is_command(const std::string& givenCommand, const std::string& wantedCommand);
}

namespace process
{
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

  void process_arguments_and_print_result(const std::string& command, const std::vector<double>& numbers)
  {
    if (is_command(command, "sum"))
    {
      double result = math_utility::calc_sum(numbers);
      print_result("Sum: ", result);
    }
    else if (is_command(command, "product"))
    {
      double result = math_utility::calc_mult(numbers);
      print_result("Product: ", result);
    }
    else if (is_command(command, "min"))
    {
      double result = math_utility::calc_min(numbers);
      print_result("Minimum: ", result);
    }
    else if (is_command(command, "max"))
    {
      double result = math_utility::calc_min(numbers);
      print_result("Maximum: ", result);
    }
    else if (is_command(command, "sort"))
    {
      std::vector<double> sortedSequence = math_utility::create_sorted_sequence(numbers);
      print_sequence_onLine("Sorted Sequence: ", sortedSequence);
    }
    else if (is_command(command, "median"))
    {
      double result = math_utility::get_median_from(numbers);
      print_result("Median: ", result);
    }
    else if (is_command(command, "average"))
    {
      double result = math_utility::calc_avg(numbers);
      print_result("Average: ", result);
    }
    else if (is_command(command, "size"))
    {
      int result = numbers.size();
      print_result("Size: ", result);
    }
    else 
    {
      std::cout << "Command (" << command << ") is not supported" << std::endl;
    }
}

void print_result(const std::string& message, double result)
{
    std::cout << message << result << std::endl;
}

void print_sequence_onLine(const std::string& message, const std::vector<double> sequence)
{
    std::cout << message << std::endl;

    for (const auto& element : sequence)
    {
        std::cout << element << " ";
    }

    std::cout << std::endl;
}

std::string trim_spaces_left_right(const std::string& toTrim)
{
    std::string result{toTrim};
    
    if (result.size() == 0)
    {
        return result;
    }

    // left trimming

    while(std::isspace(result.at(0)))
    {
        result.erase(0, 1);
    }

    // right trimming

    int lastIndex = result.size() - 1;
    while(std::isspace(result.at(lastIndex)))
    {
        result.erase(lastIndex, 1);
        lastIndex = result.size() - 1;
    }

    return result;
  }

  bool requests_help(const std::string& givenCommand)
  {
    return is_command(givenCommand, "help") ||
            is_command(givenCommand, "-h") ||
            is_command(givenCommand, "--help");
  }

}

namespace
{
  bool is_command(const std::string& givenCommand, const std::string& wantedCommand)
  {
    return givenCommand.compare(wantedCommand) == 0;
  }
}

