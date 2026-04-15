#include <iostream>
#include <valarray>
#include <string>
#include <map>
#include <fstream>
#include <memory>
#include <set>
#include <functional>
#include <algorithm>
#include <stdlib.h> 
#include "JSON/json.hpp"
#include "EFiT++/DataStorage.h"
#include "EFiT++/EFTExpansion.h"
#include "EFiT++/ChiSquare.h"
#include "EFiT++/ChiSquareExpression.h"
#include "EFiT++/Minimizer.h"
#include "EFiT++/Fit.h"
#include "EFiT++/Utilities.h"
#include "WprimeMatching.h"

using namespace std;
using json = nlohmann::json;


const vector<string> createWCsList (const string coef, const vector<string>& listCoefs) {
    /// Creates a new list with the chosen coefficient as the first
    vector<string> updated_list ({coef});

    /// Adds to the list all coefficients, except the chosen one
    for (auto coef_name: listCoefs) {
        if (coef_name != coef)
            updated_list.push_back(coef_name);
    }

    return updated_list;
}

inline std::string make_pseudo_name(double beta, double mxx) {
    std::ostringstream oss;
    oss << "Wprime-beta_"
        << std::fixed << std::setprecision(0) << beta * 100
        << "E-02-MXX_"
        << std::fixed << std::setprecision(0) << mxx
        << "-TeV.json";
    return oss.str();
}


void save_to_json(const std::string& filename, const std::map<std::string, double>& data) {
    json j = data;  // implicit conversion: works automatically

    std::ofstream out(filename);
    if (!out)
        throw std::runtime_error("Cannot open file: " + filename);

    out << std::setw(4) << j;  // pretty printing
}

int main (int argc, char* argv[]) {
    /// ------------------------------------------------------------------------------------------------------------
    /// Information needed to run the fit
    char* endptr;   
    const double mxx =  strtod(argv[1], &endptr);       /// Mass of the W prime 
    const double beta = strtod(argv[2], &endptr);       /// Coupling value
    const string wilsonCoef = argv[3];                  /// Wilson coefficient we want to extract the limits
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Information on the USMEFT and Model

    /// Defines all the WCs for the analysis
    const EFTExpansion::WilsonCoefsOrders usmeft_coefs {
        /// Dimension-6 coefficients
        {"Cphi1",   EFTExpansionOrder::dim6},
        {"Delta4F", EFTExpansionOrder::dim6},
        {"CBW",     EFTExpansionOrder::dim6},
        {"C2JB",    EFTExpansionOrder::dim6},
        /// Dimension-8 coefficients 
        {"C3W2H4",    EFTExpansionOrder::dim8},
        {"C2psi4D2",  EFTExpansionOrder::dim8},
        {"C7psi4H2",  EFTExpansionOrder::dim8},
        {"C3psi4D2",  EFTExpansionOrder::dim8}
    };

    /// Defines the EFT expansion
    EFTExpansion usmeft (usmeft_coefs);

    /// Matching between the model param and the WCs
    EFTMatching wprime_matching (usmeft, {"beta", "MXX"});
    wprime_matching.set_matching( "Cphi1", &Cphi1 );
    wprime_matching.set_matching( "CBW"  , &CBW   );
    wprime_matching.set_matching( "Delta4F" , &Delta4F  );
    /// ------------------------------------------------------------------------------------------------------------
    
    /// ------------------------------------------------------------------------------------------------------------
    /// Path to the folder where data and theory predictions are stored
    const string datafolder = "/data/01/martines/PhD_Projects/USMEFT-HL-LHC/Data";
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Prefix of the pseudo data files
    string prefix_pseudo_data = make_pseudo_name(beta, mxx);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// NC DY Information

    /// Theory
    EFTStorage eft_ncdy_pred (datafolder + "/NCDY/USMEFT-NCDY.json");
    eft_ncdy_pred.set_bins_number(15);

    /// Experimental data
    ExperimentalData ncdy_data (datafolder + "/NCDY/pseudo_data_Wprime/NCDY-" + prefix_pseudo_data);
    ncdy_data.set_bins_number(15);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_ncdy (ncdy_data, eft_ncdy_pred, &usmeft);
    chisq_ncdy.setChiSquareFunc(&GaussianChiSquareHLLHC);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// CC DY Information
    
     /// Theory
    EFTStorage eft_ccdy_pred (datafolder + "/CCDY/USMEFT-CCDY.json");
    eft_ccdy_pred.set_bins_number(9);

    /// Experimental data
    ExperimentalData ccdy_data (datafolder + "/CCDY/pseudo_data_Wprime/CCDY-" + prefix_pseudo_data);
    ccdy_data.set_bins_number(9);


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
           &chisq_ewpo
        }
    );

    /// Defines the minimizer
    NLoptMinimizer minimizer;

    /// Constructs the Fit object
    Fit fit (&global_chisq, &minimizer);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Constructs the SMEFT expansion
    const vector<string> allowed_coefs = {
        "C2JB", "CBW", "Cphi1",  "Delta4F", 
        // "C2psi4D2", "C3psi42", "C7psi4H2", "C3W2H4"
    };
    const vector<string> fit_coefs = createWCsList(wilsonCoef, allowed_coefs);
    usmeft.build_EFTExpansion(fit_coefs, EFTExpansionOrder::dim8);
    /// ------------------------------------------------------------------------------------------------------------
    
    /// ------------------------------------------------------------------------------------------------------------
    /// SM + NP prediction for the EWPO
    valarray<double> pseudo_data_ew = ewpo_data.get_data("SM") + wprime_matching.get_prediction({beta, mxx}, eft_ewpo);
    /// Replace the true EWPO data by the pseudo data based on the Zprime model
    ewpo_data.set_data("data", pseudo_data_ew);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// RUNS THE FIT 
    // vector<double> initial_guest (fit_coefs.size(), 0.);
    // cout << global_chisq.evaluate(initial_guest) << endl;   
    /// Map to store the information of the fit
    // map<string, double> benchmark_fit;
    // benchmark_fit.emplace("beta", beta);
    // benchmark_fit.emplace("MXX",  mxx);
        
    // /// Best-fit value  
    vector<double> initial_guest2 (fit_coefs.size(), 0.);
    double minchi = fit.minimizeChiSquare(initial_guest2);
    cout << minchi << endl;

    // cout << "Best-fit value " << initial_guest[0] << endl;


    // /// Vectors ranges for different coefficients
    // const map<const string, const vector<double>> xvalues {
    //     {"C2JB", initialize_vector(-0.01, 0.01, 0.0001)},
    //     {"Cphi1", initialize_vector(-0.1, 0.1, 0.001)},
    //     {"CBW", initialize_vector(-0.1, 0.1, 0.001)},
    //     {"Delta4F", initialize_vector(-0.001, 0.001, 0.00001)}
    // };

    // /// Computes the confidence interval
    // const vector<double> conf_interval = fit.findConfidenceInterval(xvalues.at(wilsonCoef), false);

    /// C2JB : range [-0.1, 0.1]
    /// Delta4F: range [-0.01, 0.01]
    /// Cphi1 : range [-0.1, 0.1]
    /// CBW : range [-0.1, 0.1]
    // benchmark_fit.emplace("best-fit", initial_guest[0]);
    // benchmark_fit.emplace("upper-limit", conf_interval[1]);
    // benchmark_fit.emplace("lower-limit", conf_interval[0]);

    // /// Stores the chi-square evaluated at the SM
    // vector<double> zeros (fit_coefs.size(), 0.);
    // double chi_sq_SM = chisq_ncdy.evaluate(zeros);
    // benchmark_fit.emplace("ChiSq-SM-NCDY", chi_sq_SM);

    // /// Chi-Square last bin
    // ncdy_data.slice_bins(14, 1);
    // eft_ncdy_pred.slice_bins(14, 1);
    // double chi_sq_SM_last_bin = chisq_ncdy.evaluate(zeros);
    // benchmark_fit.emplace("ChiSq-SM-NCDY-last-bin", chi_sq_SM_last_bin);

    // /// Stores the chi-square evaluated at the SM
    // chi_sq_SM = chisq_ccdy.evaluate(zeros);
    // benchmark_fit.emplace("ChiSq-SM-CCDY", chi_sq_SM);

    // /// Chi-Square last bin
    // ccdy_data.slice_bins(8, 1);
    // eft_ccdy_pred.slice_bins(8, 1);
    // chi_sq_SM_last_bin = chisq_ccdy.evaluate(zeros);
    // benchmark_fit.emplace("ChiSq-SM-CCDY-last-bin", chi_sq_SM_last_bin);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Saves the results of the fit in the output file
    // save_to_json (wilsonCoef + "-" + prefix_pseudo_data, benchmark_fit);
    /// ------------------------------------------------------------------------------------------------------------

    return 0;
}