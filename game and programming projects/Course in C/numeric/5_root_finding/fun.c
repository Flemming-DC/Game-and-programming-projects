#include "include.h"

void fun_jac(const gsl_vector* x, gsl_vector* fx, gsl_matrix* J){

double a = 1e4;

gsl_vector_set(fx, 0, a*gsl_vector_get(x,0)*gsl_vector_get(x,1)-1 );
gsl_vector_set(fx, 1, exp( -gsl_vector_get(x,0) ) + exp( -gsl_vector_get(x,1) ) - 1 - 1/a );

gsl_matrix_set(J, 0, 0, a*gsl_vector_get(x,1) );
gsl_matrix_set(J, 0, 1, a*gsl_vector_get(x,0) );
gsl_matrix_set(J, 1, 0, -exp( -gsl_vector_get(x,0) ) );
gsl_matrix_set(J, 1, 1, -exp( -gsl_vector_get(x,1) ) );

}


void fun_nojac(const gsl_vector* x, gsl_vector* fx){

double a = 1e4;

gsl_vector_set(fx, 0, a*gsl_vector_get(x,0)*gsl_vector_get(x,1)-1 );
gsl_vector_set(fx, 1, exp( -gsl_vector_get(x,0) ) + exp( -gsl_vector_get(x,1) ) - 1 - 1/a );

}


int fun_gsl(const gsl_vector* x, void* params, gsl_vector* fx){

double a = 1e4;

gsl_vector_set(fx, 0, a*gsl_vector_get(x,0)*gsl_vector_get(x,1)-1 );
gsl_vector_set(fx, 1, exp( -gsl_vector_get(x,0) ) + exp( -gsl_vector_get(x,1) ) - 1 - 1/a );

return GSL_SUCCESS;
}



