CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

run: out.txt plot_1.svg plot_2.svg plot_3.svg
	cat out.txt


plot_1.svg: path.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'y_1(x) = integral of exp(x) from 2 to x';\
	set xlabel 'x';\
	set ylabel 'y_1(x)';\
	plot '$<' using 1:2 with lines title 'y_1(x)' \
	" > $@

plot_2.svg: path.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'y_2(x) = integral of x from 2 to x';\
	set xlabel 'x';\
	set ylabel 'y_2(x)';\
	plot '$<' using 1:3 with lines title 'y_2(x)' \
	" > $@

plot_3.svg: path.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'y_3(x) = integral of 1./x from 2 to x';\
	set xlabel 'x';\
	set ylabel 'y_3(x)';\
	plot '$<' using 1:4 with lines title 'y_3(x)' \
	" > $@


out.txt path.txt: main
	./$<  1>  out.txt


main: main.o rkstep23.o driver.o


.PHONY: clean

clean:
	$(RM) main *.o *.txt *.svg


