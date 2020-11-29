
CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


run: out_para.txt out_rosen.txt out_fit.txt plot_fit.svg plot_rosen.svg
	cat out_para.txt out_rosen.txt out_fit.txt



plot_fit.svg: err_fit.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Fit af A*exp(-t/T)+B til data';\
	set xlabel 'tid';\
	set ylabel 'aktivitet af radioaktiv substans';\
	plot '$<' using 1:4 with lines title 'fit' \
	, '$<' using 1:2:3 with yerrorbars title 'datapunkter' \
	" > $@

plot_rosen.svg: out_rosen.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'y(x) for vejen mod rosenbrocks minimun';\
	set xlabel 'x';\
	set ylabel 'y(x)';\
	plot \
	 '$<' using 2:3 with lines title 'y(x)' \
	" > $@



out_fit.txt err_fit.txt: fit_min
	./fit_min 1> out_fit.txt   ./fit_min 2> err_fit.txt

out_rosen.txt: rosen_min
	./rosen_min > $@

out_para.txt: para_min
	./para_min > $@



fit_min: fit_min.o fit.o fit_def.h

rosen_min: rosen_min.o rosen.o rosen_def.h

para_min: para_min.o para.o para_def.h



.PHONY: clean

clean:
	$(RM) *.o *.txt *.svg fit_min rosen_min para_min 
