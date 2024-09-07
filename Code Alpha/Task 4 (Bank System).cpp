#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
private:
    int customer_id;
    string name;
    string address;
    string phone_number;
    string email;

public:
    Customer(int id, string n, string addr, string phone, string em) {
        customer_id = id;
        name = n;
        address = addr;
        phone_number = phone;
        email = em;
    }

    int get_customer_id() {
        return customer_id;
    }

    string get_customer_info() {
        return "Customer ID: " + to_string(customer_id) + ", Name: " + name + ", Address: " + address + ", Phone Number: " + phone_number + ", Email: " + email;
    }
};

class Account {
private:
    int account_id;
    int customer_id;
    string account_type;
    double balance;
    vector<string> transactions;

public:
    Account(int id, int cust_id, string type, double bal) {
        account_id = id;
        customer_id = cust_id;
        account_type = type;
        balance = bal;
    }

    int get_account_id() {
        return account_id;
    }

    string get_account_info() {
        return "Account ID: " + to_string(account_id) + ", Customer ID: " + to_string(customer_id) + ", Account Type: " + account_type + ", Balance: " + to_string(balance);
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back("Deposit: " + to_string(amount));
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back("Withdrawal: " + to_string(amount));
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void transfer(Account& recipient, double amount) {
        if (balance >= amount) {
            balance -= amount;
            recipient.deposit(amount);
            transactions.push_back("Transfer: " + to_string(amount) + " to Account " + to_string(recipient.get_account_id()));
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    vector<string> get_transactions() {
        return transactions;
    }
};

class BankingService {
public:
    void perform_withdrawal(Account& account, double amount) {
        account.withdraw(amount);
    }

    void perform_deposit(Account& account, double amount) {
        account.deposit(amount);
    }

    void perform_transfer(Account& sender, Account& recipient, double amount) {
        sender.transfer(recipient, amount);
    }

    void get_account_balance(Account& account) {
        cout << "Account Balance: " << account.get_account_info() << endl;
    }

    void get_recent_transactions(Account& account) {
        vector<string> transactions = account.get_transactions();
        cout << "Recent Transactions:" << endl;
        for (string transaction : transactions) {
            cout << transaction << endl;
        }
    }
};

int main() {
    Customer customer1(1, "Juzer Abdul Ali", "123 Main St", "0335-3733053", "juzerabdulali@gamil.com");
    Customer customer2(2, "Sakina Mustafa", "456 Elm St", "0331-3441309", "sakinamustafa@gmail.com");

    Account account1(1, customer1.get_customer_id(), "checking", 1000.0);
    Account account2(2, customer2.get_customer_id(), "savings", 500.0);

    BankingService service;

    service.perform_deposit(account1, 500.0);
    service.perform_withdrawal(account1, 200.0);
    service.perform_transfer(account1, account2, 300.0);

    service.get_account_balance(account1);
    service.get_recent_transactions(account1);
    
    cout << endl; 

    service.get_account_balance(account2);
    service.get_recent_transactions(account2);

    return 0;
}