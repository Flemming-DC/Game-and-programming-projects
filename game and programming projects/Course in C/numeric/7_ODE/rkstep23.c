#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void rkstep23(void f(double x, double* y, double* dydx),
	int n, double x, double h, double* yx, double* yh, double* dy){
/*
n  = number of equation = length of yx;
x  = current value of variable
h  = step size
yx = y(x)
f(x,y,dydx) beregner dydx ud fra x og y
yh = y(x+h)
dy = error på yh
*/

int i;
double k1[n], k2[n], k3[n], k4[n], yt[n];


f(x,yx,k1);
for(i=0; i<n; i++){ yt[i] = yx[i]+1./2*k1[i]*h; }

f(x+1./2*h,yx,k2);
for(i=0; i<n; i++){ yt[i] = yx[i]+3./2*k2[i]*h; }

f(x+3./4*h,yx,k3);
for(i=0; i<n; i++){ yh[i] = yx[i]+( 2./9*k1[i]+1./3*k2[i]+4./9*k3[i] )*h; }	//her benyttes b'erne

f(x+h,yh,k4);
for(i=0; i<n; i++){
	yt[i] = yx[i]+( 7./24*k1[i]+1./4*k2[i]+1./3*k3[i]+1./8*k4[i] )*h;	//her benyttes b*'erne
	dy[i] = yh[i]-yt[i];
	}



}

