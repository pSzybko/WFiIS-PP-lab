#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int str_cmp(const void *a, const void *b){
    return strcmp(*(const char **)a, *(const char **)b);
}   

int double_cmp(const void *a, const void *b){
    return  *(const  double *)a - *( const  double *)b;
}


int main(int argc, char* argv[]){
    if(argc<3)
        return 0;
    char *strings[] = { "Alex", "Bill","Bill","Celine", "Dexter", "Forest","Forest","Garcia","Garcia","Garcia", "Pedro","Zorro"};
    double numbers[] = {1.34, 1.34, 4.34, 5.55, 5.67, 5.67, 5.67, 7.76, 8.1, 8.1, 9.12, 11.23};

    int ls=1, ld=1;

    char **str_ptr=NULL;
    str_ptr=(char **)bsearch(argv+1, strings, sizeof(strings)/sizeof(char *), sizeof(char *), str_cmp);

    while(*str_ptr==*(str_ptr+ls) || *str_ptr==*(str_ptr-ls))
        ls++;

    printf("Slowo %s wystepuje %d razy.\n", argv[1], ls);

    double tmp=atof(argv[2]);
    double *double_ptr=NULL;
    double_ptr=(double *)bsearch(&tmp, numbers, sizeof(numbers)/sizeof(double), sizeof(double), double_cmp);

    while(*double_ptr==*(double_ptr+ld) || *double_ptr==*(double_ptr-ld))
        ld++;

    if(double_ptr)
        printf("Liczba %f wystepuje %d razy.\n", tmp, ld);
}