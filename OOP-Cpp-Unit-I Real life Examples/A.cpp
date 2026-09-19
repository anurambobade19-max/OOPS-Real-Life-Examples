#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like std::cout)

#include <string>                            // <string> = library for handling text data (std::string)
#include <vector>                            // <vector> = library for dynamic arrays (std::vector)
using namespace std;                         // using namespace std = allows using cout, string, vector directly without std:: prefix

class SoilSensor {                           // class = keyword to define a blueprint/type
                                             // SoilSensor = name of the class representing a physical soil sensor

private:                                     // private = access specifier (accessible ONLY inside SoilSensor class)
    string sensorId;                         // string = text variable storing unique sensor ID (e.g., "S001")
    double moistureLevel;                    // double = decimal variable storing soil moisture percentage
    string timestamp;                        // string = text variable storing reading timestamp (e.g., "08:00")

public:                                      // public = access specifier (accessible from anywhere)
    SoilSensor(string id, double moisture, string time) // constructor function to initialize SoilSensor objects
        : sensorId(id), moistureLevel(moisture), timestamp(time) {} // member initializer list sets variables directly

    void readSensor(double newMoisture, string newTime) { // void = function returns no value
                                             // readSensor = method to update current sensor reading data
                                             // newMoisture = parameter for updated moisture value
                                             // newTime = parameter for updated timestamp value

        moistureLevel = newMoisture;         // updates private moistureLevel variable with new reading
        timestamp = newTime;                 // updates private timestamp variable with new time
    }

    void displayData() const {               // displayData = method to print current sensor readings
                                             // const = promises not to modify any member variables inside this function
        cout << "Sensor: " << sensorId       // cout = prints sensor ID string to console
             << " | Moisture: " << moistureLevel << "%" // prints current moisture percentage
             << " | Time: " << timestamp << endl;      // prints timestamp and moves to next line (endl)
    }
};                                           // ; = ends SoilSensor class declaration

int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    vector<SoilSensor> farmSensors;          // vector<SoilSensor> = dynamic array storing SoilSensor objects
                                             // farmSensors = variable name for the collection of sensors

    farmSensors.emplace_back("S001", 45.2, "08:00"); // emplace_back = constructs SoilSensor #1 directly inside vector memory
    farmSensors.emplace_back("S002", 52.8, "08:00"); // constructs SoilSensor #2 directly inside vector memory
    farmSensors.emplace_back("S003", 38.5, "08:00"); // constructs SoilSensor #3 directly inside vector memory

    cout << "=== Morning Sensor Readings ===" << endl; // prints header text to screen

    for (const auto& sensor : farmSensors) {  // for = range-based loop over every sensor in vector
                                             // const auto& = read-only reference to avoid copying object memory
        sensor.displayData();                // calls displayData() method for each individual sensor object
    }

    farmSensors[0].readSensor(47.5, "09:00"); // farmSensors[0] = accesses first sensor ("S001")
                                             // readSensor(...) = updates its moisture to 47.5% and time to "09:00"

    cout << "\n=== Updated Reading ===" << endl; // prints header text for updated section

    farmSensors[0].displayData();            // displays updated reading data for the first sensor ("S001")
}