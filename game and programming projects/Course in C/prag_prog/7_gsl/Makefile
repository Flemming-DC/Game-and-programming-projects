CFLAGS = -Wall -std=gnu99 $$(gsl-config --cflags)
LDLIBS = `gsl-config --libs`

all: airy.svg out.txt
	cat out.txt

airy.svg: airy.gpi airy.txt
	gnuplot $< > $@

out.txt airy.txt:main
	./$< 1> out.txt 2> airy.txt

main: main.o airy.o

main.o airy.o: airy.h

test:
	@echo $(CFLAGS)
	@echo $(LDLIBS)

.PHONEY:clean
clean:
	$(RM) *.o *.txt *.svg main
