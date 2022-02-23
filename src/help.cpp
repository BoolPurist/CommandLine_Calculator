#include <iostream>
#include "help.hpp"

void print_help()
{
    const char* help_message = R"(
        Takes numbers and calculates a result according to given command.
        
        Note: command can be given as in line arguments or 
        via interactive mode. If no in line arguments or no numbers are given,
         then the interactive mode is started.

        Syntax:
        <command> <number> <number> ... <number>

        <command>: Kind of calculation to be performed.
        <number>: A whole or floating number.

        List of commands:
        sum - Prints result of adding up all given numbers.
        min - Prints the smallest number among the given numbers.
        max - Prints the greatest number among the given numbers.
        product - Prints result of multiplying every given number.
        sort - Prints given number in sorted order.
        median - Prints the median of given numbers.
        average - Prints average of given numbers.
        size - Prints number of the given numbers.
        help, -h, --help - Displays this information.
    )";

    std::cout << help_message << std::endl;
}