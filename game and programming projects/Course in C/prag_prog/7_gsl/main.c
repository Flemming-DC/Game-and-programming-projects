#include "make_gamma_plot.h"
#include "airy.h"
#include "gsl/gsl_vector.h"
#include "gsl/gsl_matrix.h"
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_blas.h>

int main(){


airy();

//make_gamma_plot();


const int n=3;
gsl_vector* v = gsl_vector_alloc(n);
gsl_vector* w = gsl_vector_alloc(n);
gsl_vector* x = gsl_vector_alloc(n);
gsl_matrix* A = gsl_matrix_alloc(n,n);
gsl_matrix* B = gsl_matrix_alloc(n,n);


gsl_vector_set(v,0,6.23);
gsl_vector_set(v,1,5.37);
gsl_vector_set(v,2,2.29);

gsl_matrix_set(A,0,0,6.13);	gsl_matrix_set(A,0,1,-2.9);	gsl_matrix_set(A,0,2,5.86);
gsl_matrix_set(A,1,0,8.08);	gsl_matrix_set(A,1,1,-6.31);	gsl_matrix_set(A,1,2,-3.89);
gsl_matrix_set(A,2,0,-4.36);	gsl_matrix_set(A,2,1,1.00);	gsl_matrix_set(A,2,2,0.19);

//B=(const gsl_matrix*) A;
gsl_matrix_memcpy(B,A);


/*
gsl_vector_fprintf(stdout,v,"%g");
printf("hej\n");
gsl_matrix_fprintf(stdout,A,"%g");
printf("hej\n");
gsl_matrix_fprintf(stdout,B,"%g");
*/

printf("Løsningen er:\n");
gsl_linalg_HH_solve(B,v,x);
gsl_vector_fprintf(stdout,x,"x=%g");

printf("Nu tester vi om løsningen passer.\n");

gsl_blas_dgemv(CblasNoTrans, 1, A, x, 0, w);
gsl_vector_fprintf(stdout,w,"v=%g");

printf("Det passer!\n");


gsl_vector_free(v);
gsl_vector_free(w);
gsl_vector_free(x);
gsl_matrix_free(A);
gsl_matrix_free(B);


return 0;}
