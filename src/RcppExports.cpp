// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// count_combo_barcodes_paired
Rcpp::List count_combo_barcodes_paired(std::string path1, std::string constant1, bool reverse1, int mismatches1, Rcpp::CharacterVector pool1, std::string path2, std::string constant2, bool reverse2, int mismatches2, Rcpp::CharacterVector pool2, bool randomized, bool use_first, int nthreads);
RcppExport SEXP _screenCounter_count_combo_barcodes_paired(SEXP path1SEXP, SEXP constant1SEXP, SEXP reverse1SEXP, SEXP mismatches1SEXP, SEXP pool1SEXP, SEXP path2SEXP, SEXP constant2SEXP, SEXP reverse2SEXP, SEXP mismatches2SEXP, SEXP pool2SEXP, SEXP randomizedSEXP, SEXP use_firstSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::string >::type path1(path1SEXP);
    Rcpp::traits::input_parameter< std::string >::type constant1(constant1SEXP);
    Rcpp::traits::input_parameter< bool >::type reverse1(reverse1SEXP);
    Rcpp::traits::input_parameter< int >::type mismatches1(mismatches1SEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type pool1(pool1SEXP);
    Rcpp::traits::input_parameter< std::string >::type path2(path2SEXP);
    Rcpp::traits::input_parameter< std::string >::type constant2(constant2SEXP);
    Rcpp::traits::input_parameter< bool >::type reverse2(reverse2SEXP);
    Rcpp::traits::input_parameter< int >::type mismatches2(mismatches2SEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type pool2(pool2SEXP);
    Rcpp::traits::input_parameter< bool >::type randomized(randomizedSEXP);
    Rcpp::traits::input_parameter< bool >::type use_first(use_firstSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_combo_barcodes_paired(path1, constant1, reverse1, mismatches1, pool1, path2, constant2, reverse2, mismatches2, pool2, randomized, use_first, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// count_combo_barcodes_single
Rcpp::List count_combo_barcodes_single(std::string path, std::string constant, int strand, Rcpp::List pool, int mismatches, bool use_first, int nthreads);
RcppExport SEXP _screenCounter_count_combo_barcodes_single(SEXP pathSEXP, SEXP constantSEXP, SEXP strandSEXP, SEXP poolSEXP, SEXP mismatchesSEXP, SEXP use_firstSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< std::string >::type constant(constantSEXP);
    Rcpp::traits::input_parameter< int >::type strand(strandSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type pool(poolSEXP);
    Rcpp::traits::input_parameter< int >::type mismatches(mismatchesSEXP);
    Rcpp::traits::input_parameter< bool >::type use_first(use_firstSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_combo_barcodes_single(path, constant, strand, pool, mismatches, use_first, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// count_dual_barcodes
Rcpp::List count_dual_barcodes(std::string path1, std::string constant1, bool reverse1, int mismatches1, Rcpp::CharacterVector pool1, std::string path2, std::string constant2, bool reverse2, int mismatches2, Rcpp::CharacterVector pool2, bool randomized, bool use_first, bool diagnostics, int nthreads);
RcppExport SEXP _screenCounter_count_dual_barcodes(SEXP path1SEXP, SEXP constant1SEXP, SEXP reverse1SEXP, SEXP mismatches1SEXP, SEXP pool1SEXP, SEXP path2SEXP, SEXP constant2SEXP, SEXP reverse2SEXP, SEXP mismatches2SEXP, SEXP pool2SEXP, SEXP randomizedSEXP, SEXP use_firstSEXP, SEXP diagnosticsSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::string >::type path1(path1SEXP);
    Rcpp::traits::input_parameter< std::string >::type constant1(constant1SEXP);
    Rcpp::traits::input_parameter< bool >::type reverse1(reverse1SEXP);
    Rcpp::traits::input_parameter< int >::type mismatches1(mismatches1SEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type pool1(pool1SEXP);
    Rcpp::traits::input_parameter< std::string >::type path2(path2SEXP);
    Rcpp::traits::input_parameter< std::string >::type constant2(constant2SEXP);
    Rcpp::traits::input_parameter< bool >::type reverse2(reverse2SEXP);
    Rcpp::traits::input_parameter< int >::type mismatches2(mismatches2SEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type pool2(pool2SEXP);
    Rcpp::traits::input_parameter< bool >::type randomized(randomizedSEXP);
    Rcpp::traits::input_parameter< bool >::type use_first(use_firstSEXP);
    Rcpp::traits::input_parameter< bool >::type diagnostics(diagnosticsSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_dual_barcodes(path1, constant1, reverse1, mismatches1, pool1, path2, constant2, reverse2, mismatches2, pool2, randomized, use_first, diagnostics, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// count_dual_barcodes_single_end
Rcpp::List count_dual_barcodes_single_end(std::string path, std::string constant, Rcpp::List pools, int strand, int mismatches, bool use_first, bool diagnostics, int nthreads);
RcppExport SEXP _screenCounter_count_dual_barcodes_single_end(SEXP pathSEXP, SEXP constantSEXP, SEXP poolsSEXP, SEXP strandSEXP, SEXP mismatchesSEXP, SEXP use_firstSEXP, SEXP diagnosticsSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< std::string >::type constant(constantSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type pools(poolsSEXP);
    Rcpp::traits::input_parameter< int >::type strand(strandSEXP);
    Rcpp::traits::input_parameter< int >::type mismatches(mismatchesSEXP);
    Rcpp::traits::input_parameter< bool >::type use_first(use_firstSEXP);
    Rcpp::traits::input_parameter< bool >::type diagnostics(diagnosticsSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_dual_barcodes_single_end(path, constant, pools, strand, mismatches, use_first, diagnostics, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// count_random_barcodes
Rcpp::List count_random_barcodes(std::string path, std::string constant, int strand, int mismatches, bool use_first, int nthreads);
RcppExport SEXP _screenCounter_count_random_barcodes(SEXP pathSEXP, SEXP constantSEXP, SEXP strandSEXP, SEXP mismatchesSEXP, SEXP use_firstSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< std::string >::type constant(constantSEXP);
    Rcpp::traits::input_parameter< int >::type strand(strandSEXP);
    Rcpp::traits::input_parameter< int >::type mismatches(mismatchesSEXP);
    Rcpp::traits::input_parameter< bool >::type use_first(use_firstSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_random_barcodes(path, constant, strand, mismatches, use_first, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// count_single_barcodes
Rcpp::List count_single_barcodes(std::string path, std::string constant, int strand, Rcpp::CharacterVector pool, int mismatches, bool use_first, int nthreads);
RcppExport SEXP _screenCounter_count_single_barcodes(SEXP pathSEXP, SEXP constantSEXP, SEXP strandSEXP, SEXP poolSEXP, SEXP mismatchesSEXP, SEXP use_firstSEXP, SEXP nthreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< std::string >::type constant(constantSEXP);
    Rcpp::traits::input_parameter< int >::type strand(strandSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type pool(poolSEXP);
    Rcpp::traits::input_parameter< int >::type mismatches(mismatchesSEXP);
    Rcpp::traits::input_parameter< bool >::type use_first(use_firstSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_single_barcodes(path, constant, strand, pool, mismatches, use_first, nthreads));
    return rcpp_result_gen;
END_RCPP
}
// match_barcodes
Rcpp::List match_barcodes(Rcpp::CharacterVector sequences, Rcpp::CharacterVector choices, int substitutions, bool reverse);
RcppExport SEXP _screenCounter_match_barcodes(SEXP sequencesSEXP, SEXP choicesSEXP, SEXP substitutionsSEXP, SEXP reverseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type sequences(sequencesSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< int >::type substitutions(substitutionsSEXP);
    Rcpp::traits::input_parameter< bool >::type reverse(reverseSEXP);
    rcpp_result_gen = Rcpp::wrap(match_barcodes(sequences, choices, substitutions, reverse));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_screenCounter_count_combo_barcodes_paired", (DL_FUNC) &_screenCounter_count_combo_barcodes_paired, 13},
    {"_screenCounter_count_combo_barcodes_single", (DL_FUNC) &_screenCounter_count_combo_barcodes_single, 7},
    {"_screenCounter_count_dual_barcodes", (DL_FUNC) &_screenCounter_count_dual_barcodes, 14},
    {"_screenCounter_count_dual_barcodes_single_end", (DL_FUNC) &_screenCounter_count_dual_barcodes_single_end, 8},
    {"_screenCounter_count_random_barcodes", (DL_FUNC) &_screenCounter_count_random_barcodes, 6},
    {"_screenCounter_count_single_barcodes", (DL_FUNC) &_screenCounter_count_single_barcodes, 7},
    {"_screenCounter_match_barcodes", (DL_FUNC) &_screenCounter_match_barcodes, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_screenCounter(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
