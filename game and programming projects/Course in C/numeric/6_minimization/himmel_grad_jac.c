#include "include.h"

void himmel_grad_jac(const gsl_vector* x, gsl_vector* fx, gsl_matrix* J){

double x0 = gsl_vector_get(x,0);
double x1 = gsl_vector_get(x,1);

gsl_vector_set(fx, 0, 4*x0*(x0*x0+x1-11) + 2*(x0+x1*x1-7) );
gsl_vector_set(fx, 1, 2*(x0*x0+x1-11) + 4*x1*(x0+x1*x1-7) );

gsl_matrix_set(J, 0, 0, 12*x0*x0+4*x1-42 );
gsl_matrix_set(J, 0, 1, 4*(x0+x1) );
gsl_matrix_set(J, 1, 0, 4*(x0+x1) );
gsl_matrix_set(J, 1, 1, 12*x1*x1+4*x0-26 );

}

