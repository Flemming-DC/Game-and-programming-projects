CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)


run: out.txt plot.svg
	cat out.txt


plot.svg: data.txt Makefile
	gnuplot -e "\
	set terminal svg background 'white'; \
	set xrange [-2:2];\
	set yrange [-2:2];\
	set title 'Orbit of planet in a relativistic gravitational field';\
	plot '$<' using 1:2 with lines title 'orbit' \
	" > $@




#data.txt:main
#	./main 2> $@

out.txt data.txt: main
	./main > out.txt

main: main.o ode_logistic.o ode_orbit.o orbit_make_graph.o 


.PHONY: clean

clean:
	$(RM) main *.txt *.o





