#include <stdio.h>
#include <stdlib.h>


void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n"); return;
}

void swap(int*a, int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
};

void swap_tab(int *a, int *b, int size){
    //procedura wymieniająca zawartość tablic a i b (o tym samym rozmiarze) przy użyciu procedury swap
    // wymieniamy zawartość elementu a[i] z zawartością elementu b[i]
    for(int i=0; i<size; i++)
        swap(a+i, b+i);
    return;
};

void swap_row(int n, int (*a)[n], int x, int y){
    //procedura wymieniająca wiersz x z wierszem y - wiersze mają tę samą długość
    // przy użyciu procedury swap_tab
    swap_tab(*(a+x),*(a+y), n);
    return;
};

int main(){
    int tab_1[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4};
    for(int i=0; i<4; i++)
        wypisz_i(tab_1[i], tab_1[i]+5);
    printf("\n");
    swap_row(5, tab_1, 1, 3);
    for(int i=0; i<4; i++)
        wypisz_i(tab_1[i], tab_1[i]+5);
    printf("\n");
    int tab_11[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4};
    for(int i=0; i<4; i++)
        wypisz_i(tab_11[i], tab_11[i]+5);
    printf("\n");
    swap_tab(*tab_11, *(tab_11+3), 5);
    for(int i=0; i<4; i++)
        wypisz_i(tab_11[i], tab_11[i]+5);
    printf("\n");
    int tab_2 [5][2] = {1,1,2,2,3,3,4,4,5,5};
    for(int i=0; i<5; i++)
        wypisz_i(tab_2[i], tab_2[i]+2);
    printf("\n");
    swap_row(2, tab_2, 0, 2);
    for(int i=0; i<5; i++)
        wypisz_i(tab_2[i], tab_2[i]+2);
    printf("\n");
    int tab_22 [5][2] = {1,1,2,2,3,3,4,4,5,5};
    for(int i=0; i<5; i++)
        wypisz_i(tab_22[i], tab_22[i]+2);
    printf("\n");
    swap_tab(*(tab_22+1), *(tab_22+2), 2);
    for(int i=0; i<5; i++)
        wypisz_i(tab_22[i], tab_22[i]+2);
    printf("\n");
    int **tab_3 = malloc(6*sizeof(int*));
    for(int i = 0; i < 6; i++)
        tab_3[i] = malloc(3 * sizeof(int));
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)
            tab_3[i][j] = rand() % 21;
    for(int i=0; i<6; i++)
        wypisz_i(tab_3[i], tab_3[i]+3);
    printf("\n");
    swap_tab(*(tab_3+1), *(tab_3+5), 3);
    for(int i=0; i<6; i++)
        wypisz_i(tab_3[i], tab_3[i]+3);
    printf("\n");
    for(int i=0; i<6; i++)
        free(tab_3[i]);
    free(tab_3);
    int **tab_33= malloc( 6*sizeof(int*));
    tab_33[0] = malloc(6*3 * sizeof(int));
    for(int i = 1; i < 6; i++)
        tab_33[i] = tab_33[i-1]+3;
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)
            tab_33[i][j] = rand() % 21;
    swap_tab(*(tab_33+2), *(tab_33+4), 3);
    for(int i=0; i<6; i++)
        wypisz_i(tab_33[i], tab_33[i]+3);
    printf("\n");
    free(tab_33[0]);
    free(tab_33);
    return 0;
}