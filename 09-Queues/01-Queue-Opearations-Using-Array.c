#include <stdio.h>
#include <stdlib.h>

/* Queue follows FIFO - (F)irst (I)n (F)irst (O)ut */

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} Queue;

void enqueue(Queue *q, int value) {
    /* If front pointer is ponting just after rear, q is full */
    if((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    }
    /* To reuse the free space we take mod */
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = value;
}

int dequeue(Queue *q) {
    if(q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    /* To reuse the free space we take mod */
    q->front = (q->front + 1) % q->size;
    return q->Q[q->front];
}

void display(Queue *q) {
    if(q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front + 1;
    do {
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    } while(i != (q->rear + 1) % q->size);
    printf("\n");
}

int main() {
    /* Creating a queue */
    Queue q;
    printf("Enter the size of queue: ");
    scanf("%d", &q.size);
    q.Q = malloc(q.size * sizeof(int));
    q.front = q.rear = 0;

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
                display(&q);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                enqueue(&q, x);
                break;
            case 3:
                p = dequeue(&q);
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
