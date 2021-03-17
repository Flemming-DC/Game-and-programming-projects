CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


erf_latex.pdf: erf.tex plot-cairo.tex
	pdflatex $<

plot-cairo.tex: plot.gpi out_integrate.txt
	sed -e 's/TERM/cairolatex pdf/' -e 's/OUT/$@/' < $< | gnuplot


run: out_integrate.txt
	cat $^

out_integrate.txt:integrate
	./integrate 0.5 1.5 0.05  >  $@


integrate: integrate.o


.PHONY: clean

clean:
	$(RM) *.o *.pdf *.txt integrate

