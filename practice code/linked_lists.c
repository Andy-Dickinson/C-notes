#include <stdio.h>

/* Downside to singly linked lists is cannot backtrack. Would need
to traverse list again from beginning - wasteful. Use
doubly linked lists to do this */

struct node {
    int data;
    struct node* link;
};

void prepend(struct node** list, int num); // inserts 'num' at beginning of 'list'
void append(struct node** list, int num); // appends 'num' at end of 'list'
int count(struct node* list); // counts number of nodes in list (ie gets length)
void delete(struct node** list, int num); // removes first element in list which matches 'num'
void display(struct node* list); // prints contents of list to console
void insert_after(struct node* list, int location, int num); // inserts 'num' after index 'location'

int main(void) {
    struct node* list;
    list = NULL;

    printf("No of elements in linked list = %d\n", count(list));

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

    insert_after(list, 99, 3);
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

// counts number of nodes in list (ie gets length)
int count(struct node* list) {
    int count = 0;  // could have also called this var 'length'

    // NULL when reaches end of the list (including empty list (end of very short list))
    while (list != NULL) {
        list = list -> link;
        count++;
    }
    return count;
}

// prints contents of list to console
void display(struct node* list) {

    // NULL when reaches end of the list (including empty list (end of very short list))
    while(list != NULL) {
        printf("%d ", list -> data);
        list = list -> link;
    }
    printf("\n");
}

// appends 'num' at end of 'list'
void append(struct node** list, int num) {

    struct node* temp, * r;
    // if list is empty
    if(*list == NULL){
        temp = (struct node*) malloc (sizeof(struct node));
        temp -> data = num;
        temp -> link = NULL;
        *list = temp; // sets passed in list pointer to point at temp address
    } else {
        temp = *list;
        // set temp to point to top
        while(temp -> link != NULL)
            temp = temp -> link;

        r = (struct node*) malloc(sizeof(struct node));
        r -> data = num;
        r -> link = NULL;
        temp -> link = r;
    }
}


// inserts 'num' at beginning of 'list'
void prepend(struct node** list, int num) {
    struct node* temp; // creates a new temporary node
    temp = (struct node*) malloc(sizeof(struct node));

    // sets temps data and links to beginning of list
    temp -> data = num;
    temp -> link = *list;

    // sets list to now point at temp (prepended node)
    *list = temp;
}


// inserts 'num' after index 'location'
void insert_after(struct node* list, int location, int num) {
    struct node* temp, * r;
    int i;
    temp = list;
    for(i=0; i<location; i++) {

        temp = temp -> link;
        if(temp == NULL) {
            printf("Length of list is %d but supplied location is %d\n", i, location);
            return;
        }
    }
    r = (struct node*) malloc (sizeof(struct node));
    r -> data = num;
    r -> link = temp -> link;
    temp -> link = r;
}

// removes first element in list which matches 'num'
void delete(struct node** list, int num) {
    struct node* old, * temp;
    temp = *list;

    while(temp != NULL) {
        if(temp -> data == num) {
            if(temp == *list) {
                *list = temp -> link;
            } else
                old -> link = temp -> link;
                free(temp);
                return;
        } else {
            old = temp;
            temp = temp -> link;
        }
    }
    printf("Element %d not found in the supplied list\n", num);
}
