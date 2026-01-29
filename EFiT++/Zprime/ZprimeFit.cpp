#include <iostream>
#include <valarray>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <memory>
#include <set>
#include <functional>
#include <format>
#include <algorithm>
#include <stdlib.h> 
#include <iomanip>
#include "JSON/json.hpp"
#include "EFiT++/DataStorage.h"
#include "EFiT++/EFTExpansion.h"
#include "EFiT++/ChiSquare.h"
#include "EFiT++/ChiSquareExpression.h"
#include "EFiT++/Minimizer.h"
#include "EFiT++/Fit.h"
#include "EFiT++/Utilities.h"
#include "ZprimeMatching.h"


using namespace std;
using json = nlohmann::json;


int main () {
    /// ------------------------------------------------------------------------------------------------------------
    /// Information about the USMEFT and Model

    /// Defines all the WCs for the analysis
    const EFTExpansion::WilsonCoefsOrders usmeft_coefs {
        /// Dimension-6 coefficients
        {"Cphi1",     EFTExpansionOrder::dim6},
        {"Delta4F",   EFTExpansionOrder::dim6},
        {"CBW",       EFTExpansionOrder::dim6},
        {"C2JB",      EFTExpansionOrder::dim6},
        /// Dimension-8 coefficients 
        {"C3W2H4",    EFTExpansionOrder::dim8},
        {"C2psi4D2",  EFTExpansionOrder::dim8},
        {"C7psi4H2",  EFTExpansionOrder::dim8},
        {"C3psi4D2",  EFTExpansionOrder::dim8}
    };

    /// Defines the EFT expansion
    EFTExpansion usmeft (usmeft_coefs);

    /// Matching between the model param and the WCs
    EFTMatching zprime_matching (usmeft, {"beta", "MXX"});
    zprime_matching.set_matching( "Cphi1" ,    &Cphi1 );
    zprime_matching.set_matching( "CBW"   ,    &CBW   );
    zprime_matching.set_matching( "C2JB"  ,    &C2JB  );
    zprime_matching.set_matching( "C2psi4D2" , &C2psi4D2);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Path to the folder where data and theory predictions are stored
    const string datafolder = "../Data";
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Model param
    const double beta = 1.0, MXX = 7;
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// NC DY Information

    /// Theory
    EFTStorage eft_ncdy_pred (datafolder + "/NCDY/USMEFT-NCDY-HLLHC.json");
    eft_ncdy_pred.set_bins_number(13);

    /// Experimental data
    ExperimentalData ncdy_data (datafolder + "/NCDY/pseudo_data_Zprime/" + format("NCDY-Zprime-beta_{:.0f}E-01-MXX_{:.0f}-TeV.json", beta * 10, MXX));
    ncdy_data.set_bins_number(13);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_ncdy (ncdy_data, eft_ncdy_pred, &usmeft);
    chisq_ncdy.setChiSquareFunc(&GaussianChiSquareHLLHC);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// CC DY Information
    
    /// Theory
    EFTStorage eft_ccdy_pred (datafolder + "/CCDY/USMEFT-CCDY-HLLHC.json");
    eft_ccdy_pred.set_bins_number(8);

    /// Experimental data
    ExperimentalData ccdy_data (datafolder + "/CCDY/CCDY_pseudo_data_Zprime.json");
    ccdy_data.set_bins_number(8);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_ccdy (ccdy_data, eft_ccdy_pred, &usmeft);
    chisq_ccdy.setChiSquareFunc(&GaussianChiSquareHLLHC);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// EWPO Information

    /// Theory
    EFTStorage eft_ewpo (datafolder + "/EWPO/EWPOTheory.json");
    eft_ewpo.set_bins_number(16);

    /// Experimental data
    ExperimentalData ewpo_data (datafolder + "/EWPO/EWPOData.json");
    ewpo_data.set_bins_number(16);
    ewpo_data.read_inverse_cov_matrix (datafolder + "/EWPO/EWPOInvCovMatrix.json");

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_ewpo (ewpo_data, eft_ewpo, &usmeft);
    chisq_ewpo.setChiSquareFunc(&GaussianChiSquareEWPO);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Register all the EFT prediction in the EFTExpansion object
    usmeft.add_EFTStorage(&eft_ncdy_pred);
    usmeft.add_EFTStorage(&eft_ccdy_pred);
    usmeft.add_EFTStorage(&eft_ewpo);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Global chi-square and Fit object
    CombinedChiSquare global_chisq (
        {
           &chisq_ncdy, 
           &chisq_ccdy,
        //    &chisq_ewpo
        }
    );

    /// Defines the minimizer
    NLoptMinimizer minimizer;

    /// Constructs the Fit object
    Fit fit (&global_chisq, &minimizer);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// DEFINES THE EFT TRUNCATION
    /// fit_coefs = {"Delta4F", "Cphi1", "CBW", "C2JB"} AND EFTExpansionOrder::dim6 -> ONLY LINEAR D=6 TERMS
    /// fit_coefs = {"Delta4F", "Cphi1", "CBW", "C2JB"} AND EFTExpansionOrder::dim8 -> LINEAR D=6 AND (D=6)^2 TERMS
    /// fit_coefs = {"C2JB", "Delta4F", "Cphi1", "CBW", "C7psi4H2", "C2psi4D2", "C3psi4D2", "C3W2H4"} AND EFTExpansionOrder::dim8 -> LINEAR D=6, (D=6)^2, LINEAR D=8 TERMS
    /// The order of the coefficients does not matter
    /// The different sets of coefficients can be chosen
    vector<string> fit_coefs = {"Delta4F", "Cphi1", "CBW", "C2JB"};
    usmeft.build_EFTExpansion(fit_coefs, EFTExpansionOrder::dim6);
    /// ------------------------------------------------------------------------------------------------------------
    
    /// ------------------------------------------------------------------------------------------------------------
    /// UPDATES THE DATA FOR THE EWPO USING THE MATCHING RELATIONS
    valarray<double> pseudo_data_ew = ewpo_data.get_data("SM") + zprime_matching.get_prediction({beta, MXX}, eft_ewpo);
    // Replace the true EWPO data by the pseudo data based on the Zprime model
    ewpo_data.set_data("data", pseudo_data_ew);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------    
    /// Best-fit value
    vector<double> initial_guest (fit_coefs.size(), 0.);
    double minchi = fit.minimizeChiSquare(initial_guest);

    /// Best fit value for the first coefficient in the fit_coefs vector
    cout << format("Best-fit value = {:.4f}", initial_guest[0]) << endl;
    /// Min of the chi-square
    cout << format("Chi-square min value = {:.4f}", minchi) << endl;

    /// Computes the confidence interval for the FIRST coefficient in the fit_coefs vector
    vector<double> xvalues = initialize_vector(-0.01, 0.01, 0.0001);
    /// 1 sigma CL
    const vector<double> conf_interval = fit.findConfidenceInterval(xvalues);
    /// ------------------------------------------------------------------------------------------------------------  

    return 0;
}