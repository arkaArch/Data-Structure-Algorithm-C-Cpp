// Reference is the part of only c++ language.

/* Reference is the nickname/alias given to a variable. It is required for
 * parameter passing and we use use it generally for writting small functions,
 * instead of using pointers. */

#include <iostream>

int main() {
    int a = 10;
    /* Making the reference */
    int &r = a;
    std::cout << r << std::endl;
    std::cout << sizeof(r) << " bytes." << std::endl;
}