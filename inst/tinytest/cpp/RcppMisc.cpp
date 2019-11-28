
#include <RcppClassic.h>

// [[Rcpp::depends(RcppClassic)]]

using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::List RcppFrameFunc() {
    std::vector<std::string> names;
    names.push_back("A");
    names.push_back("B");
    names.push_back("C");
    RcppFrame fr(names);

    std::vector<ColDatum> colDatumVector(3);
    colDatumVector[0].setDoubleValue(1.23);
    colDatumVector[1].setIntValue(42);
    colDatumVector[2].setLogicalValue(0);
    fr.addRow(colDatumVector);

    colDatumVector[0].setDoubleValue(4.56);
    colDatumVector[1].setIntValue(21);
    colDatumVector[2].setLogicalValue(1);
    fr.addRow(colDatumVector);

    RcppResultSet rs;
    rs.add("data.frame", fr);
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppListFunc() {
    RcppList l;
    l.setSize(3);
    l.append("foo", 1);
    l.append("bar", 2.0);
    l.append("biz", "xyz");
    return l.getList();
}

// [[Rcpp::export]]
SEXP RcppParams_Double(SEXP x) {
    double y = 2 * RcppParams(x).getDoubleValue("val");
    return Rcpp::wrap(y);
}

// [[Rcpp::export]]
SEXP RcppParams_Int(SEXP x) {
    int y = 2 * RcppParams(x).getIntValue("val");
    return Rcpp::wrap(y);
}

// [[Rcpp::export]]
SEXP RcppParams_String(SEXP x) {
    std::string y = RcppParams(x).getStringValue("val");
    y = y + y; // trivial string operation
    return Rcpp::wrap(y);
}

// [[Rcpp::export]]
SEXP RcppParams_Bool(SEXP x) {
    bool y = RcppParams(x).getBoolValue("val");
    return Rcpp::wrap(y);
}

// [[Rcpp::export]]
SEXP RcppParams_Date(SEXP x) {
    RcppDate y = RcppParams(x).getDateValue("val");
    RcppResultSet rs;
    rs.add("date", y);
    return rs.getReturnList();
}

// [[Rcpp::export]]
SEXP RcppParams_Datetime(SEXP x) {
    RcppDatetime y = RcppParams(x).getDatetimeValue("val");
    RcppResultSet rs;
    rs.add("datetime", y);
    return rs.getReturnList();
}
