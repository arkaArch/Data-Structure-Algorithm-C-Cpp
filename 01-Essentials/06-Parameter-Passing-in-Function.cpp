#include <iostream>

void swap_pass_by_value(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_pass_by_address(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Here comes the power of reference in c++ */
void swap_pass_by_reference(int &a, int &b) {
    /* The interesting point about this function is, since it is using the
     * reference, inside memory there are no activation record is created by
     * this function, when this function is called its just pasted inside the
     * "main" function. So it's like monolithic program. So we can say that
     * though source code is modular the inside working of the function is
     * monolithic.*/
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 5;
    swap_pass_by_value(x, y);
    /* Value of x and y will not be change. In the function the arguments value
     * will be copied and they changed. But they can't affect the argument value
     * in main function. */
    std::cout << "After swapping[swap_pass_by_value] x = " << x << ", y = " << y
              << std::endl;

    swap_pass_by_address(&x, &y);
    /* The value of arguments will be changed after calling this function since
     * the function chanhe the values by accessing their address. */
    std::cout << "After swapping[swap_pass_by_address] x = " << x
              << ", y = " << y << std::endl;

    /* Reset the value */
    x = 10, y = 5;
    swap_pass_by_reference(x, y);
    std::cout << "After swapping[swap_pass_by_reference] x = " << x
              << ", y = " << y << std::endl;

    return 0;
}