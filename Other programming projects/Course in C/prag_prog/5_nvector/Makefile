CFLAGS=-Wall -std=gnu99
LDLIBS=-lm

all:out.txt
	cat $< 

out.txt:main2
	./$< > $@  



main2:main2.o nvector.o

main2.o nvector.o:nvector.h



clean:
	$(RM) main main.o nvector.o out.txt main2 main2.o

