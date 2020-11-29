#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char** argv){


for(int i=1;i<argc;i++){
	double y=atof(argv[i]);
	printf("%g	%lg\n",y,sin(y));
}

/*
double x;
while( scanf("%lg",&x) != EOF ) printf("%lg \t %lg\n",x,cos(x));
*/


return 0;}
