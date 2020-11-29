#include <stdio.h>
#include <math.h>

int main(){
	double x=2;
	printf("hello æøåñ x=%8.3g\n",x);
	fprintf(stdout,"this goes to stdout\n");
	FILE* mystream=fopen("out.mystream","w");
	fprintf(mystream,"this goes to mystream");
	fclose(mystream);
	scanf("%lg",&x);
	printf("x=%lg\n",x);

return 0;}
