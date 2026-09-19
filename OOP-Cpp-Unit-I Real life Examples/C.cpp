#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <string>                            // <string> = library for handling text data (std::string)
using namespace std;                         // using namespace std = allows using cout, string, endl directly without std:: prefix

class Product {                              // class = keyword to define a blueprint/type
                                             // Product = name of the class representing an inventory item

private:                                     // private = access specifier (accessible ONLY inside Product class)
    int productId;                           // int = integer variable storing unique product ID
    string productName;                      // string = text variable storing product name
    double price;                            // double = decimal variable storing price
    int stockQuantity;                       // int = integer variable storing available stock quantity
    static int totalProducts;                // static = shared variable across ALL instances of Product class

public:                                      // public = access specifier (accessible from anywhere)
    Product(int id, string name, double p, int stock) // constructor function to create Product objects
        : productId(id), productName(name), price(p), stockQuantity(stock) { // member initializer list sets member variables directly
        totalProducts++;                     // increments shared totalProducts count whenever a new object is created
    }

    inline int getId() const { return productId; } // inline = requests compiler to replace function calls with function body for performance
                                             // getId() = getter function returning productId
                                             // const = promises not to modify any member variables

    inline string getName() const { return productName; } // getter function returning productName (inline)

    inline double getPrice() const { return price; } // getter function returning price (inline)

    void updateStock(int quantity) {         // void = function returns no value
                                             // updateStock = method to update current stock quantity
                                             // quantity = parameter with new stock value
        stockQuantity = quantity;            // updates private stockQuantity variable
    }

    static int getTotalProducts() {          // static = method that can be called without creating an object instance
        return totalProducts;                // returns total number of currently active Product objects
    }

    void display() const {                   // display = method to print product details
                                             // const = guarantees function won't modify class members
        cout << "ID: " << productId          // prints product ID
             << " | Product: " << productName // prints product name
             << " | Price: Rs. " << price    // prints price with currency label
             << " | Stock: " << stockQuantity << endl; // prints remaining stock and moves to next line (endl)
    }

    ~Product() {                             // ~Product() = destructor function (runs automatically when object is destroyed)
        totalProducts--;                     // decrements shared count when an object goes out of scope or is deleted
    }
};                                           // ; = ends Product class declaration

int Product::totalProducts = 0;              // allocates memory and initializes static member totalProducts to 0 outside class

int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    Product p1(1001, "Laptop", 55000, 15);   // creates 1st Product object p1 (totalProducts becomes 1)
    Product p2(1002, "Mouse", 450, 50);      // creates 2nd Product object p2 (totalProducts becomes 2)
    Product p3(1003, "Keyboard", 1200, 30);  // creates 3rd Product object p3 (totalProducts becomes 3)

    cout << "=== Product Catalog ===" << endl; // prints header text to screen

    p1.display();                            // displays details for p1
    p2.display();                            // displays details for p2
    p3.display();                            // displays details for p3

    cout << "\nTotal Products in Catalog: "   // prints summary header text
         << Product::getTotalProducts() << endl; // calls static method Product::getTotalProducts() (returns 3)
}