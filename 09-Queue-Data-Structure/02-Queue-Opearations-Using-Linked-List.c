#include <stdio.h>
#include <stdlib.h>

/* Queue follows FIFO - (F)irst (I)n (F)irst (O)ut */

typedef struct Node { 
    int data;
    struct Node* link;
} Node;

Node* FRONT = NULL;
Node* REAR = NULL;

void enqueue(int value) {
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL) {  // Heap is full
        printf("Queue is full");
        return;
    }
    new_node->data = value;
    new_node->link = NULL;
    /* Check if the element is first in queue */
    if(FRONT == NULL)
        FRONT = new_node;
    else
        REAR->link = new_node;
    REAR = new_node;
}

int dequeue() {
    if(FRONT == NULL) 
        return -1;
    Node* temp = FRONT;
    int p = temp->data;
    FRONT = FRONT->link;
    free(temp);
    return p;
}

void display() {
    if(FRONT == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = FRONT;
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
        printf("1. Display queue\n");
        printf("2. Insert into queue\n");
        printf("3. Delete from queue\n");
        printf("4. Exit\n");
        
        printf("\ninput >> ");
        scanf("%d", &input);

        int x, p;
        switch(input) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 3:
                p = dequeue();
                if(p == -1)
                    printf("Queue is empty\n");
                else
                    printf("Popped element: %d\n", p);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong input\n");
        }
    }
    return 0;
}
