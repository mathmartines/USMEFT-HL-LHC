#ifndef ZPRIME_MATCHING_H
#define ZPRIME_MATCHING_H

#include <map>
#include <string>


const double Cphi1 (const std::map<std::string, double>& model_couplings) {
    const double g1 = 0.355976;
    const double beta = model_couplings.at("beta");
    const double MXX  = model_couplings.at("MXX");
    return 0.5 * pow(g1, 2) * pow(beta, 2) / pow(MXX, 2);
}

const double C2JB (const std::map<std::string, double>& model_couplings) {
    const double beta = model_couplings.at("beta");
    const double MXX  = model_couplings.at("MXX");
    return -0.5 * pow(beta, 2) / pow(MXX, 2);
}

const double CBW (const std::map<std::string, double>& model_couplings) {
    const double g1 = 0.355976;
    const double g2 = 0.649553;
    const double beta = model_couplings.at("beta");
    const double MXX  = model_couplings.at("MXX");
    return -0.25 * g1 * g2 * pow(beta, 2) / pow(MXX, 2);
}

const double C2psi4D2 (const std::map<std::string, double>& model_couplings) {
    const double beta = model_couplings.at("beta");
    const double MXX  = model_couplings.at("MXX");
    return -0.5 * pow(beta, 2) / pow(MXX, 4);
}

#endif