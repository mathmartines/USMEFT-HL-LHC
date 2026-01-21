#ifndef CHI_SQUARE_H
#define CHI_SQUARE_H

#include <vector>
#include <valarray>
#include <functional>
#include <algorithm> 
#include <cmath>
#include "EFiT++/DataStorage.h"
#include "EFiT++/EFTExpansion.h"


/// @class ChiSquare
/// @brief Interface that defines the ChiSquare function for the fit.
class ChiSquare {
    public:
        /// @brief Returns the value of the chi-square computed using the values of each coefficient given by
        ///        coef_values.
        virtual const double evaluate (const std::vector<double>& coef_values) const = 0;

        /// @brief Optional storage for coefficient values.
        std::vector<double> stored_coef_values;
};

/// @class CombinedChiSquare
/// @brief Combined chi-square class that sums the result of several chi-square objects (non-owning).
class CombinedChiSquare: public ChiSquare {
    public:
        CombinedChiSquare(const std::vector<const ChiSquare*>& chi_squares): _chi_squares (chi_squares) {};

        /// @brief The final chi-square is given by evaluating and summing the value for each component.
        const double evaluate(const std::vector<double>& coef_values) const override;

    private:
        /// @brief Holds all the chi-squares used in the analysis.
        std::vector<const ChiSquare*> _chi_squares;
};


/// @class ObservableChiSquare
/// @brief Computes the chi-square for a given model prediction (EFT or model couplings).
class ObservableChiSquare: public ChiSquare {
    public: 
        using ChiSquareFunc = std::function<const double(const std::valarray<double>& prediction, const ExperimentalData& experimental_data)>;
        
        ObservableChiSquare(const ExperimentalData& experimental_data, 
                            EFTStorage& eft_storage, 
                            ModelPrediction* model_prediction);

        /// @brief Sets the chi-square function used to evaluate the chi-square.
        void setChiSquareFunc (ChiSquareFunc chisq_func){ _chisquare_func = chisq_func;};   
        
        /// @brief - Evaluates the chi-square
        virtual const double evaluate(const std::vector<double>& coef_values) const override;

    protected:
        const ExperimentalData& _exp_data;   /// experimental data
        EFTStorage& _eft_data;               /// eft terms to use
        ModelPrediction* _model_prediction;  /// Calculates the Model Prediction

        /// Function to evaluate chi-square
        ChiSquareFunc _chisquare_func; 
};

#endif