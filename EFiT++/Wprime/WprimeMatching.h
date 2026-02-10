#ifndef WPRIME_MATCHING_H
#define WPRIME_MATCHING_H

#include <map>
#include <string>


const double Cphi1 (const std::map<std::string, double>& model_couplings) {
    const double g2 = 0.649553;
    const double lambda = 0.128868;
    const double beta = model_couplings.at("beta");
    const double MXX = model_couplings.at("MXX");
    return pow(g2, 2) * lambda * pow(beta / MXX, 2);
}

const double Delta4F (const std::map<std::string, double>& model_couplings) {
    const double g2 = 0.649553;
    const double beta = model_couplings.at("beta");
    const double MXX = model_couplings.at("MXX");
    return 0.25 * pow(g2, 2) * pow(beta / MXX, 2);
}

const double CBW (const std::map<std::string, double>& model_couplings) {
    const double g1 = 0.355976;
    const double g2 = 0.649553;
    const double beta = model_couplings.at("beta");
    const double MXX = model_couplings.at("MXX");
    return -0.25 * g1 * g2 * pow(beta / MXX, 2) ;
}

#endif