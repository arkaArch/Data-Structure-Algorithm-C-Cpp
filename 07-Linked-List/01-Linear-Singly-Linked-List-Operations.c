#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int info;
    struct Node *link;
} Node;

void display(Node *start) {
    if(start == NULL) {
        printf("List is empty.");
        return;
    }
    Node *ptr = start;
    while(ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}

int count(Node *start) {
    int count = 0;
    Node *ptr = start;
    while(ptr != NULL) {
        ptr = ptr->link;
        count++;
    }
    return count;
}   

void search(Node *start, int item) {
    Node *ptr = start;
    int position = 1;
    while(ptr != NULL) {
        if(ptr->info == item) {
            printf("%d found at position %d\n", item, position);
            return;
        }
        ptr = ptr->link;
        position++;
    }
    printf("%d is not found in list.\n", item);
}

Node *add_at_beginning(Node *start, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->info = data;
    new_node->link = start;
    start = new_node;
    return start;
}

Node *add_at_end(Node *start, int data) {
    /* If list is empty, add it at_the_beginning */
    if (start == NULL)
        return add_at_beginning(start, data);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->info = data;
    new_node->link = NULL;
    /* Go to last node */
    Node *ptr = start;
    while(ptr->link != NULL)
        ptr = ptr->link;
    /* Insert the new node address into the last_node->link */
    ptr->link = new_node;
    return start;
}

Node *add_after_node(Node *start, int key, int data) {
    /* Add data after key */
    /* Find position of info inside the list */
    Node *ptr = start;
    while(ptr != NULL) {
        if(ptr->info == key) {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->info = data;
            new_node->link = ptr->link;
            ptr->link = new_node;
            return start;
        }
        ptr = ptr->link;
    }
    printf("%d is not present in the list\n", key);
    return start;
}

Node *add_before_node(Node *start, int key, int data) {
    /* Add data before key */
    /* If list is empty */
    if(start == NULL) {
        printf("List is empty\n");
        return start;
    }
    /* If data to be inserted before first node */
    if(start->info == key)
        return add_at_beginning(start, data);
    
    Node *ptr = start;
    while(ptr->link != NULL) {
        if(ptr->link->info == key) {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->info = data;
            new_node->link = ptr->link;
            ptr->link = new_node;
            return start;
        }
        ptr = ptr->link;
    }
    printf("%d is not present in the list\n", key);
    return start;
}

Node *delete_node(Node *start, int data) {
    /* If list is empty */
    if(start == NULL) {
        printf("Nothing to delete\n");
        return start;
    }
    /* Deletion of first node */
    if(start->info == data) {
        Node *temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    /* Deletion of node in between or last */
    Node *ptr = start;
    while(ptr->link != NULL) {
        if(ptr->link->info == data) {
            Node *temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
            return start;
        }
        ptr = ptr->link;
    }
    printf("%d is not present in the list\n", data);
    return start;
}

Node *create_list(Node *start) {
    int number_of_nodes, element;
    printf("Enter the number of nodes: ");
    scanf("%d", &number_of_nodes);
    start = NULL;
    if(number_of_nodes <= 0)
        return start;
    for(int i = 0; i < number_of_nodes; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &element);
        start = add_at_end(start, element);
    }
    return start;
}

Node *reverse_list(Node *start) {
    Node *ptr = start;
    Node *prev = NULL;
    Node *next;
    while(ptr != NULL) {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
}

bool is_sorted(Node *start) {
    Node *ptr = start;
    while(ptr->link != NULL) {
        if(ptr->info > ptr->link->info)
            return false;
        ptr = ptr->link;
    }
    return true;
}

Node *remove_duplicate_from_sorted_list(Node *start) {
    if(!is_sorted(start)) {
        printf("The list is not sorted.\n");
        return start;
    }
    Node *ptr = start;
    while(ptr->link != NULL) {
        if(ptr->info == ptr->link->info) {
           Node *temp = ptr->link;
           ptr->link = ptr->link->link;
           free(temp);
           continue;    // For more than 2 same elements
        }
        ptr = ptr->link;
    }
    return start;
}


int main() {
    Node *start = NULL;
    
    int input;
    while(1) {
        puts("\n===============: Choose the option from below :===============");
        printf("1. Display list\n");
        printf("2. Count items of list\n");
        printf("3. Search for item\n");
        printf("4. Add at beginning of list\n");
        printf("5. Add at end of list\n");
        printf("6. Add after a node\n");
        printf("7. Add before a node\n");
        printf("8. Delete a node\n");
        printf("9. Create a linked list.\n");
        printf("10. Reverse the list\n");
        printf("11. Check if the list is sorted\n");
        printf("12. Remove duplicate element from sorted list\n");
        printf("13. Exit \n");

        printf("\ninput >> ");
        scanf("%d", &input);
 
        int x, y;
        switch(input) {
            case 1:
                display(start);
                break;
            case 2:
                printf("%d\n", count(start));
                break;
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &x);
                search(start, x);
                break;
            case 4:
                printf("Enter integer: ");
                scanf("%d", &x);
                start = add_at_beginning(start, x);
                break;
            case 5:
                printf("Enter integer: ");
                scanf("%d", &x);
                start = add_at_end(start, x);
                break;
            case 6:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                printf("Enter the integer after which to insert: ");
                scanf("%d", &y);
                start = add_after_node(start, y, x);
                break;
            case 7:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                printf("Enter the integer before which to insert: ");
                scanf("%d", &y);
                start = add_before_node(start, y, x);
                break;
            case 8:
                printf("Enter the element to be deleted: ");
                scanf("%d", &x);
                start = delete_node(start, x);
                break;
            case 9:
                start = create_list(start);
                break;
            case 10:
                start = reverse_list(start);
                break;
            case 11:
                printf("%s\n", is_sorted(start) ? "True" : "Flase");
                break;
            case 12:
                start = remove_duplicate_from_sorted_list(start);
                break;
            case 13:
                exit(0);
            default:
                printf("Wrong input.");
        }
    }
    return 0;
}
