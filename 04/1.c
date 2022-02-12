#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float float_rand(float min, float max){
    float s=rand()/(float)RAND_MAX;
    return min+s*(max-min);
}

int main(){
    srand(time(NULL));
    int size=0, new_size=0;
    printf("Prosze podac rozmiar tablicy:\n");
    scanf("%d", &size);
    float *arr=calloc(size, sizeof(float));
    for(int i=0; i<size; i++)
        arr[i]=float_rand(23., 34.);
    float *iter=arr;
    for(int i=0; i<size; i++)
        printf("%f\t", *(iter+i));
    printf("\nProsze podac nowy rozmiar tablicy:\n");
    scanf("%d", &new_size);
    if(new_size>size){
        arr=realloc(arr, new_size*sizeof(float));
        for(int i=size; i<new_size; i++)
            arr[i]=float_rand(-20., -5.);
    }
    else{
        arr=realloc(arr, new_size*sizeof(float));
    }
    iter=arr;
    for(int i=0; i<new_size; i++)
        printf("%f\t", *(iter+i));
    printf("\n");
    free(arr);
}