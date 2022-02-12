#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_f(float min, float max){
    float r = (float) rand()/RAND_MAX;
    return r*(max - min) + min;
}

void print_arr(float **arr, int rows, int col){
    for(int i=0; i<rows; i++){
        for(int j=0; j<col; j++)
            printf("%f\t", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void free_arr(float **arr, int rows){
    if(!arr) return;
    for(int i=0; i<rows; i++)
        free(arr[i]);
    free(arr);
    arr=NULL;
}

float **matrix(int rows, int col, FILE *fp);

int main(){
    float tab[30];
    int i, x, y;
    srand(time(0));
    FILE *f_1 = fopen ("dane_1.dat","wb");
    int var;
    printf ("rozmiar = ");
    scanf ("%d", &var);
    for (i=0; i<var; i++)
        tab[i]=rand_f(0.0, 40.0);
    //zapisywanie do pliku binarnego dane_1.dat zawartosci tablicy tab
    fwrite (tab,sizeof(float),var, f_1);
    fclose(f_1);
    f_1=fopen("dane_1.dat", "rb");
    float **arr=matrix(4, 5, f_1);
    print_arr(arr, 4, 5);  
    float **arr2=matrix(5, 4, f_1);
    print_arr(arr2, 5, 4);
    float **arr3=matrix(5, 5, f_1);
    print_arr(arr3, 5, 5);
    free_arr(arr, 4);
    free_arr(arr2, 5);
    free_arr(arr3, 5);
    fclose(f_1);
    return 0;
}

float **matrix(int rows, int col, FILE *fp){
    if(col<1 || rows<1) return NULL;
    rewind(fp);
    float **arr=calloc(rows, sizeof(float *));
    for(int i=0; i<rows; i++){
        arr[i]=calloc(col, sizeof(float));
        for(int j=0; j<col; j++){
            float tmp;
            if(fread(&tmp, sizeof(float), 1, fp)!=0)
                arr[i][j]=tmp;
            else break;
        }
    }
    return arr;
}