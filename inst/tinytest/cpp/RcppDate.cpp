
#include <RcppClassic.h>

// [[Rcpp::depends(RcppClassic)]]

using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::List get_functions() {
    RcppDate dt = RcppDate(12,31,1999);
    RcppResultSet rs;
    rs.add("month", dt.getMonth());
    rs.add("day",   dt.getDay());
    rs.add("year",  dt.getYear());
    rs.add("julian",dt.getJulian());
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppDate_operators() {
    RcppDate d1 = RcppDate(12,31,1999);
    RcppDate d2 = d1 + 1;
    RcppResultSet rs;
    rs.add("diff",    d2 - d1);
    rs.add("bigger",  d2 > d1);
    rs.add("smaller", d2 < d1);
    rs.add("equal",   d2 == d1);
    rs.add("ge",      d2 >= d1);
    rs.add("le",      d2 <= d1);
    return rs.getReturnList();
}

// [[Rcpp::export]]
SEXP RcppDate_wrap() {
    RcppDate dt = RcppDate(12,31,1999);
    return wrap(dt);
}

// [[Rcpp::export]]
Rcpp::List RcppDatetime_functions(Rcpp::NumericVector x) {
    RcppDatetime dt = RcppDatetime(x);
    RcppResultSet rs;
    rs.add("year",     dt.getYear());
    rs.add("month",    dt.getMonth());
    rs.add("day",      dt.getDay());
    rs.add("wday",     dt.getWeekday());
    rs.add("hour",     dt.getHour());
    rs.add("minute",   dt.getMinute());
    rs.add("second",   dt.getSecond());
    rs.add("microsec", dt.getMicroSec());
    return rs.getReturnList();
}

// [[Rcpp::export]]
Rcpp::List RcppDatetime_operators() {
    RcppDatetime d1 = RcppDatetime(946774923.123456);
    //RcppDatetime d1 = RcppDatetime(1152338523.456789);
    // as.POSIXct("2006-07-08 01:02:03.456789")
    RcppDatetime d2 = d1 + 60*60;
    RcppResultSet rs;
    rs.add("diff",    d2 - d1);
    rs.add("bigger",  d2 > d1);
    rs.add("smaller", d2 < d1);
    rs.add("equal",   d2 == d1);
    rs.add("ge",      d2 >= d1);
    rs.add("le",      d2 <= d1);
    return rs.getReturnList();
}

// [[Rcpp::export]]
SEXP RcppDatetime_wrap() {
    RcppDatetime dt = RcppDatetime(981162123.123456);
    return wrap(dt);
}
