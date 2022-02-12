#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Klient
{
	char f_name[20];
	char l_name[30];
	char code[7];
	int age;
}Klient;

int K_cmp(const void *a, const void *b){
    const Klient *ka=a;
    const Klient *kb=b;

    return (strcmp(ka->l_name, kb->l_name)==0) ? strcmp(ka->f_name, kb->f_name) : strcmp(ka->l_name, kb->l_name);
}

int main(int argc, char* argv[]){
    Klient arr[6];
    for(int i=0; i<6; i++){
        scanf("%s", arr[i].l_name);
        scanf("%s", arr[i].f_name);
        scanf("%s", arr[i].code);
        scanf("%d", &arr[i].age);
    }
    for(int i=0; i<6; i++)
        printf("%s\t%s\t%s\t%d\n", arr[i].l_name, arr[i].f_name, arr[i].code, arr[i].age);
    
    qsort(arr,6 , sizeof(*arr), K_cmp);
    printf("\n\n");
    for(int i=0; i<6; i++)
        printf("%s\t%s\t%s\t%d\n", arr[i].l_name, arr[i].f_name, arr[i].code, arr[i].age);
}