#include <stdio.h>
#include <stdlib.h>

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n"); return;
}

void proc_1(int arr[], int size, int n){
    if(n>=size)
        return;
    for(int i=0; i<n; i++){
        int tmp=arr[0];
        for(int j=1; j<size; j++)
            arr[j-1]=arr[j];
        arr[size-1]=tmp;
    }
}

int main(){
    int tab_1[5] = {1,2,3,4,5};
    proc_1(tab_1, sizeof(tab_1)/sizeof(int), 3);
    wypisz_i(tab_1, tab_1+5);

    int tab_2 [4][2] = {{10,11},{12,13},{14,15},{16,17}};
    proc_1(*tab_2, sizeof(tab_2)/sizeof(int), 1);
    for(int i=0; i<4; i++)
        wypisz_i(tab_2[i], tab_2[i]+2);
    
    int **arr=calloc(5, sizeof(int *));
    arr[0]=calloc(15, sizeof(int));
    for(int i=1; i<5; i++)
        arr[i]=arr[0]+3*i;
    for(int i=0; i<5; i++)
        for(int j=0; j<3; j++)
            arr[i][j]=i*3+j;
    for(int i=0; i<5; i++)
        wypisz_i(arr[i], arr[i]+3);
    proc_1(*arr, 15, 3);
    printf("\n");
    for(int i=0; i<5; i++)
        wypisz_i(arr[i], arr[i]+3);
    free(arr[0]);
    free(arr);
}