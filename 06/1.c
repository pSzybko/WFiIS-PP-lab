#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char** arr, int size){
    int s=0;
    for(int i=0; i<size; i++)
        s+=strlen(arr[i]);
    s+=1;
    char *string=calloc(s, sizeof(char));
    strcpy(string, arr[0]);
    for(int i=1; i<size; i++)
        strcat(string, arr[i]);
    return string;
}

int main(){
    char *strings[ ] = {"The sun did not shine.","It was too wet to play."," So we sat in the house - ","All that cold, cold, wet day."};
    char *str=concat(strings, sizeof(strings)/sizeof(char*));
    printf("%s\n", str);
    free(str);
}