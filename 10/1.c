#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void va_cat(char **result,int num, ...){
    va_list ptr;
    va_start(ptr, num);
    char *tmp=va_arg(ptr, char *);
    int len=strlen(tmp)+1;
    *result=calloc(len, sizeof(char));
    strcpy(*result, tmp);
    for(int i=0; i<num-1; i++){
        char *tmp=va_arg(ptr, char *);
        len+=strlen(tmp);
        *result=realloc(*result, len*sizeof(char));
        strcat(*result, tmp);
    }
    va_end(ptr);
}

int main(){
    char *ptr;
    va_cat (&ptr ,3, "If you never did You should.","These things are fun.", "and Fun is good.");
    printf("%s\n", ptr);
    free(ptr);
    va_cat (&ptr ,4, "Sometimes ","you will never know ","the value of a moment ","until it becomes a memory.");
    printf("%s\n", ptr);
    free(ptr);
}