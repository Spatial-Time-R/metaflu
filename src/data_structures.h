#ifndef STRUCTURES
#define STRUCTURES

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// A structure to hold a single list of parameters
// [[Rcpp::depends(RcppArmadillo)]]
struct mf_parmlist {
  double beta;              //contact rate for direct transmission
  double gamma;             //recovery rate
  double mu;                //base mortality rate
  double alpha;             //disease mortality rate
  double phi;               //infectiousness of environmental virions
  double eta;               //degradation rate of environmental virions
  double nu;                //uptake rate of environmental virion
  double sigma;             //virion shedding rate
  double omega;             //movement rate
  arma::mat chi;            //patch connectivity matrix
  arma::mat chi_cum;        //patch connectivity matrix, row-wise cumulative
  int K;                    //total number of patches
  int n_actions;             // number of possible event types

  mf_parmlist() ;  //default constructor

  mf_parmlist(List parmlist) {  //Creates this structure from an R list
    beta = as<double>(parmlist["beta"]);
    gamma = as<double>(parmlist["gamma"]);
    mu = as<double>(parmlist["mu"]);
    alpha = as<double>(parmlist["alpha"]);
    phi = as<double>(parmlist["phi"]);
    eta = as<double>(parmlist["eta"]);
    nu = as<double>(parmlist["nu"]);
    sigma = as<double>(parmlist["phi"]);
    omega = as<double>(parmlist["omega"]);
    chi = as<arma::mat>(parmlist["omega"]);
    chi_cum = cumsum(chi, 1);
    K = chi.n_rows;
    n_actions = as<int>(parmlist["n_actions"]);
  }
};

#endif