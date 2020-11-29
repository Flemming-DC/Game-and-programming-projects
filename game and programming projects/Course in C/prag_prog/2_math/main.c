#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>


int main(){


double gamma = tgamma(5);
double bessel_j1 = j1(0.5);
double complex i_sqrt_2 = csqrt(-2);
double complex e_i = cexp(I);
double complex e_i_pi = cexp(I*M_PI);
double complex i_e = cpow(I,exp(1));


printf("gamma(5) = %g\n",gamma);
printf("J_1(0.5) = %g\n",bessel_j1);
printf("sqrt(-2) = I*%g\n",cimag(i_sqrt_2));
printf("exp(i) = %g+I*%g\n",creal(e_i),cimag(e_i));
printf("exp(i*pi) = %g\n",creal(e_i_pi));
printf("i^e = %g+I*%g\n",creal(i_e),cimag(i_e));


float f = 0.1111111111111111111111111111;
double d = 0.1111111111111111111111111111;
long double ld = 0.1111111111111111111111111111L;

printf("float 0.1111111111111111111111111111 = %.25g\n",f);
printf("double 0.1111111111111111111111111111 = %.25lg\n",d);
printf("long double 0.1111111111111111111111111111 = %.25Lg\n",ld);



return 0;}


