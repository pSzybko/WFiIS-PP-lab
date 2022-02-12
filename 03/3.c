#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec)
        printf ("%6.2f", *poczatek++);
    printf ("\n");
    return;
}

void wypelnij(double arr[][6], int size){
    double tmp=rand()/(double)RAND_MAX;
    for(int i=0; i<size; i++)
        for(int j=0; j<6; j++)
            arr[i][j]=tmp+(i+j)*0.4;
}

int main(){
    srand(time(NULL));
    double A_1[8][6];
    double A_2[10][6];
    wypelnij(A_1, 8);
    wypelnij(A_2, 10);
    for(int i=0; i<8; i++)
        wypisz_d(A_1[i], A_1[i]+6);
    printf("\n\n");
    for(int i=0; i<10; i++)
        wypisz_d(A_2[i], A_2[i]+6);
}