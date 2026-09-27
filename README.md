# Object-Oriented Programming in C++

## Real-Life Examples – Unit I, Unit II & Unit III

---

### Student Information

| Field              | Details                                     |
| ------------------ | ------------------------------------------  |
| **Student Name**   | Anushka Ramchandra Bobade                   |
| **PRN**            | 125UAD1113                                  |
| **Class/Division** | S.Y B.Tech AIDS  / A                        |
| **Course Name**    | Object-Oriented Programming in C++          |
| **Units Covered**  | Unit - I- III                               |

---

# About the Repository

This repository contains **C++ programs based on real-life examples** to demonstrate the concepts of **Object-Oriented Programming (OOP)**.

The programs are organized into three units and cover fundamental as well as advanced OOP concepts such as:

* Classes and Objects
* Encapsulation
* Constructors and Destructors
* Inheritance
* Abstraction
* Polymorphism
* Function Overloading
* Function Overriding
* Operator Overloading
* Virtual Functions
* Pure Virtual Functions
* Runtime Polymorphism
* Static Members
* Smart Pointers

Each program represents a practical real-world scenario to make the concepts of C++ OOP easier to understand and implement.

---

# Unit I – OOP Fundamentals

## List of Programs

| Sr. No. | File Name                 | Program / Real-Life Example   |
| ------- | ------------------------- | ----------------------------- |
| 1       | `A.cpp`                   | Soil Sensor Monitoring System |
| 2       | `B.cpp`                   | Student Attendance System     |
| 3       | `C.cpp`                   | Product Inventory System      |
| 4       | `Mini-Project Unit-1.cpp` | Smart Home Dashboard          |

---

## 1. Soil Sensor Monitoring System – `A.cpp`

This program demonstrates a **soil sensor monitoring system** used in agriculture.

The `SoilSensor` class stores information such as the sensor ID, soil moisture level, and timestamp. Multiple sensor objects are created and their readings are displayed. The program also demonstrates updating the moisture reading of a sensor.

### OOP Concepts Used

* Class and Object
* Encapsulation
* Private and Public Members
* Constructor
* Member Functions
* Vector of Objects
* Range-Based Loop

### Real-Life Application

The program represents a basic agricultural monitoring system that can be used to track soil moisture conditions using multiple sensors.

---

## 2. Student Attendance System – `B.cpp`

This program demonstrates a **student attendance management system**.

The `Student` class stores the student's roll number, name, total number of classes, and attended classes. The program calculates and displays the attendance percentage.

### OOP Concepts Used

* Class and Object
* Encapsulation
* Constructor
* Private Data Members
* Member Functions
* Conditional Statements
* Data Calculation

### Real-Life Application

The program can be used as a basic model for managing student attendance in schools and colleges.

---

## 3. Product Inventory System – `C.cpp`

This program demonstrates a **product inventory management system**.

The `Product` class stores product ID, product name, price, and stock information. The program also uses a static data member to maintain the total number of products in the catalog.

### OOP Concepts Used

* Class and Object
* Constructor
* Encapsulation
* Static Data Member
* Static Member Function
* Inline Functions
* Destructor
* Member Functions

### Real-Life Application

The program represents a basic inventory system used to maintain product information and stock details.

---

## 4. Smart Home Dashboard – `Mini-Project Unit-1.cpp`

This mini-project demonstrates a **smart home automation system**.

The system contains different smart devices such as:

* Light
* Thermostat
* Camera
* Door Lock

`SmartDevice` acts as the base class, while the individual devices inherit from it and implement their own functionality.

### OOP Concepts Used

* Inheritance
* Polymorphism
* Virtual Functions
* Function Overriding
* Encapsulation
* Constructors
* Protected Members
* Base and Derived Classes
* Virtual Destructor

### Real-Life Application

The program represents a simplified smart home system where different devices can be controlled through a common object-oriented structure.

---

# Unit II – Inheritance and Polymorphism

## List of Programs

| Sr. No. | File Name                 | Program / Real-Life Example        |
| ------- | ------------------------- | ---------------------------------- |
| 1       | `1st.cpp`                 | Employee Payroll Management System |
| 2       | `2nd.cpp`                 | Online Payment Gateway             |
| 3       | `3rd.cpp`                 | Vehicle Fleet Management System    |
| 4       | `Mini-Project Unit-2.cpp` | Bank Account Management System     |

---

## 1. Employee Payroll Management System – `1st.cpp`

This program demonstrates an **employee payroll management system** using inheritance.

The base class `Employee` contains common employee information. Different employee categories are represented through derived classes:

* `FullTimeEmployee`
* `PartTimeEmployee`
* `Intern`

Each employee type has its own salary or stipend calculation.

### OOP Concepts Used

* Class and Object
* Inheritance
* Hierarchical Inheritance
* Function Overriding
* Virtual Functions
* Runtime Polymorphism
* Constructors
* Encapsulation

### Real-Life Application

The program represents how an organization can manage different types of employees and calculate their respective salaries or stipends.

---

## 2. Online Payment Gateway – `2nd.cpp`

This program demonstrates an **online payment gateway** supporting multiple payment methods.

The base class `PaymentMethod` provides a common interface, while the following classes implement specific payment methods:

* `CreditCardPayment`
* `UPIPayment`
* `NetBankingPayment`

Each payment method performs its own transaction operation.

### OOP Concepts Used

* Inheritance
* Runtime Polymorphism
* Virtual Functions
* Function Overriding
* Base and Derived Classes
* Encapsulation
* Smart Pointers
* Vector of Objects

### Real-Life Application

The program represents how online shopping and payment applications can support different payment methods through a common interface.

---

## 3. Vehicle Fleet Management System – `3rd.cpp`

This program demonstrates a **vehicle fleet management system**.

The base class `Vehicle` stores common vehicle information. Different types of vehicles are represented using derived classes:

* `Truck`
* `DeliveryVan`
* `Bike`

Each vehicle type displays its own specific information.

### OOP Concepts Used

* Inheritance
* Hierarchical Inheritance
* Runtime Polymorphism
* Virtual Functions
* Function Overriding
* Constructors
* Protected Members
* Smart Pointers
* `unique_ptr`
* Vector of Objects
* Virtual Destructor

### Real-Life Application

The program can be used as a basic model for transportation and logistics systems where different types of vehicles are managed under a single fleet.

---

## 4. Bank Account Management System – `Mini-Project Unit-2.cpp`

This mini-project demonstrates a **bank account management system**.

The base class `Account` stores common account information. Different account types are represented by:

* `SavingsAccount`
* `CurrentAccount`
* `FixedDepositAccount`

Each account type has its own rules for withdrawal and interest calculation.

### OOP Concepts Used

* Inheritance
* Hierarchical Inheritance
* Runtime Polymorphism
* Virtual Functions
* Function Overriding
* Encapsulation
* Constructors
* Protected Members
* Base and Derived Classes
* Virtual Destructor

### Real-Life Application

The program provides a simplified model of banking operations and demonstrates how different account types can share common functionality while implementing their own rules.

---

# Unit III – Advanced OOP Concepts

## List of Programs

| Sr. No. | File Name                 | Program / Real-Life Example |
| ------- | ------------------------- | --------------------------- |
| 1       | `1.cpp`                   | CAD Shape System            |
| 2       | `2.cpp`                   | Complex Number Calculator   |
| 3       | `3.cpp`                   | Data Validation System      |
| 4       | `Mini-Project Unit-3.cpp` | Media Player System         |

---

## 1. CAD Shape System – `1.cpp`

This program demonstrates a **Computer-Aided Design (CAD) shape system**.

The abstract base class `Shape` defines common operations such as calculating area and drawing a shape.

The derived classes include:

* `Circle`
* `Rectangle`
* `Triangle`

Each class provides its own implementation of the required functions.

### OOP Concepts Used

* Abstraction
* Abstract Class
* Pure Virtual Functions
* Inheritance
* Runtime Polymorphism
* Function Overriding
* Virtual Destructor
* Smart Pointers
* `unique_ptr`
* Vector of Objects

### Real-Life Application

The program represents how CAD or graphic-design software can manage different geometric shapes through a common interface.

---

## 2. Complex Number Calculator – `2.cpp`

This program demonstrates operations on **complex numbers** using operator overloading.

The `Complex` class contains real and imaginary parts and overloads operators to perform mathematical operations.

Supported operations include:

* Addition using `+`
* Subtraction using `-`
* Multiplication using `*`
* Comparison using `==`

### OOP Concepts Used

* Class and Object
* Encapsulation
* Constructor
* Operator Overloading
* Binary Operator Overloading
* Constant Member Functions

### Real-Life Application

Operator overloading allows complex-number calculations to be performed using natural mathematical expressions in C++.

---

## 3. Data Validation System – `3.cpp`

This program demonstrates a **data validation system** using function overloading.

The `Validator` class provides different versions of the `validate()` function for:

* Integer marks
* Decimal payment amount
* String name

The program checks whether the supplied data satisfies predefined validation rules.

### OOP Concepts Used

* Class and Object
* Function Overloading
* Compile-Time Polymorphism
* Encapsulation
* Member Functions
* Constant Member Functions
* String Handling

### Real-Life Application

Data validation is commonly used in educational systems, banking applications, registration forms, and payment systems.

---

## 4. Media Player System – `Mini-Project Unit-3.cpp`

This mini-project demonstrates a **media player system** using abstraction and runtime polymorphism.

The abstract base class `Media` defines common operations:

* Play
* Pause
* Stop
* Show Details

The derived classes include:

* `Audio`
* `Video`
* `Image`

Each media type provides its own implementation of these operations.

### OOP Concepts Used

* Abstract Class
* Pure Virtual Functions
* Inheritance
* Runtime Polymorphism
* Function Overriding
* Virtual Destructor
* Encapsulation
* Smart Pointers
* `unique_ptr`
* Vector of Objects

### Real-Life Application

The program represents the basic structure of a media player application capable of handling different types of media through a common interface.

---

# Technologies Used

* **Programming Language:** C++
* **Programming Paradigm:** Object-Oriented Programming
* **Compiler:** Any standard C++ compiler
* **File Extension:** `.cpp`
* **Libraries Used:** Standard C++ Libraries such as `<iostream>`, `<vector>`, `<memory>`, `<string>`, and `<cctype>`

---

# How to Run the Programs

## Using g++

Open a terminal in the folder containing the required `.cpp` file and compile it using:

```bash
g++ filename.cpp -o program
```

Run the program using:

```bash
./program
```

### Windows

For Windows systems:

```bash
g++ filename.cpp -o program.exe
program.exe
```

For example:

```bash
g++ A.cpp -o A.exe
A.exe
```

---

# Conclusion

This repository provides a collection of **real-life C++ programs covering Units I, II, and III of Object-Oriented Programming**.

The examples range from **soil monitoring, student attendance, inventory management, and smart homes** to **employee payroll, online payments, vehicle management, banking, CAD systems, complex-number calculations, data validation, and media players**.

Through these programs, important OOP concepts such as **encapsulation, inheritance, abstraction, polymorphism, function overloading, operator overloading, virtual functions, and smart pointers** are demonstrated using practical applications.

The repository therefore provides a structured and practical understanding of **Object-Oriented Programming in C++**.
