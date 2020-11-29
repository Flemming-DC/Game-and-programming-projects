
CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = $$(gsl-config --libs)

run: out.txt
	cat $^

out.txt: main
	./$<  >  $@


main: main.o square_deviation.o qnewton.o norm.o gram_schmidt.o QR_solve.o rosen_grad_jac.o himmel_grad_jac.o rosen.o himmel.o newton_jac.o print_matrix.o include.h



.PHONY: clean

clean:
	$(RM) main *.o *.txt

