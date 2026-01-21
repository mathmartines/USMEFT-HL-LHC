#include "EFiT++/Fit.h"

const double Fit::minimizeChiSquare (std::vector<double>& initial_guess) {
    /// Delegates the job to the minimizer
    _chimin = _minimizer->minimize(_chi_square, initial_guess);
    _bestfit_values = initial_guess;
    return _chimin;
}

const std::vector<double> Fit::computeOneDimProjection(const std::vector<double>& coef_values, const bool show_results) const {
    // Ensure that the best fit values have been computed before projecting
    if (_bestfit_values.empty()) {
        throw std::runtime_error("Best-fit values must be determined before computing the one-dimensional projection.");
    }

    // Reserve space for Chi-Square values to avoid reallocations
    std::vector<double> chi_square_values (coef_values.size());

    // Prepare remaining coefficients foGr profiling if necessary
    std::vector<double> remaining_coefs(_bestfit_values.size() - 1, 0);

    // Compute Chi-Square for each value in the given coefficient vector
    int max_number_of_laps = 2;

    /// Loops over the values four times
    for (int nlaps = 0; nlaps < max_number_of_laps; nlaps++) {
        // Loops over the entire range of values and comes back
        // 1 for forward, -1 for backward
        int direction = 1;  
        for (int i = 0; i >= 0 && i < coef_values.size(); i += direction) {
            // Updates the entry with the value of the chi-square
            chi_square_values[i] = evaluateChiSquare({coef_values[i]}, remaining_coefs);
            
            if (show_results)
                std::cout << "chi2(" <<  coef_values[i] << ") = " << chi_square_values[i] - _chimin << std::endl;
            
            // Reverse direction we get to the end of the vector
            if (i == coef_values.size() - 1 && direction == 1) 
                direction = -1;  // Start going backward 
        }
    }

    return chi_square_values;
}

const std::vector<double> Fit::findConfidenceInterval(const std::vector<double>& coef_values, const bool show_results) const {
    /// Find the one dimensional projection of the chi-square
    const std::vector<double> chisq = computeOneDimProjection(coef_values, show_results);
    /// Finds the minimum value
    const int min_index = std::min_element(chisq.begin(), chisq.end()) - chisq.begin();
    /// Finds lower and upper index 
    /// 2sigma = 3.84146
    const int upper_index = findIndexForValue(min_index, chisq.size() - 1, chisq[min_index] + 1., false, chisq);
    const int lower_index = findIndexForValue(0, min_index, chisq[min_index] + 1., true, chisq);
    /// print values
    std::cout << "[" << coef_values[lower_index] << ", " << coef_values[upper_index] << "]" << std::endl;
    return std::vector<double> ({coef_values[lower_index], coef_values[upper_index]});
}

const int Fit::findIndexForValue (const int min_index, const int max_index, const double& chi_value, const bool reverse, const std::vector<double>& chi_values) const {
    /// Computes the middle position 
    const int middle_index = (min_index + max_index) / 2;

    /// Base case: the value is reached
    if (middle_index == min_index)
        return min_index;

    /// Recursive step: 
    if (chi_values[middle_index] < chi_value) {
        if (reverse) return findIndexForValue(min_index, middle_index, chi_value, reverse, chi_values);
        return findIndexForValue(middle_index, max_index, chi_value, reverse, chi_values);
    }

    if (reverse) 
        return findIndexForValue(middle_index, max_index, chi_value, reverse, chi_values);
    return findIndexForValue(min_index, middle_index, chi_value, reverse, chi_values);
}

const std::vector<std::vector<double>> Fit::computeTwoDimProjection(const std::vector<double>& xcoef_values, const std::vector<double>& ycoef_values, const int max_xlaps, const int max_ylaps) const {
    // Ensure that the best fit values have been computed before projecting
    if (_bestfit_values.empty()) {
        throw std::runtime_error("Best-fit values must be determined before computing the one-dimensional projection.");
    }

    /// Creates a vector to alocate the results
    std::vector<std::vector<double>> chi_square_values (xcoef_values.size(), std::vector<double> (ycoef_values.size(), 0));   

    // Prepare remaining coefficients for profiling if necessary
    std::vector<double> remaining_coefs(_bestfit_values.begin() + 2, _bestfit_values.end());

    /// Evaluates the chi-square over the grid of coefficients
    int y_direction = 1;
    int x_direction = 1;
    int initial_pos_row = 0;

    // Counter to keep track the number of laps
    int ylaps = 0;


    for (int iy = 0; iy < xcoef_values.size() && iy >= 0; iy += y_direction) {
        int xlaps = 0;

        for (int ix = initial_pos_row; ix < ycoef_values.size() && ix >=0; ix += x_direction) {
            // Coefficients for this iteration
            std::vector<double> current_coefs = {xcoef_values[iy], ycoef_values[ix]}; 
            chi_square_values[iy][ix] = evaluateChiSquare(current_coefs, remaining_coefs) - _chimin;

            /// Check if it's ok
            std::cout << "chi2(" << xcoef_values[iy] << ", " << ycoef_values[ix] << ") = " << chi_square_values[iy][ix] << std::endl;
            
            /// Reverse the direction of the iteration over the row
            if (((ix == ycoef_values.size() - 1 && x_direction == 1) || (ix == 0 && x_direction == -1)) &&  xlaps < max_xlaps) {
                x_direction = -x_direction;
                xlaps++;
            }
        }   
        /// Reverse the direction over the column
        if (((iy == xcoef_values.size() - 1 && y_direction == 1) || (iy == 0 && y_direction == -1)) && ylaps < max_ylaps) {
            initial_pos_row = y_direction == 1 ? ycoef_values.size() - 1 : 0;
            y_direction = -y_direction;
            ylaps++;
        }

        /// Initializes the direction of the row for the next 
        x_direction = y_direction;
    }

    return chi_square_values;
}

const double Fit::evaluateChiSquare(const std::vector<double>& coef_values, std::vector<double>& remaining_values) const {
    if (remaining_values.empty()) 
        return _chi_square->evaluate(coef_values);
    return _minimizer->profile(_chi_square, coef_values, remaining_values);
}