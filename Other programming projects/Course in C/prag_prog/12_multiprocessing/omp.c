#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void fun(double N){

double N_inside=0;

#pragma omp parrallel for reduction(+:N_inside)
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

}


int main(){

for(int j=0; j<6; j++){
	double N = pow(10,j);
	fun(N);
	}

return 0;
}
