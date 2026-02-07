#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
} rect;

int main() {
    /* Now we can store the address of 'rect' inside a pointer. */
    struct Rectangle *r = &rect;
    /* Now we can access it's length and breadth by '->' operator. */
    r->length = 20;
    /* Which is similar to */
    (*r).breadth = 10;
    printf("Area of rectangle rect is: %d. \n", rect.length * rect.breadth);

    /* We can also create an structure dynamically. */
    struct Rectangle *dr = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    dr->breadth = 35, dr->length = 55;
    printf("Area of rectangle (which is pointed by dr) is %d \n",
           dr->length * dr->breadth);

    return 0;
}