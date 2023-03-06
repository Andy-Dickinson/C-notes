#include <stdio.h>

/*
Graphs are used for modelling real world problem domains, particularly
relationships between members of a network. For example, modelling the members
of a social network, or relationships between people in a family,
or the roles of people in an organisation.

Constructed from a set of vertices (node), and a set of edges that link
the vertices together.

Similar to linked list, but elements of list can point to any number of
other elements in list.

Directed graph = vertic1 points to vertice2, but vertice2 doesn't necessarily
point back to vertice1.

Undirected graph = if there is an edge between vertice1 and vertice2, then
it is bi-directional.

This will focus on directed graph.
*/

#define NUM_VERTICES 6

// stores list of all vertices that graph contains
struct Graph {
    struct Node* head[NUM_VERTICES];
};

//stores id of a target vertex (identifier and pointer to first neighbour vertex)
struct Node {
    int target;
    struct Node* next;
};

// stores identifier for a source and destination vertex.
// not required for structure, but convenient to help describe graph in terms
// of a collection of relationships between nodes.
struct Edge {
    int source;
    int target;
};



struct Graph* create_graph(struct Edge[], int);
void print_graph(struct Graph*);


int main(void) {
    struct Edge edges[] = { {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4} };

    // calculates number of edges
    int n = sizeof(edges)/sizeof(edges[0]);

    struct Graph* graph = create_graph(edges, n);

    print_graph(graph);

    return 0;
}

// takes a list of edges, and number of edges
struct Graph* create_graph(struct Edge edges[], int num_edges) {
    int i;
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

    // initialises graph
    for(i=0; i<NUM_VERTICES; i++) {
        graph -> head[i] = NULL;
    }

    for(i=0; i<num_edges; i++) {
        int source = edges[i].source;
        int target = edges[i].target;

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node -> target = target;
        new_node -> next = graph -> head[source];
        graph -> head[source] = new_node;
    }

    return graph;
};

// steps through array of vertices (nodes) that are stored in graph struct
// for each vertex, print out adjacent nodes that it is directly connected to
// by edges.
void print_graph(struct Graph* graph) {
    int i;
    for(i=0; i<NUM_VERTICES; i++) {
        struct Node* ptr = graph -> head[i];
        while(ptr != NULL) {
            printf("(%d -> %d)\t", i, ptr -> target);
            ptr = ptr -> next;
        }

        printf("\n");
    }
}
