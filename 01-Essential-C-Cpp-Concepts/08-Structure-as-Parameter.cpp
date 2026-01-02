#include <iostream>

struct Rectangle {
    int length;
    int breadth;
};

int area_of_rectangle(Rectangle rectangle) {
    /* IN C++ THERE IS NO NEED TO WRITE "struct" */
    /* Remember: This is call by value. An seperate object will be created here
     * and everything will be copied in the corresponding members. */
    return rectangle.length * rectangle.breadth;
}

int area_of_rectangle_ref(Rectangle &rectangle) {
    /* Now this is call by reference. It doesn't create an seperate object. It
     * worked with the actual argument of the main function. So it also consume
     * less memory[Think if a structure contins an array of some large numbers].
     * We can also use pointers to achieve same thing. */
    return rectangle.length * rectangle.breadth;
}

int main() {
    Rectangle R = {10, 5};
    std::cout << "Area of rectangle R: " << area_of_rectangle(R) << std::endl;

    if (area_of_rectangle(R) == area_of_rectangle_ref(R))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    return 0;
}