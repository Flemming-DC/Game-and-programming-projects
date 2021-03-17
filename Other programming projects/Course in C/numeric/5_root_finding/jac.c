#include "include.h"

void jac(void f(const gsl_vector* x, gsl_vector* fx), gsl_vector* x, gsl_matrix* J){

double eps = 1e-9;
double n = x->size;
gsl_vector* x_next = gsl_vector_alloc(n);
gsl_vector* fx = gsl_vector_alloc(n);
gsl_vector* fx_next = gsl_vector_alloc(n);
gsl_vector_memcpy(x_next,x);
f(x,fx);
if(fx->size != n) printf("fejl: fx og x skal have samme længde\n");

for(int j=0; j<n; j++){
	gsl_vector_set(x_next,j, gsl_vector_get(x,j)+eps );
	f(x_next,fx_next);

	for(int i=0; i<n; i++){
		gsl_matrix_set(J,i,j, ( gsl_vector_get(fx_next,i)-gsl_vector_get(fx,i) )/eps );
		}
	gsl_vector_set(x_next,j, gsl_vector_get(x,j) );
	}


}
