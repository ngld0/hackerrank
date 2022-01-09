#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    char *num;
    num = malloc(1000 * sizeof(char));
    scanf("%[^\n]", num);
    num = realloc(num, strlen(num) + 1);
    
    int ans[10] = {0};
    
    for(int i = 0 ; i < strlen(num);i++){
        if(isdigit(num[i])){
            ans[num[i] - '0'] += 1;
        }
        
    }
    for(int i = 0 ; i < 10; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}
