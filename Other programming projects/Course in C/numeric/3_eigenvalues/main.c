#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <time.h>


int jacobi(gsl_matrix*, gsl_vector*, gsl_matrix*);
int sub_jacobi(gsl_matrix*, gsl_vector*, gsl_matrix*, int);
int print_matrix(FILE*, gsl_matrix*);


int main(){

int n=4;
int required=4;
gsl_matrix* A = gsl_matrix_alloc(n,n);
gsl_vector* diag = gsl_vector_alloc(n);
gsl_matrix* V = gsl_matrix_alloc(n,n);
gsl_matrix* AgangeV = gsl_matrix_alloc(n,n);
gsl_matrix* VtransposeAV = gsl_matrix_alloc(n,n);

for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
                gsl_matrix_set(A,i,j, (double)rand()/RAND_MAX*7.0-2.0 );         //random double i [-2,5]
                gsl_matrix_set(A,j,i, gsl_matrix_get(A,i,j) );
                }
        }



clock_t begin = clock();
sub_jacobi(A, diag, V, required);
clock_t end = clock();



for(int i=0; i<n; i++){		//her gendanner vi A
        for(int j=i+1; j<n; j++){
                gsl_matrix_set(A,i,j, gsl_matrix_get(A,j,i) );
                }
        }


printf("matrix to be diagonalized = \n");
print_matrix(stdout,A);

printf("array of column-eigenvectors = \n");
print_matrix(stdout,V);

printf("list of eigenvalues = \n");
for(int i=0; i<n; i++) printf(" 	%g", gsl_vector_get(diag,i) );
printf("\n\n");


gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1, A, V, 0, AgangeV);
/*
printf("AV = \n");
print_matrix(stdout,VtransposeAV);
*/
gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1, V, AgangeV, 0, VtransposeAV);


printf("test: D = V^T*A*V = \n");
print_matrix(stdout,VtransposeAV);


printf("array of matrix sizes and diagonalization times for cyclic method (1st and 2nd row) and value-by-value mtehod for one eigen value (3rd and 4th row) and for all eigenvalues (5th and 6th row) = \n"
	"100	0.078125   	1000	0.265625   	50	0.25\n"
	"200	0.609375   	2000	1.125   	100	4.25\n"
	"300	2.0625   	3000	2.65625   	150	21.3594\n"
	"400	5.07812   	4000	5.5		200	79.0781\n"
	"500	11.0625   	5000	6.9375   	\n"
	"600	18.3125   	6000	11.7188   	\n");
printf("the sizes and times roughly follow a O(n^k) relation, where k=3 for cyclic method k=2 for value-by-value for one eigenvalue and k=4 for value-by-value for all eigenvalues. This can easily be seen on a log-log plot\n\n");

double time_of_diagonalization = (double)(end-begin)/CLOCKS_PER_SEC;
printf("time_of_diagonalization = %g\n\n",time_of_diagonalization);

printf("to obtain the largest eigenvalues rather than the lowest, you must enter the sub-jacobi file and flip the sign of both inputs to tan2\n\n");
printf("to use the cyclic method instead of value-by-value, you must enter the main file and replace"
	"'sub_jacobi(A, diag, V, required);' with 'jacobi(A, diag, V);'\n");

gsl_matrix_free(A);
gsl_vector_free(diag);
gsl_matrix_free(V);
gsl_matrix_free(AgangeV);
gsl_matrix_free(VtransposeAV);

return 0;}
