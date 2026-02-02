#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* push(Node* top, int element) {
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL) {    // Heap is full
        printf("Stack is full");
        return top;
    }
    new_node->data = element;
    new_node->link = top;
    top = new_node;
    return top;
}

