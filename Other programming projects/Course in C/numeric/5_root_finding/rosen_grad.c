#include "include.h"

void rosen_grad_jac(const gsl_vector* x, gsl_vector* fx, gsl_matrix* J){

double a = 1e2;
double x0 = gsl_vector_get(x,0);
double x1 = gsl_vector_get(x,1);

gsl_vector_set(fx, 0, 2*(x0-1)-4*a*x0*(x1-x0*x0) );
gsl_vector_set(fx, 1, 2*a*(x1-x0*x0) );

gsl_matrix_set(J, 0, 0, 2+8*a*x0*x0-4*a*(x1-x0*x0) );
gsl_matrix_set(J, 0, 1, -4*a*x0 );
gsl_matrix_set(J, 1, 0, -4*a*x0 );
gsl_matrix_set(J, 1, 1, 2*a );

}


void rosen_grad_nojac(const gsl_vector* x, gsl_vector* fx){

double a = 1e2;
double x0 = gsl_vector_get(x,0);
double x1 = gsl_vector_get(x,1);

gsl_vector_set(fx, 0, 2*(x0-1)-4*a*x0*(x1-x0*x0) );
gsl_vector_set(fx, 1, 2*a*(x1-x0*x0) );

}


int rosen_grad_gsl(const gsl_vector* x, void* params, gsl_vector* fx){

double a = 1e2;
double x0 = gsl_vector_get(x,0);
double x1 = gsl_vector_get(x,1);

gsl_vector_set(fx, 0, 2*(x0-1)-4*a*x0*(x1-x0*x0) );
gsl_vector_set(fx, 1, 2*a*(x1-x0*x0) );

return GSL_SUCCESS;
}


