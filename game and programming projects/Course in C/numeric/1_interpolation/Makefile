CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm


run: out.txt plot_deriv.svg plot_int.svg plot_pol.svg


plot_deriv.svg: out.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Derivative of quardratic interpolation of exp(0.5*x)';\
	set xlabel 'x';\
	set ylabel 'derivative';\
	plot '$<' using 1:5 with lines title 'derivative of quardratic interpolant' \
	" > $@


plot_int.svg: out.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Integral of linear and quardratic interpolations of exp(0.5*x)';\
	set xlabel 'x';\
	set ylabel 'integral';\
	plot '$<' using 1:3 with lines title 'integral of linear interpolant' \
	,    '$<' using 1:5 with lines title 'integral of quardratic interpolant' \
	" > $@

plot_pol.svg: out.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Linear and quardratic interpolation of exp(0.5*x)';\
	set xlabel 'x';\
	set ylabel 'interpolant';\
	plot '$<' using 1:2 with lines title 'linear interpolation' \
	,    '$<' using 1:4 with lines title 'quardratic interpolation' \
	" > $@


out.txt: main
	./$<  >  $@

main: main.o lin_pol.o lin_int.o quar_pol.o


.PHONY: clean

clean:
	$(RM) main *.o *.txt *.svg


