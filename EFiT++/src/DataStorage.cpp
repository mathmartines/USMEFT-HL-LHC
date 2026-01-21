#include "EFiT++/DataStorage.h"

DataStorage::DataStorage(std::string filename) {
    /// Reads the content of the file
    read_json(filename);
}

void DataStorage::read_json(std::string filename) {
    /// Reads file
    std::ifstream file(filename);
    
    /// Checking if the file is open
    if (!file) 
        throw std::runtime_error("Failed to open file: " + filename);

    /// Parse to JSON
    json json_data = json::parse(file);

    /// Iterates over the content of the file
    for (auto it = json_data.begin(); it != json_data.end(); it++) {
        /// Updates the data map
        _data[it.key()] = it.value().get<std::valarray<double>>();
    }
}

const std::valarray<double>& DataStorage::get_data(const std::string datakey) const {
    /// Looks for the key in the map
    if (auto content = _data.find(datakey); content != _data.end()) 
        return content->second;
    throw std::runtime_error("Trying to acess a non-existing key: " + datakey);
}

void DataStorage::set_data(const std::string datakey, const std::valarray<double> data) {
    _data[datakey] = data;
}

const std::valarray<double>& EFTStorage::get_EFTterm(const std::vector<std::string> wilson_coefs) const {
    /// Stores all the candidate keys
    std::stringstream attempts;

    /// Looks for the all possible combination for the keys
    for (const std::string& candidate_key: find_keynames(wilson_coefs)) {
        try {
            // Try to get data using the key
            return get_data(candidate_key);
        } catch (const std::runtime_error&) {
            // Accumulate failed attempts
            attempts << candidate_key << " ";
        }
    }

    // Throw exception if no matching key found
    throw std::runtime_error("Trying to acess a non-existing eft-term: " + attempts.str());
}

const std::vector<std::string> EFTStorage::find_keynames(const std::vector<std::string> wilson_coefs) {
    /// Base case: only one WC
    /// The only possible combination is with the WC name
    if (wilson_coefs.size() == 1)
        return wilson_coefs;

    /// Stores all possible combination of terms
    std::set<std::string> unique_combinations;

    /// Iterates over all WC to get the combination starting with the current WC
    for (size_t i = 0; i < wilson_coefs.size(); i++) {

        /// Copy the list of coefs without the current coef
        std::vector<std::string> subcoefs (wilson_coefs.begin(), wilson_coefs.end());;
        subcoefs.erase(subcoefs.begin() + i);

        /// Creates new combinations starting with the current WC
        for (const auto& comb: find_keynames(subcoefs)) {
            unique_combinations.insert (wilson_coefs[i] + "-" + comb);
        }
    }
    return {unique_combinations.begin(), unique_combinations.end()};
}

void EFTStorage::buildAnomalousMatrix(const std::vector<std::vector<std::string>>& eft_terms) {
    /// Clear the anomalous matrix in case it's non-empty
    _anomalous_matrix.clear();
    /// Updating the matrix to contain the current terms
    for (const auto& eft_term: eft_terms) {
        try {
            const std::valarray<double>& anomalous_term = get_EFTterm(eft_term);
            _anomalous_matrix.push_back(&anomalous_term);
        } catch (const std::runtime_error&) {
            /// adds a nullptr to signal that we have no prediction for this term
            _anomalous_matrix.push_back(nullptr);
        }   
    }
}

void ExperimentalData::read_inverse_cov_matrix(std::string filename) {
    /// Reads file
    std::ifstream file(filename);
    
    /// Checking if the file is open
    if (!file) 
        throw std::runtime_error("Failed to open file: " + filename);

    /// Parse to JSON
    json json_data = json::parse(file);

    // Parse the matrix as a vector of vectors
    auto matrix_vector = json_data["inv_cov_matrix"].get<std::vector<std::vector<double>>>();

    // Convert the vector of vectors to a valarray of valarrays
    _cov_matrix = std::valarray<std::valarray<double>>(
        matrix_vector.size()
    );

    for (size_t i = 0; i < matrix_vector.size(); ++i) {
        _cov_matrix[i] = std::valarray<double>(matrix_vector[i].data(), matrix_vector[i].size());
    }
}