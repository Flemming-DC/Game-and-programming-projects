#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>



int equal(double a, double b, double t, double e);



int equal(double a, double b, double t, double e){

if (abs(a-b)<t) {printf("1\n");}
else if (abs(a-b)*2/(a+b)<e) {printf("1\n");}
else printf("0\n");

return 0;}


int main(){

equal(2,5,0.1,0.1);


return 0;}
