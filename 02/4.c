#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float rand_float(float min, float max );
void Quicksort(float A[], int p, int r);
int Partition(float A[], int p, int r);
void swap(float* ptr1, float* ptr2);

int main(){
    srand(time(NULL));
    float arr[10];
    for(int i=0; i<10; i++){
        arr[i]=rand_float(-1.5, 5.5);
        printf("%f, ", arr[i]);
    }
    printf("\n");
    Quicksort(arr, 0, 9);
    for(int i=0; i<10; i++)
        printf("%f, ", arr[i]);
    printf("\n");
}

float rand_float(float min, float max ){
    float s=rand()/(float)RAND_MAX;
    return min+s*(max-min);
}

void Quicksort(float A[], int p, int r){
    if(p<r){
        int q=Partition(A, p, r);
        Quicksort(A, p, q);
        Quicksort(A, q+1, r);
    }
}

int Partition(float A[], int p, int r){
    float x=A[p];
    int i=p-1;
    int j=r+1;
    while(1){
        do{
            j--;
        }while(A[j]>x);
        do{
            i++;
        }while(A[i]<x);
        if(i<j)
            swap(A+i, A+j);
        else return j;
    }
}

void swap(float* ptr1, float* ptr2){
    float tmp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=tmp;
}