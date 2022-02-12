#include <stdio.h>
#include <stdlib.h>

void print_tab(int a[][4], int x){
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < 4; j++)
            printf ("%3d", a[i][j]);
    printf ("\n");
    }
    return;
}

void wypisz_i (int *poczatek, int *koniec){
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
    return;
}

int (*mn_tab_1(int a[][3], int b[][4], int s))[4]{
    int (*arr)[4]=calloc(4*s, sizeof(int *));
    
    for(int i=0; i<s; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<3; k++)
                arr[i][j]+=a[i][k]*b[k][j];
    return arr;
}

int main(){
    int t_A [2][3] = {{1,2,3},{4,5,6}};
    int t_B [3][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    int (*t_C)[4] = mn_tab_1 (t_A, t_B, 2);
    print_tab(t_C, 2);   
    for(int i=0; i<2; i++)
        wypisz_i(t_C[i], t_C[i]+4); 
    free(t_C);
}