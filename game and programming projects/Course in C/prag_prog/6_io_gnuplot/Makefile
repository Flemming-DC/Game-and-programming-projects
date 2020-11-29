CFLAGS=-Wall -std=gnu99
LDLIBS=-lm

all:std.out.txt cmd.out.txt plot.svg
	cat std.out.txt cmd.out.txt          

plot.svg:plot.gpi cmd.out.txt std.out.txt
	gnuplot $< > $@


plot.pgi:std.out.txt cmd.out.txt
	./std.out.txt ./cmd.out.txt > plot.gpi


std.out.txt:main-stdio Makefile
	echo 0 1 2 3 4 5 | ./main-stdio > std.out.txt     

main-stdio:main-stdio.o



cmd.out.txt:main-cmdline Makefile
	./main-cmdline 3 2 6 7 8 9 > cmd.out.txt     

main-cmdline:main-cmdline.o




clean:
	$(RM) main-stdio main-cmdline *.o *.txt *.svg




