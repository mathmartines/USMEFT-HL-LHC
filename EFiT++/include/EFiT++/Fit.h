#ifndef FIT_H
#define FIT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "EFiT++/ChiSquare.h"
#include "EFiT++/Minimizer.h"

/// @todo Consider a better implementation for this class.
/// @class Fit
/// @brief Handles the fit.
///        It can compute one- and two-dimensional projections.
class Fit {
    public:
        Fit(ChiSquare* chi_square, const Minimizer* minimizer): _chi_square(chi_square), _minimizer(minimizer) {}

        /// @brief Minimizes the chi-square.
        const double minimizeChiSquare(std::vector<double>& initial_guess);

        /// @brief Calculates the one-dimensional projection of the chi-square.
        const std::vector<double> computeOneDimProjection(const std::vector<double>& coef_values, const bool show_results = false) const;

        /// @brief Calculates the confidence interval.
        /// @param coef_values possible values to search for the confidence interval.
        /// @param show_results True if the value of chi-square at each point must be displayed.
        const std::vector<double> findConfidenceInterval(const std::vector<double>& coef_values, const bool show_results = false) const;

        /// @brief Calculates the two-dimensional projection of the chi-square.
        const std::vector<std::vector<double>> computeTwoDimProjection(
                    const std::vector<double>& xcoef_values,
                    const std::vector<double>& ycoef_values,
                    const int max_xlaps = 1,
                    const int max_ylaps = 0) const;

        /// @brief Evaluates the chi-square over the set of WCs.
        const double evaluateChiSquare(const std::vector<double>& coef_values, std::vector<double>& remaining_values) const;

        /// @brief Getters.
        const double& chi_min() const { return _chimin; }
        const std::vector<double>& bestfit_values() const { return _bestfit_values; }

    private:
        /// Pointer to the chi-square object (non-owning).
        ChiSquare* _chi_square;

        /// Pointer to the minimizer object (non-owning).
        const Minimizer* _minimizer;

        /// Stores the value of the chi-square at the minimum.
        double _chimin;

        /// Values of the coefficients at the minimum.
        std::vector<double> _bestfit_values;

        /// @brief Finds the index of the value that lies on the 95% C.L. limit.
        const int findIndexForValue(const int min_index,
                                const int max_index,
                                const double& chi_value,
                                const bool reverse,
                                const std::vector<double>& chi_values) const;
};

#endif
