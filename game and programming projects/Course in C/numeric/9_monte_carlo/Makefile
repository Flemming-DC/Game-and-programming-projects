CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

run: out.txt plot.svg
	cat out.txt

plot.svg: plot.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Error as function of number of datapoints in the monte carlo integrator.';\
	set xlabel 'log10(n)';\
	set ylabel 'log10(error)';\
	set grid; \
	plot '$<' using 1:2 with lines title 'tendenslinje' \
	    ,'$<' using 1:3 with points title 'sample standarddeviation on integral' \
	    ,'$<' using 1:4 with points title 'error-estimate calculated by the integrator' \
	" > $@


out.txt plot.txt: main
	./$<  1>  out.txt


main: main.o monte_carlo.o print_matrix.o


.PHONY: clean

clean:
	$(RM) main *.o *.txt
