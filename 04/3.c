#include "stdio.h"
#include "stdlib.h"

int main(){
    int N=0;
    printf("Podaj wysokosc trojkata:\n");
    scanf("%d", &N);
    int* pas=calloc(1, sizeof(int));
    for(int i=0; i<N+1; i++){
        pas=realloc(pas, sizeof(int)*(i+1));
        for(int j=0; j<N-i; j++)
            printf(" ");
        for(int j=i; j>=0; j--){
            if(j==0 || j==i)
                pas[j]=1;
            else
                pas[j]=pas[j-1]+pas[j];
            printf("%d ", pas[j]);
        }
        printf("\n");
    }
    free(pas);
}