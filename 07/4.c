#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add2(int *a, int *b){return *a+*b;}
int comp2(int *a, int *b){return *a-*b;}
int add2_or_comp2 (int a, int b, int (*fun)(int *, int *)){
    return fun(&a,&b);
}

int main(){
    int a, b;
    printf("Podaj dwie liczby:\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\n%d\n",add2_or_comp2(a, b, add2));
    printf("%d\n",add2_or_comp2(a, b, comp2));
}

