#include <stdio.h>
#include <string.h>
#include <math.h>

double f1(double x){
    return -pow(x,2)+3*x+11;
}

int zero(double (*f)(double), double a, double b, double* m_z, double eps){
    if(f(a)==0){
        *m_z=a;
        return 1;
    }
    if(f(b)==0){
        *m_z=b;
        return 1;
    }
    if(f(a)*f(b)<0){
        double tmp=(a+b)/2;
        if(b-tmp<eps){
            *m_z=tmp;
            return 1;
        }
        if(f(a)*f(tmp)<0.)
            return zero(f, a, tmp, m_z, eps);
        else return zero(f, tmp, b, m_z, eps);
    }
    *m_z=-9999;
    return 0;
}

int main(){
    double mz=0.;
    zero(sin, -1, 1, &mz, 0.01);
    printf("%f\n", mz);
    zero(f1, -1, 1, &mz, 0.01);
    printf("%f\n", mz);
    zero(f1, 0, 8, &mz, 0.001);
    printf("%f\n", mz);
}