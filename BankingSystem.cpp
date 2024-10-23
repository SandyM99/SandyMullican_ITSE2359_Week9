#include "BankAccount.h"
#include <iostream>

using namespace std;

// Custom exception method implementations
const char* InsufficientFunds::what() const noexcept {
    return "Error: Insufficient funds for this withdrawal.";
}

const char* NegativeDeposit::what() const noexcept {
    return "Error: Deposit amount cannot be negative.";
}

// BankAccount constructor implementation
BankAccount::BankAccount(string accNo, double initialBalance)
    : accountNumber(accNo), balance(initialBalance) {}

// Method to withdraw an amount from the account
void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        throw InsufficientFunds(); // Throw exception if insufficient funds
    }
    balance -= amount;
    cout << "Successfully withdrew: $" << amount << endl;
}

// Method to deposit an amount into the account
void BankAccount::deposit(double amount) {
    if (amount < 0) {
        throw NegativeDeposit(); // Throw exception for negative deposit
    }
    balance += amount;
    cout << "Successfully deposited: $" << amount << endl;
}

// Method to get the current balance
double BankAccount::getBalance() const {
    return balance;
}

// Function to process withdrawal, demonstrating exception propagation
void processWithdrawal(BankAccount& account, double amount) {
    account.withdraw(amount);  // Exception may propagate from here
}

int main() {
    try {
        // Creating a BankAccount object with initial balance
        BankAccount myAccount("12345", 100.0);

        cout << "Initial balance: $" << myAccount.getBalance() << endl;

        // Perform a valid deposit
        myAccount.deposit(50); 
        cout << "New balance after deposit: $" << myAccount.getBalance() << endl;

        // Attempt to withdraw an amount greater than the balance
        processWithdrawal(myAccount, 200);  // This will throw InsufficientFunds

    } catch (const InsufficientFunds& e) {
        cout << e.what() << endl; // Handle InsufficientFunds exception
    } catch (const NegativeDeposit& e) {
        cout << e.what() << endl; // Handle NegativeDeposit exception
    } catch (...) {
        cout << "An unexpected error occurred." << endl; // Handle unexpected exceptions
    }

    cout << "Program completed." << endl; // Indicate completion
    return 0;
}

