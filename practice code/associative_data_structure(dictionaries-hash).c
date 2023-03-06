#include <stdio.h>
#include <stdlib.h>

struct DataItem* delete(struct DataItem* item); // finds element and sets slot to NULL
void display(void); // prints key followed by value as comma-separated pair
void insert(int key, int data); // insert key/value pair into hashArray
int hashCode(int); // returns a potential index value
struct DataItem* search(int key); // searches associative structure for key and returns associated value

#define SIZE 10

// structure to store associative pairs
struct DataItem {
    int data;
    int key;
};

struct DataItem* hashArray[SIZE]; // array of DataItems - this is out dictionary/hashmap
struct DataItem* tempItem;
struct DataItem* item;  // key-value pair

// main method
int main(void) {

    // creates key/value pair structure to store key and data
    // initialises data and key to -1
    tempItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    tempItem -> data = -1;
    tempItem -> key = -1;

    display();

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(37, 97);
    insert(10, 0);

    display();

    item = search(37);
    if(item != NULL) {
        printf("Element found: %d\n", item->data);
    }else {
        printf("Element not found\n");
    }

    item = delete(item);
    if(item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }

    display();

    item = search(37);
    if(item != NULL) {
        printf("Element not found\n");
    }
    display();

    return 0;
}

// prints key followed by value as comma-separated pair
void display(void) {
    int i;
    for(i=0; i<SIZE; i++){
        if(hashArray[i] != NULL)
            printf(" (%d,%d)", hashArray[i] -> key, hashArray[i] -> data);
        else
            printf(" ~,~ ");
    }
    printf("\n");
}

// returns a potential index value,
// or place to store the value based on underlying storage.
// Key aspect is that a hash function should ideally give constant, or near constant,
// time access to any given value, regardless of how large the structure is
// or how much data is stored within it.
int hashCode(int key) {
    return key % SIZE;
}

// insert key/value pair into hashArray
void insert(int key, int data) {
    struct DataItem* item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item -> data = data;
    item -> key = key;

    // due to data not being linear, use modulus of array size to get array index
    // if space is taken, we increment the location we are looking at
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex] -> key != -1) {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

// searches associative structure for key and returns associated value
// not ideal way to retrieve data, as may be collisions amongst keys
struct DataItem* search(int key) {
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex] -> key == key)
            return hashArray[hashIndex];

        ++hashIndex;
        hashIndex %= SIZE;
    }

    return NULL;
};

// finds element and sets slot to NULL
struct DataItem* delete(struct DataItem* item) {
    int key = item -> key;
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL) {

        if(hashArray[hashIndex] -> key == key) {
            struct DataItem* temp = hashArray[hashIndex];
            hashArray[hashIndex] = NULL;
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return NULL;
};
