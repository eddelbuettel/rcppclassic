
## defaults
machine <- '' 							# unset, if used filled-in by `uname -m` to reflect crosscompilation
sysname <- Sys.info()[["sysname"]]		# same as `uname -s`, generally
has_uname <- nzchar(Sys.which("uname"))
arch <- .Platform$r_arch
userdir <- "../inst/lib"

isMacOS <- sysname == "Darwin"

if (isMacOS && has_uname) {
    machine <- system2("uname", "-m", stdout = TRUE)
    userdir <- file.path(userdir, machine)
} else if (arch != "") {
    userdir <- paste0(userdir, arch)
}

infile <- file.path("src", "Makevars.in")
outfile <- file.path("src", "Makevars")
lines <- readLines(infile)
lines <- gsub("@MACHINE@", machine, lines)
lines <- gsub("@ARCH@", arch, lines)
lines <- gsub("@USERDIR@", userdir, lines)
lines <- gsub("@LIBDIR@", gsub("inst/", "", userdir), lines)
writeLines(lines, outfile)
