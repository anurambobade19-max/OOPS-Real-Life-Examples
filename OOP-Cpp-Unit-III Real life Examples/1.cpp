#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <memory>                            // <memory> = library for smart pointers (unique_ptr, make_unique)
#include <vector>                            // <vector> = library for dynamic arrays (vector)
using namespace std;                         // using namespace std = allows using cout, vector directly without std:: prefix

class Shape {                                // class = keyword to define a blueprint/type
                                             // Shape = abstract base class for different shapes

public:                                      // public = access specifier (accessible from anywhere)
    virtual double area() const = 0;        // virtual = enables runtime polymorphism
                                             // double = function returns a decimal value
                                             // area() = function to calculate the area of the shape
                                             // const = promises not to modify member variables
                                             // = 0; = pure virtual function, making Shape an abstract class

    virtual void draw() const = 0;           // virtual = enables runtime polymorphism
                                             // void = function does not return any value
                                             // draw() = function to display/draw the shape
                                             // const = promises not to modify member variables
                                             // = 0; = pure virtual function

    virtual ~Shape() = default;              // virtual = ensures proper destruction through base-class pointer
                                             // ~Shape() = destructor of Shape class
                                             // = default; = compiler generates the default destructor
};                                           // ; = ends Shape abstract base class declaration


class Circle : public Shape {                // Circle = derived class inheriting from Shape
                                             // : = inheritance operator
                                             // public Shape = publicly inherits from Shape

private:                                     // private = accessible ONLY inside Circle class
double radius;                               // double = decimal variable storing the radius of the circle

public:                                      // public = accessible from outside the class
explicit Circle(double r) : radius(r) {}     // Circle = constructor function
                                             // double r = parameter storing the radius value
                                             // explicit = prevents unwanted implicit conversion
                                             // : radius(r) = member initializer list initializes radius

double area() const override {               // override = confirms implementation of Shape's area() function
                                             // const = matches the const function in the base class
return 3.14159265359 * radius * radius;      // calculates and returns the area of the circle
}                                            // ends the area() function

void draw() const override {                 // override = implements the pure virtual draw() function
                                             // void = function does not return a value
        cout << "Drawing circle with radius " << radius << endl; // displays circle radius
}                                            // ends the draw() function
};                                           // ; = ends Circle class declaration


class Rectangle : public Shape {             // Rectangle = derived class inheriting from Shape
                                             // : = inheritance operator
                                             // public Shape = publicly inherits from Shape

private:                                     // private = accessible ONLY inside Rectangle class
double length;                               // double = decimal variable storing rectangle length
double width;                                // double = decimal variable storing rectangle width

public:                                      // public = accessible from outside the class
Rectangle(double l, double w) : length(l), width(w) {} // constructor function
                                             // double l = parameter for length
                                             // double w = parameter for width
                                             // : length(l), width(w) = initializes length and width

double area() const override {               // override = implements Shape's area() function
                                             // const = function does not modify member variables
return length * width;                       // calculates and returns the area of the rectangle
}                                            // ends the area() function

void draw() const override {                 // override = implements Shape's draw() function
                                             // void = function does not return a value
        cout << "Drawing rectangle " << length << " x " << width << endl; // displays rectangle dimensions
}                                            // ends the draw() function
};                                           // ; = ends Rectangle class declaration


class Triangle : public Shape {              // Triangle = derived class inheriting from Shape
                                             // : = inheritance operator
                                             // public Shape = publicly inherits from Shape

private:                                     // private = accessible ONLY inside Triangle class
double base;                                 // double = decimal variable storing the base of triangle
double height;                               // double = decimal variable storing the height of triangle

public:                                      // public = accessible from outside the class
Triangle(double b, double h) : base(b), height(h) {} // constructor function
                                             // double b = parameter for base
                                             // double h = parameter for height
                                             // : base(b), height(h) = initializes base and height

double area() const override {               // override = implements Shape's area() function
                                             // const = function does not modify member variables
return 0.5 * base * height;                  // calculates and returns the area of the triangle
}                                            // ends the area() function

void draw() const override {                 // override = implements Shape's draw() function
                                             // void = function does not return a value
cout << "Drawing triangle with base " << base // displays the base of the triangle
<< " and height " << height << endl;         // displays the height of the triangle
}                                            // ends the draw() function
};                                           // ; = ends Triangle class declaration


int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution in C++ program

vector<unique_ptr<Shape>> shapes;            // vector = dynamic array
                                             // unique_ptr<Shape> = smart pointer to Shape objects
                                             // shapes = stores pointers to different shape objects

shapes.push_back(make_unique<Circle>(5.0)); // make_unique = dynamically creates a Circle object
                                             // Circle(5.0) = creates Circle with radius 5
                                             // push_back = adds the object pointer to the vector

shapes.push_back(make_unique<Rectangle>(4.0, 6.0)); // dynamically creates a Rectangle object
                                             // Rectangle(4.0, 6.0) = creates rectangle with length 4 and width 6
                                             // push_back = adds the object pointer to the vector

shapes.push_back(make_unique<Triangle>(3.0, 8.0)); // dynamically creates a Triangle object
                                             // Triangle(3.0, 8.0) = creates triangle with base 3 and height 8
                                             // push_back = adds the object pointer to the vector

cout << "=== CAD Shape System ===" << endl;  // cout = displays output on the screen
                                             // prints the title of the CAD Shape System

for (const auto& shape : shapes) {           // for = range-based loop for iterating through the vector
                                             // const = prevents modification of the element
                                             // auto& = automatically determines the data type and uses a reference
                                             // shape = represents the current shape pointer

shape->draw();                               // -> = accesses a function through the smart pointer
                                             // draw() = calls the appropriate draw() function using runtime polymorphism

cout << "Area: " << shape->area() << " square units" << endl; // calls area() and displays the calculated area
                                             // area() = invokes the correct derived-class function
}                                            // ends the for loop
}                                            // ends the main() function