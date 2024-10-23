#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <exception>
#include <string>

// Custom exception classes
class InsufficientFunds : public std::exception {
public:
    const char* what() const noexcept override;
};

class NegativeDeposit : public std::exception {
public:
    const char* what() const noexcept override;
};

class BankAccount {
private:
    double balance;               // Current account balance
    std::string accountNumber;    // Account number

public:
    // Constructor to initialize account number and balance
    BankAccount(std::string accNo, double initialBalance);

    // Method to withdraw an amount from the account
    void withdraw(double amount);

    // Method to deposit an amount into the account
    void deposit(double amount);

    // Method to get the current balance
    double getBalance() const;
};

#endif // BANKACCOUNT_H
