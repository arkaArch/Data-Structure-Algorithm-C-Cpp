/* A class template in C++ allows you to define a single, generic class
 * structure that can work with any data type, avoiding the need to write the
 * same code repeatedly for different types (e.g., a stack for integers, a stack
 * for doubles, a stack for custom objects). */

#include <iostream>

template <class T> class Arithmatic {
  private:
    T first_number;
    T second_number;

  public:
    Arithmatic(T first_number, T second_number);
    T add();
    T subtract();
};

template <class T> Arithmatic<T>::Arithmatic(T first_number, T second_number) {
    this->first_number = first_number;
    this->second_number = second_number;
}

template <class T> T Arithmatic<T>::add() {
    return first_number + second_number;
}

template <class T> T Arithmatic<T>::subtract() {
    return first_number - second_number;
}

int main() {
    Arithmatic<int> ar_int(10, 5);
    std::cout << ar_int.add() << " " << ar_int.subtract() << std::endl;

    Arithmatic<double> ar_float(30.67, 20.60);
    std::cout << ar_float.add() << " " << ar_float.subtract() << std::endl;
}