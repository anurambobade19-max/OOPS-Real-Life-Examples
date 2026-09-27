#include <cctype>                           // #include = adds a library
                                           // <cctype> = library for character checking functions like isalpha()

#include <iostream>                        // <iostream> = library for standard input/output (like cout)

#include <string>                          // <string> = library for handling text data (std::string)
using namespace std;                       // using namespace std = allows using cout and string directly without std:: prefix


class Validator {                          // class = keyword to define a blueprint/type
                                           // Validator = class used to validate marks, amount, and name

public:                                    // public = accessible from outside the class

bool validate(int marks) const {            // validate = function to validate integer marks
                                           // int marks = parameter storing marks
                                           // const = function does not modify class data members
return marks >= 0 && marks <= 100;          // checks whether marks are between 0 and 100
                                           // && = logical AND operator; both conditions must be true
}                                          // ends the integer validate() function


bool validate(double amount) const {        // validate = overloaded function to validate decimal amount
                                           // double amount = parameter storing payment amount
                                           // const = function does not modify class data members
return amount > 0.0 && amount <= 1000000.0; // checks whether amount is greater than 0 and up to 1,000,000
                                           // && = logical AND operator; both conditions must be true
}                                          // ends the double validate() function


bool validate(const string& name) const {   // validate = overloaded function to validate a name
                                           // const string& name = receives the name as a constant reference
                                           // const = function does not modify class data members

if (name.empty()) {                         // if = checks whether the name is empty
return false;                              // returns false because an empty name is invalid
}                                          // ends the if statement

for (char ch : name) {                      // for = range-based loop that checks every character in the name
                                           // char ch = stores one character at a time

if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ') { // isalpha() = checks whether character is alphabetic
                                           // static_cast<unsigned char>(ch) = safely converts character for isalpha()
                                           // ! = NOT operator; reverses the result of isalpha()
                                           // ch != ' ' = checks that the character is not a space
                                           // && = both conditions must be true

return false;                              // returns false if the name contains a non-letter character
}                                          // ends the if statement
}                                          // ends the for loop

return true;                               // returns true if all characters in the name are valid
}                                          // ends the string validate() function
};                                         // ; = ends Validator class declaration


int main() {                                // int = return type of main function
                                           // main() = mandatory entry point of execution in C++ programs

Validator validator;                       // creates an object named validator of the Validator class

cout << boolalpha;                         // boolalpha = displays boolean values as true or false instead of 1 or 0

cout << "Marks 88 valid: " << validator.validate(88) << endl; // calls validate(int) for marks 88 and displays the result

cout << "Marks 120 valid: " << validator.validate(120) << endl; // calls validate(int) for marks 120 and displays the result

cout << "Amount 4500.50 valid: " << validator.validate(4500.50) << endl; // calls validate(double) for the amount and displays the result

cout << "Name Priya Sharma valid: " // displays the label for the first name validation
<< validator.validate(string("Priya Sharma")) << endl; // creates a string and calls validate(string) to check the name

cout << "Name Priya123 valid: " // displays the label for the second name validation
<< validator.validate(string("Priya123")) << endl; // creates a string and calls validate(string) to check the name
}                                          // ends the main() function