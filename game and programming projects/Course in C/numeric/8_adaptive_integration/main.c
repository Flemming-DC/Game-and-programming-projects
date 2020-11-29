#include <math.h>
#include <assert.h>
#include <stdio.h>

double adaptive_integrator
	(double f(double, int*), double a,double b,double acc,double eps,int* calls);
double curtis
	(double f(double, int*), double a,double b,double acc,double eps,int* calls);
double clenshaw_curtis
	(double f(double, int*),double a,double b,double acc,double eps, int* calls);
void gsl_integrator(void);


double root(double x,int* calls) {
	(*calls)++;
	return sqrt(x);
}


double root_inv(double x, int* calls){
	(*calls)++;
	return 1/sqrt(x);
}


double log_over_root(double x, int* calls){
	(*calls)++;
	return log(x)/sqrt(x);
}

double f(double x, int* calls){
	(*calls)++;
	return 4*sqrt( 1-(1-x)*(1-x) );
}


int main(){


	int calls=0;
	double a=0,b=1,acc=1e-8,eps=1e-8;
	printf("we will integrate some functions from %g to %g with absolute error = %g and relative error = %g\n\n",a,b,acc,eps);

	printf("adaptive_integrator gives:\n");

	calls=0;
	double Q=adaptive_integrator(root,a,b,acc,eps,&calls);
	double exact=2./3;
	printf("\n integrand: sqrt(x)\n");
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));

	calls=0;
	Q=adaptive_integrator(root_inv,a,b,acc,eps,&calls);
	exact=2;
	printf("\n integrand: 1/sqrt(x)\n");
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));

	calls=0;
	Q=adaptive_integrator(log_over_root,a,b,acc,eps,&calls);
	exact=-4;
	printf("\n integrand: ln(x)/sqrt(x)\n");
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));

	calls=0;
	Q=adaptive_integrator(f,a,b,acc,eps,&calls);
	exact=3.141592653589793238462643383279502884197169399375;
	printf("\n integrand: 4*sqrt(1-(1-x)^2)\n");
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));


	printf("\n\n clenshaw_curtis gives:\n");

	calls=0;
	Q=clenshaw_curtis(root,a,b,acc,eps,&calls);
	exact=2./3;
	printf("\n integrand: sqrt(x)\n");
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));



	calls=0;
	Q=clenshaw_curtis(root_inv,a,b,acc,eps,&calls);
	exact=2;
	printf("\n integrand: 1/sqrt(x)\n");
	printf("acc=%g eps=%g\n",acc,eps);
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));

	calls=0;
	Q=clenshaw_curtis(log_over_root,a,b,acc,eps,&calls);
	exact=-4;
	printf("\n integrand: ln(x)/sqrt(x)\n");
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));

	calls=0;
	Q=clenshaw_curtis(f,a,b,acc,eps,&calls);
	exact=3.141592653589793238462643383279502884197169399375;
	printf("\n integrand: 4*sqrt(1-(1-x)^2)\n");
	printf("              Q = %.10g\n",Q);
	printf("          exact = %.10g\n",exact);
	printf("          calls = %d\n",calls);
	printf("estimated error = %g\n",acc+fabs(Q)*eps);
	printf("   actual error = %g\n",fabs(Q-exact));

	printf("\n\n gsl_integrator gives:\n");
	calls=0;
	gsl_integrator();

	printf("\n\n We note that chenshaw_curtis requires fewer calls, than adaptive_integrator, when applied to 1/sqrt(x) or ln(x)/sqrt(x), as expected from the fact that it is designed to deal effectively with singularities.\n");


return 0 ;
}
