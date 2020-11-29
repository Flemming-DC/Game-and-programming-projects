#include "include.h"
#include <assert.h>

void QR_solve(gsl_matrix*, gsl_matrix*, gsl_vector*, gsl_vector*);


void inverse(gsl_matrix* Q, gsl_matrix* R, gsl_matrix* A_inv){

assert(Q->size1==Q->size2);
int m=R->size1;
gsl_vector* A_inv_column = gsl_vector_alloc(m);
gsl_vector* e_j = gsl_vector_calloc(m);


for(int j=0; j<m; j++){
	if(j>0) gsl_vector_set(e_j,j-1,0);
	gsl_vector_set(e_j,j,1);
	QR_solve(Q,R,e_j,A_inv_column);
	for(int i=0; i<m; i++){
		gsl_matrix_set(A_inv,i,j, gsl_vector_get(A_inv_column,i) );
		}

	}

gsl_vector_free(A_inv_column);
gsl_vector_free(e_j);
}








