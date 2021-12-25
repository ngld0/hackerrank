#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int i = *a, j = *b;
    *a = i + j;
    *b = (i - j)< 0 ? (j-i):(i - j) ;  
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
