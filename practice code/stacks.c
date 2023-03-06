#include <stdio.h>

#define MAX 5 // sets maximum number of items stack can hold

// structure to store variables
struct stack {
    int array[MAX];// stores stack contents
    int top; // points to top of stack
};

void init_stack(struct stack *); // function to initialise stack top
void push(struct stack *, int item); // adds item to stack if stack isn't full
int *pop(struct stack *); // pops top item from stack if not empty

int main() {

    struct stack s;

    init_stack(&s);
    printf("s.top after init_stack: %d\n", s.top); // -1

    push(&s, 5);
    printf("s.top after 1 item [5] added: %d\n", s.top); // 0

    push(&s, 7);
    printf("s.top after 2 items [5,7] added: %d\n", s.top);

    push(&s, 3);
    printf("s.top after 3 items [5,7,3] added: %d\n", s.top);

    push(&s, 1);
    printf("s.top after 4 items [5,7,3,1] added: %d\n", s.top);

    push(&s, 9);
    printf("s.top after 5 items [5,7,3,1,9] added: %d\n", s.top);

    push(&s, 8);
    printf("s.top after attempting to add 6th item (8): %d\n", s.top);

    int *i = NULL;

    i = pop(&s);
    if(i) {
        printf("Item popped: %d\n", *i);
    }

    i = pop(&s);
    if(i) {
        printf("Item popped: %d\n", *i);
    }

    return 0;
}

/* accessing variable that points to top of stack and
setting to -1 to indicate empty */
void init_stack(struct stack *s) {
    s->top = -1;
}

// adds item to stack if stack isn't full
void push(struct stack *s, int item) {

    // checks where pointer is and if stack is full
    if(s->top == MAX-1) {
        printf("Stack is full. Couldn't push '%d' onto stack\n", item);
        return;
    }
    s->top++;
    s->array[s->top] = item;
}

// pops top item in stack if not empty
int *pop(struct stack *s) {
    int *data; // temporary storage for item popped

    // checks if stack is empty
    if(s->top == -1) {
        printf("Stack is empty\n");
        return NULL;
    }

    data = &s->array[s->top];
    s->top--;
    return data;
}
