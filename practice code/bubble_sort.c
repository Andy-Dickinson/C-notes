#include <stdio.h>
#include <unistd.h>

/* simple but very inefficient way to sort data.
compares each adjacent pair of items & swaps if they
are in wrong order. Each element 'bubbles' through to correct place.

after first iteration, last element will be in place, so can
check one less element on subsequent iterations */

#define SIZE 10

void printArray(int* arr, int, int, int); // prints contents of array

int main(void) {
    int arr[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};
    int idx, target, tmp;

    int milliseconds = 500;
    int useconds = milliseconds*1000;

    printf("Bubble Sort\n");
    printf("Before Sorting: \n");
    printArray(arr, -1, -1, 0);

    // program waits for mu (greek symbol) seconds
    usleep(useconds);

    // The Bubble Sort
    // iterates all but last element
    for(idx=0; idx<SIZE-1; idx++) {
        // iterates all except those that have been 'bubbled' to end of array (and last element)
        for(target=0; target<(SIZE-1)-idx; target++) {
            // compares 2 adjacent elements (starts with 1st and 2nd, then 2nd and 3rd...)
            // if 1st is greater than 2nd, swaps
            if(arr[target]>arr[target+1]) {
                    // outputs bubbled element in yellow, and other comparison element in red
                    // clears screen
                    system("cls");
                    printf("Sorting...\n");
                    printArray(arr, target+1, target, 1);
                    // program waits for mu (greek symbol) seconds
                    usleep(useconds);

                    // temporary variable to store 1st
                    tmp = arr[target];

                    // swaps elements
                    arr[target] = arr[target+1];
                    arr[target+1] = tmp;

                    // outputs bubbled element in yellow, and other comparison element in red
                    // clears screen
                    system("cls");
                    printf("Sorting...\n");
                    printArray(arr, target, target+1, 1);
                    // program waits for mu (greek symbol) seconds
                    usleep(useconds);
            } else {

                // outputs compared elements in red
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printArray(arr, target, target+1, 0);
                // program waits for mu (greek symbol) seconds
                usleep(useconds);
            }
        }
    }

    system("cls");
    printf("After Sorting: \n");
    printArray(arr, -1, -1, 0);

    return(0);
}

// prints contents of array
void printArray(int* arr, int target, int next, int swap){
    // prints contents of array
    for(int idx=0; idx<SIZE; idx++) {
        // if elements compared
        if(idx == target || idx == next){
            // outputs compared elements in colour
            if(swap==1 && idx == next){
                // if element has been bubbled
                // outputs in yellow text
                printf("\033[0;33m%d\t\033[0;37m", arr[idx]);
            }else {
                // outputs in red text
                printf("\33[0;31m%d\t\033[0;37m", arr[idx]);
            }
        } else {
            printf("%d\t", arr[idx]);
        }
    }
    printf("\n");
}
