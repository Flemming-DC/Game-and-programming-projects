#include <math.h>
#include "gsl/gsl_vector.h"

double feed_forward(double, gsl_vector*);


double square_deviation(gsl_vector* p, gsl_vector* x, gsl_vector* y){

int N_data = x -> size;

double sum = 0;
for(int i=0; i<N_data; i++){
	double xi=gsl_vector_get(x,i);
	double yi=gsl_vector_get(y,i);
	double fi=feed_forward(xi,p);
	sum += pow(fi-yi,2);
	}


return sum/N_data;
}
