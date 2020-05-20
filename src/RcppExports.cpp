// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// setup_barcodes_combo_dual
SEXP setup_barcodes_combo_dual(SEXP constants, SEXP guide_list, Rcpp::LogicalVector allowSub, Rcpp::LogicalVector allowDel);
RcppExport SEXP _screenCounter_setup_barcodes_combo_dual(SEXP constantsSEXP, SEXP guide_listSEXP, SEXP allowSubSEXP, SEXP allowDelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type constants(constantsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type guide_list(guide_listSEXP);
    Rcpp::traits::input_parameter< Rcpp::LogicalVector >::type allowSub(allowSubSEXP);
    Rcpp::traits::input_parameter< Rcpp::LogicalVector >::type allowDel(allowDelSEXP);
    rcpp_result_gen = Rcpp::wrap(setup_barcodes_combo_dual(constants, guide_list, allowSub, allowDel));
    return rcpp_result_gen;
END_RCPP
}
// count_barcodes_combo_dual
SEXP count_barcodes_combo_dual(SEXP seqs, SEXP xptr, bool use_forward, bool use_reverse);
RcppExport SEXP _screenCounter_count_barcodes_combo_dual(SEXP seqsSEXP, SEXP xptrSEXP, SEXP use_forwardSEXP, SEXP use_reverseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type seqs(seqsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< bool >::type use_forward(use_forwardSEXP);
    Rcpp::traits::input_parameter< bool >::type use_reverse(use_reverseSEXP);
    rcpp_result_gen = Rcpp::wrap(count_barcodes_combo_dual(seqs, xptr, use_forward, use_reverse));
    return rcpp_result_gen;
END_RCPP
}
// report_barcodes_combo_dual
SEXP report_barcodes_combo_dual(SEXP xptr);
RcppExport SEXP _screenCounter_report_barcodes_combo_dual(SEXP xptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type xptr(xptrSEXP);
    rcpp_result_gen = Rcpp::wrap(report_barcodes_combo_dual(xptr));
    return rcpp_result_gen;
END_RCPP
}
// setup_barcodes_single
SEXP setup_barcodes_single(SEXP constants, SEXP guide_list, Rcpp::LogicalVector allowS, Rcpp::LogicalVector allowD);
RcppExport SEXP _screenCounter_setup_barcodes_single(SEXP constantsSEXP, SEXP guide_listSEXP, SEXP allowSSEXP, SEXP allowDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type constants(constantsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type guide_list(guide_listSEXP);
    Rcpp::traits::input_parameter< Rcpp::LogicalVector >::type allowS(allowSSEXP);
    Rcpp::traits::input_parameter< Rcpp::LogicalVector >::type allowD(allowDSEXP);
    rcpp_result_gen = Rcpp::wrap(setup_barcodes_single(constants, guide_list, allowS, allowD));
    return rcpp_result_gen;
END_RCPP
}
// count_barcodes_single
Rcpp::IntegerVector count_barcodes_single(SEXP seqs, SEXP xptr, bool use_forward, bool use_reverse);
RcppExport SEXP _screenCounter_count_barcodes_single(SEXP seqsSEXP, SEXP xptrSEXP, SEXP use_forwardSEXP, SEXP use_reverseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type seqs(seqsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< bool >::type use_forward(use_forwardSEXP);
    Rcpp::traits::input_parameter< bool >::type use_reverse(use_reverseSEXP);
    rcpp_result_gen = Rcpp::wrap(count_barcodes_single(seqs, xptr, use_forward, use_reverse));
    return rcpp_result_gen;
END_RCPP
}
// identify_barcodes_single
Rcpp::IntegerVector identify_barcodes_single(SEXP seqs, SEXP xptr, bool use_forward, bool use_reverse);
RcppExport SEXP _screenCounter_identify_barcodes_single(SEXP seqsSEXP, SEXP xptrSEXP, SEXP use_forwardSEXP, SEXP use_reverseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type seqs(seqsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type xptr(xptrSEXP);
    Rcpp::traits::input_parameter< bool >::type use_forward(use_forwardSEXP);
    Rcpp::traits::input_parameter< bool >::type use_reverse(use_reverseSEXP);
    rcpp_result_gen = Rcpp::wrap(identify_barcodes_single(seqs, xptr, use_forward, use_reverse));
    return rcpp_result_gen;
END_RCPP
}
// basic_hash
SEXP basic_hash(Rcpp::StringVector input);
RcppExport SEXP _screenCounter_basic_hash(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type input(inputSEXP);
    rcpp_result_gen = Rcpp::wrap(basic_hash(input));
    return rcpp_result_gen;
END_RCPP
}
// shift_hash
SEXP shift_hash(Rcpp::StringVector input, Rcpp::StringVector coming);
RcppExport SEXP _screenCounter_shift_hash(SEXP inputSEXP, SEXP comingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type input(inputSEXP);
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type coming(comingSEXP);
    rcpp_result_gen = Rcpp::wrap(shift_hash(input, coming));
    return rcpp_result_gen;
END_RCPP
}
// substitute_hash
SEXP substitute_hash(Rcpp::StringVector input);
RcppExport SEXP _screenCounter_substitute_hash(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type input(inputSEXP);
    rcpp_result_gen = Rcpp::wrap(substitute_hash(input));
    return rcpp_result_gen;
END_RCPP
}
// delete_hash
SEXP delete_hash(Rcpp::StringVector input);
RcppExport SEXP _screenCounter_delete_hash(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type input(inputSEXP);
    rcpp_result_gen = Rcpp::wrap(delete_hash(input));
    return rcpp_result_gen;
END_RCPP
}
// build_dict
SEXP build_dict(Rcpp::StringVector guides, bool allowS, bool allowD);
RcppExport SEXP _screenCounter_build_dict(SEXP guidesSEXP, SEXP allowSSEXP, SEXP allowDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type guides(guidesSEXP);
    Rcpp::traits::input_parameter< bool >::type allowS(allowSSEXP);
    Rcpp::traits::input_parameter< bool >::type allowD(allowDSEXP);
    rcpp_result_gen = Rcpp::wrap(build_dict(guides, allowS, allowD));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_screenCounter_setup_barcodes_combo_dual", (DL_FUNC) &_screenCounter_setup_barcodes_combo_dual, 4},
    {"_screenCounter_count_barcodes_combo_dual", (DL_FUNC) &_screenCounter_count_barcodes_combo_dual, 4},
    {"_screenCounter_report_barcodes_combo_dual", (DL_FUNC) &_screenCounter_report_barcodes_combo_dual, 1},
    {"_screenCounter_setup_barcodes_single", (DL_FUNC) &_screenCounter_setup_barcodes_single, 4},
    {"_screenCounter_count_barcodes_single", (DL_FUNC) &_screenCounter_count_barcodes_single, 4},
    {"_screenCounter_identify_barcodes_single", (DL_FUNC) &_screenCounter_identify_barcodes_single, 4},
    {"_screenCounter_basic_hash", (DL_FUNC) &_screenCounter_basic_hash, 1},
    {"_screenCounter_shift_hash", (DL_FUNC) &_screenCounter_shift_hash, 2},
    {"_screenCounter_substitute_hash", (DL_FUNC) &_screenCounter_substitute_hash, 1},
    {"_screenCounter_delete_hash", (DL_FUNC) &_screenCounter_delete_hash, 1},
    {"_screenCounter_build_dict", (DL_FUNC) &_screenCounter_build_dict, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_screenCounter(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
