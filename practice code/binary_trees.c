#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// node structure. Child pointers to structure of same type, so no different to parent nodes
struct binary_tree_node {
    struct binary_tree_node* left_child;
    struct binary_tree_node* right_child;
    int data;
};

void insert(struct binary_tree_node**, int);
void traverse(struct binary_tree_node*); // prints tree in order traversal
void search(struct binary_tree_node**, int, struct binary_tree_node**, struct binary_tree_node**, int*);
void delete(struct binary_tree_node**, int);


int main(void) {

    struct binary_tree_node *root;
    int i=0;
    int content[] = {11, 9, 13, 8, 10, 12, 14, 15, 7};
    root = NULL;

    // populates tree with content making root the root node
    while(i<=8) {
        insert(&root, content[i]);
        i++;
    }

    traverse(root);
    printf("\n");

    printf("deleting 10\n");
    delete(&root, 10);
    traverse(root);
    printf("\n");

    printf("deleting 14\n");
    delete(&root, 14);
    traverse(root);
    printf("\n");

    printf("deleting 8\n");
    delete(&root, 8);
    traverse(root);
    printf("\n");

    printf("deleting 13\n");
    delete(&root, 13);
    traverse(root);
    printf("\n");

    return 0;
}

// inserts a new node.
// First checks if tree is empty, if not, it checks current num against the nodes data.
// Recursively calls itself until it finds an empty slot.
// Means data sorts by value either side of a node
void insert(struct binary_tree_node** node, int num) {

    if(*node == NULL) {
        *node = (struct binary_tree_node*) malloc (sizeof(struct binary_tree_node));
        (*node) -> left_child = NULL;
        (*node) -> right_child = NULL;
        (*node) -> data = num;
    } else {
        if(num < (*node) -> data)
            insert(&((*node) -> left_child), num);
        else
            insert(&((*node) -> right_child), num);
    }
}

// traverses tree and prints data from each node
// Due to order of recursive call, will print data from bottom left most node,
// before printing parent, followed by right child
void traverse(struct binary_tree_node* node) {

    if(node != NULL) {
        traverse(node -> left_child);

        // prints left child of node data
        struct binary_tree_node* temp = node -> left_child;
        if(temp != NULL)
            printf("(%d):", temp ->data);
        else
            printf("(nc):");

        // prints node data
        printf("%d", node -> data);

        // prints right child of node data
        temp = node -> right_child;
        if(temp != NULL)
            printf(":(%d)\t", temp ->data);
        else
            printf(":(nc)\t");

        traverse(node -> right_child);
    }
}

// searches tree for a number
void search(struct binary_tree_node** root, int num, struct binary_tree_node** parent, struct binary_tree_node** found_node, int* found_status) {
    struct binary_tree_node* temp;
    temp = *root;
    *found_status = FALSE;
    *parent = NULL;

    while(temp != NULL) {
        if(temp -> data == num) {
            *found_status = TRUE;
            *found_node = temp;
            return;
        }

        *parent = temp;

        // traverses tree
        if(temp -> data > num)
            temp = temp -> left_child;
        else
            temp = temp -> right_child;
    }
}

void delete(struct binary_tree_node** root, int num) {
    int found;
    // search_node is one getting deleted, parent is that of the search node
    struct binary_tree_node* parent, * search_node, * next;

    // checks if nothing to delete
    if(*root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    // searches tree for num
    parent = search_node = NULL;
    search(root, num, &parent, &search_node, &found);

    if(found == FALSE) {
        printf("Data not found\n");
        return;
    }

    // when search node has 2 children, rotates sub-tree by copying data from right then all the way left child of search_node to search_node
    // The child which had its data copied will be deleted in one of the following if statements
    if(search_node -> left_child != NULL && search_node -> right_child != NULL) {
        parent = search_node;
        next = search_node -> right_child;
        while(next -> left_child != NULL) {
            parent = next;
            next = next -> left_child;
        }
        search_node -> data = next -> data; // copies data from next node to search node
        search_node = next; // sets search_node pointer to point at node which had its data copied...this will be deleted in following if statments
    }

    // when search_node has no children
    if(search_node -> left_child == NULL && search_node -> right_child == NULL) {
        // sets parent node of search_node (one getting deleted) to no longer point at search_node
        if(parent -> right_child == search_node)
            parent -> right_child = NULL;
        else
            parent -> left_child = NULL;

        free(search_node);
        return;
    }

    // when search_node has right child only
    if(search_node -> left_child == NULL && search_node -> right_child != NULL) {
        // sets parent of search_node (one getting deleted) to point at search_nodes child instead
        if(parent -> left_child == search_node)
            parent -> left_child = search_node -> right_child;
        else
            parent -> right_child = search_node -> right_child;

        free(search_node);
        return;
    }

    // when search_node has left child only
    if(search_node -> left_child != NULL && search_node -> right_child == NULL) {
        // sets parent of search_node (one getting deleted) to point at search_nodes child instead
        if(parent -> left_child == search_node)
            parent -> left_child = search_node -> left_child;
        else
            parent -> right_child = search_node -> left_child;

        free(search_node);
        return;
    }
}
