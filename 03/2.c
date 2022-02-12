#include <stdio.h>
#include <stdlib.h>

void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec)
        printf ("%6.2f", *poczatek++);
    printf ("\n");
    return;
}

double suma(double* tab[], int index, int len){
    double wynik=0.;
    for(int i=0; i<len; i++)
        wynik+=tab[index][i];
    return wynik;
}

double* find_tab(double* tab[], int len){
    int index=0;
    for(int i=1; i<len; i++)
        if(suma(tab, i, len)<suma(tab, index, len))
            index=i;
    return tab[index];
}

void swap_new(double* arr1[], double* arr2[]){
    double* tmp=*arr1;
    *arr1=*arr2;
    *arr2=tmp;
}

double** find_tab_1(double* tab[], int len, int ind){
    int index=ind;
    for(int i=ind; i<len; i++)
        if(suma(tab, i, len)<suma(tab, index, len))
            index=i;
    return tab+index;
}

int main(){
    double T_1[4] = {1.0,3.0, 2.0,1.5};
    double T_2[4] = {1.8, 2.0, 1.2, 3.8};
    double T_3[4] = {5.6, 1.0, 3.3, 3.3};
    double T_4[4] = {1.1, 2.1, -6.5, 1.7};
    double T_5[4] = {6.7, 7.8, 9.1, 1.0};
    double* TAB[5]={T_1, T_2, T_3, T_4, T_5};
    int i,j;
    for (i = 0; i<sizeof(TAB)/sizeof(double*); i++){
        for (j = 0; j<4; j++)
            printf(" %.2f", TAB[i][j]);
        printf ("\n");
    }
    double **TABLICA=TAB;
    for(int i=0; i<5; i++)
        wypisz_d(TABLICA[i], TABLICA[i]+4);

    printf("%f\n", suma(TAB, 0, 4));
    printf("%f\n", suma(TAB, 1, 4));
    printf("%f\n", suma(TAB, 2, 4));
    printf("%f\n", suma(TAB, 3, 4));
    printf("%f\n", suma(TAB, 4, 4));

    double* min_ptr=find_tab(TAB, 4);
    wypisz_d(min_ptr, min_ptr+4);

    for(int i=0; i<5; i++){
        swap_new(find_tab_1(TAB, 5, i), TAB+i);
    }
    printf("%f\n", suma(TAB, 0, 4));
    printf("%f\n", suma(TAB, 1, 4));
    printf("%f\n", suma(TAB, 2, 4));
    printf("%f\n", suma(TAB, 3, 4));
    printf("%f\n", suma(TAB, 4, 4));

}