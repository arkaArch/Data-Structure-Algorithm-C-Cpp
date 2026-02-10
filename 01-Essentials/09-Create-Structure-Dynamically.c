#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int breadth;
} Rectangle;

Rectangle *create_rectangle(int l, int b) {
    Rectangle *r = (Rectangle *)malloc(sizeof(Rectangle));
    r->length = l;
    r->breadth = b;
    return r;
}

int area_of_rectangle(Rectangle *r) { return r->length * r->breadth; }

int main() {
    Rectangle *rectangle_1 = create_rectangle(20, 15);
    printf("Area of rectangle_1: %d\n", area_of_rectangle(&(*rectangle_1)));
    return 0;
}