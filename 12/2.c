#include <stdio.h>
#include <stdlib.h>

#define MAK_1(x) printf("%s = %d\n",#x, x)
#define MAK_2(x) (x%2) ? 0 : (x>0) ? 1 : -1

int main(){
    int x=5, y=9;
    MAK_1(7*x+2-y/6);
    int z=-2;
    printf("%d\n", MAK_2(z));
    return 0;
}