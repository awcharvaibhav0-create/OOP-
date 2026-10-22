
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative.");
        }

        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }

        balance += amount;
        cout << "Deposit successful!" << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }

        if (amount > balance) {
            throw runtime_error("Insufficient account balance.");
        }

        balance -= amount;
        cout << "Withdrawal successful!" << endl;
    }

    void displayBalance() const {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Available Balance: Rs. " << balance << endl;
    }
};

int main() {
    string name;
    double initialBalance, amount;
    int choice;

    cout << "===== BANK ACCOUNT SYSTEM =====" << endl;

    cout << "Enter account holder name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Error: Name cannot be empty." << endl;
        return 1;
    }

    cout << "Enter initial balance: Rs. ";
    if (!(cin >> initialBalance)) {
        cout << "Error: Invalid balance input." << endl;
        return 1;
    }

    try {
        BankAccount account(name, initialBalance);

        do {
            cout << "\n===== MENU =====" << endl;
            cout << "1. Deposit Money" << endl;
            cout << "2. Withdraw Money" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                throw runtime_error("Invalid menu input.");
            }

            try {
                switch (choice) {
                    case 1:
                        cout << "Enter deposit amount: Rs. ";
                        if (!(cin >> amount)) {
                            throw runtime_error("Invalid amount input.");
                        }

                        account.deposit(amount);
                        account.displayBalance();
                        break;

                    case 2:
                        cout << "Enter withdrawal amount: Rs. ";
                        if (!(cin >> amount)) {
                            throw runtime_error("Invalid amount input.");
                        }

                        account.withdraw(amount);
                        account.displayBalance();
                        break;

                    case 3:
                        account.displayBalance();
                        break;

                    case 4:
                        cout << "Thank you for using our banking system." << endl;
                        break;

                    default:
                        cout << "Invalid choice! Select 1 to 4." << endl;
                }
            }
            catch (const exception& e) {
                cout << "Transaction failed: " << e.what() << endl;
            }

        } while (choice != 4);
    }
    catch (const exception& e) {
        cout << "Account creation failed: " << e.what() << endl;
        return 1;
    }

    return 0;
}