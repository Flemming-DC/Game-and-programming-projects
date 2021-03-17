CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


run:main out_int.txt plot.svg
	cat out_int.txt

plot.svg: data.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set title 'Energi of harmonic oscillator as a function of the variational parameter alpha';\
	set xlabel 'alpha';\
	set ylabel 'E';\
	plot \
	 '$<' using 1:2 with lines title 'J_0' \
	" > $@


data.txt:main Makefile
	./main `seq .2 .02 2` > data.txt

out_int.txt: int
	./$<  >  $@

main: main.o

int: int.o

.PHONY: clean

clean:
	$(RM) main *.o *.txt *.svg






