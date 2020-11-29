#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){

int m = INT_MAX;
double m_d = (double) INT_MAX;
double mio = 1000000;
printf("int_max = %i\n",m);
printf("int_max = %g mio.\n",m_d/mio);

return 0;}
