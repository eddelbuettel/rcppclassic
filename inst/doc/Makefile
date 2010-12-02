
## There is an old bug in texidvi that makes it not swallow the ~
## marker used to denote whitespace. This is actually due to fixing
## another bug they whereby you could not run texidvi on directory
## names containing a tilde (as we happen to do for Debian builds of R
## alpha/beta/rc releases). The 'tilde' bug will go away as it
## reportedly has been squashed upstream but I am still bitten by it
## on Ubuntu so for Dirk will insist on pdflatex and this variable helps
whoami=$(shell whoami)

all: clean index.html RcppClassic.pdf

pdfclean:
	rm -f RcppClassic.pdf
clean:
	rm -f index.html
	rm -f *.tex *.bbl *.blg *.aux *.out *.log

RcppClassic.pdf: RcppClassic.Rnw
	R CMD Sweave RcppClassic.Rnw
	Rscript --vanilla -e "tools::texi2dvi( 'RcppClassic.tex', pdf = TRUE, clean = FALSE )"
	rm -fr RcppClassic.tex

