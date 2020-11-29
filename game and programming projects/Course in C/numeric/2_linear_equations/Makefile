CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

run: out.txt
	cat $^

out.txt: main
	./$<  >  $@


main: main.o gram_schmidt.o QR_solve.o inverse.o print_matrix.o include.h 


.PHONY: clean

clean:
	$(RM) main *.o *.txt
