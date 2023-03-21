#include <stdio.h>
#include <unistd.h>

/* simple sorting algorithm, relatively efficient
when dealing with small amounts of data, or data
that is mostly sorted, but otherwise is beaten by
other algorithms. Compares target element with those
before it. If earlier is greater, then shift elements
to make space */

#define SIZE 10

void printArray(int* arr, int, int, int); // prints contents of array

int main(void) {
    int arr[SIZE] = {26, 34543, 17, 31, 13, 543,  456, 1, 0, 2};
    int idx, cmp, shift, tmp;

    int milliseconds = 600;
    int useconds = milliseconds*1000;

    printf("Insertion Sort\n");
    printf("Before Sorting: \n");
    printArray(arr, -1, -1, 0);

    // program waits for mu (greek symbol) seconds
    usleep(useconds);

    // The Insertion Sort
    // iterates all in array except 1st
    for(cmp=1; cmp<SIZE; cmp++) {
        // iterates all in array which are to the left of cmp
        for(idx=0; idx<cmp; idx++) {
            // if element at idx is greater than cmp, swap
            if(arr[idx]>arr[cmp]) {
                // outputs cmp element in yellow, and greater in blue
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printArray(arr, idx, cmp, 2);
                // program waits for mu (greek symbol) seconds
                usleep(useconds);

                // temp variable to store greater element
                tmp = arr[idx];
                // inserts compared element
                arr[idx] = arr[cmp];

                // outputs cmp element in new position in yellow, and old position in red
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printArray(arr, cmp, idx, 1);
                // program waits for mu (greek symbol) seconds
                usleep(useconds);

                // shifts remaining sorted elements up 1
                for(shift = cmp; shift>idx+1; shift--) {

                    // outputs cmp element in new position (idx) in yellow, elements to be shifted in red, and shifting element in green
                    // clears screen
                    system("cls");
                    printf("Sorting...\n");
                    printShift(arr, idx, cmp, shift-1, 0);
                    // program waits for mu (greek symbol) seconds
                    usleep(useconds);

                    arr[shift] = arr[shift-1];

                    // outputs cmp element in new position (idx) in yellow, elements to be shifted in red, and shifting element in green
                    // clears screen
                    system("cls");
                    printf("Sorting...\n");
                    printShift(arr, idx, cmp, shift, 0);
                    // program waits for mu (greek symbol) seconds
                    usleep(useconds);
                }
                // inserts greater element back into array
                arr[shift] = tmp;

                // outputs cmp element in new position (idx) in yellow, elements to be shifted in red, and shifting element in green
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printShift(arr, idx, cmp, shift+1, 1);
                // program waits for mu (greek symbol) seconds
                usleep(useconds);
            } else {
                // outputs compared elements in red
                // clears screen
                system("cls");
                printf("Sorting...\n");
                printArray(arr, idx, cmp, 0);
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

void printShift(int* arr, int yellow, int max_red, int green_blue, int last) {
    for(int idx=0; idx<SIZE; idx++) {
        // if elements compared
        if(idx>=yellow && idx<=max_red) {
            if(idx==yellow) {
                if(yellow==green_blue){
                    // green
                    printf("\033[0;32m%d\t\033[0;37m", arr[idx]);
                } else {
                    // yellow
                    printf("\033[0;33m%d\t\033[0;37m", arr[idx]);
                }
            }else if(idx==green_blue){
                // outputs in green text
                printf("\033[0;32m%d\t\033[0;37m", arr[idx]);
            }else if(idx==yellow+1){
                if(last==0){
                    // outputs in purple text
                    printf("\33[0;35m%d\t\033[0;37m", arr[idx]);
                } else {
                    // outputs in blue text
                    printf("\033[0;34m%d\t\033[0;37m", arr[idx]);
                }
            } else {
                // outputs in purple text
                printf("\33[0;35m%d\t\033[0;37m", arr[idx]);
            }
        } else {
            printf("%d\t", arr[idx]);
        }
    }
    printf("\n");
}

// prints contents of array
void printArray(int* arr, int red_blue, int red_yellow, int swap){
    // prints contents of array
    for(int idx=0; idx<SIZE; idx++) {
        // if elements compared
        if(idx == red_blue || idx == red_yellow){
            // outputs compared elements in colour
            if((swap==1 || swap==2) && idx == red_yellow){
                // outputs in yellow text
                printf("\033[0;33m%d\t\033[0;37m", arr[idx]);
            }else if(swap==2 && idx == red_blue) {
                // outputs in blue text
                printf("\033[0;34m%d\t\033[0;37m", arr[idx]);
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
