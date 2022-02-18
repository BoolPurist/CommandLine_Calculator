#include <iostream>

#include "process.hpp"
#include "math_utility.hpp"

void assert_math(std::vector<double>& input);
void print_result(const char* message, double result);


int main(int argc, char** argv)
{
    auto result = create_from_arguments(argc, argv);
    convert_comma_to_point(result);
    std::vector<double> numbers = create_numbers_from(result);
    assert_math(numbers);
    
    // for (const auto& argument: numbers)
    // {
    //     std::cout << argument << std::endl;
    // }
}

void assert_math(std::vector<double>& input)
{    
    double sum = calc_sum(input);
    double average = calc_avg(input);
    double product = calc_mult(input);
    double min = calc_min(input);
    double max = calc_max(input);
    sort_sequence(input);

    print_result("Sum: ", sum);
    print_result("Average: ", average);
    print_result("Product: ", product);
    print_result("Min: ", min);
    print_result("Max: ", max);

    std::cout << "Sorted" << std::endl;

    for (const auto& argument: input)
    {
        std::cout << argument << std::endl;
    }
}

void print_result(const char* message, double result)
{
    std::cout << message << result << std::endl;
}