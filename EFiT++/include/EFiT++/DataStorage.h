#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <valarray>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "JSON/json.hpp"


using json = nlohmann::json;

/** 
 * @class - General container to store and access the data
 *        - obs: data is stored in underline map structure
**/
class DataStorage {

    public:
        DataStorage(std::string filename);

        /// @brief - Access to the data labeled by datakey 
        const std::valarray<double>& get_data(const std::string datakey) const;

        /// @brief - Sets a new data that that can be acessed by the datakey
        void set_data(const std::string datakey, const std::valarray<double> data);

        /// @brief - Total number of bins 
        const int get_bins_number() const {return _number_of_bins;};

        /// @brief - Sets the total number of bins
        void set_bins_number(int nbins) {_number_of_bins = nbins;};

        /// @brief - reads data that are stored .json file
        void read_json(std::string filename);

    protected:
        /// holds the data
        std::map<std::string, std::valarray<double>> _data;

        /// holds the number of bins 
        int _number_of_bins;
};

/**
 * @class - Stores the information about the experimental data
 */
class ExperimentalData: public DataStorage {
    public:
        ExperimentalData(std::string filename): DataStorage(filename) {};

        /// @brief - Loads the inverse of the covariance matrix
        void read_inverse_cov_matrix(std::string filename);

        /// @brief - Returns a reference to the inverse of the covariance matrix
        const std::valarray<std::valarray<double>>& get_inv_cov_matrix () const {return _cov_matrix;};
    
    private: 
        std::valarray<std::valarray<double>> _cov_matrix;
};

/**
 * @class - Stores the information about the EFT predictions
 */
class EFTStorage: public DataStorage {

    public:
        EFTStorage(std::string filename): DataStorage(filename) {};

        /// @brief - Returns the prediction for the eft term correspoiding to the list of wilson coefs
        ///          If there's more than one coefficient, we search for the interference term among them 
        const std::valarray<double>& get_EFTterm(const std::vector<std::string> wilson_coefs) const;

        /// @brief - Builds the matrices holding the effective terms following the order of 
        ///          the requested in the vector
        void buildAnomalousMatrix (const std::vector<std::vector<std::string>>& eft_terms);

        /// @brief - Gives acess to the anomalous matrix
        const std::vector<const std::valarray<double>*>& get_AnomalousMatrix() const {return _anomalous_matrix;}; 

    private:
        /// @brief - Finds all possible keynames that corresponds to the EFT term 
        static const std::vector<std::string> find_keynames(const std::vector<std::string> wilson_coefs);

        /// @brief - Holds 
        std::vector<const std::valarray<double>*> _anomalous_matrix;
};


#endif