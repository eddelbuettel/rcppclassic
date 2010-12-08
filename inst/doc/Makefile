
## There is an old bug in texidvi that makes it not swallow the ~
## marker used to denote whitespace. This is actually due to fixing
## another bug they whereby you could not run texidvi on directory
## names containing a tilde (as we happen to do for Debian builds of R
## alpha/beta/rc releases). The 'tilde' bug will go away as it
## reportedly has been squashed upstream but I am still bitten by it
## on Ubuntu so for Dirk will insist on pdflatex and this variable helps
whoami=$(shell whoami)

all: clean RcppClassic-unitTests.pdf RcppClassic.pdf 

pdfclean:
	rm -f RcppClassic.pdf RcppClassic-unitTests.pdf
clean:
	@rm -f *.tex *.bbl *.blg *.aux *.out *.log

RcppClassic-unitTests.pdf:
	rm -fr unitTests-results/*
	Rscript --vanilla unitTests/RcppClassic-unitTests.R
	R CMD Sweave RcppClassic-unitTests.Rnw
	Rscript --vanilla -e "tools::texi2dvi( 'RcppClassic-unitTests.tex', pdf = TRUE, clean = TRUE )"
	rm -fr RcppClassic-unitTests.tex

RcppClassic.pdf: RcppClassic.Rnw
	R CMD Sweave RcppClassic.Rnw
ifneq (,$(findstring edd,$(whoami)))
	pdflatex RcppClassic.tex
	bibtex RcppClassic
	pdflatex RcppClassic.tex
	pdflatex RcppClassic.tex
else
	Rscript --vanilla -e "tools::texi2dvi( 'RcppClassic.tex', pdf = TRUE, clean = FALSE )"
endif
	rm -fr RcppClassic.tex

