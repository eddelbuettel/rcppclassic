
#include <RcppClassic.h>

// [[Rcpp::depends(RcppClassic)]]

using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::List RcppMatrix_int(SEXP x) {
    RcppMatrix<int> m(x);
    RcppResultSet rs;
    rs.add("dim1",  m.getDim1());
    rs.add("dim2",  m.getDim2());
    rs.add("rows",  m.rows());
    rs.add("cols",  m.cols());
    rs.add("p22",   m(1,1));
    std::vector<std::vector<int> > mm = m.stlMatrix();
    rs.add("m",     mm);
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppMatrix_double(SEXP x) {
    RcppMatrix<double> m(x);
    RcppResultSet rs;
    rs.add("dim1",  m.getDim1());
    rs.add("dim2",  m.getDim2());
    rs.add("rows",  m.rows());
    rs.add("cols",  m.cols());
    rs.add("p22",   m(1,1));
    std::vector<std::vector<double> > mm = m.stlMatrix();
    rs.add("m",     mm);
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppMatrix_double_na_nan(SEXP x) {
    RcppMatrix<double> m(x);
    RcppResultSet rs;
    rs.add("na_21",  R_IsNA(m(1,0)));
    rs.add("na_22",  R_IsNA(m(1,1)));
    rs.add("nan_31", R_IsNaN(m(2,0)));
    rs.add("nan_32", R_IsNaN(m(2,1)));
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppMatrixView_int(SEXP x) {
    RcppMatrixView<int> m(x);
    RcppResultSet rs;
    rs.add("dim1",  m.dim1());
    rs.add("dim2",  m.dim2());
    rs.add("rows",  m.rows());
    rs.add("cols",  m.cols());
    rs.add("p22",   m(1,1));
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppMatrixView_double(SEXP x) {
    RcppMatrixView<double> m(x);
    RcppResultSet rs;
    rs.add("dim1",  m.dim1());
    rs.add("dim2",  m.dim2());
    rs.add("rows",  m.rows());
    rs.add("cols",  m.cols());
    rs.add("p22",   m(1,1));
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppVector_int(SEXP x) {
    RcppVector<int> m(x);
    RcppResultSet rs;
    rs.add("size",  m.size());
    rs.add("p2",    m(1));
    std::vector<int> v = m.stlVector();
    rs.add("v",     v);
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppVector_double(SEXP x) {
    RcppVector<double> m(x);
    RcppResultSet rs;
    rs.add("size", m.size());
    rs.add("p2",   m(1));
    std::vector<double> v = m.stlVector();
    rs.add("v",     v);
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppVector_double_na_nan(SEXP x) {
    RcppVector<double> m(x);
    RcppResultSet rs;
    rs.add("na_2",  R_IsNA(m(1)));
    rs.add("na_3",  R_IsNA(m(2)));
    rs.add("nan_4", R_IsNaN(m(3)));
    rs.add("nan_5", R_IsNaN(m(4)));
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppVectorView_int(SEXP x) {
    RcppVectorView<int> m(x);
    RcppResultSet rs;
    rs.add("size",  m.size());
    rs.add("p2",    m(1));
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppVectorView_double(SEXP x) {
    RcppVectorView<double> m(x);
    RcppResultSet rs;
    rs.add("size", m.size());
    rs.add("p2",   m(1));
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppStringVector_classic(SEXP x) {
    RcppStringVector s = RcppStringVector(x);
    RcppResultSet rs;
    rs.add("string", s);
    return rs.getReturnList();
}

// [[Rcpp::export]]
SEXP RcppStringVector_wrap(SEXP x) {
    RcppStringVector s = RcppStringVector(x);
    return wrap(s);
}

// [[Rcpp::export]]
SEXP RcppStringVector_begin(SEXP x) {
    RcppStringVector s = RcppStringVector(x);
    return wrap(*s.begin());
}

// [[Rcpp::export]]
SEXP RcppStringVector_end(SEXP x) {
    RcppStringVector s = RcppStringVector(x);
    return wrap(s(s.size()-1));
}
