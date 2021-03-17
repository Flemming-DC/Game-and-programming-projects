#include <math.h>
#include <assert.h>
#include <stdio.h>


double curtis24
        (double f(double, int*),double a_ny, double b_ny, double a, double b,
        double acc, double eps, double f2, double f3, int nrec, int* calls)
{

        assert(nrec<1000000);
        double f1 = f(a + (b-a)*cos(a_ny+(b_ny-a_ny)/6), calls) * sin(a_ny+(b_ny-a_ny)/6) * (b-a);
        double f4 = f(a + (b-a)*cos(a_ny+5*(b_ny-a_ny)/6), calls) * sin(a_ny+5*(b_ny-a_ny)/6) * (b-a);
        double Q = (2*f1+f2+f3+2*f4)/6*(b_ny-a_ny);
        double q = (f1+f4+f2+f3)/4*(b_ny-a_ny);
        double tolerance = acc+eps*fabs(Q);
        double error = fabs(Q-q)/2;
        if(error < tolerance) return Q;
        else {
                double Q1=curtis24(f, a_ny, (a_ny+b_ny)/2, a, b, acc/sqrt(2.), eps, f1, f2, nrec+1, calls);
                double Q2=curtis24(f, (a_ny+b_ny)/2, b_ny, a, b, acc/sqrt(2.), eps, f3, f4, nrec+1, calls);
                return Q1+Q2;
        }

}


double clenshaw_curtis
        (double f(double, int*), double a,double b,
        double acc,double eps,int* calls)
{
        double f2=f( a + (b-a)*cos(M_PI/6), calls ) * sin(M_PI/6) * (b-a);
        double f3=f( a + (b-a)*cos(M_PI/3), calls ) * sin(M_PI/3) * (b-a);
        int nrec=0;
        return curtis24(f,0,M_PI/2,a,b,acc,eps,f2,f3,nrec,calls);
}














