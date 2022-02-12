#include "stdio.h"
#include "stdlib.h"
#include "time.h"

float float_rand(float min, float max){
    float s=rand()/(float)RAND_MAX;
    return min+s*(max-min);
}

int main(){
    srand(time(NULL));
    int n;
    printf("Prosze podac rozmiar tablicy:\n");
    scanf("%d", &n);
    float* arr=calloc(n, sizeof(float));
    for(int i=0; i<n; i++){
        arr[i]=float_rand(-1.5, 1.5);
        printf("%f\t", arr[i]);
    }

    printf("\n");

    float* dod=calloc(1,sizeof(float));
    float* uje=calloc(1,sizeof(float));

    int s1=0;
    int s2=0;

    for(int i=0; i<n; i++){
        if(arr[i]<0){
            s2++;
            uje=realloc(uje, s2*sizeof(float));
            uje[s2-1]=arr[i];
        }
        else{
            s1++;
            dod=realloc(dod, s1*sizeof(float));
            dod[s1-1]=arr[i];
        }
    }
    for(int i=0; i<s2; i++)
        printf("%f\t", uje[i]);
    printf("\n");
    for(int i=0; i<s1; i++)
        printf("%f\t", dod[i]);
    printf("\n");
    free(arr);
    free(uje);
    free(dod);
}