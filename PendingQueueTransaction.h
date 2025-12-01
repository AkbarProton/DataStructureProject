#pragma once
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

//node in Pending Queue
/*Add constructors and accessors/mutators too! */
class PendingQueueTransaction {
private:
    string AccountNumber;
    string type;
    double amount;
    PendingQueueTransaction* next;
    steady_clock::time_point timestamp;
public:
    //Default Constructor
    PendingQueueTransaction()
        : AccountNumber(""), type(""), amount(0.0), next(nullptr) {
        timestamp = steady_clock::now();
    }

    //Parametrized Constructor
    PendingQueueTransaction(string accountNumber, string type, double amount)
        : AccountNumber(accountNumber), type(type), amount(amount), next(nullptr) {
        timestamp = steady_clock::now();
    }

    //accessors
    string getAccountNumber()  const { return this->AccountNumber; }
    string getType()           const { return this->type; }
    double getAmount()         const { return this->amount; }
    PendingQueueTransaction* getNext() const { return next; }

    steady_clock::time_point getTimestamp() const {
        return timestamp;
    }

    //mutators
    void setAccountNumber(string& num)  { this->AccountNumber = num; }
    void setType(string& type)          { this->type = type; }
    void setAmount(double amount)       { this->amount = amount; }
    void setNext(PendingQueueTransaction* nxt) { next = nxt; }

};