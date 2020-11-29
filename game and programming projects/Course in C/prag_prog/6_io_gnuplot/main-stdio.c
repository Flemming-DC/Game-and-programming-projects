#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char** argv){

/*
double a[argc-1];

for(int i=0;i<argc-1;i++){
    a[i]=atof(argv[i+1]);
    printf("%g  %g\n",a[i],cos(a[i]));
}
*/

double x;
while( scanf("%lg",&x) != EOF ) printf("%lg \t %lg\n",x,cos(x));


return 0;}







