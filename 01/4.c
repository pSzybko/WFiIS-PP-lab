#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float suma (float *t, int n, float* min, float* max, float* sr, float* maxo, float* mino);

float suma_arr (float t[], int n, float* min, float* max, float* sr, float* maxo, float* mino);

int main(){
	float arr[]={11.,1.,2.,3.,4.};
	float min=0, max=0, sr=0, maxo=0, mino=0;
	float s=suma(arr,sizeof(arr)/sizeof(float), &min, &max, &sr, &maxo, &mino);
	printf("suma=%f\tmin=%f\tmax=%f\tsr=%f\tmaxo=%f\tmino=%f\t\n", s,min,max,sr,maxo,mino);
	s=suma_arr(arr,sizeof(arr)/sizeof(float), &min, &max, &sr, &maxo, &mino);
	printf("suma=%f\tmin=%f\tmax=%f\tsr=%f\tmaxo=%f\tmino=%f\t\n", s,min,max,sr,maxo,mino);
}

float suma (float *t, int n, float* min, float* max, float* sr, float* maxo, float* mino){
	printf("\nwersja wskaznikowa\n");
	float s=*t;
	*min=*max=*t;
	for(int i=1; i<n; i++){
		s+=*(t+i);
		if(*(t+i)<*min)
			*min=*(t+i);
		if(*(t+i)>*max)
			*max=*(t+i);
	}
	*sr=s/n;
	*maxo=(fabs(*max-*sr)>fabs(*min-*sr) ? fabs(*max-*sr) : fabs(*min-*sr));
	*mino=fabs(*t-*sr);
	for(int i=1; i<n; i++)
		if(fabs(*(t+i)-*sr)<*mino)
			*mino=fabs(*(t+i)-*sr);
	return s;
}

float suma_arr (float t[], int n, float* min, float* max, float* sr, float* maxo, float* mino){
	printf("\nwersja indeksowa\n");
	float s=t[0];
	*min=*max=t[0];
	for(int i=1; i<n; i++){
		s+=t[i];
		if(t[i]<*min)
			*min=t[i];
		if(t[i]>*max)
			*max=t[i];
	}
	*sr=s/n;
	*maxo=(fabs(*max-*sr)>fabs(*min-*sr) ? fabs(*max-*sr) : fabs(*min-*sr));
	*mino=fabs(t[0]-*sr);
	for(int i=1; i<n; i++)
		if(fabs(t[i]-*sr)<*mino)
			*mino=fabs(t[i]-*sr);
	return s;
}