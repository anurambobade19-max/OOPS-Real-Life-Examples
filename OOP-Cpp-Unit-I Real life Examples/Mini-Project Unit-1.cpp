#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <vector>                            // <vector> = library for dynamic arrays (std::vector)
using namespace std;                         // using namespace std = allows using cout, string, vector directly without std:: prefix

// Base Class
class SmartDevice {                          // class = keyword to define a blueprint/type
                                             // SmartDevice = base class representing general smart home devices

protected:                                   // protected = access specifier (accessible in SmartDevice & derived classes)
    string deviceID;                         // string = text variable storing device ID (e.g., "L001")
    string location;                         // string = text variable storing location (e.g., "Living Room")
    string status;                           // string = text variable storing current power/lock state
    string lastUpdated;                      // string = text variable storing timestamp of last update

public:                                      // public = access specifier (accessible from anywhere)
    SmartDevice(string id, string loc) {     // SmartDevice = constructor function with parameters
        deviceID = id;                       // assigns parameter id to member variable deviceID
        location = loc;                      // assigns parameter loc to member variable location
        status = "OFF";                      // sets default status to "OFF"
        lastUpdated = "Not Updated";         // sets default update timestamp
    }

    virtual void switchOn() {                // virtual = enables method overriding in derived classes
                                             // switchOn = method to turn device ON
        status = "ON";                       // updates status variable to "ON"
        lastUpdated = "Just Now";            // updates timestamp to "Just Now"
    }

    virtual void switchOff() {               // virtual = enables method overriding in derived classes
                                             // switchOff = method to turn device OFF
        status = "OFF";                      // updates status variable to "OFF"
        lastUpdated = "Just Now";            // updates timestamp to "Just Now"
    }

    virtual void display() {                 // virtual = allows derived classes to customize display output
                                             // display = method to print base device details
        cout << "Device ID     : " << deviceID << endl;   // prints device ID
        cout << "Location      : " << location << endl;   // prints room location
        cout << "Status        : " << status << endl;     // prints current power/lock status
        cout << "Last Updated  : " << lastUpdated << endl; // prints timestamp of last state change
    }

    string getStatus() {                     // string = returns string value
                                             // getStatus = getter method returning device status
        return status;                       // returns private/protected status member
    }

    virtual ~SmartDevice() {}                // virtual = ensures proper destruction of derived objects via base pointers
                                             // ~SmartDevice() = default empty virtual destructor
};


// Light Device
class Light : public SmartDevice {           // Light = child class inheriting publicly from SmartDevice
                                             // : = inheritance operator
                                             // public SmartDevice = inherits base class public/protected members

public:                                      // public = accessible from outside the class
    Light(string id, string loc) : SmartDevice(id, loc) {} // constructor passing parameters directly to SmartDevice base constructor

    void switchOn() override {               // override = explicitly confirms this overrides SmartDevice::switchOn()
        status = "ON";                       // sets status to "ON"
        lastUpdated = "Just Now";            // updates timestamp to "Just Now"
    }

    void display() override {                // override = explicitly confirms this overrides SmartDevice::display()
        cout << "\n[LIGHT]" << endl;         // prints section header label for Light
        SmartDevice::display();              // reuses base class display() method to print common fields
    }
};


// Thermostat Device
class Thermostat : public SmartDevice {      // Thermostat = child class inheriting publicly from SmartDevice
                                             // : = inheritance operator
                                             // public SmartDevice = inherits base class public/protected members

private:                                     // private = accessible ONLY inside Thermostat class
    float temperature;                       // float = decimal variable storing target temperature in Celsius

public:                                      // public = accessible from outside the class
    Thermostat(string id, string loc, float temp) // constructor function accepting ID, location, and temperature
        : SmartDevice(id, loc) {             // passes id and loc to base SmartDevice constructor
        temperature = temp;                  // initializes temperature member variable
    }

    void setTemperature(float temp) {        // setTemperature = method to adjust thermostat temperature setting
        temperature = temp;                  // updates temperature variable with new value
        lastUpdated = "Just Now";            // updates timestamp to "Just Now"
    }

    void display() override {                // override = explicitly confirms this overrides SmartDevice::display()
        cout << "\n[THERMOSTAT]" << endl;    // prints section header label for Thermostat
        SmartDevice::display();              // reuses base class method to print ID, Location, Status, Timestamp
        cout << "Temperature   : " << temperature << " C" << endl; // prints specific temperature value in Celsius
    }
};


// Camera Device
class Camera : public SmartDevice {          // Camera = child class inheriting publicly from SmartDevice
                                             // : = inheritance operator
                                             // public SmartDevice = inherits base class public/protected members

public:                                      // public = accessible from outside the class
    Camera(string id, string loc) : SmartDevice(id, loc) {} // constructor passing parameters directly to SmartDevice base constructor

    void display() override {                // override = explicitly confirms this overrides SmartDevice::display()
        cout << "\n[CAMERA]" << endl;        // prints section header label for Camera
        SmartDevice::display();              // reuses base class display() method to print common fields
    }
};


// Door Lock Device
class DoorLock : public SmartDevice {        // DoorLock = child class inheriting publicly from SmartDevice
                                             // : = inheritance operator
                                             // public SmartDevice = inherits base class public/protected members

public:                                      // public = accessible from outside the class
    DoorLock(string id, string loc) : SmartDevice(id, loc) {} // constructor passing parameters directly to SmartDevice base constructor

    void switchOn() override {               // override = explicitly confirms custom behavior for locking
        status = "LOCKED";                   // sets status specifically to "LOCKED" instead of "ON"
        lastUpdated = "Just Now";            // updates timestamp to "Just Now"
    }

    void switchOff() override {              // override = explicitly confirms custom behavior for unlocking
        status = "UNLOCKED";                 // sets status specifically to "UNLOCKED" instead of "OFF"
        lastUpdated = "Just Now";            // updates timestamp to "Just Now"
    }

    void display() override {                // override = explicitly confirms this overrides SmartDevice::display()
        cout << "\n[DOOR LOCK]" << endl;     // prints section header label for Door Lock
        SmartDevice::display();              // reuses base class display() method to print common fields
    }
};


// Main Function
int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    Light livingLight("L001", "Living Room"); // instantiates Light object for Living Room
    Thermostat thermostat("T001", "Bedroom", 24.5); // instantiates Thermostat object set to 24.5°C
    Camera camera("C001", "Main Door");       // instantiates Camera object for Main Door
    DoorLock door("D001", "Main Entrance");   // instantiates DoorLock object for Main Entrance

    // Device Operations
    livingLight.switchOn();                  // turns living room light ON
    thermostat.switchOn();                   // turns thermostat ON
    thermostat.setTemperature(22.5);         // updates thermostat setting to 22.5°C
    camera.switchOn();                       // turns security camera ON
    door.switchOn();                         // locks the main entrance door

    // Home Dashboard
    cout << "========================================" << endl; // prints header line
    cout << "       SMART HOME DASHBOARD" << endl;             // prints dashboard title
    cout << "========================================" << endl; // prints header line

    livingLight.display();                   // prints status report for Light
    thermostat.display();                    // prints status report for Thermostat
    camera.display();                        // prints status report for Camera
    door.display();                          // prints status report for Door Lock

    cout << "\n========================================" << endl; // prints summary footer line

    return 0;                                // return 0 = signals to OS that program executed without errors
}