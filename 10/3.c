#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct liczba{
    char type;
    union{
        int i;
        double d;
    };
}liczba;

int rand_int(int a, int b){
    return rand() % (b-a+1) + a;
}

double rand_double(double a, double b){
     return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

void liczba_print(liczba* l, int size){
    for(int i=0; i<size; i++){
        if(l[i].type=='i')
            printf("wartosc: %d\t\ttyp: int\n", l[i].i);
        else printf("wartosc: %f\ttyp: double\n", l[i].d);
    }
}

int liczba_cmp(const void *a, const void *b){
    const liczba *la=(const liczba *) a;
    const liczba *lb=(const liczba *) b;

    if(la->type!=lb->type){
        if(la->type=='i')
            return -1;
        else return 1;
    }
    if(la->type=='i')
        return (la->i<lb->i);
    else
        return (la->d>lb->d);
}

int main(){
    srand(time(NULL));
    liczba *arr=calloc(20, sizeof(liczba));
    for(int i=0; i<20; i++){
        if(rand()%2){
            arr[i].type='i';
            arr[i].i=rand_int(0,10);
        }
        else{
            arr[i].type='d';
            arr[i].d=rand_double(0.,10.);
        }
    }
    liczba_print(arr, 20);
    qsort(arr, 20, sizeof(liczba), liczba_cmp);
    printf("\n\nPo sortowaniu:\n");
    liczba_print(arr, 20);
    free(arr);
}