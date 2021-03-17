#include<stdio.h>
#include<math.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>

void numeric_gradient(double beta(gsl_vector*), gsl_vector*x, gsl_vector*grad){
	double fx=beta(x);
	double eps=1e-6;
	for(int i=0;i< x->size;i++){
		double xi=gsl_vector_get(x,i);
		double dx=abs(xi)*eps;
		if(abs(xi)<sqrt(eps)) dx=eps;
		gsl_vector_set(x,i,xi+dx);
		gsl_vector_set(grad,i,(beta(x)-fx)/dx);
		gsl_vector_set(x,i,xi);
	}

}

void qnewton(double beta(gsl_vector*), gsl_vector*x, double acc) {
	int n=x->size,nsteps=0,nbad=0,ngood=0;
	gsl_matrix* B=gsl_matrix_alloc(n,n);
	gsl_vector* gradient=gsl_vector_alloc(n);
	gsl_vector* Dx=gsl_vector_alloc(n);
	gsl_vector* z=gsl_vector_alloc(n);
	gsl_vector* gz=gsl_vector_alloc(n);
	gsl_vector* y=gsl_vector_alloc(n);
	gsl_vector* u=gsl_vector_alloc(n);
	gsl_matrix_set_identity(B);
	numeric_gradient(beta,x,gradient);
	double fx=beta(x),fz;
	double eps=1e-6;
	int max_nstep=1e3;
	while(nsteps<max_nstep){
		nsteps++;
		gsl_blas_dgemv(CblasNoTrans,-1,B,gradient,0,Dx);
		if(gsl_blas_dnrm2(Dx)<eps*gsl_blas_dnrm2(x))
			{printf("searching stops, since step-size is less than eps*|x|\n"); break;}
		if(gsl_blas_dnrm2(gradient)<acc)
			{printf("searching stops, since the gradient is less than the required accuracy\n"); break;}
		double lambda=1;
		while(1){
			gsl_vector_memcpy(z,x);
			gsl_vector_add(z,Dx);
			fz=beta(z);
			double sTg; gsl_blas_ddot(Dx,gradient,&sTg);
			if(fz<fx+0.01*sTg){
				ngood++;
				break;
				}
			if(lambda<eps){
				nbad++;
				break;
				}
			lambda*=0.5;
			gsl_vector_scale(Dx,0.5);
		}
		numeric_gradient(beta,z,gz);
		gsl_vector_memcpy(y,gz);
		gsl_blas_daxpy(-1,gradient,y); // y=grad(z)-grad(x)
		gsl_vector_memcpy(u,Dx); // u=s
		gsl_blas_dgemv(CblasNoTrans,-1,B,y,1,u); // u=s-By
		double sTy,uTy;
		gsl_blas_ddot(Dx,y,&sTy);
		if(abs(sTy)>1e-12){
			gsl_blas_ddot(u,y,&uTy);
			double gamma=uTy/2/sTy;
			gsl_blas_daxpy(-gamma,Dx,u); // u=u-gamma*s
			gsl_blas_dger(1.0/sTy,u,Dx,B);
			gsl_blas_dger(1.0/sTy,Dx,u,B);
		}
		gsl_vector_memcpy(x,z);
		gsl_vector_memcpy(gradient,gz);
		fx=fz;
	}
if(nsteps==max_nstep) printf("warning: maximum step number reached. minimization may have failed\n");


gsl_matrix_free(B);
gsl_vector_free(gradient);
gsl_vector_free(Dx);
gsl_vector_free(z);
gsl_vector_free(gz);
gsl_vector_free(y);
gsl_vector_free(u);

printf("number of steps = %i\n",nsteps);
printf("objective function at root = %g\n",fx);
printf("x_root = ");
for(int i=0; i<n; i++)  printf("%g   	",gsl_vector_get(x,i));
printf("\n");


}
