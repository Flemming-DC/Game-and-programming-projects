#include <math.h>
#include <gsl/gsl_vector.h>

double rosen(gsl_vector* x){

double a = 1e2;
double x0 = gsl_vector_get(x,0);
double x1 = gsl_vector_get(x,1);

double phi = (1-x0)*(1-x0)+a*(x1-x0)*(x1-x0);

return phi;
}


