#ifndef MINIMIZER_H
#define MINIMIZER_H

#include <vector>
#include <iostream>
#include "nlopt.hpp"
#include "EFiT++/ChiSquare.h"

/// @class Minimizer
/// @brief Defines an interface that a minimizer should have.
///        In this way, the code is independent of the minimization
///        library that is used.
class Minimizer {
    public:
        /// @brief Returns the value of the chi-square at the minimum.
        ///        It must also store the parameters that minimize the fit
        ///        in the initial_guess vector.
        virtual const double minimize(ChiSquare* chi_square, std::vector<double>& initial_guest) const = 0;

        /// @brief Profiles the chi-square by fixing the first n coefficients
        ///        to the values in fixed_values while minimizing with respect
        ///        to the remaining ones.
        virtual const double profile(ChiSquare* chi_square, const std::vector<double>& fixed_values, std::vector<double>& initial_guest) const = 0;
};

/// @class NLoptMinimizer
/// @brief Uses the NLopt library to perform the minimization.
class NLoptMinimizer : public Minimizer {
    public:
        /// @brief Performs the minimization.
        const double minimize(ChiSquare* chi_square, std::vector<double>& initial_guest) const override;

        /// @brief Profiles the chi-square.
        const double profile(ChiSquare* chi_square, const std::vector<double>& fixed_values, std::vector<double>& initial_guest) const override;

        /// @brief Static function with the signature expected by the NLopt library
        ///        for standard minimization.
        static double nlopt_signature_function(const std::vector<double>& coefs, std::vector<double>& grad, void* chi_square);

        /// @brief Static function with the signature expected by the NLopt library
        ///        for profiling the chi-square.
        static double nlopt_signature_prof_function(const std::vector<double>& coefs, std::vector<double>& grad, void* chi_square);
};

#endif
