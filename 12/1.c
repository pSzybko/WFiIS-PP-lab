#include <stdio.h>
#include <stdlib.h>


typedef struct Klient{
    char f_name[20];
    char l_name[20];
    char code[7];
    int age;
}Klient;

Klient* fun(int *size, const char *name){
    FILE *f=fopen(name, "r");
    if(!f) return NULL;
    Klient *arr=calloc(2, sizeof(Klient));
    *size=1;
    while(fscanf(f, "%s", arr[*size-1].l_name)==1){
        arr=realloc(arr, (*size+1)*sizeof(Klient));
        fscanf(f, "%s", arr[*size-1].f_name);
        fscanf(f, "%s", arr[*size-1].code);
        fscanf(f, "%d", &arr[*size-1].age);
        (*size)++;
    }
    arr=realloc(arr, --(*size)*sizeof(Klient));
    fclose(f);
    return arr;
}

int main(){
    FILE* f=fopen("dane.dat", "wb");
    int n=0;
    Klient *ptr=fun(&n, "spis.txt");
    for(int i=0; i<n; i++)
        printf("%s\t%s\t%s\t%d\n", ptr[i].l_name, ptr[i].f_name, ptr[i].code, ptr[i].age);
    fwrite(ptr, sizeof(Klient), n, f);
    fclose(f);
    free(ptr);
    f=fopen("dane.dat", "rb");
    Klient *tmp=calloc(1, sizeof(Klient));
    printf("\n\n");
    for(int i=0; i<n; i++){
        fread(tmp, sizeof(Klient), 1, f);
        if(tmp->age>17)
            printf("%s\t%s\t%s\t%d\n", tmp->l_name, tmp->f_name, tmp->code, tmp->age);
    }
    free(tmp);
    fclose(f);
    return 0;
}