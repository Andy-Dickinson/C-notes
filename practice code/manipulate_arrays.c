#include <stdio.h>

#define MAX 5

void display(int* array); // function to display contents of array
void init(int* array); // function to initialise array
void insert(int* array, int pos, int num); // function to insert into a given position (NOT index) and move everything else up one postion (may loose value at end of array if no free slots)
void delete(int* array, int pos); // function to delete an element in array, also moves, arrays in higher positions down
void reverse(int* array); // function to reverse array
void search(int* array, int num); // function to search array for particular value

int main () {

    int array[MAX];

    printf("Initialised array: \n");
    init(array);
    display(array);

    insert(array, 1, 11);  // Note this is position 1....ie index 0
    insert(array, 2, 12);
    insert(array, 3, 13);
    insert(array, 4, 14);
    insert(array, 5, 15);

    printf("Array Contents: \n");
    display(array);

    delete(array, 5);
    delete(array, 2);

    printf("After Deletion: \n");
    display(array);

    insert(array, 2, 222);
    insert(array, 5, 555);

    printf("Array Insertion: \n");
    display(array);

    reverse(array);

    printf("After Reversal: \n");
    display(array);

    printf("\n");
    search(array, 222);
    search(array, 666);

    return 0;
}

// function to display contents of array
void display(int* array) {

    int idx;
    for (idx=0; idx<MAX; idx++){
        printf("%d\t", idx);
    }
    printf("\n");

    for (idx=0; idx<MAX; idx++){
        printf("%d\t", array[idx]);
    }
    printf("\n");
}

// function to initialise array
void init(int* array) {
    int idx;
    for (idx=0; idx<MAX; idx++) {
        array[idx] = 0;
    }
}

/* function to insert into a given position (NOT index) and move everything else up one position
(may loose value at end of array if no free slots) */
void insert(int* array, int pos, int num) {
    int idx;

    for (idx=MAX-1; idx>=pos; idx--) {
        array[idx] = array[idx-1];
    }
    array[idx] = num;
}

/* function to delete an element in array,
also moves arrays in higher positions down*/
void delete(int* array, int pos) {
    int idx;
    for (idx=pos; idx<MAX; idx++) {
        array[idx-1] = array[idx];
    }
    array[idx-1] = 0;
}

// function to reverse array
void reverse(int* array) {
    int idx;
    for(idx=0; idx<MAX/2; idx++) {
        int temp = array[idx];
        array[idx] = array[MAX-1-idx];
        array[MAX-1-idx] = temp;
    }
}

// function to search array for particular value
void search(int* array, int num) {
    int idx;
    for(idx=0; idx<MAX; idx++) {
        if(array[idx] == num) {
            printf("%d found in position %d\n", num, idx+1);
            return;
        }
    }
    if(idx == MAX) {
        printf("%d not found in array\n", num);
    }
}
