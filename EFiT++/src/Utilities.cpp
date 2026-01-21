#include "EFiT++/Utilities.h"

void saveOneDimensionProjections(std::string filename, const std::vector<double>& coef_values, const std::vector<double>& chi_values) {
    // Creates the file
    std::ofstream output_file;
    output_file.open(filename);
    output_file << std::setprecision(6);
    
    // Saves the content
    for (size_t i = 0; i < coef_values.size(); i++) 
        output_file << std::scientific << coef_values[i] << "   " << std::scientific << chi_values[i] << "\n";
    
    // Close file
    output_file.close();
}

void saveTwoDimensionProjections(std::string filename, const std::vector<double>& xcoef_values, const std::vector<double>& ycoef_values, const std::vector<std::vector<double>>& chi_values, bool transpose) {
    // Creates the file
    std::ofstream output_file;
    output_file.open(filename);
    output_file << std::setprecision(6);

    const std::vector<double>& xaxis = transpose? ycoef_values: xcoef_values;
    const std::vector<double>& yaxis = transpose? xcoef_values: ycoef_values;
    
    /// Saves the content
    for (size_t ix = 0; ix < xaxis.size(); ix++) {
        for (size_t iy = 0; iy < yaxis.size(); iy++) {
            const double& chival = transpose? chi_values[iy][ix] : chi_values[ix][iy];
            output_file << std::scientific << xaxis[ix] << "   " << yaxis[iy] << "   " << chival << "\n";
        }
    }
    // for (size_t ix = 0; ix < xcoef_values.size(); ix++) {
    //     for (size_t iy = 0; iy < ycoef_values.size(); iy++) 
    //         output_file << std::scientific << xcoef_values[ix] << "   " << ycoef_values[iy] << "   " << chi_values[ix][iy] << "\n";
    // }

    /// Close file
    output_file.close();
}

void saveTwoDimensionProjections(std::string filename,  const std::vector<std::vector<double>>& chi_values, bool transpose) {
    // Creates the file
    std::ofstream output_file;
    output_file.open(filename);
    output_file << std::setprecision(6);

    for (const auto& row: chi_values) {
        double xval = row[0], yval = row[1];
        if (transpose) std::swap(xval, yval);
        output_file << std::scientific << xval << "   " << yval << "   " << row[2] << "\n";   
    }

    /// Close file
    output_file.close();
}

const std::vector<double> initialize_vector(const double start, const double stop, const double step) {
    std::vector<double> xvalues; 
    for (double val = start; val <= stop; xvalues.push_back(val += step));
    return xvalues;
}

const std::vector<std::vector<std::string>> construct_parameters_pairs (std::vector<std::string> coefs) {
    std::vector<std::vector<std::string>> possible_parameters;

    for(int i = 0; i < coefs.size() - 1; i++) {
        for (int j = i + 1; j < coefs.size(); j++) {
            /// Parameters for the fits
            std::vector<std::string> params = {coefs[i], coefs[j]};
            for (int counter = 0; counter < coefs.size(); counter++) {
                if (counter != i && counter != j) params.push_back(coefs[counter]);
            }
            possible_parameters.push_back(params);
        }
    }
    return possible_parameters;
}