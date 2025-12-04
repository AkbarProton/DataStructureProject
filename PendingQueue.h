#pragma once
#include "PendingQueueTransaction.h"
#include "BankTree.h"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace chrono;

//Pending Queue specifies queues when limit of transactions at a time are reached

//This can be approached if the time limit was set to add the transaction to transaction history. 
// For example if the delay of several minutes between transactioin is added, 
// other transactions must be added to queue and then only retrieved from it and added to transaction history


//Node from queue ( PendingQueueTransaction ) saves data about transaction's type, amount of transaction, and account nubmer to which transaction is applied

//Each account from transaction queue should be found and this transaction should be added to BST node corresponding to account number from PendingQueueTransaction
/*Add constructors and accessors/mutators too! */
class PendingQueue {
private:
    //pointers to boundaries
    PendingQueueTransaction* front;
    PendingQueueTransaction* rear;

    //queue for delayed transactions
    PendingQueueTransaction* waitingFront;
    PendingQueueTransaction* waitingRear;

    //timer control
    steady_clock::time_point lastAddedTime;
    seconds delay;
public:

    //Default Constructor
    PendingQueue(int delaySeconds = 120)
        : front(nullptr),
        rear(nullptr),
        waitingFront(nullptr),
        waitingRear(nullptr),
        delay(delaySeconds)
    {
        lastAddedTime = steady_clock::now() - delay;
    }

    //Destructor
    ~PendingQueue() {
        while (!isEmpty()) dequeuePendingQueueTransaction();
        while (!waitingIsEmpty()) dequeueWaiting();
    }

    //Accessors
    PendingQueueTransaction* getFront() const { return front; }
    PendingQueueTransaction* getRear() const { return rear; }

    //Mutators
    void setFront(PendingQueueTransaction* f) { front = f; }
    void setRear(PendingQueueTransaction* r) { rear = r; }


    //Enqueue to add the transaction node to queue to rear
    void enqueuePendingQueueTransaction(PendingQueueTransaction* node) {
        if (rear == nullptr) {
            setFront(node);
            setRear(node);
        }
        else {
            rear->setNext(node);
            setRear(node);
        }
    }


    //Dequeue to remove the transaction node to queue from front
    void dequeuePendingQueueTransaction() {
        if (isEmpty()) return;

        PendingQueueTransaction* temp = front;
        front = front->getNext();

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void enqueueWithDelay(PendingQueueTransaction* node) {
        auto now = steady_clock::now();

        if (now - lastAddedTime >= delay) {
            node->setNext(nullptr);
            enqueuePendingQueueTransaction(node);
            lastAddedTime = now;
        }
        else {
            enqueueWaiting(node);
        }
    }



    /*Check whether the transaction queue is empty*/
    bool isEmpty(void) const {
        return front == nullptr;
    }

    /* =================  Waiting Queue ====================== */

    void enqueueWaiting(PendingQueueTransaction* node) {
        node->setNext(nullptr);

        if (waitingRear == nullptr) {
            waitingFront = waitingRear = node;
        }
        else {
            waitingRear->setNext(node);
            waitingRear = node;
        }
    }

    void dequeueWaiting() {
        if (waitingIsEmpty()) return;

        PendingQueueTransaction* temp = waitingFront;
        waitingFront = waitingFront->getNext();

        if (waitingFront == nullptr) waitingRear = nullptr;
        delete temp;
    }

    bool waitingIsEmpty() const { return waitingFront == nullptr; }

    // ===================================== //

    void processWaiting() {
        auto now = steady_clock::now();

        while (!waitingIsEmpty() && now - lastAddedTime >= delay) {
            PendingQueueTransaction* node = waitingFront;

            //remove from waiting queue WITHOUT deleting
            waitingFront = waitingFront->getNext();

            if (waitingFront == nullptr) waitingRear = nullptr;

            node->setNext(nullptr);
            enqueuePendingQueueTransaction(node);
            lastAddedTime = std::chrono::steady_clock::now();
        }
    }

    void processQueue(BankTree* bankAccounts) {
        processWaiting();

        while (!isEmpty()) {
            PendingQueueTransaction* transaction = getFront();

            this_thread::sleep_for(milliseconds(200));

            string current_status = "Processing [ " + transaction->getType() + " $" + std::to_string(transaction->getAmount())
                + " ] for Account: " + transaction->getAccountNumber();

            BankAccount* account = bankAccounts->findBankAccount(transaction->getAccountNumber());

            if (account != nullptr) {
                string transType = transaction->getType();
                double amt = transaction->getAmount();

                if (transType == "Deposit") {
                    account->depositMoney(amt);
                    cout << current_status << " ==> SUCCESS! (New Balance: " << account->getAccountBalance() << ")" << endl;
                }
                else if (transType == "Withdraw") {
                    account->withdrawMoney(amt);
                    cout << current_status << " ==> Finished withdraw attempt." << endl;
                }
                else {
                    cout << current_status << " ==> ERROR: Invalid transaction type: " << transType << endl;
                }
            }
            else {
                //print detailed error status
                cout << current_status << " ==> ERROR: Account not found." << endl;
            }

            dequeuePendingQueueTransaction();
        }
    }

    void addTransaction(string accNum, string type, double amount) {
        PendingQueueTransaction* node = new PendingQueueTransaction(accNum, type, amount);
        auto now = steady_clock::now();
        if (now - lastAddedTime >= delay) {
            enqueuePendingQueueTransaction(node);
            lastAddedTime = now;
        }
        else {
            enqueueWaiting(node);
        }
    }
};