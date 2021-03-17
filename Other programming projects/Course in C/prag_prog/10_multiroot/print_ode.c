#include <stdio.h>
#include <math.h>

double u_ode(double, double);

int main(){

double E = -0.5;
double r = 10;

double U = u_ode(E,r);
double U_control = r*exp(-r);
printf("Solving the radial schrödinger equation with E=0-0.5 up to r=%g gives %g.",r,U);
printf("The correct solution is %g*exp(-%g)=%g.\n",r,r,U_control);


return 0;}

