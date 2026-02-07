#include <stdio.h>
#include <stdlib.h>

/* Stack follows LIFO - (L)ast (I)n (F)irst (O)ut */

typedef struct Stack {
    int size;
    int top;
    int *S;
} Stack;

void push(Stack *st, int value) {
    if(st->top == st->size - 1) {
        printf("Stack is full");
        return;
    }
    st->top ++;
    st->S[st->top] = value;
}

int pop(Stack *st) {
    int val = -1;
    if(st->top > -1) {          // Stack is not empty
        val = st->S[st->top];
        st->top --;
    }
    return val;
}

int peek(Stack *st, int index) {
    /* We count index of stack from above (st.top = position-1) */
    if(index < 1 || index > st->top + 1)    // Invalid input
        return -1;
    return st->S[index - st->top + 1];
}

int top(Stack *st) {
    if(st->top == -1)   // Stack is empty
        return -1;
    return st->S[st->top];
}

void display(Stack *st) {
    if(st->top == -1) {
        printf("Stack is empty");
        return;
    }
    for(int i = st->top; i > -1; i--)
        printf("%d ", st->S[i]);
    printf("\n");
}

int main() {
    /* Create a stack */
    Stack st;
    printf("Enter the size of stack: ");
    scanf("%d", &st.size);
    st.S = malloc(st.size * sizeof(int));
    st.top = -1;

    int input;
    while(1) {
        puts("\n===============: Choose the option from below :===============");
        printf("1. Display stack\n");
        printf("2. Insert into stack\n");
        printf("3. Delete from stack\n");
        printf("4. See an element of stack\n");
        printf("5. Top element of stack\n");
        printf("6. Exit\n");

        printf("\ninput >> ");
        scanf("%d", &input);

        int x, p;
        switch(input) {
            case 1:
                display(&st);
                break;
            case 2:
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                push(&st, x);
                break;
            case 3:
                p = pop(&st);
                if(p == -1)
                    printf("Stack is empty.\n");
                else
                    printf("Popped element: %d", p);
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &x);
                p = peek(&st, x);
                if(p == -1)
                    printf("Invalid input.\n");
                else
                    printf("Element at %d: %d", x, p);
                break;
            case 5:
                p = top(&st);
                if(p == -1)
                    printf("Stack is empty.\n");
                else
                    printf("Top element: %d", p);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid input");
        }
    }
    return 0;
}
