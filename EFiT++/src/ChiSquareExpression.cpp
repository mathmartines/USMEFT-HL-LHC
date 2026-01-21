#include "EFiT++/ChiSquareExpression.h"

const double GaussianChiSquareHLLHC(const std::valarray<double>& prediction, const ExperimentalData& experimental_data) {
    /// Luminosity in fb-1
    const double lumi = 3000;
    
    /// Experimental data (in fb)
    const std::valarray<double>& model_pred = experimental_data.get_data("data");
    /// SM prediction (fb)
    const std::valarray<double>& sm_pred = experimental_data.get_data("SM");
    /// Bin edges in (GeV)
    const std::valarray<double>& bin_edges = experimental_data.get_data("bin-edges");

    /// Central values of the bins (in TeV)
    std::valarray<double> central_values (0., bin_edges.size() - 1);
    for (int i = 0; i < bin_edges.size() - 1; i++)
        central_values[i] = i != bin_edges.size() - 2 ? 0.001 * (bin_edges[i] + bin_edges[i + 1])/2. : 0.001 * bin_edges[i];

    /// Systematic uncertainties
    const std::valarray<double> sys_error_sq = std::pow(0.05 * central_values * model_pred, 2);

    /// Statistical uncertainties 
    const std::valarray<double> stat_error_sq = model_pred / lumi;

    /// Chi-square value 
    return (std::pow(model_pred - sm_pred - prediction, 2) / (stat_error_sq + sys_error_sq)).sum();
}

const double GaussianChiSquareEWPO (const std::valarray<double>& prediction, const ExperimentalData& experimental_data) {
    /// Experimental data
    const std::valarray<double>& obs_data = experimental_data.get_data("data");
    /// SM prediction
    const std::valarray<double>& background = experimental_data.get_data("SM");
    /// inverse of the cov matrix
    const std::valarray<std::valarray<double>>& inv_cov_mat = experimental_data.get_inv_cov_matrix();
    /// Data - (theory prediction + background)
    const std::valarray<double> diff = obs_data - (background + prediction);

    /// Calculating the chi-square
    std::valarray<double> result (obs_data.size());

    // /// First matrix multiplcation
    for (int i = 0; i < inv_cov_mat.size(); i++) 
        result[i] = (inv_cov_mat[i] * diff).sum();
    
    /// Returns the value of the chi-square
    return (diff * result).sum();
}
