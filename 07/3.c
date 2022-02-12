#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** podziel(char *str, int *n){
    if(!str)
        return NULL;
    char znaki[]=", ;.:";
    char **arr=calloc(1, sizeof(char *));
    char *ptr=strtok(str, znaki);
    int i=1;
    arr[0]=ptr;
    while(ptr){
        arr=realloc(arr,(i+1)*sizeof(char *));
        ptr=strtok(NULL, znaki);
        arr[i++]=ptr;
    }
    *n+=i-1;
    return arr;
}

void sort(char **arr, int n){
    if(!str)
        return NULL;
    char *tmp;
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (strcmp(arr[i],arr[j]) > 0){
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
}

char *sklej(char **arr, int n){
    if(!arr)
        return NULL;
    int size=n;
    for(int i=0; i<n; i++)
        size+=strlen(arr[i]);
    char *tmp=calloc(size, sizeof(char));
    strcpy(tmp, arr[0]);
    strcat(tmp, " ");
    for(int i=1; i<n; i++){
        if(!strstr(tmp, arr[i])){
            strcat(tmp, arr[i]);
            strcat(tmp, " ");}}
    return tmp;
}

int main(int argc, char *argv[]){
    int n=0;
    char **arr=podziel(argv[1], &n);
    printf("%d\n", n);
    for(int i=0; i<n; i++)
        printf("%s\n",arr[i]);
    sort(arr,n);
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%s\n",arr[i]);
    char *ptr=sklej(arr, n);
    printf("%s\n", ptr);
    free(arr);
    free(ptr);
}