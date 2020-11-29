CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


run: out.txt plot.svg
	cat out.txt


plot.svg: plot.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'fit of c_1log(x)+c_2+c_3x to data';\
	set xlabel 'x';\
	set ylabel 'c_1log(x)+c_2+c_3x';\
	plot '$<' using 1:2 with lines title 'c_1log(x)+c_2+c_3x' \
	,    '$<' using 3:4:5 with yerrorbars title 'data' \
	" > $@


out.txt plot.txt: main
	./$<  1>  out.txt


main: main.o gram_schmidt.o QR_solve.o inverse.o print_matrix.o include.h


.PHONY: clean

clean:
	$(RM) main *.o *.txt *.svg




