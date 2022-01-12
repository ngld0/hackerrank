#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void tri_swap(triangle *a, triangle *b){
    triangle temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    //buble sort  algo  ref: https://en.wikipedia.org/wiki/Bubble_sort
    for(int i = 0 ; i < n -1 ; i++){
        for (int j = 0; j < n-i-1; j++) {
            float p  = (float) (tr[j].a + tr[j].b + tr[j].c)/2.0;
            float area = (float) sqrt(p *(p-tr[j].a) * (p - tr[j].b ) * (p - tr[j].c ));
            float p2 =  (float) (tr[j+1].a + tr[j+1].b + tr[j+1].c)/2.0;
            float area2 = (float) sqrt(p2 *(p2-tr[j+1].a) * (p2 - tr[j+1].b ) * (p2 - tr[j+1].c ));
            if(area2 < area){ 
                tri_swap((tr + j), (tr+j+1));
            }
        }
     
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
