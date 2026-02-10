#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* TOP = NULL;

void push(int element) {
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL) {    // Heap is full
        printf("Stack is full\n");
        return;
    }
    new_node->data = element;
    new_node->link = TOP;
    TOP = new_node;
}

int pop() {
    if(TOP == NULL) 
        return -1;
    Node* temp = TOP;
    int popped = TOP->data;
    TOP = TOP->link;
    free(temp);
    return popped;
}

int peek(int index) {
    /* We count index of stack from above (st.TOP = position - 1) */
    Node *temp = TOP;
    for(int i = 1; temp != NULL & i < index; i++)
        temp = temp->link;
    if(temp != NULL)
        return temp->data;
    return -1;
}

void display() {
    if(TOP == NULL) {
        printf("Stack is empty");
        return;
    }
    Node* temp = TOP;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int input;
    while(1) {
        puts("\n===============: Choose the option from below :===============");
        printf("1. Display stack\n");
        printf("2. Insert into stack\n");
        printf("3. Delete from stack\n");
        printf("4. See an element of stack\n");
        printf("5. Exit\n");
        
        printf("\ninput >> ");
        scanf("%d", &input);
        
        int x, p;
        switch(input) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                push(x);
                break;
            case 3:
                p = pop();
                if(p == -1)
                    printf("Stack is empty.\n");
                else
                    printf("Popped element: %d", p);
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &x);
                p = peek(x);
                if(p == -1 || x < 1)
                    printf("Invalid input\n");
                else
                    printf("Element at %d: %d", x, p);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input");
        }
    }
    return 0;
}
