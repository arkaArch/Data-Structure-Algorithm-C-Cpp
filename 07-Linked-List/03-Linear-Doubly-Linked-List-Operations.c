#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

void display_list(Node* first) {
    if(first == NULL)
        printf("List is empty\n");
    Node *ptr = first;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int length(Node *first) {
    Node* ptr = first;
    int len = 0;
    while(ptr != NULL) {
        ptr = ptr->next;
        len ++;
    }
    return len;
}

Node* add_to_empty(int data) {
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

Node* insert_node(Node* first, int pos, int data) {
    /* Empty list is handled in main */
    if(pos == 1) {
        Node* new = malloc(sizeof(Node));
        new->data = data;
        new->prev = NULL;
        new->next = first;
        first->prev = new;
        return new;
    }
    Node* ptr = first;
    while(pos > 2) {
        ptr = ptr->next;
        pos--;
    }
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->prev = ptr;
    new->next = ptr->next;
    if(ptr->next != NULL)
        ptr->next->prev = new;
    ptr->next = new;
    return first;
}

Node *delete_node(Node* first, int data) {
    /* Empty list is handled in main */
    Node* ptr = first;
    if(ptr->data == data) {       // first node
        if(ptr->next == NULL) {   // only one node
            free(first);
            return NULL;
        }
        first = ptr->next;
        first->prev = NULL;
        free(ptr);
        return first;
    }
    while(ptr->next != NULL) {
        if(ptr->next->data == data) {
            Node* temp = ptr->next;
            ptr->next = temp->next;
            if(temp->next != NULL)      // For node which is not last
                temp->next->prev = ptr;
            return first;
        }
        ptr = ptr->next;
    }
    printf("%d is not present in the list\n", data);
    return first;
}

Node* reverse_list(Node* first) {
    Node* ptr = first;
    while(ptr != NULL) {
        if(ptr->next == NULL)
            // After reversing that should be head pointer
            first = ptr;

        /* swap prev and next */
        Node* temp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = temp;
        
        /* After swap ptr->next become ptr->prev */
        ptr = ptr->prev;     // Go to next node
    }
    return first;
}

int main() {
    Node *start = NULL;
    int input;
    while(1) {
        puts("\n===============: Choose the option from below :===============");
        printf("1. Display list\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Reverse list\n");
        printf("5. Exit\n");

        printf("\ninput >> ");
        scanf("%d", &input);

        int x, y;
        switch(input) {
            case 1:
                display_list(start);
                break;
            case 2:
                if(start == NULL) {
                    printf("Enter integer: ");
                    scanf("%d", &x);
                    start = add_to_empty(x);
                    break;
                }
                printf("Enter position(1 for first): ");
                scanf("%d", &y);
                if(y < 1 || y > length(start) + 1) {
                    printf("Invalid position\n");
                    break;
                }
                printf("Enter integer: ");
                scanf("%d", &x);
                start = insert_node(start, y, x);
                break;
            case 3:
                if(start == NULL) {
                    printf("There is nothing to delete.\n");
                    break;
                }
                printf("Enter integer: ");
                scanf("%d", &x);
                start = delete_node(start, x);
                break;
            case 4:
                start = reverse_list(start);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong input");
        }
    }
    return 0;
}
