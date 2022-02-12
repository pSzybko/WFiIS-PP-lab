#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string_array(char**, size_t);//procedura wypisująca tablicę stringów
char* min_string (char**, size_t); //znajdowanie najmniejszego stringu w sensie leksykalnym w tablicy stringów - zwraca wskaźnik do minimalnego

int main()
{
    char* strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    char* wsk_string;
    size_t strings_len = sizeof(strings)/sizeof(char *); //okreslenie długości tablicy strings
    print_string_array(strings, strings_len); //wypisanie tablicy stringów

    wsk_string = min_string(strings,strings_len);//znalezienie najmniejszego stringu w tablicy
    printf("%s\n", wsk_string); //wypisanie najmniejszego stringu
    return 0;
}

void print_string_array(char** arr, size_t len){
    for(int i=0; i<(int)len; i++)
        printf("%s\t", arr[i]);
    printf("\n");
}
char* min_string (char** arr, size_t len){
    char* min=arr[0];
    for(int i=1; i<(int)len; i++)
        if(strcmp(min, arr[i])>0)
            min=arr[i];
    return min;
}