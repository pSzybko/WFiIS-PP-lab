#include <stdio.h>
#include <math.h>

#define S sizeof(int)*8+1

// p - pozycja , n - to liczba bitów
unsigned bity(int x, int p, int n){
	return ((int)pow(2,n)-1 & (x>>p));
}
void do_binar (int n, char *wsk){
	for(int i=0; i<S; i++)
		wsk[i]=1;
	wsk[S-1]='\0';
	for(int i=S-2; i>-1; i--, n>>=1)
		wsk[i]=(01 & n)+'0';
	int i=0;
	while(wsk[i]=='0') i++;
	if(S-i<3)
		for(int j=0; j<2-S+i; j++)
			printf ("0");
	for(i; i<S; i++)
		printf("%c", wsk[i]);
	printf ("\n");
}
int main (){
	unsigned wynik, liczba = 18; // 10010
	char str1[S], str2[S];
	do_binar(liczba, str1);//wypisanie zmiennej liczba z użyciem do_binar
	wynik = bity(liczba, 1, 3); // 3 bity od pozycji 1, czyli: 1 001 0
	do_binar(wynik, str2);//wypisanie zmiennej wynik z użyciem do_binar
	return 0;
}