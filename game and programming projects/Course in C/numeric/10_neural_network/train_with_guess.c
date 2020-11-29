#include "include.h"


void train_with_guess(gsl_vector* p_root, gsl_vector* x, gsl_vector* y, double acc){


int n = (p_root->size)/3;
assert(3*n == p_root->size);

qnewton(square_deviation,p_root,x,y,acc);


}



