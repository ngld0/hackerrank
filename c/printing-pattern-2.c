#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for (int i = 0; i < 2*n - 1; i++) {
        int cnt = 0;
        int mn;
        if (i < n)
            mn = n - i;
        else
            mn = 2 + i%n;
        for (int j = 0; j < 2*n - 1; j++) {
            if (j < n-1) {
                printf("%d ", mn > (n - cnt) ?mn :(n - cnt)  );
                cnt++;
            }
            else {
                printf("%d ", mn > (n - cnt) ?mn: (n - cnt) );
                cnt--;
            }
        }
        printf("\n");
    }
    return 0;
}
