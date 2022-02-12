#include <stdio.h>
#include <stdlib.h>

float* my_floor(float* a, float* b){
    float* r=calloc(1, sizeof(float));
    int tmp=(int)(*a**b);
    if(tmp<0)
        tmp--;
    *r=(float)tmp;
    return r;
}

int main(){
    float a=3.;
    float b=1.34;
    float *c=my_floor(&a, &b);
    printf("wynik to : %f\n", *c);
}

