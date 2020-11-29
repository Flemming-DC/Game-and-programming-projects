#include "include.h"
#define RND (double)rand()/RAND_MAX


void train_without_guess(gsl_vector* p_root, gsl_vector* x, gsl_vector* y, gsl_matrix* B, int N_guess, double acc){

int n = (p_root->size)/3;
assert(3*n == p_root->size);

gsl_vector* p = gsl_vector_calloc(3*n);

double b00 = gsl_matrix_get(B,0,0); double b01 = gsl_matrix_get(B,0,1);
double b10 = gsl_matrix_get(B,1,0); double b11 = gsl_matrix_get(B,1,1);
double b20 = gsl_matrix_get(B,2,0); double b21 = gsl_matrix_get(B,2,1);


for(int k=0; k<N_guess; k++){
        for(int i=0;   i<n;   i++) gsl_vector_set(p,i, b00 + (b01-b00)*RND );
        for(int i=n;   i<2*n; i++) gsl_vector_set(p,i, b10 + (b11-b10)*RND );
        for(int i=2*n; i<3*n; i++) gsl_vector_set(p,i, b20 + (b21-b20)*RND );

        qnewton(square_deviation,p,x,y,acc);
        if(square_deviation(p,x,y) <= square_deviation(p_root,x,y)) gsl_vector_memcpy(p_root,p);
        }


gsl_vector_free(p);

}



