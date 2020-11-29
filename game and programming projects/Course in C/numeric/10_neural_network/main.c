#include "include.h"

double function_to_fit(double x){
	return sqrt(5*x)-0.5*x;
}


int main(){

double acc = 1*1e-5;
//int N_guess = 10;
int N_neuron = 3;	//dette kaldes for n i andre stykker kode
int N_data = 60;
int N_taet = 10*N_data;

gsl_vector* p_root = gsl_vector_calloc(3*N_neuron);
gsl_vector* x = gsl_vector_alloc(N_data);	//dette kaldes for d1 i andre stykker kode
gsl_vector* y = gsl_vector_alloc(N_data);	//dette kaldes for d2 i andre stykker kode
gsl_matrix* data = gsl_matrix_alloc(N_data,2);
//gsl_matrix* B = gsl_matrix_calloc(3,2);


double xmin = 0;
double xmax = 15;

for(int i=0; i<N_data; i++) {
	double xi = xmin+xmax/N_data*i;
        gsl_vector_set(x,i, xi);
        gsl_vector_set(y,i, function_to_fit(xi));

        gsl_matrix_set(data,i,0, xi);
        gsl_matrix_set(data,i,1, function_to_fit(xi));
        }


for(int i=0;i<N_neuron;i++){
	double ai = xmin+(i+0.5)*(xmax-xmin)/N_neuron;
	double bi = .1/(i+1);
	double wi = 1;
	gsl_vector_set(p_root, 0*N_neuron+i, ai);
	gsl_vector_set(p_root, 1*N_neuron+i, bi);		//bi ganges på (xi-ai), i stedet for at divideres på
	gsl_vector_set(p_root, 2*N_neuron+i, wi);
	}


train_with_guess(p_root,x,y,acc);


printf("   a          b            w\n");
for(int i=0; i<N_neuron; i++){
	printf("%8.5g", gsl_vector_get(p_root, 0*N_neuron+i) );
	printf("%12.5g", gsl_vector_get(p_root, 1*N_neuron+i) );		//bi ganges på (xi-ai), i stedet for at divideres på
	printf("%12.5g", gsl_vector_get(p_root, 2*N_neuron+i) );
	printf("\n");
	}

/*
gsl_vector_set_all(p_root,0);

    //setting bounderies for guesses
gsl_matrix_set(B,0,1,15);	//maksimum a
gsl_matrix_set(B,1,1,3);	//maksimum b
gsl_matrix_set(B,2,1,10);	//maksimum w


train_without_guess(p_root,x,y,B,N_guess,acc);
printf("train_without_guess:	square_deviation(p_root) = %g\n", square_deviation(p_root,x,y) );
*/


FILE* plot = fopen("plot.txt","w");
for(int i=0; i<N_taet; i++){
	double x_plot = xmin+(i+0.5)*(xmax-xmin)/N_taet;
	fprintf(plot, "%8.8g   %8.8g   %8.8g   %8.8g",
		x_plot,
		feed_forward(x_plot,p_root),
		derivative(x_plot,p_root),
		integral(x_plot,p_root)
		);

	if(i<N_data) fprintf(plot, "%8.5g  %8.5g\n", gsl_vector_get(x,i), gsl_vector_get(y,i) );
	if(i>=N_data) fprintf(plot, "\n");
	}
fclose(plot);






gsl_vector_free(p_root);
gsl_vector_free(x);
gsl_vector_free(y);
gsl_matrix_free(data);
//gsl_matrix_free(B);


return 0;}
