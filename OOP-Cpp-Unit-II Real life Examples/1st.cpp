#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <string>                            // <string> = library for handling text data (std::string)
using namespace std;                         // using namespace std = allows using cout, string, endl directly without std:: prefix

class Employee {                             // class = keyword to define a blueprint/type
                                             // Employee = abstract base class (cannot be instantiated directly)

protected:                                   // protected = access specifier (accessible in Employee & derived classes)
    int empId;                               // int = integer variable storing unique employee ID
    string name;                             // string = text variable storing employee name
    string department;                       // string = text variable storing department name

public:                                      // public = access specifier (accessible from anywhere)
    Employee(int id, string n, string dept)  // Employee = constructor function
                                             // id = parameter for ID
                                             // n = parameter for name
                                             // dept = parameter for department
        : empId(id), name(n), department(dept) {} // member initializer list sets member variables directly

    void displayBasicInfo() const {          // void = function returns no value
                                             // displayBasicInfo = non-virtual function printing ID, name, & department
                                             // const = guarantees function won't modify class members
        cout << "ID: " << empId              // prints employee ID
             << " | Name: " << name          // prints employee name
             << " | Department: " << department; // prints department name
    }

    virtual double calculateSalary() const = 0; // virtual = enables runtime polymorphism
                                             // double = returns floating-point salary
                                             // const = promises not to modify object state
                                             // = 0; = pure virtual function (makes Employee an abstract class)

    virtual ~Employee() = default;            // virtual = ensures proper destruction when deleting derived objects via base pointers
                                             // ~Employee() = base destructor
                                             // = default; = generates standard default destructor
};                                           // ; = ends Employee abstract base class declaration

class FullTimeEmployee : public Employee {   // FullTimeEmployee = child class inheriting publicly from Employee
                                             // : = inheritance operator
                                             // public Employee = inherits Employee's public/protected members

private:                                     // private = accessible ONLY inside FullTimeEmployee class
    double monthlySalary;                    // double = decimal variable storing fixed monthly salary

public:                                      // public = accessible from outside the class
    FullTimeEmployee(int id, string n, string dept, double salary) // constructor function
                                             // id = parameter for ID
                                             // n = parameter for name
                                             // dept = parameter for department
                                             // salary = parameter for monthly pay
        : Employee(id, n, dept), monthlySalary(salary) {} // passes base arguments to Employee constructor & sets monthlySalary

    double calculateSalary() const override { // override = explicitly confirms this implements Employee::calculateSalary()
                                             // const = matches pure virtual function signature in base class
        return monthlySalary;                // returns fixed monthly salary
    }

    void display() const {                   // void = function returns no value
                                             // display = method to print full employee details
                                             // const = guarantees function won't modify class members
        displayBasicInfo();                  // reuses base class method to print ID, Name, Department
        cout << " | Type: Full-Time | Salary: Rs. " // prints employment type label
             << calculateSalary() << endl;   // calls calculateSalary() and moves to next line (endl)
    }
};                                           // ; = ends FullTimeEmployee class declaration

class PartTimeEmployee : public Employee {   // PartTimeEmployee = child class inheriting publicly from Employee
                                             // : = inheritance operator
                                             // public Employee = inherits Employee's public/protected members

private:                                     // private = accessible ONLY inside PartTimeEmployee class
    double hourlyRate;                       // double = decimal variable storing pay rate per hour
    int hoursWorked;                         // int = integer variable storing total hours worked

public:                                      // public = accessible from outside the class
    PartTimeEmployee(int id, string n, string dept, double rate, int hours) // constructor function
                                             // id = parameter for ID
                                             // n = parameter for name
                                             // dept = parameter for department
                                             // rate = parameter for hourly rate
                                             // hours = parameter for hours worked
        : Employee(id, n, dept), hourlyRate(rate), hoursWorked(hours) {} // passes base args & sets hourlyRate/hoursWorked

    double calculateSalary() const override { // override = explicitly confirms this implements Employee::calculateSalary()
                                             // const = matches virtual function signature
        return hourlyRate * hoursWorked;     // calculates total salary (rate * hours)
    }

    void display() const {                   // void = function returns no value
                                             // display = method to print full details
                                             // const = guarantees function won't modify class members
        displayBasicInfo();                  // reuses base class method to print ID, Name, Department
        cout << " | Type: Part-Time | Salary: Rs. " // prints employment type label
             << calculateSalary() << endl;   // calls calculateSalary() and moves to next line (endl)
    }
};                                           // ; = ends PartTimeEmployee class declaration

class Intern : public Employee {             // Intern = child class inheriting publicly from Employee
                                             // : = inheritance operator
                                             // public Employee = inherits Employee's public/protected members

private:                                     // private = accessible ONLY inside Intern class
    double stipend;                          // double = decimal variable storing fixed internship stipend

public:                                      // public = accessible from outside the class
    Intern(int id, string n, string dept, double stipendAmount) // constructor function
                                             // id = parameter for ID
                                             // n = parameter for name
                                             // dept = parameter for department
                                             // stipendAmount = parameter for fixed stipend
        : Employee(id, n, dept), stipend(stipendAmount) {} // passes base args & sets stipend member directly

    double calculateSalary() const override { // override = explicitly confirms this implements Employee::calculateSalary()
                                             // const = matches virtual function signature
        return stipend;                      // returns fixed stipend amount
    }

    void display() const {                   // void = function returns no value
                                             // display = method to print full details
                                             // const = guarantees function won't modify class members
        displayBasicInfo();                  // reuses base class method to print ID, Name, Department
        cout << " | Type: Intern | Stipend: Rs. " // prints employment type label
             << calculateSalary() << endl;   // calls calculateSalary() and moves to next line (endl)
    }
};                                           // ; = ends Intern class declaration

int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    FullTimeEmployee f1(101, "Amit", "IT", 65000); // creates FullTimeEmployee object (ID 101, salary 65000)
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120); // creates PartTimeEmployee object (ID 102, 250/hr * 120 hrs = 30000)
    Intern i1(103, "Rohan", "Marketing", 15000);   // creates Intern object (ID 103, stipend 15000)

    cout << "=== Employee Payroll ===" << endl; // prints header text to screen

    f1.display();                            // displays Amit's details and monthly salary
    p1.display();                            // displays Sneha's details and calculated hourly salary
    i1.display();                            // displays Rohan's details and intern stipend
}