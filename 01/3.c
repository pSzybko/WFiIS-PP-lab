#include <stdio.h>
#include <stdlib.h>

void zamiana(int* a,int* b);

void odwroc(int* arr, int n);

void wymien_tablice(int* arr1, int* arr2, int n);

int main(){
	int a=0;
	int b=121;
	printf("a=%d\tb=%d\n", a, b);
	zamiana(&a, &b);
	printf("a=%d\tb=%d\n", a, b);

	int arr[]={0,1,2,3,4,5,6,7,8,9};

	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		printf("%d, ", arr[i]);
	printf("\n");
	odwroc(arr, sizeof(arr)/sizeof(int)-1);
	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		printf("%d, ", arr[i]);
	printf("\n");

	int arr2[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	wymien_tablice(arr,arr2,sizeof(arr)/sizeof(int));

	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		printf("%d, ", arr[i]);
	printf("\n");

	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		printf("%d, ", arr2[i]);
	printf("\n");	
}

void zamiana(int* a,int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void odwroc(int* arr, int n){
	for(int i=0; i<n/2; i++)
		zamiana(arr+i, arr+n-i);
}

void wymien_tablice(int* arr1, int* arr2, int n){
	for(int i=0; i<n; i++)
		zamiana(arr1+i, arr2+i);
}