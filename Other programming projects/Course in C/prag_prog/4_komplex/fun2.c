#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){



struct S {int i; double d;};
//struct S V;
struct S V = {2,3.3};

printf("V[0]=%i and V[1]=%g\n",V.i,V.d);

typedef struct S S;
S W = {1,2.1};

printf("W[0]=%i and W[1]=%g\n",W.i,W.d);







/*
double* ptr;
double a=2;

ptr =& a;
printf("%g\n",*ptr);

int A[10];

A[0]=1;
*(A+1)=2;
printf("%i\n",*A);
printf("%i\n",A[1]);

int n=10;
double* B = malloc(n*sizeof(double));

B[0]=10;
*(B+1)=20;
printf("%g\n",*B);
printf("%g\n",B[1]);

free(B);
*/



return 0;}
