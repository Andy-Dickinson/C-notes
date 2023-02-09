#include <stdio.h>

int main() {
    // declaring an integer
    int an_int = 5;

    // print value of an_int
    printf("value of variable 'an_int': %d\n", an_int);

    // print address of an_int with reference operator '&'
    printf("address of variable using reference operator '&an_int': %p\n", &an_int);

    // declaring a pointer which currently doesn't point to anything
    int* my_ptr = NULL;

    // print value of what pointer is pointing to
    printf("value of what pointer is pointing to using dereference operator '*my_ptr' (initialised to NULL): %d\n", *my_ptr);

    // print memory address of what pointer is pointing to
    printf("memory address of what pointer is pointing to 'my_ptr'(initialised to NULL): %p\n", my_ptr);

    /* setting pointer to point at an_int variable
    this could have been done in one step above:
    int *my_ptr = &an_int;
    */
    my_ptr = &an_int;

    // print value of what pointer is pointing to using dereference operator '*'
    printf("value of what pointer is pointing to using dereference operator '*my_ptr' (now set to variable): %d\n", *my_ptr);

    // print memory address of what pointer is pointing to
    printf("memory address of what pointer is pointing to 'my_ptr' (now set to variable): %p\n", my_ptr);

    return 0;
}
