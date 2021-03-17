CFLAGS = -Wall -std=gnu99 
LDLIBS = -pthread -fopenmp -lgomp -lm 

run: out_pthread.txt out_omp.txt
	cat $^

out_omp.txt:omp
	./$<  >  $@

out_pthread.txt:pthread
	./$<  >  $@


omp: omp.o
pthread: pthread.o


.PHONY: clean

clean:
	$(RM) *.o *.txt pthread omp
