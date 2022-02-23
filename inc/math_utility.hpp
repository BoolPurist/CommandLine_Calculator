#ifndef header_math_utility
#define header_math_utility

#include <vector>
#include <algorithm>

namespace math_utility
{
  double calc_sum(const std::vector<double>& toCalculateFrom);
  double calc_avg(const std::vector<double>& toCalculateFrom);
  double calc_mult(const std::vector<double>& toCalculateFrom);
  double calc_min(const std::vector<double>& toCalculateFrom);
  double calc_max(const std::vector<double>& toCalculateFrom);
  std::vector<double> create_sorted_sequence(const std::vector<double>& toBeCopied);
  double get_median_from(const std::vector<double>& toExtractMedianFrom);
}

#endif