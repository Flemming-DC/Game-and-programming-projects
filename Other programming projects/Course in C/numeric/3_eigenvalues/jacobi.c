#include<math.h>
#include<gsl/gsl_matrix.h>

int jacobi(gsl_matrix* A, gsl_vector* diag, gsl_matrix* V){
/* Jacobi diagonalization; upper triangle of A is destroyed;
   e and V accumulate eigenvalues and eigenvectors */
int changed, sweeps=0, n=A->size1;

for(int i=0;i<n;i++) gsl_vector_set(diag,i,gsl_matrix_get(A,i,i));

gsl_matrix_set_identity(V);

do{ changed=0; sweeps++; int p,q;
	for(p=0;p<n;p++)for(q=p+1;q<n;q++){
		double a_pp = gsl_vector_get(diag,p);
		double a_qq = gsl_vector_get(diag,q);
		double a_pq = gsl_matrix_get(A,p,q);
		double phi = 0.5*atan2(2*a_pq,a_qq-a_pp);
		double c = cos(phi), s = sin(phi);
		double a_pp1 = c*c*a_pp-2*s*c*a_pq+s*s*a_qq;
		double a_qq1 = s*s*a_pp+2*s*c*a_pq+c*c*a_qq;
		if(a_pp1!=a_pp || a_qq1!=a_qq){
			changed = 1;
			gsl_vector_set(diag,p,a_pp1);
			gsl_vector_set(diag,q,a_qq1);
			gsl_matrix_set(A,p,q,0.0);
			for(int i=0;i<p;i++){
				double a_ip = gsl_matrix_get(A,i,p);
				double a_iq = gsl_matrix_get(A,i,q);
				gsl_matrix_set(A,i,p,c*a_ip-s*a_iq);
				gsl_matrix_set(A,i,q,c*a_iq+s*a_ip); }
			for(int i=p+1;i<q;i++){
				double a_pi = gsl_matrix_get(A,p,i);
				double a_iq = gsl_matrix_get(A,i,q);
				gsl_matrix_set(A,p,i,c*a_pi-s*a_iq);
				gsl_matrix_set(A,i,q,c*a_iq+s*a_pi); }
			for(int i=q+1;i<n;i++){
				double a_pi = gsl_matrix_get(A,p,i);
				double a_qi = gsl_matrix_get(A,q,i);
				gsl_matrix_set(A,p,i,c*a_pi-s*a_qi);
				gsl_matrix_set(A,q,i,c*a_qi+s*a_pi); }
			for(int i=0;i<n;i++){
				double v_ip = gsl_matrix_get(V,i,p);
				double v_iq = gsl_matrix_get(V,i,q);
				gsl_matrix_set(V,i,p,c*v_ip-s*v_iq);
				gsl_matrix_set(V,i,q,c*v_iq+s*v_ip); }
			}
		}
	}
while(changed!=0);

return sweeps; }
