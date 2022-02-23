#include <vector>
#include <iostream>
#include <algorithm>

namespace math_utility
{

  double calc_sum(const std::vector<double> &toCalculateFrom)
  {
    double total_sum{0.0};

    for (const auto &number : toCalculateFrom)
    {
      total_sum += number;
    }

    return total_sum;
  }

  double calc_avg(const std::vector<double> &toCalculateFrom)
  {
    double average{0.0};

    for (const auto &number : toCalculateFrom)
    {
      average += number;
    }

    double divider = static_cast<double>(toCalculateFrom.size());
    return average / divider;
  }

  double calc_mult(const std::vector<double> &toCalculateFrom)
  {
    if (toCalculateFrom.size() == 0)
    {
      return 0.0;
    }

    double product{1.0};

    for (const auto &number : toCalculateFrom)
    {
      product *= number;
    }

    return product;
  }

  double calc_min(const std::vector<double> &toCalculateFrom)
  {
    if (toCalculateFrom.size() == 0)
    {
      return 0.0;
    }

    double min{toCalculateFrom.at(0)};

    for (const auto &number : toCalculateFrom)
    {
      min = std::min(number, min);
    }

    return min;
  }

  double calc_max(const std::vector<double> &toCalculateFrom)
  {
    if (toCalculateFrom.size() == 0)
    {
      return 0.0;
    }

    double max{toCalculateFrom.at(0)};

    for (const auto &number : toCalculateFrom)
    {
      max = std::max(number, max);
    }

    return max;
  }

  std::vector<double> create_sorted_sequence(const std::vector<double> &toBeCopied)
  {
    auto toBeSorted = toBeCopied;
    std::sort(toBeSorted.begin(), toBeSorted.end());
    return toBeSorted;
  }

  double get_median_from(const std::vector<double> &toExtractMedianFrom)
  {
    std::vector<double> sorted = create_sorted_sequence(toExtractMedianFrom);

    int size = sorted.size();
    bool isSizeOdd = size % 2 == 0;

    int middleIndex = size / 2;
    double middleValue = sorted.at(middleIndex);

    if (!isSizeOdd)
    {
      return middleValue;
    }
    else
    {
      double bottomMiddle = sorted.at(middleIndex - 1);      
      return (middleValue + bottomMiddle) / 2.0;
    }
  }

}
