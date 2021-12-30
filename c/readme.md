Generic Pointers/Void Pointer
========
- "When a variable is declared as being a pointer to type void, it is known as a generic pointer. 
Since you cannot have a variable of type void, the pointer will **not point to any data** and therefore cannot be dereferenced. 
It is still a pointer though, to use it you just have to **cast it to another kind of pointer first**. Hence the term Generic pointer."
- **This is very useful when you want a pointer to point to data of different types at different times.**
```
#include<stdlib.h>
int main()
{
    int x = 4;
    float y = 5.5;
    //A void pointer
    void *ptr;
    ptr = &x;
    // (int*)ptr - does type casting of void 
    // *((int*)ptr) dereferences the typecasted 
    // void pointer variable.
    printf("Integer variable is = %d", *( (int*) ptr) );
 
    // void pointer is now float
    ptr = &y; 
    printf("\nFloat variable is= %f", *( (float*) ptr) );
    return 0;
}
```
Pointer to Pointer
=======
```
Example 1.
int x= 5;
int *p  &x;
*p = 6;
int**q = &p;
int*** r = &q;
print *p, *q, **qm **r, ***r //  6, xxxxx64,6,xxxxx64,6 respectively
***r= 10;
print x // 10
**q = *p +2;
print x // 12

//Example 2.
int num=123;
/*A normal pointer pr2*/
int *pr2;
/*This pointer pr2 is a double pointer*/
int **pr1;
/* Assigning the address of variable num to the pointer pr2 */
pr2 = #
/*Assigning the address of pointer pr2 to the pointer-to-pointer pr1*/
pr1 = &pr2;
Explain:
num == *pr2 == **pr1
&num == pr2 == *pr1
&pr2 == pr1
```
