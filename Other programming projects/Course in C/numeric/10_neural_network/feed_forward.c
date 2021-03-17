#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <gsl/gsl_vector.h>

double f(double x){return x*exp(-x*x);}
double dfdx(double x){return (1-2*x*x)*exp(-x*x);}
double int_f(double x){return -0.5*exp(-x*x);}


double feed_forward(double x, gsl_vector* p){

int n = (p->size)/3;

double F=0;
for(int i=0; i<n; i++){
	double ai = gsl_vector_get(p,0*n+i);
	double bi = gsl_vector_get(p,1*n+i);
	double wi = gsl_vector_get(p,2*n+i);
	double vi = bi*(x-ai);
	F += wi*f(vi);
}

return F;
}



double derivative(double x, gsl_vector* p){

int n = (p->size)/3;

double dFdx=0;
for(int i=0; i<n; i++){
	double ai = gsl_vector_get(p,0*n+i);
	double bi = gsl_vector_get(p,1*n+i);
	double wi = gsl_vector_get(p,2*n+i);
	double vi = bi*(x-ai);
	dFdx += wi*bi*dfdx(vi);
}

return dFdx;
}


double integral(double x, gsl_vector* p){

int n = (p->size)/3;

double int_F=0;
for(int i=0; i<n; i++){
	double ai = gsl_vector_get(p,0*n+i);
	double bi = gsl_vector_get(p,1*n+i);
	double wi = gsl_vector_get(p,2*n+i);
	double vi = bi*(x-ai);
	int_F += wi*int_f(vi)/bi;
}

return int_F;
}
















