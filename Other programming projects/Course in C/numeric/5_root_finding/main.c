#include "include.h"


int main(){

double err_tol = 1e-5;
gsl_vector* x = gsl_vector_alloc(2);
gsl_vector* fx = gsl_vector_alloc(2);
gsl_matrix* J = gsl_matrix_alloc(2,2);


printf("\n Searching for roots in fun with jacobian\n");
gsl_vector_set(x,0,8.0);
gsl_vector_set(x,1,1.0);
newton_jac(fun_jac,x,err_tol);



printf("\n Minimizing rosen with jacobian\n");
gsl_vector_set(x,0,2);
gsl_vector_set(x,1,1.5);
newton_jac(rosen_grad_jac,x,err_tol);


printf("\n Minimizing himmel with jacobian\n");
gsl_vector_set(x,0,3);
gsl_vector_set(x,1,3);
newton_jac(himmel_grad_jac,x,err_tol);


printf("\n Searching for roots in fun without jacobian\n");
gsl_vector_set(x,0,10);
gsl_vector_set(x,1,5);
newton_nojac(fun_nojac,x,err_tol);


printf("\n Minimizing rosen without jacobian\n");
gsl_vector_set(x,0,2);
gsl_vector_set(x,1,1.5);
newton_nojac(rosen_grad_nojac,x,err_tol);


printf("\n Minimizing himmel without jacobian \n");
gsl_vector_set(x,0,3);
gsl_vector_set(x,1,3);
newton_nojac(himmel_grad_nojac,x,err_tol);


printf("\n Searching for roots in fun with gsl_solver\n");
gsl_vector_set(x,0,10);
gsl_vector_set(x,1,5);
gsl_solver(&fun_gsl,x,err_tol);


printf("\n Minimizing rosen with gsl_solver\n");
gsl_vector_set(x,0,2);
gsl_vector_set(x,1,1.5);
gsl_solver(&rosen_grad_gsl,x,err_tol);


printf("\n Minimizing himmel with gsl_solver \n");
gsl_vector_set(x,0,3);
gsl_vector_set(x,1,3);
gsl_solver(&himmel_grad_gsl,x,err_tol);

gsl_vector_free(x);
gsl_vector_free(fx);
gsl_matrix_free(J);


return 0;}
