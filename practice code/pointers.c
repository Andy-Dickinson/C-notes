#include <stdio.h>

int main() {
    // declaring an integer
    int an_int = 5;

    // print value of an_int variable
    printf("value of variable 'an_int;': %d\n", an_int);

    // print address of an_int with reference operator '&'
    printf("address of variable 'an_int' using reference operator '&an_int;': %p\n", &an_int);

    // declaring a pointer which currently doesn't point to anything
    int* my_ptr = NULL;

    // print memory address of what pointer is pointing to
    printf("memory address of what pointer is pointing to 'my_ptr;'(initialised to NULL): %p\n", my_ptr);

    /* setting pointer to point at an_int variable
    this could have been done in one step above:
    int* my_ptr = &an_int;
    */
    my_ptr = &an_int;

    // print value of what pointer is pointing to using dereference operator '*'
    printf("value of what pointer is pointing to using dereference operator '*my_ptr;' (now set to variable): %d\n", *my_ptr);

    // print memory address of what pointer is pointing to
    printf("memory address of what pointer is pointing to 'my_ptr;' (now set to variable): %p\n\n---------\n\n", my_ptr);





    // declaring a char
    char a_char = 'a';

    // declaring another char
    char another_char = 'b';

    // print value of a_char variable
    printf("value of variable 'a_char;': %c\n", a_char);

    // print value of another_char variable
    printf("value of variable 'another_char;': %c\n", another_char);

    // print address of a_char with reference operator '&'
    printf("address of variable 'a_char' using reference operator '&a_char;': %p\n", &a_char);

    // print address of another_char with reference operator '&'
    printf("address of variable 'another_char' using reference operator '&another_char;': %p\n\n", &another_char);

    printf("two pointers declared in one line with: 'char* ptr_a, * ptr_b;'\n");
    printf("could also assign at same time with: 'char* ptr_a = &a_char, * ptr_b = &another_char;'\n\n");

    // declaring multiple pointers
    char* ptr_a, * ptr_b;
    ptr_a = &a_char;
    ptr_b = &another_char;

    // print value of what pointer is pointing to using dereference operator '*'
    printf("value of what pointer 'ptr_a' is pointing to using dereference operator '*ptr_a;': %c\n", *ptr_a);

    // print memory address of what pointer is pointing to
    printf("value of what pointer 'ptr_b' is pointing to using dereference operator '*ptr_b;': %c\n", *ptr_b);

    // print address of what pointer is pointing to
    printf("memory address of what pointer is pointing to 'ptr_a;': %p\n", ptr_a);

    // print address of what pointer is pointing to
    printf("memory address of what pointer is pointing to 'ptr_b;': %p\n", ptr_b);

    return 0;
}
