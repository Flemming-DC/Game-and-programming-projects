#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

void* fun(void* ptr_void_N){

double* ptr_double_N=(double*)ptr_void_N;
double N=*ptr_double_N;
double N_inside=0;

for(int i=0; i<N; i++){
	unsigned int seed = i*i-i+3;
	double x = (double)rand_r(&seed)/(double)RAND_MAX;
	double y = (double)rand_r(&seed)/(double)RAND_MAX;
	if(sqrt(x*x+y*y)<1) {
		N_inside++;
		}
	}
double pi=4*N_inside/N;
printf("for N=%g, så fås pi=%g\n",N,pi);

return 0;
}


int main(){

for(int j=0; j<6; j++){

	double N = pow(10,j);
	pthread_t thread;

	pthread_create(&thread, NULL, fun, &N);
	pthread_join(thread, NULL);

	}

return 0;
}

