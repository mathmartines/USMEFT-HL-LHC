#include "EFiT++/EFTExpansion.h"

void EFTExpansion::build_EFTExpansion(const std::vector<std::string>& wilson_coefs, const EFTExpansionOrder eft_expansion_order) {
    _eft_terms.clear();
    /// Checks all possible combinations of EFT terms
    for (int i = 0; i < wilson_coefs.size(); i++) {
        /// Holds the dimension of the respective term
       const EFTExpansionOrder order_i = _wcoefs[wilson_coefs[i]];

        /// Test only the Wilson coef - linear term allowed
        if (order_i <= eft_expansion_order) {
             _eft_terms.push_back({wilson_coefs[i]});
        }

        /// Interference between WCs
        for(int j = i; j < wilson_coefs.size(); j++) {
            /// Holds the dimension of the j coef
            const EFTExpansionOrder order_j = _wcoefs[wilson_coefs[j]];
            /// Checks if the EFT cross term is allowed
            if (order_i + order_j <= eft_expansion_order) {
                _eft_terms.push_back({wilson_coefs[i], wilson_coefs[j]});
            }
        }
    }

    /// Builds the anomalous matrix for each EFTStorage
    for (EFTStorage* eft_st: _eft_storages) 
        eft_st->buildAnomalousMatrix(_eft_terms);
    
    /// Save the order of the Wilson coefficients
    _wilson_coefs_order = wilson_coefs;
}

const std::valarray<double> EFTExpansion::get_prediction(const std::vector<double>& coefs_values, const EFTStorage& eft_storage) const {
    // Validate storage and coefficient size
    if (std::find(_eft_storages.begin(), _eft_storages.end(), &eft_storage) == _eft_storages.end()) 
        throw std::runtime_error("EFTStorage not registered.");
    if (coefs_values.size() != _wilson_coefs_order.size())
        throw std::runtime_error("Mismatch between Wilson coefficients and provided values.");
    
    // Access anomalous matrix
    const auto& anomalous_matrix = eft_storage.get_AnomalousMatrix();

    if (anomalous_matrix.empty())
        throw std::runtime_error("Anomalous matrix is empty.");

    /// Creates a map with the coefficient values
    std::map<std::string, double> map_coefs_values;
    for (size_t index = 0; index < _wilson_coefs_order.size(); index++)
        map_coefs_values[_wilson_coefs_order[index]] = coefs_values[index];

    // Compute prediction
    std::valarray<double> number_of_evts(eft_storage.get_bins_number());
    for (size_t i = 0; i < anomalous_matrix.size(); ++i) {
        double coef_product = WilsonCoefsProduct(_eft_terms[i], map_coefs_values);
        if (anomalous_matrix[i]) /// Checks if it's not a nullptr
            number_of_evts += coef_product * (*anomalous_matrix[i]);
    }

    return number_of_evts;
}

const double EFTExpansion::WilsonCoefsProduct (const std::vector<std::string>& coefs_names, const std::map<std::string, double>& coefs_values) {
    double coef_value = 1;
    for (const auto& coef_name: coefs_names)
        coef_value *= coefs_values.at(coef_name);
    return coef_value;
}

const std::vector<double> EFTMatching::compute_wilson_coefs_values (const std::vector<double>& coups_values) const {
    if (coups_values.size() != _model_couplings.size())
        throw std::runtime_error("Mismatch between number of couplings in the model and provided values.");
    
    /// Map between the model parameters and its values
    std::map<std::string, double> map_coup_values;
    for (int i = 0; i < _model_couplings.size(); i++)
        map_coup_values[_model_couplings[i]] = coups_values[i];

    /// Gets the order of the WCs
    const std::vector<std::string> &wilson_coefs = _eft_expansion.getWCSequence();

    /// Initializes the vector to hold the value of the wilson coefs - 
    /// Default: zero value to all the WCs
    std::vector<double> wilson_coefs_values (wilson_coefs.size(), 0);

    /// Computes the values of the Wilson coefficients using the matching relations
    for (int i = 0; i < wilson_coefs.size(); i++) {
        std::string coef_name = wilson_coefs[i];
        /// Checks if the Wilson coefficient is in the list of matching relations
        if (_matching_relations.find(coef_name) != _matching_relations.end())
            wilson_coefs_values[i] = _matching_relations.at(coef_name)(map_coup_values);
    }

    return wilson_coefs_values;
}

const std::valarray<double> EFTMatching::get_prediction(const std::vector<double>& coups_values, const EFTStorage& eft_storage) const {
    /// Computes the values of the Wilson coefficients
    const std::vector<double> wilson_coefs_values = compute_wilson_coefs_values(coups_values);
    /// Computes the EFT prediction
    return _eft_expansion.get_prediction(wilson_coefs_values, eft_storage);
}