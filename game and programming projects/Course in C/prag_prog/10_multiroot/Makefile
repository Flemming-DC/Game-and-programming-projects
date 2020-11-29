CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


run: out.rosen.txt out.u_rod.txt out.print_ode.txt 
	cat $^


plot.svg: data.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Probability density for finding the electron at distance r from the nucleus of a hydrogen atom';\
	set xlabel 'r';\
	set ylabel 'probability density';\
	plot '$<' using 1:2 with lines title 'probability density' \
	" > $@


out.u_rod.txt: u_rod
	./$^ > $@

out.print_ode.txt: print_ode
	./$^ > $@

out.rosen.txt: rosen
	./$^ > $@



u_rod: u_rod.o u_lim.o u_print.o u_ode.o u_ode_plot.o u_def.h

print_ode: print_ode.o u_ode.o

rosen: rosen.o rosen_print.o rosen_deriv.o rosen_fun.o rosen_def.h



.PHONY: clean

clean:
	$(RM) print_ode *.o rosen_selv rosen_with_deriv out* u_rod rosen
