#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 5
#define COL 5

int rand_int(int a, int b){
    return rand() % (b-a+1) + a;
}

int sum (const int t[], int len){
int i;
int ss = 0.;
for (i=0; i<len; ss+=t[i++]);
return ss;}
//---------------------------
double avg (const int t[], int len){
double ss = (double)sum(t,len)/len;
return ss;}

int rows_cmp(const void *a, const void *b){
    int *da=(int *)a;
    int *db=(int *)b;
    return avg(da, ROW)-avg(db, ROW);
}

int main(){
    int TAB[ROW][COL];
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            TAB[i][j]=rand_int(-10, 10);

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++)
            printf("%7d", TAB[i][j]);
        printf("\n");
    }
    qsort(TAB, ROW, COL*sizeof(int), rows_cmp);
    printf("\n\nPo sortowaniu:\n");
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++)
            printf("%7d", TAB[i][j]);
        printf("\n");
    }
}