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
#include "ZprimeMatching.h"

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
    oss << "NCDY-Zprime-beta_"
        << std::fixed << std::setprecision(0) << beta * 10
        << "E-01-MXX_"
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
    const double mxx =  strtod(argv[1], &endptr);       /// Mass of the Z prime 
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
    EFTMatching zprime_matching (usmeft, {"beta", "MXX"});
    zprime_matching.set_matching( "Cphi1", &Cphi1 );
    zprime_matching.set_matching( "CBW"  , &CBW   );
    zprime_matching.set_matching( "C2JB" , &C2JB  );
    zprime_matching.set_matching( "C2psi4D2", &C2psi4D2);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// NC DY Information

    /// Experimental data and theory predictions
    const string hl_ncdy_path = "/data/01/martines/hep_programs/HepData/USMEFT-HLLHC/NCDY";
    
    /// Theory
    EFTStorage eft_ncdy_pred (hl_ncdy_path + "/USMEFT-NCDY-HLLHC.json");
    eft_ncdy_pred.set_bins_number(13);

    /// Experimental data
    string pseudo_data_ncdy = make_pseudo_name(beta, mxx);
    ExperimentalData ncdy_data (hl_ncdy_path + "/pseudo_data_Zprime/" + pseudo_data_ncdy);
    ncdy_data.set_bins_number(13);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_ncdy (ncdy_data, eft_ncdy_pred, &usmeft);
    chisq_ncdy.setChiSquareFunc(&GaussianChiSquareHLLHC);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// CC DY Information

    /// Experimental data and theory predictions
    string hl_ccdy_path = "/data/01/martines/hep_programs/HepData/USMEFT-HLLHC/CCDY";
    
    /// Theory
    EFTStorage eft_ccdy_pred (hl_ccdy_path + "/USMEFT-CCDY-HLLHC.json");
    eft_ccdy_pred.set_bins_number(8);

    /// Experimental data
    ExperimentalData ccdy_data (hl_ccdy_path + "/CCDY_pseudo_data_Zprime.json");
    ccdy_data.set_bins_number(8);

    // Defines the chi-square for the fit
    ObservableChiSquare chisq_ccdy (ccdy_data, eft_ccdy_pred, &usmeft);
    chisq_ccdy.setChiSquareFunc(&GaussianChiSquareHLLHC);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// EWPO Information

    /// Experimental data and theory predictions
    string ewpo_path = "/data/01/martines/hep_programs/HepData/USMEFT-HLLHC/EWPO";
    
    /// Theory
    EFTStorage eft_ewpo (ewpo_path + "/EWPOTheory.json");
    eft_ewpo.set_bins_number(16);

    /// Experimental data
    ExperimentalData ewpo_data (ewpo_path + "/EWPOData.json");
    ewpo_data.set_bins_number(16);
    ewpo_data.read_inverse_cov_matrix (ewpo_path + "/EWPOInvCovMatrix.json");

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
    const vector<string> allowed_coefs = {"C2JB", "CBW", "Cphi1",  "Delta4F", "C3W2H4", "C2psi4D2", "C3psi4D2", "C7psi4H2"};
    const vector<string> fit_coefs = createWCsList(wilsonCoef, allowed_coefs);
    usmeft.build_EFTExpansion(fit_coefs, EFTExpansionOrder::dim8);
    /// ------------------------------------------------------------------------------------------------------------
    
    /// ------------------------------------------------------------------------------------------------------------
    /// SM + NP prediction for the EWPO
    valarray<double> pseudo_data_ew = ewpo_data.get_data("SM") + zprime_matching.get_prediction({beta, mxx}, eft_ewpo);
    /// Replace the true EWPO data by the pseudo data based on the Zprime model
    ewpo_data.set_data("data", pseudo_data_ew);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// RUNS THE FIT 

    /// Map to store the information of the fit
    map<string, double> benchmark_fit;
    benchmark_fit.emplace("beta", beta);
    benchmark_fit.emplace("MXX",  mxx);
        
    /// Best-fit value  
    vector<double> initial_guest (fit_coefs.size(), 0.);
    double minchi = fit.minimizeChiSquare(initial_guest);
    benchmark_fit.emplace("best-fit", initial_guest[0]);

    cout << "Best-fit value " << initial_guest[0] << endl;

    /// Computes the confidence interval
    vector<double> xvalues = initialize_vector(-20, 20, 0.01);
    const vector<double> conf_interval = fit.findConfidenceInterval(xvalues);

    benchmark_fit.emplace("upper-limit", conf_interval[1]);
    benchmark_fit.emplace("lower-limit", conf_interval[0]);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Saves the results of the fit in the output file
    save_to_json (wilsonCoef + "-" + pseudo_data_ncdy, benchmark_fit);
    /// ------------------------------------------------------------------------------------------------------------

    return 0;
}