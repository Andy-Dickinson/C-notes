#include <stdio.h>
#include <stdlib.h>

/* Benefit over singly linked lists as now able to backtrack.
However, must also now need to manage two links for every node
increasing memory and time complexity
*/

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

int count(struct node* list); // returns length of list
void display(struct node* list); // prints contents of list to console
void append(struct node** list, int num); // adds node to end of list
void prepend(struct node** list, int num); // adds node to beginning of list
void insert_after(struct node* list, int location, int num); // inserts 'num' at index 'location'
void delete(struct node** list, int num); // delete element 'num' from list

int main(void) {
    struct node* list;
    list = NULL;

    printf("No of elements in linked list = %d\n", count(list));
    display(list);
printf("list add = %p\n", &list);
    append(&list, 14);
    append(&list, 30);
    append(&list, 25);
    append(&list, 42);
    append(&list, 17);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    prepend(&list, 999);
    prepend(&list, 888);
    prepend(&list, 777);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    insert_after(list, 1, 0);
    insert_after(list, 2, 1);
    insert_after(list, 5, 99);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    insert_after(list, 99, 10);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    delete(&list, 99);
    delete(&list, 1);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    delete(&list, 10);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    return 0;
}

// returns length of list
int count(struct node* list) {
printf("count list add = %p\n", &list);
    int count = 0;
    while(list != NULL) {
        list = list -> next;
        count++;
    }
    return count;
}

// prints contents of list to console
void display(struct node* list) {
    while(list != NULL) {
        printf("%2d\t", list -> data);
        list = list -> next;
    }
    printf("\n");
}

// Adds node to end of list
// method setup  here must traverse the list to get to the end
void append(struct node** list, int num) {
    // temp used to create new node when list is not empty, current set to point at list (used to traverse list)
    struct node* temp, * current = *list;

    // if list is not empty
    if(*list == NULL) {
        // allocate enough memory
        *list = (struct node*) malloc(sizeof(struct node));

        // first node, so no pointers, but set data
        (*list) -> prev = NULL;
        (*list) -> data = num;
        (*list) -> next = NULL;
    } else {
        // traverses list until last node
        while(current -> next != NULL)
            current = current -> next;

        // allocate enough memory
        temp = (struct node*) malloc(sizeof(struct node));

        // temp is new node thats appended
        temp -> data = num;
        temp -> next = NULL;
        temp -> prev = current;
        // current updates last node to point at new node
        current -> next = temp;
    }
}

// adds node to beginning of list
void prepend(struct node** list, int num) {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = num;
    temp -> next = *list;

    (*list) -> prev = temp;
    *list = temp;
}

// inserts 'num' at index 'location'
void insert_after(struct node* list, int location, int num) {
    struct node* temp;
    int i;

    for(i=0; i<location; i++) {
        list = list -> next;
        if(list == NULL) {
            printf("Length of list is %d but supplied location is %d\n", i, location);
            return;
        }
    }
    list = list -> prev;
    temp = (struct node *) malloc(sizeof(struct node));

    temp -> data = num;
    temp -> prev = list;
    temp -> next = list -> next;
    temp -> next -> prev = temp;
    list -> next = temp;
}

// delete element 'num' from list
void delete(struct node**  list, int num) {
    struct node* temp = *list;
    while(temp != NULL) {
        if(temp -> data == num) {

            // if num is the first element in the list, remove from list
            if(temp == *list) {
                *list = (*list) -> next;
                (*list) -> prev = NULL;
            } else {
                if(temp -> next == NULL)
                    temp -> prev -> next = NULL;
                else {
                    temp -> prev -> next = temp -> next;
                    temp -> next -> prev = temp -> prev;
                }
                free(temp);
            }
            return;
        }
        temp = temp -> next;
    }
    printf("Element %d not found in the supplied list\n", num);
}
