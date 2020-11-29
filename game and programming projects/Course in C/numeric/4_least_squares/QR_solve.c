#include "include.h"

void back_sub(gsl_matrix* R, gsl_vector* c){

int n = c->size;


for(int i=n-1; i>=0; i--){
        double s = gsl_vector_get(c,i);
        for(int k=i+1; k<n; k++){
                s -= gsl_matrix_get(R,i,k)*gsl_vector_get(c,k);
                }

        gsl_vector_set(c,i,s/gsl_matrix_get(R,i,i));
        }

}



void QR_solve(gsl_matrix* Q, gsl_matrix* R, gsl_vector* b, gsl_vector* x){


gsl_blas_dgemv(CblasTrans, 1.0, Q, b, 0.0, x);   //denne værdi af x bliver snart overskrevet

back_sub(R,x);

}

