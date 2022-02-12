#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct wektor{
    double x;
    double y;
    double z;
}wektor;

typedef struct abc{
    wektor vect;
    double len;
}abc;

double rand_double(double a, double b){
 	return (a+(rand()/(1.0*RAND_MAX))*(b-a));
}

double wekt_len (wektor w){
    return pow(pow(w.x, 2)+pow(w.y, 2)+pow(w.z, 2), 0.5);
}

void f_d (struct abc *arr, int n){
    for(int i=0; i<n; i++)
        arr[i].len=wekt_len(arr[i].vect);
}

int abc_cmp(const void *a, const void *b){
    const abc *aa=a;
    const abc *ab=b;
    return (aa->len==ab->len) ? 0 : ((aa->len>ab->len) ? 1 : -1);
}

int main(int argc, char* argv[]){
    srand(time(NULL));

    abc *arr=calloc(atoi(argv[1]), sizeof(abc));
    for(int i=0; i<atoi(argv[1]); i++){
        arr[i].vect.x=rand_double(0.,50.);
        arr[i].vect.y=rand_double(0.,50.);
        arr[i].vect.z=rand_double(0.,50.);
    }
    f_d(arr, atoi(argv[1]));
    for(int i=0; i<atoi(argv[1]); i++)
        printf("%d\t%f\t%f\t%f\t%f\n", i, arr[i].vect.x, arr[i].vect.y, arr[i].vect.z, arr[i].len);

    qsort(arr, atoi(argv[1]), sizeof(*arr), abc_cmp);
    printf("\n\n");

    for(int i=0; i<atoi(argv[1]); i++)
        printf("%d\t%f\t%f\t%f\t%f\n", i, arr[i].vect.x, arr[i].vect.y, arr[i].vect.z, arr[i].len);
    
    free(arr);
}