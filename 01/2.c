#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* zamien(char* , int );

int main(){
	char tab[]="Tu JeSt JaKiS TeKst";

	for(int i=0; i<strlen(tab); i++)
		printf("%c", tab[i]);
	printf("\n");
	char* ukl=zamien(tab, strlen(tab));
	
	for(int i=0; i<strlen(tab); i++)
		printf("%c", ukl[i]);

	printf("\n");
	free(ukl);
}

char* zamien(char* arr, int n){
	char *tab=calloc(n, sizeof(char));
	int j=0;
	for(int i=0; i<n; i++){
		if(isupper(arr[i])){
			tab[j++]=arr[i];
		}
	}
	for(int i=0; i<n; i++){
		if(!isupper(arr[i]))
			tab[j++]=arr[i];
	}
	return tab;
}