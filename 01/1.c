#include <stdio.h>
#include <stdlib.h>
#define N 10

int suma(const int* p, const int* tab);

int main(void){
//deklaracja tablicy 10 liczb całkowitych, użyj N
	int tab[N];
//deklaracja wskaźnika p do liczby całkowitej, użyj NULL
	int *p=NULL;
//nie używaj zmiennej int do indeksowania tablicy
//przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran
	for(p=tab; p < N + tab; p++){
		*p=rand()%28+7; // nie korzystaj z tab
		//oblicz wartość indeksu kolejnych elementów tablicy, wypisz wartości kolejnych elementów używając p
		printf("p[%d] = %d\n", p-tab,  *p);
	}
	printf("\n");
	//oblicz rekurencyjnie sumę elementów tablicy.
	int su = suma(p, tab); //nie używaj N
	printf("su=%d\n",su);
	return 0;
}
//funkcja rekurencyjna liczaca sume elementów tablicy
int suma (const int* p, const int* tab){ //nie używaj N
	if (p!=tab)
		return *--p + suma(p, tab);
	else
		return *p;
}