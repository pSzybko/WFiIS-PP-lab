#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
    return;
}

void swap(int* ptr1, int* ptr2){
    int tmp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=tmp;
}

int suma (int *tab, int len) {
    int ss = 0;
    for (int i = 0; i < len; i++)
    ss+= tab[i];
    return ss;
}

int main(){
    srand(time(NULL));
    int abc[5][4];
    for(int i=0; i<5; i++)
        for(int j=0; j<4; j++)
            abc[i][j]=rand()%20-10;
    for(int i=0; i<5; i++)
        wypisz_i(abc[i], abc[i]+4);
    int suma_abc[5];
    printf("SUMA WIERSZY:\n");
    for(int i=0; i<5; i++)
        suma_abc[i]=suma(abc[i],4);
    wypisz_i(suma_abc, suma_abc+5);
    int suma_all = suma (abc[0],sizeof(abc)/sizeof(int));
    printf("SUMA CALEJ TABLICY:\n%4d\n", suma_all);
    int abc1[5][5];
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++){
            abc1[i][j]=0;
    }
    for(int i=0; i<5; i++)
        for(int j=0; j<4; j++){
            abc1[i][j]=abc[i][j];
    }
    printf("TABLICA ABC1:\n");
    for(int i=0; i<5; i++)
        wypisz_i(abc1[i], abc1[i]+5);
    for(int i=0; i<5; i++)
        for(int j=i+1; j<5; j++){
            swap(abc1[i]+j,abc1[j]+i);
    }
    printf("TRANSPONOWANA:\n");
    for(int i=0; i<5; i++)
        wypisz_i(abc1[i], abc1[i]+5);
    int suma_po_kolumnach=0;
    for(int i=0; i<5; i++)
        suma_po_kolumnach+=suma(abc1[i],5);

    if(suma_po_kolumnach==suma_all)
        printf("SUMY SA JEDNAKOWE I WYNOSZĄ:\n%4d\n\n", suma_po_kolumnach);
    for(int i=0; i<5; i++)
        wypisz_i(abc1[i], abc1[i]+i+1);

    return 0;
}