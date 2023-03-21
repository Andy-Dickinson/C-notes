#include <stdio.h>

typedef struct
{
    int id ;
    char name [30];
} employee ;


int main() {

    // declare variables of different types
    int integer_variable;
    float float_variable;
    double double_variable;
    char char_variable;
    char string_variable[10];
    int integer_array[100];
    int num_elements;


    // declare unsigned integer
    size_t size;

    // get size of integer_variable
    size = sizeof(integer_variable);

    // print size of integer_variable
    printf("Size of Integer variable is %zu bytes\n", size);

    // get size of float variable and print
    size = sizeof(float_variable);
    printf("Size of Float variable is %zu bytes\n", size);

    // get size of double variable and print
    size = sizeof(double_variable);
    printf("Size of Double variable is %zu bytes\n", size);

    // get size of char variable and print
    size = sizeof(char_variable);
    printf("Size of Char variable is %zu bytes\n", size);

    // get size of string variable and print
    size = sizeof(string_variable);
    num_elements = size / sizeof(char);
    printf("Size of String variable for %zu elements is %zu bytes\n", num_elements, size);

    // get size of integer array and print
    size = sizeof(integer_array);
    num_elements = size / sizeof(int);
    printf ("Size of Integer array for %zu elements is %zu bytes\n\n", num_elements, size);

    // Creating an object from defined struct and printing sizes
    employee e1 = {1 , "Andy"};
    printf ("ID: %d\nName: %s\n", e1.id , e1.name);
    printf ("Size of member ID is %zu\nSize of member Name is %zu\nSize of Struct is %zu\n", sizeof(e1.id), sizeof(e1.name), sizeof(e1));
    printf("Note the size of the members adds to less than that of the struct,\nthis is because the compiler adds some padding to the members in order to align them\n");

    return 0;
}
