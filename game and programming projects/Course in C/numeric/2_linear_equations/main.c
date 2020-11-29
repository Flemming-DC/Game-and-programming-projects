#include "include.h"

void gram_schmidt(gsl_matrix*, gsl_matrix*);
void QR_solve(gsl_matrix*, gsl_matrix*, gsl_vector*, gsl_vector*);
void inverse(gsl_matrix*, gsl_matrix*, gsl_matrix*);
void print_matrix(FILE*, gsl_matrix*);

int main(){

size_t n = 2;
size_t m = 2;

gsl_matrix* A = gsl_matrix_alloc(n,m);
gsl_matrix* Q = gsl_matrix_alloc(n,m);
gsl_matrix* R = gsl_matrix_calloc(m,m);
gsl_matrix* A_inv = gsl_matrix_alloc(m,m);
gsl_matrix* Q_transpose = gsl_matrix_alloc(m,n);
gsl_matrix* test_A = gsl_matrix_alloc(n,m);
gsl_matrix* test_I = gsl_matrix_alloc(m,m);
gsl_vector* b = gsl_vector_alloc(n);
gsl_vector* test_b = gsl_vector_alloc(n);
gsl_vector* x = gsl_vector_calloc(m);


for(int i=0; i<n; i++){
	gsl_vector_set(b,i,(double)rand()/RAND_MAX*5.0-1.0 );		//random double i [-2,5]

	for(int j=0; j<m; j++){
		gsl_matrix_set(A,i,j,(double)rand()/RAND_MAX*7.0-2.0 );		//random double i [-2,5]
		gsl_matrix_set(Q,i,j, gsl_matrix_get(A,i,j) );
		}
	}



gram_schmidt(Q,R);

printf("\n A = \n");
print_matrix(stdout,A);
printf("\n Q = \n");
print_matrix(stdout,Q);
printf("\n R = \n");
print_matrix(stdout,R);


gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1, Q, R, 0, test_A);

printf("\n test af kode: A = \n");
print_matrix(stdout,test_A);

gsl_matrix_transpose_memcpy(Q_transpose,Q);
gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1, Q_transpose, Q, 0, test_I);

printf("\n test af kode: identity = Q^T*Q = \n");
print_matrix(stdout,test_I);

printf("\n b = \n");
gsl_vector_fprintf(stdout, b,"%g");
printf("\n");

QR_solve(Q,R,b,x);

gsl_blas_dgemv(CblasNoTrans, 1.0, A, x, 0.0, test_b);

printf("\n test af kode: b = A*x = \n");
gsl_vector_fprintf(stdout,test_b,"%g");


inverse(Q,R,A_inv);

gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1, A, A_inv, 0, test_I);

printf("\n test af kode: identity = A*A_inv = \n");
print_matrix(stdout,test_I);





gsl_matrix_free(A);
gsl_matrix_free(Q);
gsl_matrix_free(R);
gsl_matrix_free(A_inv);
gsl_matrix_free(Q_transpose);
gsl_matrix_free(test_A);
gsl_matrix_free(test_I);
gsl_vector_free(b);
gsl_vector_free(test_b);
gsl_vector_free(x);



return 0;
}
