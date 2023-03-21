#include <stdio.h>
#include <unistd.h>

/* possibly simplest sorting method. Starting with first
element (current), compare to every other in array. Each
time current is greater than target, swap those elements.
After one iteration, smallest item will be in first position.
Repeat */

#define SIZE 10

void printArray(int* arr, int, int, int); // prints contents of array

int main(void) {
    int arr[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};
    int idx, target, tmp;

    int milliseconds = 500;
    int useconds = milliseconds*1000;

    printf("Selection Sort\n");
    printf("Before Sorting: \n");
    printArray(arr, -1, -1, 0);

    // program waits for mu (greek symbol) seconds
    usleep(useconds);

    // The Selection Sort
    // iterates all but last element
    for(idx=0; idx<SIZE-1; idx++) {
        // starts at beginning plus one, but finished at end
        for(target=idx+1; target<SIZE; target++) {
            // compares 2 elements (the current and the target)
            // if current is greater than target, swaps
            if(arr[idx]>arr[target]) {
                // outputs swap element in yellow, and other comparison element in red
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printArray(arr, idx, target, 1);
                // program waits for mu (greek symbol) seconds
                usleep(useconds);

                // temporary variable to store current
                tmp = arr[idx];

                // swaps elements
                arr[idx] = arr[target];
                arr[target] = tmp;

                // outputs swap element in yellow, and other comparison element in red
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printArray(arr, target, idx, 1);
                // program waits for mu (greek symbol) seconds
                usleep(useconds);
            } else {
                // outputs compared elements in red
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printArray(arr, idx, target, 0);
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
void printArray(int* arr, int red, int red_yellow, int swap){
    // prints contents of array
    for(int idx=0; idx<SIZE; idx++) {
        // if elements compared
        if(idx == red || idx == red_yellow){
            // outputs compared elements in colour
            if(swap==1 && idx == red_yellow){
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
