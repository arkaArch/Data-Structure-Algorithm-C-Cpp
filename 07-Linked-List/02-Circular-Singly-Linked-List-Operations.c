#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* In circular linked list it is better to keep track of tail node rather head node
 * if we track the head node, to insert a node at beginnning and end it requires to 
 * traverse the whole list, but if we keep track of tail node we can do the insertion
 * at beginning and end at constant time instead of O(N) */

void display(Node *tail) {
    if(tail == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *ptr = tail->next;     // head = tail->next
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
    printf("\n");
}

Node *add_to_empty(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node;
    return new_node;
}

Node *add_at_beginning(Node *tail, int data) {
    if(tail == NULL)
        return add_to_empty(data);
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = tail->next;
    tail->next = new_node;
    return tail;
}

Node *add_at_end(Node *tail, int data) {
    if(tail == NULL)
        return add_to_empty(data);
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
    return tail;
}

Node *add_node_at_position(Node *tail, int data, int position) {
    if(position == 1)
        return add_at_beginning(tail, data);
    Node *ptr = tail->next;
    Node *new_node = malloc(sizeof(Node));
    while(position > 2) {
        ptr = ptr->next;
        position --;
    }
    new_node->data = data;
    new_node->next = ptr->next;
    ptr->next = new_node;
    if(ptr == tail)
        tail = new_node;
    return tail;
}

Node *delete_node(Node *tail, int element) {
    if (tail->next == tail && tail->data == element) {  // only one node 
        free(tail);
        return NULL;
    }
    Node *ptr = tail;
    do {
        if(ptr->next->data == element) {
            Node *temp = ptr->next;
            ptr->next = temp->next;
            if(temp == tail)
                tail = ptr;
            free(temp);
            return tail;
        }
        ptr = ptr->next;
    } while(ptr != tail);
    printf("%d is not present in the list\n", element);
    return tail;
} 

int main() {
    Node *tail = NULL;
    int input;
    while(1) {
        puts("\n===============: Choose the option from below :===============");
        printf("1. Display list\n");
        printf("2. Add at beginning of list\n");
        printf("3. Add at end of list\n");
        printf("4. Add at certain position\n");
        printf("5. Delete node\n");
        printf("13. Exit \n");
            
        printf("\ninput >> ");
        scanf("%d", &input);
        int x, y;
        
         switch(input) {
            case 1:
                display(tail);
                break;
            case 2:
                printf("Enter integer: ");
                scanf("%d", &x);
                tail = add_at_beginning(tail, x);
                break;
            case 3:
                printf("Enter integer: ");
                scanf("%d", &x);
                tail = add_at_end(tail, x);
                break;
            case 4:
                printf("Enter position(1 for first): ");
                scanf("%d", &y);
                printf("Enter integer: ");
                scanf("%d", &x);
                tail = add_node_at_position(tail, x, y);
                break;
            case 5:
                if(tail == NULL) {
                    printf("Nothing to delete in empty list.\n");
                    break;
                }
                printf("Enter the element to be deleted: ");
                scanf("%d", &x);
                tail = delete_node(tail, x);
                break;
            case 13:
                exit(0);
            default:
                printf("Wrong input.");
         }
    }
    return 0;
}
