#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100000

int main(){
	int arr[N];
	int lp=2;
	for(int i=0; i<N; i++)
		arr[i]=i;
	while(lp<sqrt(N)){
		for(int i=lp+1; i<N; i++)
			if(arr[i]%lp==0)
				arr[i]=-1;
		while(arr[++lp]==-1);
	}
	for(int i=2; i<N; i++)
		if(arr[i]!=-1)
			printf("%d, ", arr[i]);
	printf("\n");
}