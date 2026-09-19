#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <memory>                            // <memory> = library for smart pointers (std::unique_ptr, std::make_unique)
#include <string>                            // <string> = library for handling text data (std::string)
#include <vector>                            // <vector> = library for dynamic arrays (std::vector)
using namespace std;                         // using namespace std = allows using cout, string, vector directly without std:: prefix

class PaymentMethod {                        // class = keyword to define a blueprint/type
                                             // PaymentMethod = abstract base class (cannot be instantiated directly)

protected:                                   // protected = access specifier (accessible in PaymentMethod & derived classes)
    string transactionId;                    // string = text variable storing unique transaction ID (e.g., "TXN001")
    double amount;                           // double = decimal variable storing payment amount in rupees

public:                                      // public = access specifier (accessible from anywhere)
    PaymentMethod(string tid, double amt)    // PaymentMethod = constructor function
                                             // tid = parameter for transaction ID
                                             // amt = parameter for payment amount
        : transactionId(tid), amount(amt) {} // member initializer list sets member variables directly

    virtual bool processPayment() const = 0; // virtual = enables runtime polymorphism
                                             // bool = function returns true or false (success/failure)
                                             // const = promises not to modify any member variables
                                             // = 0; = pure virtual function (makes PaymentMethod an abstract class)

    virtual ~PaymentMethod() = default;      // virtual = ensures proper destruction when deleting derived objects via base pointers
                                             // ~PaymentMethod() = base destructor
                                             // = default; = generates standard default destructor
};                                           // ; = ends PaymentMethod abstract base class declaration

class CreditCardPayment : public PaymentMethod { // CreditCardPayment = child class inheriting publicly from PaymentMethod
                                             // : = inheritance operator
                                             // public PaymentMethod = inherits base class public/protected members

private:                                     // private = accessible ONLY inside CreditCardPayment class
    string maskedCardNumber;                 // string = text variable storing masked credit card number (e.g., "XXXX-1234")

public:                                      // public = accessible from outside the class
    CreditCardPayment(string tid, double amt, string card) // constructor function
                                             // tid = parameter for transaction ID
                                             // amt = parameter for amount
                                             // card = parameter for card number
        : PaymentMethod(tid, amt), maskedCardNumber(card) {} // passes base arguments & initializes maskedCardNumber

    bool processPayment() const override {   // override = explicitly confirms this implements PaymentMethod::processPayment()
                                             // const = matches pure virtual function signature in base class
        cout << "Credit-card transaction " << transactionId // prints transaction ID
             << " for Rs. " << amount        // prints payment amount
             << " using " << maskedCardNumber << " completed." << endl; // prints card details and completion status
        return true;                         // returns true indicating payment processed successfully
    }
};                                           // ; = ends CreditCardPayment class declaration

class UPIPayment : public PaymentMethod {    // UPIPayment = child class inheriting publicly from PaymentMethod
                                             // : = inheritance operator
                                             // public PaymentMethod = inherits base class public/protected members

private:                                     // private = accessible ONLY inside UPIPayment class
    string upiId;                            // string = text variable storing UPI address (e.g., "student@upi")

public:                                      // public = accessible from outside the class
    UPIPayment(string tid, double amt, string upi) // constructor function
                                             // tid = parameter for transaction ID
                                             // amt = parameter for amount
                                             // upi = parameter for UPI ID
        : PaymentMethod(tid, amt), upiId(upi) {} // passes base arguments & initializes upiId

    bool processPayment() const override {   // override = explicitly confirms this implements PaymentMethod::processPayment()
                                             // const = matches virtual function signature
        cout << "UPI transaction " << transactionId // prints transaction ID
             << " for Rs. " << amount        // prints payment amount
             << " from " << upiId << " completed." << endl; // prints UPI handle and completion status
        return true;                         // returns true indicating payment processed successfully
    }
};                                           // ; = ends UPIPayment class declaration

class NetBankingPayment : public PaymentMethod { // NetBankingPayment = child class inheriting publicly from PaymentMethod
                                             // : = inheritance operator
                                             // public PaymentMethod = inherits base class public/protected members

private:                                     // private = accessible ONLY inside NetBankingPayment class
    string bankName;                         // string = text variable storing bank name (e.g., "Example Bank")

public:                                      // public = accessible from outside the class
    NetBankingPayment(string tid, double amt, string bank) // constructor function
                                             // tid = parameter for transaction ID
                                             // amt = parameter for amount
                                             // bank = parameter for bank name
        : PaymentMethod(tid, amt), bankName(bank) {} // passes base arguments & initializes bankName

    bool processPayment() const override {   // override = explicitly confirms this implements PaymentMethod::processPayment()
                                             // const = matches virtual function signature
        cout << "Net-banking transaction " << transactionId // prints transaction ID
             << " for Rs. " << amount        // prints payment amount
             << " through " << bankName << " completed." << endl; // prints bank name and completion status
        return true;                         // returns true indicating payment processed successfully
    }
};                                           // ; = ends NetBankingPayment class declaration

int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    vector<unique_ptr<PaymentMethod>> payments; // vector = dynamic array storing smart pointers (unique_ptr) to base PaymentMethod

    payments.push_back(make_unique<CreditCardPayment>("TXN001", 2500, "XXXX-XXXX-1234")); // make_unique = dynamically creates CreditCardPayment
                                             // push_back = adds unique_ptr to vector

    payments.push_back(make_unique<UPIPayment>("TXN002", 1200, "student@upi")); // dynamically creates and adds UPIPayment object

    payments.push_back(make_unique<NetBankingPayment>("TXN003", 5000, "Example Bank")); // dynamically creates and adds NetBankingPayment object

    cout << "=== Payment Gateway ===" << endl; // prints header text to screen

    for (const auto& payment : payments) {    // for = range-based loop iterating over every smart pointer in vector
                                             // const auto& = read-only reference to unique_ptr to prevent copying
        payment->processPayment();           // -> operator dereferences smart pointer to polymorphically call processPayment()
    }

    return 0;                                // return 0 = signals to OS that program finished without errors
}