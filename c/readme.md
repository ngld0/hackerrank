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
