#pragma once

#include "PendingQueueTransaction.h"

//Pending Queue specifies queues when limit of transactions at a time are reached

//This can be approached if the time limit was set to add the transaction to transaction history. 
// For example if the delay of several minutes between transactioin is added, 
// other transactions must be added to queue and then only retrieved from it and added to transaction history


//Node from queue ( PendingQueueTransaction ) saves data about transaction's type, amount of transaction, and account nubmer to which transaction is applied

//Each account from transaction queue should be found and this transaction should be added to BST node corresponding to account number from PendingQueueTransaction
/*Add constructors and accessors/mutators too! */
class PendingQueue {
private:
    PendingQueueTransaction* front;
    PendingQueueTransaction* rear;
public:

    //Default Constructor
    PendingQueue() : front(nullptr), rear(nullptr) {}

    //Destructor
    ~PendingQueue() {
        while (!isEmpty()) {
            dequeuePendingQueueTransaction();
        }
    }

    // --- Accessors ---
    PendingQueueTransaction* getFront() const { return front; }
    PendingQueueTransaction* getRear() const { return rear; }

    // --- Mutators (          ) ---
    void setFront(PendingQueueTransaction* f) { front = f; }
    void setRear(PendingQueueTransaction* r) { rear = r; }


    /* Enqueue to add the transaction node to queue to rear */
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


    /* Dequeue to remove the transaction node to queue from front */
    void dequeuePendingQueueTransaction() {
        if (isEmpty()) return;

        PendingQueueTransaction* temp = front;
        front = front->getNext();

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }


    /*Check whether the transaction queue is empty*/
    bool isEmpty(void) const {
        return front == nullptr;
    }
};