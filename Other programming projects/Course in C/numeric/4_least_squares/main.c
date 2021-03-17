#include "include.h"

void gram_schmidt(gsl_matrix*, gsl_matrix*);
void QR_solve(gsl_matrix*, gsl_matrix*, gsl_vector*, gsl_vector*);
void inverse(gsl_matrix*, gsl_matrix*, gsl_matrix*);
void print_matrix(FILE*, gsl_matrix*);

int main(){

int n = 9;
int m = 3;

gsl_matrix* A = gsl_matrix_alloc(n,m);
gsl_matrix* Q = gsl_matrix_alloc(n,m);
gsl_matrix* R = gsl_matrix_calloc(m,m);
gsl_matrix* AtransA = gsl_matrix_alloc(m,m);
gsl_matrix* R_AtransA = gsl_matrix_calloc(m,m);
gsl_matrix* covariance = gsl_matrix_calloc(m,m);
gsl_vector* b = gsl_vector_alloc(n);
gsl_vector* c = gsl_vector_alloc(m);


double x[9]  = {0.1, 1.33, 2.55, 3.78, 5, 6.22, 7.45, 8.68, 9.9};
double y[9]  = {-15.3, 0.32, 2.45, 2.75, 2.27, 1.35, 0.157, -1.23, -2.75};
double dy[9] = { 1.04, 0.594, 0.983, 0.998, 1.11, 0.398, 0.535, 0.968, 0.478};


for(int i=0; i<n; i++){
        gsl_vector_set(b,i,y[i]/dy[i] );

	gsl_matrix_set(A,i,0,log(x[i]) );
	gsl_matrix_set(A,i,1,1 );
	gsl_matrix_set(A,i,2,x[i] );

        for(int j=0; j<m; j++){
                gsl_matrix_set(Q,i,j, gsl_matrix_get(A,i,j) );
                }
        }


gram_schmidt(Q,R);


QR_solve(Q,R,b,c);

printf("c = \n");
for(int i=0; i<m; i++) printf("    %g",gsl_vector_get(c,i) );
printf("\n\n");

gsl_blas_dgemm(CblasTrans, CblasNoTrans, 1, A, A, 0, AtransA);

printf("A^T*A = \n");
print_matrix(stdout,AtransA);

gram_schmidt(AtransA, R_AtransA);
inverse(AtransA, R_AtransA, covariance);

printf("covariance matrix = \n");
print_matrix(stdout,covariance);

int N=100;
double x_g[N];
double F[100];
FILE* plot = fopen("plot.txt", "w+");

for(int i=0; i<N; i++){
	x_g[i] = 0.1*i;
	F[i] = gsl_vector_get(c,0)*log(x_g[i]) + gsl_vector_get(c,1) + gsl_vector_get(c,2)*x_g[i];

	if(i<n) fprintf(plot,"%g	%g	%g	%g	%g", x_g[i], F[i], x[i], y[i], dy[i] );
	fprintf(plot, "%g	%g\n", x_g[i], F[i] );
	}

fclose(plot);




gsl_matrix_free(A);
gsl_matrix_free(Q);
gsl_matrix_free(R);
gsl_matrix_free(AtransA);
gsl_matrix_free(R_AtransA);
gsl_matrix_free(covariance);

gsl_vector_free(b);
gsl_vector_free(c);


return 0; }
