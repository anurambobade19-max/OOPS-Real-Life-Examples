#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

using namespace std;                         // using namespace std = allows using cout directly without std:: prefix


class Complex {                              // class = keyword to define a blueprint/type
                                             // Complex = class representing complex numbers

private:                                     // private = accessible ONLY inside the Complex class
                                            
double real;                                 // double = decimal variable storing the real part
double imag;                                 // double = decimal variable storing the imaginary part

public:                                      // public = accessible from outside the class

Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {} // constructor function
                                             // double r = parameter for real part with default value 0.0
                                             // double i = parameter for imaginary part with default value 0.0
                                             // : real(r), imag(i) = member initializer list initializes data members

Complex operator+(const Complex& other) const { // operator+ = overloads the + operator for Complex objects
                                             // const Complex& other = receives another Complex object by constant reference
                                             // const = function does not modify the current object

return Complex(real + other.real, imag + other.imag); // adds real parts and imaginary parts
                                             // returns a new Complex object containing the sum
}                                            // ends the operator+ function


Complex operator-(const Complex& other) const { // operator- = overloads the - operator for Complex objects
                                             // const Complex& other = receives another Complex object by constant reference
                                             // const = function does not modify the current object

return Complex(real - other.real, imag - other.imag); // subtracts real parts and imaginary parts
                                             // returns a new Complex object containing the difference
}                                            // ends the operator- function


Complex operator*(const Complex& other) const { // operator* = overloads the * operator for Complex objects
                                             // const Complex& other = receives another Complex object by constant reference
                                             // const = function does not modify the current object

return Complex(                             // returns a new Complex object as the multiplication result
real * other.real - imag * other.imag,       // calculates the real part of the product
real * other.imag + imag * other.real        // calculates the imaginary part of the product
);                                           // ends the Complex object construction
}                                            // ends the operator* function


bool operator==(const Complex& other) const { // operator== = overloads the == operator for comparison
                                             // bool = function returns true or false
                                             // const Complex& other = receives another Complex object by constant reference
                                             // const = function does not modify the current object

return real == other.real && imag == other.imag; // compares both real and imaginary parts
                                             // && = logical AND operator, both conditions must be true
}                                            // ends the operator== function


void display() const {                       // void = function does not return any value
                                             // display() = function used to display the complex number
                                             // const = function does not modify the object

cout << real << " + " << imag << "i" << endl; // displays the complex number in real + imaginary i format
}                                            // ends the display() function
};                                           // ; = ends Complex class declaration


int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution in C++ programs
  
Complex c1(3.0, 4.0);                        // creates Complex object c1 with real part 3.0 and imaginary part 4.0
Complex c2(1.0, 2.0);                        // creates Complex object c2 with real part 1.0 and imaginary part 2.0

cout << "C1: ";                              // displays label for the first complex number
c1.display();                                // calls display() function to show c1

cout << "C2: ";                              // displays label for the second complex number
c2.display();                                // calls display() function to show c2

cout << "Sum: ";                             // displays label for addition result
(c1 + c2).display();                         // uses overloaded + operator and displays the sum

cout << "Difference: ";                      // displays label for subtraction result
(c1 - c2).display();                         // uses overloaded - operator and displays the difference

cout << "Product: ";                         // displays label for multiplication result
(c1 * c2).display();                         // uses overloaded * operator and displays the product
}                                            // ends the main() function