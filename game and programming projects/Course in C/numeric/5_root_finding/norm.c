#include "include.h"

double norm(gsl_vector* v){

double sum = 0;

for(int i=0; i< v->size; i++){
	sum += pow( gsl_vector_get(v,i), 2);
	}

return sqrt(sum);
}
