#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int char_cmp(const void *a, const void *b){
    const char *ca=a;
    const char *cb=b;
    char abs_a=tolower(*ca);
    char abs_b=tolower(*cb);
    if(abs_a==abs_b)
        return (islower(*ca) && islower(*cb)) ? 0 : ((islower(*ca)) ? -1 : 1);
    return (abs_a>abs_b) ? 1 : -1; 
}

int str_cmp(const void *a, const void *b){
    const char *ptr1=a;
    const char *ptr2=b;
    while(*ptr1!='\0'){
        if(char_cmp(ptr1, ptr2)!=0)
            return char_cmp(ptr1, ptr2);
        ptr1++; ptr2++;
    }
    return 0;
}

int main(){
    srand(time(NULL));
    char arr[20][16];
    printf("Wygenerowane łańcuchy:\n");
    for(int i=0; i<20; i++){
        for(int j=0; j<15; j++){
            int tmp=rand()%2;
            if(tmp) arr[i][j]=rand()%26+65;
            else arr[i][j]=rand()%26+97;
        }
        arr[i][15]='\0';
        printf("%s\n", arr[i]);
        qsort(arr[i], 15, sizeof(char), char_cmp);
    }
    printf("\n\nPosortowany każdy łańcuch:\n");
    for(int i=0; i<20; i++)
        printf("%s\n", arr[i]);
    printf("\n\nPosortowana tablica łańcuchów:\n");
    qsort(arr, 20, 16*sizeof(char), str_cmp);
    for(int i=0; i<20; i++)
        printf("%s\n", arr[i]);
}