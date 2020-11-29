CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

run: out.txt
	cat $^

out.txt: main
	./$<  >  $@


main: main.o jacobi.o sub_jacobi.o print_matrix.o


.PHONY: clean

clean:
	$(RM) main *.o *.txt

