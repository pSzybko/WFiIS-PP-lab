#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double fun0(double x) { return log(x); }
double fun1(double x) { return x*x; }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

double (**find_max(double (**arr)(double), double n))(double){
    int tmp=0;
    int i=1;
    while(arr[i])
        if(arr[i++]>arr[tmp])
            tmp=i-1;
    return arr+tmp;
}

int main(){
    char * nazwy[]={"log", "pow","sin","cos"};
    double (*TAB_FUN[5])(double);
    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;

    double (**wsk_fun)(double);
    wsk_fun=TAB_FUN;

    double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };

    char **str = nazwy;
    while(*wsk_fun) { //pętla po wskaźnikach do funkcji
        for (int i = 0; i < 8; i++) //pętla po argumentach
            printf("%s(%f)=%.4f\t", *str, data[i], (*wsk_fun)(data[i]));
        printf ("\n");
        wsk_fun++;
        str++;
    }
    double (**wsk_max)(double)=find_max (TAB_FUN, 0.05);
	printf ("dla x= %f najwieksza wartosc ma %s, ktora wynosi %.3f\n", 0.05, nazwy[wsk_max - TAB_FUN], (*wsk_max)(0.05));
	return 0;
}