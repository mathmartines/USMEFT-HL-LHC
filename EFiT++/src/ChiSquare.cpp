#include "EFiT++/ChiSquare.h"


const double CombinedChiSquare::evaluate(const std::vector<double>& coef_values) const {
    /// Holds the final chi-square value
    double chisq_value = 0;

    /// Adds the contribution of each distribution
    for (const auto& chisq: _chi_squares) 
        chisq_value += chisq->evaluate(coef_values);
    
    return chisq_value;
}

ObservableChiSquare::ObservableChiSquare(const ExperimentalData& experimental_data, EFTStorage& eft_storage, ModelPrediction* model_prediction):
    _exp_data(experimental_data), _eft_data(eft_storage), _model_prediction(model_prediction), _chisquare_func(nullptr) {};


const double ObservableChiSquare::evaluate(const std::vector<double>& coef_values) const {
    /// Checks if the chi-square function has been set
    if (!_chisquare_func) 
        throw std::runtime_error("ObservableChiSq: No Chi-Square function has been set. Please call setChiSquareFunc before evaluate.");
    /// Evaluates the prediction
    const std::valarray<double> prediction = _model_prediction->get_prediction(coef_values, _eft_data);
    /// Returns the chi-square value
    return _chisquare_func(prediction, _exp_data);
}
