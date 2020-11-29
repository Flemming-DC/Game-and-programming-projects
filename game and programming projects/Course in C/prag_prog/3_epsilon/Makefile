CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm

run: out_limit.txt out_sum.txt out_Equal.txt
	cat $^



out_Equal.txt: equal
	./$<  >  $@

out_sum.txt: sum
	./$<  >  $@

out_limit.txt: limit
	./$<  >  $@



equal: equal.o

sum: sum.o

limit: limit.o




.PHONY: clean

clean:
	$(RM) *.o *.txt Equal sum limit

