#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <memory>                            // <memory> = library for smart pointers (std::unique_ptr, std::make_unique)
#include <string>                            // <string> = library for handling text data (std::string)
#include <vector>                            // <vector> = library for dynamic arrays (std::vector)
using namespace std;                         // using namespace std = allows using cout, string, vector directly without std:: prefix

class Vehicle {                              // class = keyword to define a blueprint/type
                                             // Vehicle = base class representing general vehicles

protected:                                   // protected = access specifier (accessible in Vehicle & derived classes)
    string vehicleId;                        // string = text variable storing vehicle ID (e.g., "V001")
    string registrationNumber;               // string = text variable storing license plate number
    double fuelLevel;                        // double = decimal variable storing fuel percentage (0.0 to 100.0)

public:                                      // public = access specifier (accessible from anywhere)
    Vehicle(string vid, string reg)          // Vehicle = constructor function
                                             // vid = parameter for vehicle ID
                                             // reg = parameter for registration number
        : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {} // initializes members and sets fuel to 100.0%

    void startEngine() const {               // void = function returns no value
                                             // startEngine = non-virtual function to print engine status
                                             // const = guarantees function won't modify object state
        cout << "Vehicle " << vehicleId << " engine started." << endl; // prints engine start message
    }

    void refuel(double amount) {             // refuel = method to add fuel
                                             // amount = parameter specifying fuel percentage to add
        fuelLevel += amount;                 // increases fuel level by amount
        if (fuelLevel > 100.0) {             // checks if fuel exceeds maximum capacity of 100.0%
            fuelLevel = 100.0;               // caps fuel level at 100.0%
        }
    }

    virtual void displayInfo() const {       // virtual = enables method overriding in derived classes
                                             // displayInfo = method printing base vehicle details
                                             // const = guarantees function won't modify object state
        cout << "Vehicle ID: " << vehicleId   // prints vehicle ID
             << " | Registration: " << registrationNumber // prints registration number
             << " | Fuel: " << fuelLevel << "%" << endl; // prints fuel percentage
    }

    virtual ~Vehicle() = default;            // virtual = ensures proper destruction when deleting derived objects via base pointers
                                             // ~Vehicle() = base destructor
                                             // = default; = generates standard default destructor
};                                           // ; = ends Vehicle base class declaration

class Truck : public Vehicle {               // Truck = child class inheriting publicly from Vehicle
                                             // : = inheritance operator
                                             // public Vehicle = inherits base class public/protected members

private:                                     // private = accessible ONLY inside Truck class
    double cargoCapacity;                    // double = decimal variable storing cargo limit in tonnes

public:                                      // public = accessible from outside the class
    Truck(string vid, string reg, double capacity) // constructor function
                                             // vid = parameter for ID
                                             // reg = parameter for registration
                                             // capacity = parameter for cargo capacity
        : Vehicle(vid, reg), cargoCapacity(capacity) {} // passes base arguments & sets cargoCapacity

    void displayInfo() const override {      // override = explicitly confirms this overrides Vehicle::displayInfo()
                                             // const = matches virtual function signature in base class
        cout << "Truck | ";                  // prints vehicle category prefix
        Vehicle::displayInfo();              // calls base class method to print ID, Registration, and Fuel
        cout << "Cargo capacity: " << cargoCapacity << " tonnes" << endl; // prints cargo capacity detail
    }
};                                           // ; = ends Truck class declaration

class DeliveryVan : public Vehicle {         // DeliveryVan = child class inheriting publicly from Vehicle
                                             // : = inheritance operator
                                             // public Vehicle = inherits base class public/protected members

private:                                     // private = accessible ONLY inside DeliveryVan class
    int packageCount;                        // int = integer variable storing number of loaded packages

public:                                      // public = accessible from outside the class
    DeliveryVan(string vid, string reg, int packages) // constructor function
                                             // vid = parameter for ID
                                             // reg = parameter for registration
                                             // packages = parameter for package count
        : Vehicle(vid, reg), packageCount(packages) {} // passes base arguments & sets packageCount

    void displayInfo() const override {      // override = explicitly confirms this overrides Vehicle::displayInfo()
                                             // const = matches virtual function signature
        cout << "Delivery Van | ";           // prints vehicle category prefix
        Vehicle::displayInfo();              // reuses base class method to print common vehicle information
        cout << "Packages loaded: " << packageCount << endl; // prints number of loaded packages
    }
};                                           // ; = ends DeliveryVan class declaration

class Bike : public Vehicle {                // Bike = child class inheriting publicly from Vehicle
                                             // : = inheritance operator
                                             // public Vehicle = inherits base class public/protected members

private:                                     // private = accessible ONLY inside Bike class
    bool hasDeliveryBox;                     // bool = boolean variable indicating if delivery box is attached

public:                                      // public = accessible from outside the class
    Bike(string vid, string reg, bool hasBox) // constructor function
                                             // vid = parameter for ID
                                             // reg = parameter for registration
                                             // hasBox = parameter for delivery box flag
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {} // passes base arguments & sets hasDeliveryBox

    void displayInfo() const override {      // override = explicitly confirms this overrides Vehicle::displayInfo()
                                             // const = matches virtual function signature
        cout << "Delivery Bike | ";          // prints vehicle category prefix
        Vehicle::displayInfo();              // reuses base class method to print common vehicle information
        cout << "Delivery box: " << (hasDeliveryBox ? "Available" : "Not available") << endl; // ternary operator prints availability string
    }
};                                           // ; = ends Bike class declaration

int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    vector<unique_ptr<Vehicle>> fleet;       // vector = dynamic array storing smart pointers (unique_ptr) to base Vehicle

    fleet.push_back(make_unique<Truck>("V001", "MH12-AB-1234", 10.5)); // make_unique = dynamically creates Truck
                                             // push_back = adds unique_ptr to vector

    fleet.push_back(make_unique<DeliveryVan>("V002", "MH12-CD-5678", 50)); // dynamically creates and adds DeliveryVan object

    fleet.push_back(make_unique<Bike>("V003", "MH12-EF-9012", true)); // dynamically creates and adds Bike object

    cout << "=== Fleet Status ===" << endl;   // prints report header text to screen

    for (const auto& vehicle : fleet) {       // for = range-based loop iterating over every smart pointer in vector
                                             // const auto& = read-only reference to unique_ptr to prevent copying
        vehicle->startEngine();              // calls non-virtual startEngine() via pointer
        vehicle->displayInfo();              // polymorphically calls overridden displayInfo() for each specific vehicle
        cout << endl;                        // prints blank line for visual separation
    }
}