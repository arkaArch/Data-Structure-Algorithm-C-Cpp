#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

Node *prepend(Node *head, int data) {
    Node *new = create(data);
    if(head != NULL)
        new->next = head;
    return new;
}

Node *append(Node *head, int data) {
    Node *new = create(data);

    /* If list is empty, return the new node */
    if(head == NULL)
        return new;
    /* Go to last node */
    Node *last = head;
    while(last->next != NULL)
        last = last->next;
    /* Insert the new node address into the last_node->next */
    last->next = new;
    return head;
}

Node *search_node(Node *head, int key) {
    Node *temp = head;
    while(temp != NULL) {
        if(temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//void insert_before() {};

Node *insert_next(Node *head, int key, int data) {
    /* Find position of data inside the list */
    Node *new = create(data);
    Node *position = search_node(head, key);
    if(position == NULL) {
        printf("%d is not present in the list\n", key);
        return head;
    }
    new->next = position->next;
    position->next = new;
    return head;
}

void display(Node *head) {
    if(head == NULL) {
        printf("List is empty.");
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    
    int input;
    while(1) {
        puts("\n===============: Choose the option from below :===============");
        printf("1. DISPLAY \n");
        printf("2. PREPEND \n");
        printf("3. APPEND \n");
        printf("4. INSERT NEXT \n");
        printf("6. EXIT \n");

        printf("\ninput >> ");
        scanf("%d", &input);
 
        int x, y;
        switch(input) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter integer: ");
                scanf("%d", &x);
                head = prepend(head, x);
                break;
            case 3:
                printf("Enter integer: ");
                scanf("%d", &x);
                head = append(head, x);
                break;
            case 4:
                printf("Enter the integer of which you want to enter the item: ");
                scanf("%d", &x);
                printf("Enter integer: ");
                scanf("%d", &y);
                head = insert_next(head, x, y);
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong input.");
        }
    }
    return 0;
}


