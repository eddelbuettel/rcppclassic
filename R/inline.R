
inlineCxxPlugin <- Rcpp::Rcpp.plugin.maker(
    include.before = "#include <RcppClassic.h>",
    package = "RcppClassic",
    Makevars = NULL,
    Makevars.win = NULL,
    libs = RcppClassicLdFlags()
    )

RcppClassic.system.file <- function(...) {
    tools::file_path_as_absolute(base::system.file(..., package = "RcppClassic"))
}

RcppClassicLdPath <- function() {
    if (nzchar(.Platform$r_arch)) {	## eg amd64, ia64, mips
        path <- RcppClassic.system.file("lib",.Platform$r_arch)
    } else {
        path <- RcppClassic.system.file("lib")
    }
    path
}

RcppClassicLdFlags <- function(static=staticLinking()) {
    rcppclassicdir <- RcppClassicLdPath()
    if (static) {                               # static is default on Windows and OS X
        if (.isMacOS()) {
            flags <- file.path(rcppclassicdir, .getMachine(), "libRcppClassic.a")
        } else {
            flags <- file.path(rcppclassicdir, "libRcppClassic.a")
        }
    } else {					# else for dynamic linking
        flags <- paste0("-L", rcppclassicdir, " -lRcppClassic") # baseline setting
        if ((.Platform$OS.type == "unix") &&    # on Linux, we can use rpath to encode path
            (length(grep("^linux",R.version$os)))) {
            flags <- paste0(flags, " -Wl,-rpath,", rcppclassicdir)
        }
    }
    invisible(flags)
}

LdFlags <- function(static=staticLinking()) {
    cat(RcppClassicLdFlags(static=static))
}

staticLinking <- function() {
    ! grepl( "^linux", R.version$os )
}

.getMachine <- function() {
    ## we use 'uname' as a crosscompilation may occur and the host system
    ## given in `Sys.info()["machine"]` may not be the target platform
    .machine <- system2("uname", "-m", stdout = TRUE)
    .machine
}

.isMacOS <- function() {
    Sys.info()[["sysname"]] == "Darwin"
}
