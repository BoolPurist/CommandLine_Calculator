#include <vector>
#include <algorithm>

double calc_sum(const std::vector<double>& toCalculateFrom)
{
    double total_sum{0.0};

    for (const auto& number : toCalculateFrom)
    {
        total_sum += number;
    }

    return total_sum;
}

double calc_avg(const std::vector<double>& toCalculateFrom)
{
    double average{0.0};

    for (const auto& number : toCalculateFrom)
    {
        average += number;
    }
    
    double divider = static_cast<double>(toCalculateFrom.size());
    return average / divider;
}

double calc_mult(const std::vector<double>& toCalculateFrom)
{
    if (toCalculateFrom.size() == 0)
    {
        return 0.0;
    }

    double product{1.0};

    for (const auto& number : toCalculateFrom)
    {
        product *= number;
    }
    
    return product;
}

double calc_min(const std::vector<double>& toCalculateFrom)
{
    if (toCalculateFrom.size() == 0)
    {
        return 0.0;
    }

    double min{toCalculateFrom.at(0)};

    for (const auto& number : toCalculateFrom)
    {
        min = std::min(number, min);
    }
    
    return min;
}

double calc_max(const std::vector<double>& toCalculateFrom)
{
    if (toCalculateFrom.size() == 0)
    {
        return 0.0;
    }

    double max{toCalculateFrom.at(0)};

    for (const auto& number : toCalculateFrom)
    {
        max = std::max(number, max);
    }
    
    return max;
}

void sort_sequence(std::vector<double>& toCalculateFrom)
{
    std::sort(toCalculateFrom.begin(), toCalculateFrom.end());
}