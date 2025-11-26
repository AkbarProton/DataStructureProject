#pragma once

#include <string>
#include <chrono>

using namespace std;
//node in Pending Queue
/*Add constructors and accessors/mutators too! */
class PendingQueueTransaction {
private:
    string AccountNumber;
    string type;
    double amount;
    PendingQueueTransaction* next;
    std::chrono::steady_clock::time_point timestamp;
public:
    //Default Constructor
    PendingQueueTransaction()
        : AccountNumber(""), type(""), amount(0.0), next(nullptr) {
        timestamp = std::chrono::steady_clock::now();
    }

    //Parametrized Constructor
    PendingQueueTransaction(string accountNumber, string type, double amount)
        : AccountNumber(accountNumber), type(type), amount(amount), next(nullptr) {
        timestamp = std::chrono::steady_clock::now();
    }

    //accessors
    string getAccountNumber() { return this->AccountNumber; }
    string getType() { return this->type; }
    double getAmount() { return this->amount; }
    PendingQueueTransaction* getNext() const { return next; }


    //mutators
    void setAccountNumber(string num) { this->AccountNumber = num; }
    void setType(string type) { this->type = type; }
    void setAmount(double amount) { this->amount = amount; }
    void setNext(PendingQueueTransaction* nxt) { next = nxt; }

};