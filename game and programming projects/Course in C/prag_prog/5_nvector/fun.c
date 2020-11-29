#include <stdio.h>
#include <math.h>


int make_table(double (*f)(double), int n, double* x){
	for(int i=0;i<n;i++){
		printf("%g %g\n",x[i],f(x[i]));
	}

return 0;}


void* stpf(void* arg, void* result){
	double x = *(double*)arg;
	double y = sin(x);
	double* z = (double*)result;
	*z=sin(x);
};


int main(){

//	void (*func)(void*,void*)=stpf;
	double (*fun)(double);
	fun=&sin;
	double (*f[3])(double)={sin,cos,tan};
	struct bar {double (*f)(double); double (*g)(double);};
	struct bar foo = {.f=sin, .g=cos};
	const int n=5;
	double x[n];
	for(int i=0;i<n;i++){x[i]=i;}
	make_table(fun,n,x);


return 0;}
