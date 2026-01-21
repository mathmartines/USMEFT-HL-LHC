#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

/// @brief - Saves the one dimension projections
void saveOneDimensionProjections(std::string filename, const std::vector<double>& coef_values, const std::vector<double>& chi_values);

/// @brief - Saves the two dimension projections
void saveTwoDimensionProjections(std::string filename, const std::vector<double>& xcoef_values, const std::vector<double>& ycoef_values, const std::vector<std::vector<double>>& chi_values, bool transpose=false);

/// @brief - Saves the two dimension projections
void saveTwoDimensionProjections(std::string filename, const std::vector<std::vector<double>>& chi_values, bool transpose=false);

const std::vector<double> initialize_vector(const double start, const double stop, const double step);

const std::vector<std::vector<std::string>> construct_parameters_pairs (std::vector<std::string> coefs);

#endif