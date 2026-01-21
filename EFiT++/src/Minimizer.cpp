#include "EFiT++/Minimizer.h"


double NLoptMinimizer::nlopt_signature_function(const std::vector<double>& coefs, std::vector<double> &grad, void* chi_square) {
    /// Transforms to a chi-square pointer
    auto* chiSqObj = static_cast<ChiSquare*>(chi_square);

    /// Evaluates the function
    double chi_value = chiSqObj->evaluate(coefs);

    /// Evaluates the chi-square
    return chi_value;
}

double NLoptMinimizer::nlopt_signature_prof_function(const std::vector<double>& coefs, std::vector<double> &grad, void* chi_square) {
    /// Transforms to a chi-square pointer
    auto* chiSqObj = static_cast<ChiSquare*>(chi_square);
    // Fixed values for the coefficients
    std::vector<double> all_coefs (chiSqObj->stored_coef_values);
    /// Add the coefs we need to profile
    all_coefs.insert(all_coefs.end(), coefs.cbegin(), coefs.cend());
    /// Evaluates the function
    double chi_value = chiSqObj->evaluate(all_coefs);

    /// Evaluates the chi-square in all the coefficients
    return chi_value;
}


const double NLoptMinimizer::minimize(ChiSquare* chi_square, std::vector<double>& initial_guest) const {
    // creating the optmizer
    nlopt::opt optimizer (nlopt::LN_NELDERMEAD, initial_guest.size());

    // seting the function we wish to minimize
    optimizer.set_min_objective(nlopt_signature_function, chi_square);
    
     // setting tolerance
    optimizer.set_xtol_rel(1e-7);
    optimizer.set_ftol_rel(1e-7);

    // stor
    double min;

    try{
        nlopt::result result;
        for (int i = 0; i < 10; i++)
            result = optimizer.optimize(initial_guest, min);
    }
    catch(std::exception &e) {
        std::cout << "nlopt failed: " << e.what() << std::endl;
    }

   return min;
}

const double NLoptMinimizer::profile(ChiSquare* chi_square, const std::vector<double>& fixed_values, std::vector<double>& initial_guess) const {
    // Creating the optimizer
    nlopt::opt optimizer(nlopt::LN_NELDERMEAD, initial_guess.size());

    // Saves the values of the coefficients we need to maintain fixed
    chi_square->stored_coef_values = fixed_values;

    // Setting the function we wish to minimize
    optimizer.set_min_objective(nlopt_signature_prof_function, chi_square);

    // Setting tolerances
    optimizer.set_xtol_rel(1e-8);
    optimizer.set_ftol_rel(1e-8);

    double min;
    try {
        nlopt::result result = optimizer.optimize(initial_guess, min);
        return min;
    } catch (const std::exception &e) {
        std::cerr << "NLopt failed: " << e.what() << std::endl;
        return std::numeric_limits<double>::max();  // Return a large value on failure
    }
}
