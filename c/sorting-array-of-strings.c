#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b) > 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a, b) <= 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int alphabet_a[26] = {0};
    int alphabet_b[26] = {0};
    // count each char of b and set alphabet_a of this char = 1
    for(int i = 0; i < strlen(a);i++){
        alphabet_a[a[i]-'a'] = 1;
    }
    // count each char of b and set alphabet_b of this char = 1
    for(int i = 0; i < strlen(b);i++){
        alphabet_b[b[i]-'a'] = 1;
    }
    // cout distinct char of alphabet_a and alphabet_b;
    int count_a = 0;
    int count_b = 0;
    for(int i = 0 ; i < 26;i++){
        if(alphabet_a[i]==1) count_a++;
        if(alphabet_b[i]==1) count_b++; 
    }
    // check if the total alphabets of a,b is equals then compare a[] and b[]; return 1 for true, 0 false
    if(count_a ==count_b ) return strcmp(a,b) > 0;
    // else return true if number alphabets of a greater  than number alphabets of b
    else return count_a > count_b;
    
}

int sort_by_length(const char* a, const char* b) {
    // return 1 if len a greater than len b
    if(strlen(a) != strlen(b)) return  strlen(a) > strlen(b); 
    //if the len of a,b are equal.
    else return strcmp(a,b) > 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        int j = i;
        char* p = arr[i];
        while(j > 0){
            if((*cmp_func)(arr[j-1],p) > 0 )
                arr[j] = arr[j-1];
            else
                break;
            j--;
        }
        arr[j] = p;
    }   
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
