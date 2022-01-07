#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
/*
#define INT_MAX 2147483647
#define INT_MIN -2147483648
*/
void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int mx_and = 0;
  int mx_or = 0;
  int mx_xor = 0;
  
  for(int i = 1;i< n;i++){
      for(int j = i+1;j<= n;j++){
        int and, or, xor;
        and = i & j ;
        or = i | j;
        xor = i ^ j;
        if(and < k) mx_and = mx_and > and ? mx_and: and;
        if(or < k) mx_or = mx_or > or ? mx_or: or;
        if(xor < k) mx_xor = mx_xor > xor ? mx_xor: xor;
      }
      
  }
  printf("%d\n%d\n%d\n", mx_and, mx_or, mx_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
