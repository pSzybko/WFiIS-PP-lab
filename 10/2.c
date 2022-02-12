#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fun{
    char *name;
    double (*f)(double [], int);
}fun;

double sum (double t[], int len){
    int i;
    double ss = 0.;
    for (i=0; i<len; ss+=t[i++]);
    return ss;
}

double avg (double t[], int len){
    double ss = sum(t,len)/len;
    return ss;
}

double min (double t[], int len){
    int i;
    int min = 0;
    for (i=0; i<len; i++)
    if (t[i]<t[min]) min=i;
    return t[min];
}

double max (double t[], int len){
    int i;
    int max = 0;
    for (i=0; i<len; i++)
    if (t[i]>t[max]) max=i;
    return t[max];
}

fun *fun_tab(double (*arr[])(double [], int), char **names, int n){
    fun *tab=calloc(n, sizeof(fun));
    for(int i=0; i<n; i++){
        tab[i].name=calloc(strlen(names[i])+1, sizeof(char));
        strcpy(tab[i].name, names[i]);
        tab[i].f=arr[i];
    }
    return tab;
}

void fun_prn(struct fun* tab, int len_tab, double* t, int len_t){
    for(int i=0; i<len_tab; i++){
        printf("%s --> %f\n", tab[i].name, tab[i].f(t, len_t));
    }
        
}


int main(){
    double (*TAB_FUN[])(double [], int) = {sum, avg, min, max};
    char *names[] = {"sum", "avg", "min", "max"};
    double data[][4] = {1.3, 1.2, 0.2, 2.3, 3.4, 1.1, 1.1, 2.1, 0.4, 0.9, 2.3, 1.3, 2.3, 0.6, 1.1};

    fun *wsk_fun = fun_tab(TAB_FUN,names, 4);
    for(int i=0; i<4; i++){
        printf("%d wiersz\n", i);
        fun_prn(wsk_fun, 4, data[i], 4);
    }
}