
#include "include.h"


void gram_schmidt(gsl_matrix* A, gsl_matrix* R){


int n = A->size1;       //number of rows
int m = A->size2;       //number of columns


for(int i=0; i<m; i++){
        double a_i_norm_square = 0;   //a_i er den i'te søjle, ikke den i'te række
        for(int j=0; j<n; j++){
                a_i_norm_square += pow( gsl_matrix_get(A,j,i),2 );   //bemærk at i,j bytts om pga. dum notation mht. sø$
		}
        gsl_matrix_set(R,i,i,sqrt(a_i_norm_square));

        for(int j=0; j<n; j++){
                gsl_matrix_set(A,j,i, gsl_matrix_get(A,j,i)/sqrt(a_i_norm_square) );   //bemærk at i,j byttes om
                }


        for(int j=i+1; j<m; j++){


                double dot_product_ij = 0;
                for(int k=0; k<n; k++){
                        dot_product_ij += gsl_matrix_get(A,k,i)*gsl_matrix_get(A,k,j);   //bemærk at i,k og k,j byttes $
                        }
                gsl_matrix_set(R,i,j,dot_product_ij);


                for(int k=0; k<n; k++){
                        gsl_matrix_set(A,k,j, gsl_matrix_get(A,k,j) - gsl_matrix_get(A,k,i)*dot_product_ij );  //bemærk$

                        }
                }

/*      for(int j=0; j<i; j++){
                gsl_matrix_set(R,i,j,0.0);
                }
*/
        }



}


