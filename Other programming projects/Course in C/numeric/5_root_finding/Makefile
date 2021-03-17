
CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

run: out.txt
	cat $^

out.txt: main
	./$<  >  $@


main: main.o norm.o gram_schmidt.o QR_solve.o fun.o rosen_grad.o himmel_grad.o newton_jac.o newton_nojac.o print_matrix.o jac.o gsl_solver.o include.h



.PHONY: clean

clean:
	$(RM) main *.o *.txt

