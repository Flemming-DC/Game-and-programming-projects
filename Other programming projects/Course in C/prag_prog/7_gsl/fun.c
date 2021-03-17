#include <stdio.h>
#include <gsl/gsl_sf.h>
#include <math.h>

int main(){

double x=3;
double y = gsl_sf_gamma(x);
printf("%g\n",y);


return 0;}
