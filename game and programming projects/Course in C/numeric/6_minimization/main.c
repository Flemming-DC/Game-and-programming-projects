#include "include.h"
double f(double, gsl_vector*);


int main(){

double err_tol = 1e-5;
gsl_vector* x = gsl_vector_alloc(2);
gsl_vector* x3 = gsl_vector_alloc(3);
gsl_vector* fx = gsl_vector_alloc(2);
gsl_matrix* J = gsl_matrix_alloc(2,2);


printf("\n Minimizing rosen without broyden's update\n");
gsl_vector_set(x,0,2);
gsl_vector_set(x,1,1.5);

newton_jac(rosen_grad_jac,x,err_tol);


printf("\n Minimizing himmel without broyden's update\n");
gsl_vector_set(x,0,3);
gsl_vector_set(x,1,3);
newton_jac(himmel_grad_jac,x,err_tol);


printf("\n Minimizing rosen with broyden's update\n");
gsl_vector_set(x,0,2);
gsl_vector_set(x,1,1.5);
qnewton(rosen,x,err_tol);

printf("\n Minimizing himmel with broyden's update\n");
gsl_vector_set(x,0,3);
gsl_vector_set(x,1,3);
qnewton(himmel,x,err_tol);

printf("\n Minimizing square_deviation with broyden's update, thereby fitting data\n");
gsl_vector_set(x3,0,4);
gsl_vector_set(x3,1,4);
gsl_vector_set(x3,2,1);
qnewton(square_deviation,x3,err_tol);


gsl_vector_free(x);
gsl_vector_free(x3);
gsl_vector_free(fx);
gsl_matrix_free(J);


return 0;}
