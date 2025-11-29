#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

//namespaces
using namespace chrono;
using namespace std;

class TransactionNode {
    bool type;
    double amount;
    string time;
    TransactionNode* next;
public:
    TransactionNode(bool type, double amount) :type(type), amount(amount), next(nullptr) {
        auto now = system_clock::now();                         // Get current time as time_point
        time_t t = system_clock::to_time_t(now);                // Convert to time_t (seconds since 1970)
        tm tm;                                                  // Convert to local calendar time
        localtime_s(&tm, &t);
        stringstream ss;                                        // ss is very similar to txt file
        ss << put_time(&tm, "%d-%m-%Y | %H:%M");              // put_time is stored to ss
        time = ss.str();                                        // save text in time (string object)
    }

    bool   getType()    const { return type; }
    double getAmount()  const { return amount; }
    string getTime()    const { return time; }
    TransactionNode* getNext() const { return next; }

    void setType(bool t) { type = t; }
    void setAmount(double b) { amount = b; }
    void setTime(const string& t) { time = t; }
    void setNext(TransactionNode* n) { next = n; }

    void display() const {
        cout << " | " << getTime() << " | ";
        if (getType())cout << " Deposited ";
        else          cout << " Withdrawn ";
        cout << getAmount() << " sums" << endl;
    }
};

//singular linear linked list
class TransactionHistory {
    int count;
    TransactionNode* head;
public:
    TransactionHistory() :count(0), head(nullptr) {}

    void add(bool type, double amount) {
        TransactionNode* temp = new TransactionNode(type, amount);
        temp->setNext(head);
        head = temp;
        count++;
    }

    void displayHistory() {
        TransactionNode* curr = head;
        while (curr) {
            curr->display();
            curr = curr->getNext();
        }
    }

    TransactionNode* getMostRecentTransaction() const { return head; }

    int getTransactionCount() const {
        return count;
    }

    ~TransactionHistory() {
        TransactionNode* curr = head;
        while (curr) {
            TransactionNode* next = curr->getNext();
            delete curr;
            curr = next;
        }
    }
};