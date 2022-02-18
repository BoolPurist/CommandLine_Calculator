#ifndef header_math_utility
#define header_math_utility

#include <vector>
#include <algorithm>

double calc_sum(const std::vector<double>& toCalculateFrom);
double calc_avg(const std::vector<double>& toCalculateFrom);
double calc_mult(const std::vector<double>& toCalculateFrom);
double calc_min(const std::vector<double>& toCalculateFrom);
double calc_max(const std::vector<double>& toCalculateFrom);
void sort_sequence(std::vector<double>& toCalculateFrom);

#endif