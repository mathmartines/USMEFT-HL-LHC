#ifndef EFT_EXPANSION_H
#define EFT_EXPANSION_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <valarray>
#include <memory>
#include <algorithm>
#include "EFiT++/DataStorage.h"

/**
 * @class - Abtract class to represent the model prediction
 **/ 
class ModelPrediction {
    public:
        /// @brief - Must return the model prediction using the values in coef_values and taking the EFT terms from the respective EFTStorage
        virtual const std::valarray<double> get_prediction(const std::vector<double>& coefs_values, const EFTStorage& eft_storage) const = 0;
};  

/// @brief - Possible operator dimensions
enum EFTExpansionOrder {dim6 = 2, dim8 = 4, dim10 = 6, dim12 = 8};


/// @class - Constructs the terms needed to compute the observables given the set of Wilson coefficients 
///          and the EFT truncation
///          Interaction order 2 - dim-6 terms only
///          Interaction order 4 - dim-8 terms included
class EFTExpansion: public ModelPrediction {

    public:
        using WilsonCoefsOrders = std::map<std::string, EFTExpansionOrder>;

        EFTExpansion (const WilsonCoefsOrders coefs_orders): _wcoefs (coefs_orders) {};

        /// @brief - Constructs the EFT terms in the expansion taking into account only the WC in the 
        ///          list up to the order eft_expansion_order
        void build_EFTExpansion(const std::vector<std::string>& wilson_coefs, const EFTExpansionOrder eft_expansion_order);

        /// @brief - Register a new pointer to a EFTStorage that will be used in the fit
        void add_EFTStorage(EFTStorage* eft_st) {_eft_storages.insert(eft_st);};

        /// @brief - Returns the prediction using the coef_values and taking the EFT terms from the respective EFTStorage
        const std::valarray<double> get_prediction(const std::vector<double>& coefs_values, const EFTStorage& eft_storage) const override;

        /// @brief - Returns the order of the WCs for the function
        const std::vector<std::string>& getWCSequence () const  {return _wilson_coefs_order;} ;

    private:
        /// @brief - Holds the desired Wilson's coefficients and the dimension of their respective effective operator
        std::map<std::string, EFTExpansionOrder> _wcoefs;

        /// @brief - Holds pointers to all the EFTStorages
        std::set<EFTStorage*> _eft_storages;

        /// @brief - Holds the list of EFT terms
        std::vector<std::vector<std::string>> _eft_terms;

        /// @brief - Holds the order of the WC that are pass as arguments of get_EFTPrediction
        std::vector<std::string> _wilson_coefs_order;

        /// @brief - Computes the product of the Wilson coefficients
        static const double WilsonCoefsProduct (const std::vector<std::string>& coefs_names, const std::map<std::string, double>& coefs_values);
};


/// @class - EFTMatching class. 
///          Computes the predictions of the model using the EFTExpansion but with the Wilson coefficients evaluated using the matching relations 
///          for the model
class EFTMatching: public ModelPrediction {

    public:
        using MatchingRelation = std::function<const double(const std::map<std::string, double>& model_couplings)>;

        /// @brief - Constructor needs to objects
        /// @param eft_expansion - a reference to the EFTExpansion object in order to compute the EFT prediction
        /// @param model_coups - a vector with the model couplings
        EFTMatching (EFTExpansion& eft_expansion, std::vector<std::string> model_coups): _eft_expansion (eft_expansion), _model_couplings (model_coups) {};

        /// @brief - Sets a matching relation
        void set_matching (const std::string wilson_coef, MatchingRelation matching) {_matching_relations[wilson_coef] = matching;};

        /// @brief - Computes the model prediction using the matching
        const std::valarray<double> get_prediction(const std::vector<double>& coups_values, const EFTStorage& eft_storage) const override;

        /// @brief - Computes the values of the Wilson coefficients 
        const std::vector<double> compute_wilson_coefs_values (const std::vector<double>& coups_values) const;

    private:
        /// @brief - Holds the list of model couplings
        std::vector<std::string> _model_couplings;

        /// @brief - Map to store the value of the model couplings
        std::map<std::string, double> _couplings_values;

        /// @brief - Stores the functions that define the mathing relations - the keys denote the Wilson coefficients
        std::map<std::string, MatchingRelation> _matching_relations;

        /// @brief - Holds a reference to the EFTExpansion object
        EFTExpansion& _eft_expansion;
};

#endif