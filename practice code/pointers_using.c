#include <stdio.h>

int main(void) {

    // ---------------set variables----------------------
    int a = 5;
    int z = 7;
    int y = 2;

    // ---------------set pointers-----------------------
    int* b = &a;

    int** c = &b;

    // ---------------access values----------------------
    printf("access values--------------------------------\n");

    printf("value of a = %d\n", a);
    printf("value of b (address as pointer to a) = %p\n", b);
    printf("value of c (address as pointer to b) = %p\n", c);
    printf("value of a via b pointer = %d\n", *b);
    printf("value of a via c pointer = %d\n", **c);

    printf("\n");

    // ---------------access addresses-------------------
    printf("access addresses-----------------------------\n");

    printf("address of a = %p\n", &a);
    printf("address of b = %p\n", &b);
    printf("address of c = %p\n", &c);

    printf("\n");

    // --------------copy pointer------------------------

    int* f = b;

    printf("f = %d\n", *f);


    // --------------change pointers---------------------
    printf("change pointers------------------------------\n");

    // passes pointer to function
    // WON'T change what b is pointing at
    change_pointer_copy(b, z);
    printf("value of b after passing pointer to function not changed (still pointing at a) = %d\n", *b);

    printf("\n");

    // passes address of pointer
    // WILL change what b is pointing at
    change_pointer(&b, &z);
    printf("value of b (z=7) after passing address of pointer and address of variable to point at to function = %d\n", *b);

    printf("\n");

    // change what pointer is pointing to using another pointer
    int* d = &y;
    printf("value of pointer d (pointing at y=2) = %d\n", *d);
    change_pointer_to_another(&b, d);
    printf("value of b after passing address along with copy of 2nd pointer to function = %d\n", *b);

    printf("\n");

    // --------------change values via pointers-----------
    printf("change values via pointers--------------------\n");

    // changes value of what b is pointing to (a) via dereference operator
    *b = 6;
    printf("value of what b is pointing to (y) after changing via dereference = %d\n", *b);
    printf("value of y after changing via dereference = %d\n", y);

//    printf("\n"); //////////////////// causes program to hang, no idea why

    // change value of what b is pointing to via function
    change_value_via_pointer(b);
    printf("value of what b is pointing to (y) after changing via function = %d\n", *b);
    printf("value of y after changed via pointer in function = %d\n", y);

    return(0);
}

// change what pointer is pointing to with another pointer
void change_pointer_to_another(int** pt1, int* pt2) {
    *pt1 = pt2;
}

// changes value of what pointing at
void change_value_via_pointer(int* pt) {
    *pt = 1;
}

// DOESNT change what pointer is pointing to outside of function, as pt is a copy of the pointer passed
void change_pointer_copy(int* pt, int* z) {
    printf("value of pt before change in function = %d\n", *pt);
    pt = &z;
    printf("value of what pt is pointing to within function (z=7) = %d\n", *pt);
}

// same as change pointer to another, however passing a variable holding a value
void change_pointer(int** pt, int* z) {
    *pt = z;
    printf("value of what pointer is pointing to via 2 pointers within function = %d\n", **pt);
}
