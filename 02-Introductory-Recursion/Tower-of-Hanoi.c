#include <stdio.h>

void TOH(int n, char A, char B, char C) {
    if (n > 0) {
        /* Move n-1 disks from A to B not using C */
        TOH(n - 1, A, C, B);
        /* Move one disk from A to C not using B => TOH(1, A, B, C); */
        printf("Move disk %d from %c to %c not using %c\n", n, A, B, C);
        /* Move n-1 disks from B to C not using A */
        TOH(n - 1, B, A, C);
    }
}

int main() {
    TOH(3, 'A', 'B', 'C');
    return 0;
}