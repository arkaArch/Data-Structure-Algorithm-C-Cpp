#include <iostream>
using namespace std;

class Rectangle {
  private:
    int length;
    int breadth;

  public:
    /* Default constructor */
    Rectangle() { length = breadth = 0; }
    /* Parameterized constructor */
    Rectangle(int l, int b);

    /* Faccilitators */
    int area();
    int perimeter();

    /* Accessors / get functions / getter function */
    int getLength() { return length; }
    int getBreadth() { return breadth; }

    /* Mutator / set functions / setter function */
    void setLength(int length) { this->length = length; }
    void setBreadth(int breadth) { this->breadth = breadth; }

    /* Destructor */
    ~Rectangle();
};

Rectangle::Rectangle(int length, int breadth) {
    this->length = length;
    this->breadth = breadth;
}

int Rectangle::area() { return this->length * this->breadth; }
int Rectangle::perimeter() { return this->length + this->breadth; }

Rectangle::~Rectangle() {
    /* This will automatically called when an object's lifetime ends, ensuring
     * that cleanup operations (like releasing memory or closing files) are
     * performed. Here we do not need destructor (created for desmonstration) */
    cout << "\nObject is destroyed.\n";
}

int main() {
    /* Creating a Rectangle object */
    Rectangle r(10, 5);
    cout << "Length and breadth of the rectangle: " << r.getLength() << ", "
         << r.getBreadth() << endl;
    cout << "Area of this rectangle: " << r.area() << endl;
    cout << "Perimeter of this rectangle: " << r.perimeter() << endl;

    cout << endl;

    /* Change length and breadth */
    r.setLength(20), r.setBreadth(15);
    cout << "Updated length and breadth of the rectangle: " << r.getLength()
         << ", " << r.getBreadth() << endl;
    cout << "Updated area of this rectangle: " << r.area() << endl;
    cout << "Updated perimeter of this rectangle: " << r.perimeter() << endl;
}