CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm

run: out_main.txt
	cat $^

out_main.txt:main
	./$<  >  $@


main: main.o


.PHONY: clean

clean:
	$(RM) *.o *.txt main
