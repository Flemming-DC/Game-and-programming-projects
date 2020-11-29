
CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


run: out.txt plot_function.svg plot_derivative.svg plot_integral.svg
	cat out.txt


plot_function.svg: plot.txt main Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Fit to data';\
	set xlabel 'x';\
	set ylabel 'F_p(x)';\
	plot '$<' using 1:2 with lines title 'fit' \
	   , '$<' using 5:6 with points title 'data' \
	" > $@

plot_integral.svg: plot.txt main Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Fit to data';\
	set xlabel 'x';\
	set ylabel 'Integral of F_p(x)';\
	plot '$<' using 1:4 with lines title 'anti-derivative' \
	" > $@

plot_derivative.svg: plot.txt main Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Derivative of fit to data';\
	set xlabel 'x';\
	set ylabel 'dF_pdx(x)';\
	plot '$<' using 1:3 with lines title 'derivative' \
	" > $@



out.txt plot.txt: main
	./$<  1>  out.txt


main: main.o feed_forward.o square_deviation.o qnewton.o train_without_guess.o train_with_guess.o include.h 




.PHONY: clean

clean:
	$(RM) main *.o *.txt *.svg

