#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_vector.h>


void monte_carlo(double f(gsl_vector* x), int inside(gsl_vector* x), gsl_vector* a, gsl_vector* b, int n,
		double *integral, double *err ){

int d = a->size;
double a_j, b_j, F, sigma_f;
gsl_vector* x = gsl_vector_alloc(d);

double V = 1;
double sum_F = 0;
double sum_F2 = 0;

for(int j=0; j<d; j++){
	a_j = gsl_vector_get(a,j);
	b_j = gsl_vector_get(b,j);
	V *= b_j-a_j;
	}


for(int i=0; i<n; i++){

	for(int j=0; j<d; j++){
		a_j = gsl_vector_get(a,j);
		b_j = gsl_vector_get(b,j);
		gsl_vector_set(x,j, a_j+(b_j-a_j)*(double)rand()/RAND_MAX );
		}
	F = f(x)*inside(x);
	sum_F += F;
	sum_F2 += F*F;
	}

*integral = sum_F*V/n;
sigma_f = sum_F2/n - pow(sum_F/n,2);
*err = sigma_f*V/sqrt(n);

//printf("monte_carlo: integral = %g	err = %g\n", *integral, *err);

gsl_vector_free(x);

}
