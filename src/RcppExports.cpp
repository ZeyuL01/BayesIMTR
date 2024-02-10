// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// Alignment
List Alignment(NumericVector input_vec, NumericVector ref_vec);
RcppExport SEXP _BIT_Alignment(SEXP input_vecSEXP, SEXP ref_vecSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type input_vec(input_vecSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ref_vec(ref_vecSEXP);
    rcpp_result_gen = Rcpp::wrap(Alignment(input_vec, ref_vec));
    return rcpp_result_gen;
END_RCPP
}
// Main_Sampling
List Main_Sampling(int N, arma::vec xct, arma::vec nct, arma::vec tf_labels, bool display_progress);
RcppExport SEXP _BIT_Main_Sampling(SEXP NSEXP, SEXP xctSEXP, SEXP nctSEXP, SEXP tf_labelsSEXP, SEXP display_progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type xct(xctSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type nct(nctSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type tf_labels(tf_labelsSEXP);
    Rcpp::traits::input_parameter< bool >::type display_progress(display_progressSEXP);
    rcpp_result_gen = Rcpp::wrap(Main_Sampling(N, xct, nct, tf_labels, display_progress));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_BIT_Alignment", (DL_FUNC) &_BIT_Alignment, 2},
    {"_BIT_Main_Sampling", (DL_FUNC) &_BIT_Main_Sampling, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_BIT(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
