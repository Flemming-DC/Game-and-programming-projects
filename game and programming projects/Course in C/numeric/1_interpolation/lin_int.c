#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double lin_pol(int n, double *x, double* y, double z);


double lin_int(int n, double *x, double* y, double z){

assert(n>1);
assert(z>=x[0]);
assert(z<=x[n-1]);

int i=0, j=n-1;

while (j-i>1){int m=(i+j)/2 ; if (z>x[m]) i=m; else j=m;} /* binarysearch: */

double sum=0;

for(int k=0; k<i; k++){
	sum += 0.5*(x[k+1]-x[k])*(y[k+1]-y[k]) + (x[k+1]-x[k])*y[k];
	}


sum += 0.5*(z-x[i])*(y[i+1]-y[i]) + (z-x[i])*y[i];


return sum;
}

