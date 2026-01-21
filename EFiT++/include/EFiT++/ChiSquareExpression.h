#ifndef CHI_SQUARE_EXP
#define CHI_SQUARE_EXP

#include <valarray>
#include <vector>
#include <ranges>
#include "EFiT++/DataStorage.h"

/// ------------------------------------------------------------------------------------------------------------------------
//// @brief - HL-LHC chi-square

/// @brief - Gaussian chi-square for NC and CC DY data
///          prediction vector contains only the EFT contributions, except the SM one
const double GaussianChiSquareHLLHC(const std::valarray<double>& prediction, const ExperimentalData& experimental_data);
/// ------------------------------------------------------------------------------------------------------------------------
/// ------------------------------------------------------------------------------------------------------------------------
//// @brief - EWPO chi-square

/// @brief - Gaussian chi-square for NC and CC DY data
///          prediction vector contains only the EFT contributions, except the SM one
const double GaussianChiSquareEWPO(const std::valarray<double>& prediction, const ExperimentalData& experimental_data);
/// ------------------------------------------------------------------------------------------------------------------------


#endif