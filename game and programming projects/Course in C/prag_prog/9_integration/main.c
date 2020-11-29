#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>


double f(double x, void* params){
double f = log(x)/sqrt(x);
return f;}

double psi_norm_square(double x, void* params){
double alpha = *(double *) params;
double psi_norm_square = exp(-alpha*x*x);
return psi_norm_square;}

double psi_H_psi(double x, void* params){
double alpha = *(double *) params;
double psi_H_psi = (-pow(alpha*x,2)+alpha+pow(x,2))*0.5*exp(-alpha*x*x);
return psi_H_psi;}



int main(int argc, char *argv[]){

if(argc<2){
	printf("too few arguments\n");
	return 1;
}

double a=0;
double b=1;
size_t n=1000;
double epsabs=1e-4;
double epsrel=1e-4;
size_t limit=1000;
double int_f,int_pns,int_pHp,error_f,error_pns,error_pHp;

gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(n);


gsl_function F;
F.function = &f;
double p=1.0;
F.params = &p;

gsl_integration_qags(&F, a, b, epsabs, epsrel, limit, workspace, &int_f, &error_f);
//fprintf(stderr,"int_f=%g\n",int_f);




gsl_function pns;
pns.function = &psi_norm_square;

gsl_function pHp;
pHp.function = &psi_H_psi;


for(int i=1;i<argc;i++){


	double alpha=atof(argv[i]);
	pns.params = &alpha;
	pHp.params = &alpha;


	gsl_integration_qagi(&pns, epsabs, epsrel, limit, workspace, &int_pns, &error_pns);
	gsl_integration_qagi(&pHp, epsabs, epsrel, limit, workspace, &int_pHp, &error_pHp);



	double E=int_pHp/int_pns;

	/*
	printf("int_pns=%g\n",int_pns);
	printf("int_pHp=%g\n",int_pHp);
	printf("E=%g\n",E);
	*/
	printf("%g	%g\n",alpha,E);
}

gsl_integration_workspace_free(workspace);


return 0;}

