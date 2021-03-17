#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double add(double (*f[2])(double),double x){
return (*f[1])(1)+x;
}


int main(int argc, char* argv[]){


if(argc<2) printf("du mangler et input\n");
else {
	double z = atof(argv[1]);
	fprintf(stderr,"%g\n",z+1);
}


fprintf(stderr,"bum bum bum");

FILE* s=fopen("out.txt","w");
fprintf(s,"hello\n");
fprintf(s,"hello\n");
fprintf(s,"hello\n");
fclose(s);

//double y;
//scanf("%lg\n",&y);






double (*f[2])(double)= {&sin,&cos};
double x=1;
printf("%g\n",add(f,x));

struct T {int i; double (*g)(double);};
struct T S = {3,exp};
printf("S0=%i og S1=%g\n",S.i,S.g(1));



return 0;}





