#include <stdio.h>

struct Rectangle {
    int length;
    int breadth;
};

struct Example {
    int a;
    int b;
    char c;
} example;

int main() {
    struct Rectangle rect = {10, 5};
    printf("Area of this rectangle: %d\n", rect.length * rect.breadth);
    printf("%lu\t", sizeof(rect));    // 4
    printf("%lu\n", sizeof(example)); // 12
    /* Now it is expected that the size of example is to be (4 + 4 + 1) = 9
     * But for computer it is easy to read 4 - 4 blocks of memory at a time,
     * this phenomena is called padding */
    return 0;
}