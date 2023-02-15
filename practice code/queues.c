#include <stdio.h>


# define MAX 5

void enqueue(int *, int, int *, int *); // adds item to array if queue is not full
int empty(int *); // checks if queue is empty, returns 1 when empty
int dequeue(int * ,int *, int *); /* dequeues items from front (item with lowest index)
                                    and increases front flag. If front and rear both point
                                    to same index, resets both flags to -1 */

int main() {

    int arr[MAX]; // create an array
    int front = -1, rear = -1; // define front and rear flags

    enqueue(arr, 23, &front, &rear);
    enqueue(arr, 9, &front, &rear);
    enqueue(arr, 11, &front, &rear);
    enqueue(arr, -10, &front, &rear);
    enqueue(arr, 25, &front, &rear);
    enqueue(arr, 16, &front, &rear);

    int i;
    for (int idx=0; idx<MAX+1; idx++) {
        if (!empty(&front)) {
            i = dequeue(arr, &front, &rear);
            printf("Received Dequeued item: %d\n", i);
        }
    }

    return 0;
}

// adds item to array if queue is not full
void enqueue(int *arr, int item, int *pfront, int *prear) {

    // checks if rear flag has reached arrays MAX index
    if (*prear == MAX -1) {
        printf("Queue is full\n");
        return;
    } else {
        printf("Enqueuing: %d\n", item);
        (*prear)++; // increases rear flag by 1
        arr[*prear]=item; // adds item to array

        // sets front flat to 0th index when adding first item
        if (*pfront == -1)
            *pfront=0;
    }
}

// checks if queue is empty, returns 1 when empty
int empty(int *pfront) {

    if (*pfront == -1) {
        printf("Queue is empty\n");
        return 1;
    } else
        return 0;
}

/* dequeues items from front (item with lowest index)
and increases front flag. If front and rear both point
to same index, resets both flags to -1 */
int dequeue(int* arr, int* pfront, int* prear) {

    int data = arr[*pfront]; // temp variable to store item
    printf("Dequeueing: %d\n", data);

    arr[*pfront]=0; // sets array element to 0 after item removed
    if (*pfront == *prear) // resets flags if pointing to same place (front has caught up with rear)
        *pfront = *prear = -1;
    else
        (*pfront)++;  // increases front flag

    return data;
}
