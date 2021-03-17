#include<stdio.h>
#include<stdlib.h>
#include"komplex.h"

void komplex_print (char *s, komplex a) {
	printf ("%s (%g,%g)\n", s, a.re, a.im);
}

komplex komplex_new (double x, double y) {
	komplex z = { x, y };
	return z;
}

void komplex_set (komplex* z, double x, double y) {
	(*z).re = x;
	(*z).im = y;
}

komplex komplex_add (komplex a, komplex b) {
	komplex result = { a.re + b.re , a.im + b.im };
	return result;
}

int komplex_equal(komplex a, komplex b, double t, double e){

if (abs(a.re-b.re)<t && abs(a.im-b.im)<t) {return 1;}
else if (abs(a.re-b.re)/(a.re+b.re)<e && abs(a.im-b.im)/(a.im+b.im)<e) {return 1;}
else return 0;
}
