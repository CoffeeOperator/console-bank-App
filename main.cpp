#include <iostream>
#include <string>
using namespace std;

// BankAccount class to store and manage account details
class BankAccount {
private:
    string accountHolder;    // Name of the account holder
    string accountNumber;    // Account number
    double balance;          // Account balance

public:
    // Constructor to initialize account details
    BankAccount(string holder, string number, double initialBalance) {
        accountHolder = holder;  // Set account holder's name
        accountNumber = number;  // Set account number
        balance = initialBalance; // Set initial balance
    }

    // Function to display account details
    void displayAccountDetails() const {
        cout << "\n--- Account Details ---\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "-------------------------\n";
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;  // Increase the balance by the deposit amount
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid amount. Deposit failed." << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;  // Decrease the balance by the withdrawal amount
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            cout << "Invalid amount. Withdrawal failed." << endl;
        }
    }
};

// Function to display the menu and handle user input
void displayMenu() {
    cout << "\n--- Bank Menu ---\n";
    cout << "1. View Account Details\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

int main() {
    // Variables to store user input for account details
    string name, accNumber;
    double initialDeposit;

    // Gather account holder's name, account number, and initial deposit amount
    cout << "Enter account holder name: ";
    getline(cin, name);  // Get the full name
    cout << "Enter account number: ";
    cin >> accNumber;

    // Input validation for initial deposit
    do {
        cout << "Enter initial deposit amount (must be positive): $";
        cin >> initialDeposit;
        if (initialDeposit <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
        }
    } while (initialDeposit <= 0);

    // Create a new bank account using the user's input
    BankAccount userAccount(name, accNumber, initialDeposit);

    int choice;     // Variable to store the menu choice
    double amount;  // Variable to store deposit or withdrawal amount

    // Main loop for the bank menu
    do {
        displayMenu();  // Display the menu
        cin >> choice;  // Get the user's choice

        // Perform action based on user choice
        switch (choice) {
            case 1:
                userAccount.displayAccountDetails();  // Display account details
                break;
            case 2:
                cout << "Enter deposit amount (must be positive): $";
                cin >> amount;
                userAccount.deposit(amount);  // Deposit money
                break;
            case 3:
                cout << "Enter withdrawal amount (must be positive): $";
                cin >> amount;
                userAccount.withdraw(amount);  // Withdraw money
                break;
            case 4:
                cout << "Thank you for banking with us!\n";  // Exit the program
                break;
            default:
                cout << "Invalid option! Please try again.\n";  // Handle invalid input
        }
    } while (choice != 4);  // Continue until the user chooses to exit

    return 0;
}
