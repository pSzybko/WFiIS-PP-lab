#include <stdio.h>
#include <stdlib.h>


int main(){
    float arg_1[] = {1.0, 1.2, 1.2, 1.5, 1.5, 1.5, 1.6, 1.6, 1.8, 1.9};
    float arg_2[] = {1.0, 1.1, 1.1, 1.2, 1.4, 1.5, 1.6, 1.6, 1.8, 1.8, 1.8, 1.9, 1.9, 2.0, 2.0};
    float* wynik=calloc(1,sizeof(float));
    int s1=(int)(sizeof(arg_1)/sizeof(float));
    int s2=(int)(sizeof(arg_2)/sizeof(float));
    int i=0, j=0, r=0;
    while(i<s1 && j<s2){
        int tmp=1;
        if(arg_1[i]<arg_2[j]){
            for(int k=0; k<r; k++)
                if(wynik[k]==arg_1[i])
                    tmp=0;
            if(tmp){
                wynik=realloc(wynik, ++r*sizeof(float));
                wynik[r-1]=arg_1[i];
            }
            i++;
        }
        else{
            for(int k=0; k<r; k++)
                if(wynik[k]==arg_2[j])
                    tmp=0;
            if(tmp){
                wynik=realloc(wynik, ++r*sizeof(float));
                wynik[r-1]=arg_2[j];
            }
            j++;
        }
    }
    while(i<s1){
        int tmp=1;
        for(int k=0; k<r; k++)
        if(wynik[k]==arg_1[i])
            tmp=0;
        if(tmp){
            wynik=realloc(wynik, ++r*sizeof(float));
            wynik[r-1]=arg_1[i];
        }
        i++;
    }
    while(j<s2){
        int tmp=1;
        for(int k=0; k<r; k++)
            if(wynik[k]==arg_2[j])
                tmp=0;
        if(tmp){
            wynik=realloc(wynik, ++r*sizeof(float));
            wynik[r-1]=arg_2[j];
        }
        j++;
    }
    for(int i=0; i<r; i++)
        printf("%.1f, ", wynik[i]);
    printf("\n");
    free(wynik);
}