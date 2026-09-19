#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <string>                            // <string> = library for handling text data (std::string)
using namespace std;                         // using namespace std = allows using cout, string, endl directly without std:: prefix

class Student {                              // class = keyword to define a blueprint/type
                                             // Student = name of the class tracking student attendance

private:                                     // private = access specifier (accessible ONLY inside Student class)
    int rollNo;                              // int = integer variable storing roll number
    string name;                             // string = text variable storing student's name
    int totalDays;                           // int = integer variable tracking total classes held
    int presentDays;                         // int = integer variable tracking classes attended

public:                                      // public = access specifier (accessible from anywhere)
    Student(int r, string n)                 // Student = constructor function
                                             // r = parameter for roll number
                                             // n = parameter for student name
        : rollNo(r), name(n), totalDays(0), presentDays(0) {} // initializes rollNo & name, sets totalDays & presentDays to 0

    void markAttendance(bool isPresent) {     // void = function returns no value
                                             // markAttendance = function to update attendance count
                                             // isPresent = boolean parameter (true = present, false = absent)

        totalDays++;                         // totalDays++ = increments total class count by 1
        if (isPresent) {                     // if = checks if student was marked present
            presentDays++;                   // presentDays++ = increments attended class count by 1
        }
    }

    double getAttendancePercentage() const { // double = function returns floating-point percentage
                                             // getAttendancePercentage = function calculating attendance rate
                                             // const = promises not to modify any member variables

        if (totalDays == 0) {                // prevents division by zero if no classes have occurred
            return 0.0;                      // returns 0.0% if totalDays is zero
        }
        return (presentDays * 100.0) / totalDays; // calculates percentage (e.g., (2 * 100.0) / 3 = 66.6667%)
    }

    void display() const {                   // void = function returns no value
                                             // display = method to print summary details
                                             // const = guarantees function won't modify class members

        cout << "Roll: " << rollNo           // prints student roll number
             << " | Name: " << name          // prints student name
             << " | Attendance: " << getAttendancePercentage() << "%" << endl; // calls percentage function and prints result
    }
};                                           // ; = ends Student class declaration

int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    Student s1(101, "Rahul");                // creates s1 object with roll 101, name "Rahul", and 0 days
    Student s2(102, "Priya");                // creates s2 object with roll 102, name "Priya", and 0 days

    s1.markAttendance(true);                 // Day 1: Rahul is present (present: 1, total: 1)
    s1.markAttendance(true);                 // Day 2: Rahul is present (present: 2, total: 2)
    s1.markAttendance(false);                // Day 3: Rahul is absent  (present: 2, total: 3)

    s2.markAttendance(true);                 // Day 1: Priya is present (present: 1, total: 1)
    s2.markAttendance(true);                 // Day 2: Priya is present (present: 2, total: 2)
    s2.markAttendance(true);                 // Day 3: Priya is present (present: 3, total: 3)

    cout << "=== Attendance Report ===" << endl; // prints report header text

    s1.display();                            // displays Rahul's report: 2/3 present = 66.6667%
    s2.display();                            // displays Priya's report: 3/3 present = 100%
}