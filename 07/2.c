#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    char *ptr;
    char arr[50];
    int n=0;
    printf("wynik:\n");
    ptr=fgets(arr, 50, stdin);
    while(ptr){
        char *tmp=NULL;
        if(tmp=strstr(ptr, argv[1])){
            printf("%s", arr);
            n++;
            while(tmp=strstr(tmp+strlen(argv[1]), argv[1]))
                n++;
        }
        ptr=fgets(arr, 50, stdin);
    }
    printf("%d wystapien.\n", n);
}