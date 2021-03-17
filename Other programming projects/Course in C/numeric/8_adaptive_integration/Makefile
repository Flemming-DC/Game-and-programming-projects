CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

run:out.txt
	cat $<


out.txt:main
	./$< > $@


main: main.o adaptive_integrator.o clenshaw_curtis.o gsl_integrator.o


.PHONY: clean

clean:
	$(RM) main *.o *.txt


