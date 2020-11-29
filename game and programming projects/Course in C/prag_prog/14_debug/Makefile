
CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


report.pdf: latex.tex plot-cairo.tex
	pdflatex $<

plot-cairo.tex: plot.gpi out.txt
	sed -e 's/TERM/cairolatex pdf/' -e 's/OUT/$@/' < $< | gnuplot

run: out.txt
	cat $^

out.txt:find_rod
	./$< `seq -2 0.1 2`  >  $@


find_rod: find_rod.o fun.c print.c def.h


.PHONY: clean

clean:
	$(RM) *.o *.txt *.svg *.pdf find_rod plot-cairo.tex *.aux *.log

