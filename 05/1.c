#include <stdio.h>
#include <stdlib.h>

#define rows 6
#define columns 6

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
    return;
}

int main(){
    //1
    int** array_1=calloc(rows, sizeof(int*));
    for(int i=0; i<rows; i++)
        array_1[i]=calloc(columns, sizeof(int));
    
    for(int i=0; i<rows; i++)
        wypisz_i(array_1[i], array_1[i]+columns);

    for(int i=0; i<rows; i++)
        free(array_1[i]);
    free(array_1);

    printf("\n\n");
    //2
    int** array_2=calloc(rows, sizeof(int*));
    *array_2=calloc(rows*columns, sizeof(int));
    for(int i=1; i<rows; i++)
        array_2[i]=array_2[i-1]+columns;

    for(int i=0; i<rows; i++)
        wypisz_i(array_2[i], array_2[i]+columns);
    
    free(*array_2);
    free(array_2);
    
    printf("\n\n");
    //3
    int (* array_3)[columns];
    array_3=calloc(columns*rows, sizeof(int));

    for(int i=0; i<rows; i++)
        wypisz_i(*array_3, *array_3+columns);

    free(array_3);
}