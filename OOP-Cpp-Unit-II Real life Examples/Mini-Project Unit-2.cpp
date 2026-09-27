#include <iostream>                          // #include = adds a library
                                             // <iostream> = library for standard input/output (like cout)

#include <string>                            // <string> = library for handling text data (std::string)
using namespace std;                         // using namespace std = allows using cout, string, endl directly without std:: prefix

// Base Class
class Account {                              // class = keyword to define a blueprint/type
                                             // Account = base class representing general bank accounts

protected:                                   // protected = access specifier (accessible in Account & derived classes)
    int accountNumber;                       // int = integer variable storing unique account number
    string holderName;                       // string = text variable storing account holder name
    double balance;                          // double = decimal variable storing current balance in rupees

public:                                      // public = access specifier (accessible from anywhere)
    Account(int accNo, string name, double bal) { // Account = constructor function
        accountNumber = accNo;               // assigns parameter accNo to member variable accountNumber
        holderName = name;                   // assigns parameter name to member variable holderName
        balance = bal;                       // assigns parameter bal to member variable balance
    }

    // Deposit money
    void deposit(double amount) {            // deposit = method to add money to the account
                                             // amount = parameter for money to deposit
        balance += amount;                   // increases balance variable by deposit amount
        cout << "Deposited: Rs. " << amount << endl; // prints deposit confirmation message
    }

    // Virtual withdrawal function
    virtual void withdraw(double amount) {    // virtual = enables method overriding in derived classes
                                             // amount = parameter for withdrawal amount
        if (amount <= balance) {             // checks if sufficient balance exists
            balance -= amount;               // subtracts withdrawal amount from balance
            cout << "Withdrawn: Rs. " << amount << endl; // prints withdrawal confirmation message
        } else {
            cout << "Insufficient balance!" << endl; // prints error message when funds are insufficient
        }
    }

    // Virtual interest calculation
    virtual void calculateInterest() {       // virtual = allows derived classes to override interest logic
        cout << "Interest calculation not defined." << endl; // default fallback message for base class
    }

    // Display account details
    virtual void display() {                 // virtual = enables customized display in derived classes
        cout << "\nAccount Number : " << accountNumber << endl; // prints account number
        cout << "Holder Name    : " << holderName << endl;    // prints account holder name
        cout << "Balance        : Rs. " << balance << endl;    // prints current account balance
    }

    virtual ~Account() {}                    // virtual = ensures proper destruction of derived objects via base pointers
                                             // ~Account() = default empty virtual destructor
};


// Savings Account
class SavingsAccount : public Account {      // SavingsAccount = child class inheriting publicly from Account
                                             // : = inheritance operator
                                             // public Account = inherits base class public/protected members

public:                                      // public = accessible from outside the class
    SavingsAccount(int accNo, string name, double bal) // constructor function
        : Account(accNo, name, bal) {}       // member initializer list passes arguments to base Account constructor

    void calculateInterest() override {      // override = explicitly confirms this overrides Account::calculateInterest()
        double interest = balance * 0.04;    // calculates 4% annual savings interest on current balance
        balance += interest;                 // adds calculated interest directly to account balance

        cout << "Savings Interest (4%): Rs. " // prints interest header
             << interest << endl;            // prints calculated interest amount
    }

    void display() override {                // override = explicitly confirms this overrides Account::display()
        cout << "\n===== SAVINGS ACCOUNT =====" << endl; // prints Savings Account header section
        Account::display();                  // reuses base class display() method to print ID, Name, and Balance
    }
};


// Current Account
class CurrentAccount : public Account {      // CurrentAccount = child class inheriting publicly from Account
                                             // : = inheritance operator
                                             // public Account = inherits base class public/protected members

public:                                      // public = accessible from outside the class
    CurrentAccount(int accNo, string name, double bal) // constructor function
        : Account(accNo, name, bal) {}       // member initializer list passes arguments to base Account constructor

    void withdraw(double amount) override {  // override = explicitly confirms custom withdrawal rules
        // Current account allows withdrawal with minimum balance
        if (balance - amount >= 1000) {      // checks if remaining balance stays at or above minimum threshold (Rs. 1000)
            balance -= amount;               // subtracts withdrawal amount from balance
            cout << "Withdrawn: Rs. " << amount << endl; // prints withdrawal confirmation
        } else {
            cout << "Withdrawal denied! Minimum balance " // prints denial error message
                 << "of Rs. 1000 required." << endl;     // states minimum balance restriction rule
        }
    }

    void calculateInterest() override {      // override = explicitly confirms this overrides Account::calculateInterest()
        cout << "Current Account: No interest provided." << endl; // current accounts do not earn interest
    }

    void display() override {                // override = explicitly confirms this overrides Account::display()
        cout << "\n===== CURRENT ACCOUNT =====" << endl; // prints Current Account header section
        Account::display();                  // reuses base class display() method to print ID, Name, and Balance
    }
};


// Fixed Deposit Account
class FixedDepositAccount : public Account { // FixedDepositAccount = child class inheriting publicly from Account
                                             // : = inheritance operator
                                             // public Account = inherits base class public/protected members

private:                                     // private = accessible ONLY inside FixedDepositAccount class
    int years;                               // int = integer variable storing deposit tenure in years

public:                                      // public = accessible from outside the class
    FixedDepositAccount(int accNo, string name, double bal, int y) // constructor function
        : Account(accNo, name, bal) {        // passes base arguments to Account constructor
        years = y;                           // initializes private years variable
    }

    void withdraw(double amount) override {  // override = explicitly overrides withdraw to block premature withdrawals
        cout << "Withdrawal not allowed before FD maturity." << endl; // prints rule blocking FD early withdrawal
    }

    void calculateInterest() override {      // override = explicitly confirms this overrides Account::calculateInterest()
        double interest = balance * 0.07 * years; // calculates simple interest at 7% per year for total duration
        balance += interest;                 // adds calculated interest to account balance

        cout << "FD Interest (7% for "       // prints interest header label
             << years << " years): Rs. "     // prints duration in years
             << interest << endl;            // prints calculated interest amount
    }

    void display() override {                // override = explicitly confirms this overrides Account::display()
        cout << "\n===== FIXED DEPOSIT ACCOUNT =====" << endl; // prints Fixed Deposit header section
        Account::display();                  // reuses base class display() method to print ID, Name, and Balance
        cout << "FD Duration   : " << years << " years" << endl; // prints FD duration details
    }
};


// Main Function
int main() {                                 // int = return type of main function
                                             // main() = mandatory entry point of execution for C++ programs

    SavingsAccount savings(101, "Anushka", 50000);  // instantiates SavingsAccount object (ID 101, Balance 50000)
    CurrentAccount current(102, "Rahul", 75000);    // instantiates CurrentAccount object (ID 102, Balance 75000)
    FixedDepositAccount fd(103, "Priya", 100000, 2); // instantiates FixedDepositAccount object (ID 103, Balance 100000, 2 Years)

    // Savings Account Operations
    savings.deposit(5000);                   // deposits Rs. 5000 (New balance = 55000)
    savings.withdraw(10000);                 // withdraws Rs. 10000 (New balance = 45000)
    savings.calculateInterest();             // adds 4% interest of Rs. 1800 (New balance = 46800)
    savings.display();                       // displays Anushka's savings account details

    // Current Account Operations
    current.deposit(10000);                  // deposits Rs. 10000 (New balance = 85000)
    current.withdraw(20000);                 // withdraws Rs. 20000 (New balance = 65000)
    current.calculateInterest();             // prints "No interest provided"
    current.display();                       // displays Rahul's current account details

    // Fixed Deposit Operations
    fd.deposit(10000);                       // deposits Rs. 10000 (New balance = 110000)
    fd.withdraw(5000);                       // attempts withdrawal (denied due to FD maturity lock)
    fd.calculateInterest();             // adds 7% * 2 years interest of Rs. 15400 (New balance = 125400)
    fd.display();                            // displays Priya's FD account details

    return 0;                                // return 0 = signals to OS that program finished without errors
}