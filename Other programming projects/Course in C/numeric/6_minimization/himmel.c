#include "math.h"
#include "gsl/gsl_vector.h"


double himmel(gsl_vector* x){

double x0 = gsl_vector_get(x,0);
double x1 = gsl_vector_get(x,1);

double phi = (x0*x0+x1-11)*(x0*x0+x1-11) + (x0+x1*x1-7)*(x0+x1*x1-7);

return phi;
}




