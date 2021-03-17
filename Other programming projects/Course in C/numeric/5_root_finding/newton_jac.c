#include "include.h"


void newton_jac(void f(const gsl_vector* x, gsl_vector* fx, gsl_matrix* J), gsl_vector* x, double err_tol){

int n = x->size;

gsl_vector* fx = gsl_vector_alloc(n);
gsl_vector* minus_fx = gsl_vector_alloc(n);
gsl_vector* fx_next = gsl_vector_alloc(n);
gsl_vector* dx = gsl_vector_alloc(n);
gsl_vector* x_next = gsl_vector_alloc(n);
gsl_matrix* J = gsl_matrix_alloc(n,n);
gsl_matrix* R = gsl_matrix_alloc(n,n);


if(fx->size != n) printf("fejl: fx og x skal have samme længde\n");

int i=0;
double L;


do{
	f(x,fx,J);

	gram_schmidt(J,R);

	gsl_vector_memcpy(minus_fx,fx);
	gsl_vector_scale(minus_fx, -1.0);
	QR_solve(J,R,minus_fx,dx);
	L=1;

	for(int j=0; j<n; j++){
		gsl_vector_set(x_next,j, gsl_vector_get(x,j)+L*gsl_vector_get(dx,j) );
		}

	double Lmin=1.0/64;
	f(x,fx_next,J);
	while( norm(fx_next)>(1-L/2)*norm(fx) && L>=Lmin ){
		L /= 2;
		gsl_vector_memcpy(x_next,x);
		gsl_blas_daxpy(L, dx, x_next);
		f(x_next,fx_next,J);
		}

	gsl_vector_memcpy(x,x_next);

	for(int j=0; j<n; j++){
		if( gsl_vector_get(x,j) != gsl_vector_get(x,j) ) {printf("error: x_%i=nan\n",j);}
		}
	for(int j=0; j<n; j++){
		if( gsl_vector_get(fx,j) != gsl_vector_get(fx,j) ) {printf("error: fx_%i=nan\n",j);}
		}
	i++;

} while(norm(fx)>err_tol);

printf("number of steps = %i\n",i);
printf("norm of f(x_root) = %g\n",norm(fx));
printf("x_root = ");
for(int i=0; i<n; i++){ printf("%g	", gsl_vector_get(x,i)); }
printf("\n");


gsl_vector_free(fx);
gsl_vector_free(minus_fx);
gsl_vector_free(fx_next);
gsl_vector_free(dx);
gsl_vector_free(x_next);
gsl_matrix_free(J);
gsl_matrix_free(R);

}
