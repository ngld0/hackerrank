# Pointer
## Generic Pointers/Void Pointer
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
## Pointer to Pointer

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
## pointer to function
```
void add(int a){ // address of a (&a) xxxx; if we call by *a or a[] is is same -> the  value of a in main function will be changed.
    a += 1;
}
int main(){
    int a =10; //local variable and &a is yyyy difference with address in function add
    add(a);
    printf("a=%d",a); // 10
}
application's memory
- Heap 
- Stack
- Static/Global 
- Code (Text)

// Array no call by value, array call by reference -> call function add by array the array will change value if add.
```

## Dynamic Memory Allocation
``` 
- malloc()  stands for memory allocation.
    - ptr = (castType*) malloc(size); 
- calloc()  stands for contiguous allocation.
    - ptr = (castType*)calloc(n, size);
- free()use to release the space.
    - free(ptr);
- realloc() If the dynamically allocated memory is insufficient or more than required, you can change the size of previously allocated memory by using realloc
    - ptr = realloc(ptr, x);
``` 
# Struct, Union
## Struct
```
struct Person {
  char name[50];
  int citNo;
  float salary;
};
int main() {
  struct Person person1, person2, p[20];
  return 0;
}
// We use the typedef keyword to create an alias name for data types. It is commonly used with structures to simplify the syntax of declaring variables.
typedef struct Distance {
  int feet;
  float inch;
} distances;

int main() {
  distances d1, d2;
}
```
## macro
```
#define c 299792458
#define circleArea(r) (3.1415*(r)*(r))
#if expression
    // conditional codes if expression is non-zero
#elif expression1
    // conditional codes if expression is non-zero
#elif expression2
    // conditional codes if expression is non-zero
#else
    // conditional if all expressions are 0
#endif
```
## union
```
A union is a user-defined type similar to structs in C except for one key difference. 
Structures allocate enough space to store all their members, whereas unions can only hold one member value at a time.
// 1
union car
{
  char name[50];
  int price;
};

int main()
{
  union car car1, car2, *car3;
  return 0;
}
// 2
union car
{
  char name[50];
  int price;
} car1, car2, *car3;

```
