#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

int* find_max_wsk (int *, int *);

void sort (int *, int);

int main(){
	int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};
	int size=(sizeof(tab_A)/sizeof(int));
	int *max_ptr=find_max_wsk(tab_A, &size);
	printf("%d\n", *max_ptr);
	sort(tab_A, 9);
	sort(tab_A+9, size-9);
	for(int i=0; i<size; i++)
		printf("%d, ",tab_A[i]);
	printf("\n");
}

void swap(int*a, int*b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int* find_max_wsk (int *arr, int *n){
	int *ptr=arr;
	for(int i=1; i<*n; i++)
		if(*(arr+i)>*ptr)
			ptr=(arr+i);
	return ptr;
}

void sort (int *tab, int n){
	for(int i=0; i<n; i++){
		int len=n-i;
		swap(tab+i, find_max_wsk(tab+i, &len));
	}
}