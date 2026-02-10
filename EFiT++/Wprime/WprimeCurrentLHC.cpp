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
// #include "WprimeMatching.h"
#include "WprimeMatching.h"


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
        {"CBW",       EFTExpansionOrder::dim6}
    };

    /// Defines the EFT expansion
    EFTExpansion usmeft (usmeft_coefs);

    /// Matching between the model param and the WCs
    EFTMatching wprime_matching (usmeft, {"beta"});
    wprime_matching.set_matching( "Cphi1" ,    &Cphi1  );
    wprime_matching.set_matching( "CBW"   ,    &CBW    );
    wprime_matching.set_matching( "Delta4F"  , &Delta4F);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Path to the folder where data and theory predictions are stored
    const string datafolder = "../Data/DYLHC13TEV";
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// CMS dielectron 13 TeV

    /// Theory
    EFTStorage cms_dielectron_13TEV_eft_terms (datafolder + "/cms-dielectron-13TEV/cms-dielectron-13TEV_merged.json");
    cms_dielectron_13TEV_eft_terms.set_bins_number(20);

    /// Experimental data
    ExperimentalData cms_dielectron_13TEV_data (datafolder + "/cms-dielectron-13TEV/experimental_data_merged.json");
    cms_dielectron_13TEV_data.set_bins_number(20);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_cms_dielectron_13TEV (cms_dielectron_13TEV_data, cms_dielectron_13TEV_eft_terms, &wprime_matching);
    chisq_cms_dielectron_13TEV.setChiSquareFunc(&GaussianChiSquare);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// CMS dimuon 13 TeV

    /// Theory
    EFTStorage cms_dimuon_13TEV_eft_terms (datafolder + "/cms-dimuon-13TEV/cms-dimuon-13TEV_merged.json");
    cms_dimuon_13TEV_eft_terms.set_bins_number(20);

    /// Experimental data
    ExperimentalData cms_dimuon_13TEV_data (datafolder + "/cms-dimuon-13TEV/experimental_data_merged.json");
    cms_dimuon_13TEV_data.set_bins_number(20);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_cms_dimuon_13TEV (cms_dimuon_13TEV_data, cms_dimuon_13TEV_eft_terms, &wprime_matching);
    chisq_cms_dimuon_13TEV.setChiSquareFunc(&GaussianChiSquare);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// ATLAS dielectron 13 TeV

    /// Theory
    EFTStorage atlas_dielectron_13TEV_eft_terms (datafolder + "/atlas-dielectron-13TEV/atlas-dielectron-13TEV_merged.json");
    atlas_dielectron_13TEV_eft_terms.set_bins_number(20);

    /// Experimental data
    ExperimentalData atlas_dielectron_13TEV_data (datafolder + "/atlas-dielectron-13TEV/experimental_data_merged.json");
    atlas_dielectron_13TEV_data.set_bins_number(20);
    /// Sets the porcetage for the systematic uncertainties
     atlas_dielectron_13TEV_data.set_data(
        "sigma_sys",
        {0.1, 0.1, 0.1, 0.1, 0.1, 0.15, 0.15, 0.15, 0.15, 0.15, 0.2, 0.2, 0.2, 0.3, 0.3, 0.3, 0.35, 0.35, 0.35, 0.35}
    );

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_atlas_dielectron_13TEV (atlas_dielectron_13TEV_data, atlas_dielectron_13TEV_eft_terms, &wprime_matching);
    chisq_atlas_dielectron_13TEV.setChiSquareFunc(&GaussianChiSquareATLAS);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// ATLAS dimuon 13 TeV

    /// Theory
    EFTStorage atlas_dimuon_13TEV_eft_terms (datafolder + "/atlas-dimuon-13TEV/atlas-dimuon-13TEV_merged.json");
    atlas_dimuon_13TEV_eft_terms.set_bins_number(20);

    /// Experimental data
    ExperimentalData atlas_dimuon_13TEV_data (datafolder + "/atlas-dimuon-13TEV/experimental_data_merged.json");
    atlas_dimuon_13TEV_data.set_bins_number(20);
    /// Sets the porcetage for the systematic uncertainties
    atlas_dimuon_13TEV_data.set_data(
        "sigma_sys",
        {0.15, 0.15, 0.15, 0.15, 0.15, 0.2, 0.2, 0.2, 0.2, 0.2, 0.25, 0.25, 0.25, 0.35, 0.35, 0.35, 0.4, 0.4, 0.4, 0.4}
    );

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_atlas_dimuon_13TEV (atlas_dimuon_13TEV_data, atlas_dimuon_13TEV_eft_terms, &wprime_matching);
    chisq_atlas_dimuon_13TEV.setChiSquareFunc(&GaussianChiSquareATLAS);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// CMS monoelectron 13 TeV

    /// Theory
    EFTStorage cms_monoelectron_13TEV_eft_terms (datafolder + "/cms-monoelectron-13TEV/cms-monoelectron-13TEV_merged.json");
    cms_monoelectron_13TEV_eft_terms.set_bins_number(20);

    /// Experimental data
    ExperimentalData cms_monoelectron_13TEV_data (datafolder + "/cms-monoelectron-13TEV/experimental_data_merged.json");
    cms_monoelectron_13TEV_data.set_bins_number(20);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_cms_monoelectron_13TEV (cms_monoelectron_13TEV_data, cms_monoelectron_13TEV_eft_terms, &wprime_matching);
    chisq_cms_monoelectron_13TEV.setChiSquareFunc(&GaussianChiSquare);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// CMS monomuon 13 TeV

    /// Theory
    EFTStorage cms_monomuon_13TEV_eft_terms (datafolder + "/cms-monomuon-13TEV/cms-monomuon-13TEV_merged.json");
    cms_monomuon_13TEV_eft_terms.set_bins_number(14);

    /// Experimental data
    ExperimentalData cms_monomuon_13TEV_data (datafolder + "/cms-monomuon-13TEV/experimental_data_merged.json");
    cms_monomuon_13TEV_data.set_bins_number(14);

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_cms_monomuon_13TEV (cms_monomuon_13TEV_data, cms_monomuon_13TEV_eft_terms, &wprime_matching);
    chisq_cms_monomuon_13TEV.setChiSquareFunc(&GaussianChiSquare);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// ATLAS diff. xsec 13 TeV

    /// Theory
    EFTStorage diff_atlas_13TEV_eft_terms (datafolder + "/diff-atlas-ccdy-13TEV/diff-atlas-ccdy-13TEV.json");
    diff_atlas_13TEV_eft_terms.set_bins_number(12);

    /// Experimental data
    ExperimentalData diff_atlas_13TEV_data (datafolder + "/diff-atlas-ccdy-13TEV/experimental_data_combined.json");
    diff_atlas_13TEV_data.set_bins_number(12);
    diff_atlas_13TEV_data.read_inverse_cov_matrix (datafolder + "/diff-atlas-ccdy-13TEV/inverse_covariance_matrix.json");

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_atlas_diff_13TEV (diff_atlas_13TEV_data, diff_atlas_13TEV_eft_terms, &wprime_matching);
    chisq_atlas_diff_13TEV.setChiSquareFunc(&GaussianChiSquareATLAS8TEV);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// ATLAS dilepton 8 TeV

    /// Theory
    EFTStorage atlas_dilepton_8TEV_eft_terms (datafolder + "/atlas-dilepton-8TEV/atlas-dilepton-8TEV-mll-yll.json");
    atlas_dilepton_8TEV_eft_terms.set_bins_number(48);

    /// Experimental data
    ExperimentalData atlas_dilepton_8TEV_data (datafolder + "/atlas-dilepton-8TEV/experimental_data-mll-yll.json");
    atlas_dilepton_8TEV_data.set_bins_number(48);
    atlas_dilepton_8TEV_data.read_inverse_cov_matrix (datafolder + "/atlas-dilepton-8TEV/inverse_covariance_matrix.json");

    /// Defines the chi-square for the fit
    ObservableChiSquare chisq_atlas_dilepton_8TEV (atlas_dilepton_8TEV_data, atlas_dilepton_8TEV_eft_terms, &wprime_matching);
    chisq_atlas_dilepton_8TEV.setChiSquareFunc(&GaussianChiSquareATLAS8TEV);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Register all the EFT prediction in the EFTExpansion object
    usmeft.add_EFTStorage(&cms_dielectron_13TEV_eft_terms);
    usmeft.add_EFTStorage(&cms_dimuon_13TEV_eft_terms);
    usmeft.add_EFTStorage(&atlas_dielectron_13TEV_eft_terms);
    usmeft.add_EFTStorage(&atlas_dimuon_13TEV_eft_terms);
    usmeft.add_EFTStorage(&cms_monoelectron_13TEV_eft_terms);
    usmeft.add_EFTStorage(&cms_monomuon_13TEV_eft_terms);
    usmeft.add_EFTStorage(&diff_atlas_13TEV_eft_terms);
    usmeft.add_EFTStorage(&atlas_dilepton_8TEV_eft_terms);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// Global chi-square and Fit object
    CombinedChiSquare global_chisq (
        {
           &chisq_cms_dielectron_13TEV, 
           &chisq_cms_dimuon_13TEV,
           &chisq_atlas_dielectron_13TEV,
           &chisq_atlas_dimuon_13TEV,
           &chisq_cms_monoelectron_13TEV,
           &chisq_cms_monomuon_13TEV,
           &chisq_atlas_diff_13TEV,
           &chisq_atlas_dilepton_8TEV
        }
    );

    /// Defines the minimizer
    NLoptMinimizer minimizer;

    /// Constructs the Fit object
    Fit fit (&global_chisq, &minimizer);
    /// ------------------------------------------------------------------------------------------------------------

    /// ------------------------------------------------------------------------------------------------------------
    /// DEFINES THE EFT TRUNCATION
    vector<string> fit_coefs = {"Delta4F", "CBW", "Cphi1"};
    usmeft.build_EFTExpansion(fit_coefs, EFTExpansionOrder::dim8);
    /// ------------------------------------------------------------------------------------------------------------
    
    /// ------------------------------------------------------------------------------------------------------------    
    /// Best-fit value
    vector<double> initial_guest (1, 0.);
    double minchi = fit.minimizeChiSquare(initial_guest);

    /// Best fit value for the first coefficient in the fit_coefs vector
    cout << format("Best-fit value = {:.4f}", initial_guest[0]) << endl;
    /// Min of the chi-square
    cout << format("Chi-square min value = {:.4f}", minchi) << endl;

    /// Computes the confidence interval for the FIRST coefficient in the fit_coefs vector
    vector<double> xvalues = initialize_vector(-0.1, 0.1, 0.001);
    /// 1 sigma CL
    const vector<double> conf_interval = fit.findConfidenceInterval(xvalues);
    /// ------------------------------------------------------------------------------------------------------------  

    return 0;
}