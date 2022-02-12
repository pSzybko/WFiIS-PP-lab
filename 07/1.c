#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZMIAR 81 //maksymalna dlugość łańcuchów
#define GRAN 20 // maksymalna liczba łańcuchów

void sortlan(char *lan[], int num); //procedura sortująca łancuchy

int main(void)
{
    char dane[GRAN][ROZMIAR]; //tablica przechowujaca łańcuchy nie dłuzsze niz ROZMIAR znakow nie wiecej niz GRAN
    char **wsklan = calloc(ROZMIAR*GRAN,sizeof(char *)); //wskaźnik na tablicę wskaźników - rozmiar zależny od ilości wczytanych łańcuchów
    int licz = 0; //licznik danych wejsciowych
    int k; 
    printf("Podaj maksymalnie %d wierszy \n",GRAN);
    printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
    while (licz < GRAN && gets(dane[licz]) != NULL && dane[licz][0] != '\0')
    {
        wsklan[licz] = dane[licz]; //ustaw wskaźnik z tablicy wsklan na wczytany łańcuch
        licz++;
    }
    puts("\n Wczytano:\n");
    for (k = 0; k < licz; k++)
        puts(wsklan[k]) ; // z użyciem identyfikataora wsklan
    sortlan(wsklan, licz); // wywłoanie procedury sortującej
    puts("\n Oto uporzadkowana lista:\n");
    for (k = 0; k < licz; k++) puts(dane[k]) ; // z użyciem identyfikatora dane
    puts("\n Oto uporzadkowana lista:\n");
    for (k = 0; k < licz; k++) puts(wsklan[k]) ; // z użyciem identyfikatora wsklan
    free(wsklan);
    return 0; 
}
// procedura sortująca
void sortlan(char *lan[], int num) {
    char tmp[ROZMIAR];//potrzebne zmienne lokalne
    for (int i=0; i<num-1; i++)
        for (int j=i+1; j<num; j++)
            if (strcmp(lan[i],lan[j]) > 0){ 
                strcpy(tmp, lan[i]);
                strcpy(lan[i], lan[j]);
                strcpy(lan[j], tmp);
            }
}