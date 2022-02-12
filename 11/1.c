#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_double(double a, double b){
    return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

void print_text_double(char *name){
    FILE *f=fopen(name, "r");
    if(!f) return;
    double tmp;
    while(fscanf(f, "%lf", &tmp)==1)
        printf("%f\n", tmp);
    fclose(f);
}

void print_bin_double(char *name){
    FILE *f=fopen(name, "rb");
    if(!f) return;
    double tmp;
    while(fread(&tmp, sizeof(double), 1, f)==1)
        printf("%f\n", tmp);
    fclose(f);
}

int main(int argc, char * argv[]){
    srand(time(NULL));
    FILE *f1=fopen(argv[1], "wb");
    FILE *f2=fopen(argv[2], "w");
    if(!(f1 && f2))
        return 0;
    printf("Podaj rozmiar tablicy: ");
    int size;
    scanf("%d", &size);
    double *arr=calloc(size, sizeof(double));
    for(int i=0; i<size; i++)
        arr[i]=rand_double(0., 10.);
    fwrite(arr, sizeof(double), size, f1);
    for(int i=0; i<size; i++)
        fprintf(f2, "%f\n", arr[i]);
    fclose(f1);
    fclose(f2);
    print_text_double(argv[2]);
    printf("\n\n");
    print_bin_double(argv[1]);
    free(arr);
    f1=fopen(argv[1], "rb");
    f2=fopen(argv[2], "r");
    if(!(f1 && f2))
        return 0;
    fseek(f1, 0, SEEK_END);
    fseek(f2, 0, SEEK_END);
    printf("\tplik tekstowy --%ld bajtow\n\tplik binarny --%ld\n", ftell(f1), ftell(f2));
    fclose(f1);
    fclose(f2);
    f1=fopen(argv[1], "rb");
    f2=fopen(argv[2], "r");
    double *arr1=calloc(1, sizeof(double));
    double *arr2=calloc(1, sizeof(double));
    double tmp;
    size_t s=1;
    while(fread(&tmp, 1, sizeof(double), f1)){
        arr1[s-1]=tmp;
        arr1=realloc(arr1, (++s)*sizeof(double));
    }
    for(int i=0; i<s-1; i++)
        printf("%f\n", arr1[i]);
    printf("\n\n");
    free(arr1);
    double tmp2;
    s=1;
    while(fscanf(f2, "%lf", &tmp2)==1){
        arr2[s-1]=tmp2;
        arr2=realloc(arr2, (++s)*sizeof(double));
    }
    for(int i=0; i<s-1; i++)
        printf("%f\n", arr1[i]);
    free(arr2);
    fclose(f1);
    fclose(f2);
    return 0;
}