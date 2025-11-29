#include "PendingQueue.h"
#include "BankTree.h"
#include <iostream>
#include <memory>
#include <thread>
int main() {

    //Creating a simulation of queue of bank system
    PendingQueue bankTransactionQueue;

    //Creating a bank tree that stores all bank accounts
    BankTree bankAccounts;


    //Storing bank accounts in an array then to add them more conventiently to bst bankTree
    BankAccount* readyBankAccounts[] = {
        new BankAccount("001", "Abarxoja", 10000),
        new BankAccount("002", "Atabek", 9000),
        new BankAccount("003", "Sarvar", 460000),
        new BankAccount("004", "Jaxongir", 33920),
        new BankAccount("005", "Abdulloh", 7040),
        new BankAccount("100", "User_100", 100000)
    };


    //Inserting all accounts from array of readyBankAccounts to binary serach tree:  bankAccounts
    for (auto const& account : readyBankAccounts) {
        bankAccounts.insertAccount(account);
    }

    //Manual insertion of one more account that will add new account with last node's id incremented by 1 (line 124)
    bankAccounts.insertAccount(
        new BankAccount
        (
            to_string(
                stoi(bankAccounts.getLastAccount()->getAccountNumber()) + 1
            ),
            "Hi",
            11000
        )
    );

    //Displaying information of every account
    bankAccounts.displayAllAccountsSorted();

    //Searching account (6. Search Account)
    bankAccounts.findBankAccount("002")->displayInfo();



    //Pednging queue functionality showcasing

    // //Enqueue some pending transactions (using direct enqueue for simplicity; use addTransaction if adding rate limit)
     bankTransactionQueue.enqueuePendingQueueTransaction(new PendingQueueTransaction("002", "Deposit", 500.0));
     bankTransactionQueue.enqueuePendingQueueTransaction(new PendingQueueTransaction("002", "Withdraw", 200.0));
     bankTransactionQueue.enqueuePendingQueueTransaction(new PendingQueueTransaction("003", "Deposit", 1000.0));
     bankTransactionQueue.enqueuePendingQueueTransaction(new PendingQueueTransaction("999", "Deposit", 100.0));  //Invalid account for error test. It means account will not be found for this transaction

     //Enqueue to waiting queue to trigger delay
     bankTransactionQueue.enqueueWaiting(new PendingQueueTransaction("002", "Deposit", 500.0));
     bankTransactionQueue.enqueueWaiting(new PendingQueueTransaction("002", "Withdraw", 200.0));
     bankTransactionQueue.enqueueWaiting(new PendingQueueTransaction("003", "Deposit", 1000.0));
     bankTransactionQueue.enqueueWaiting(new PendingQueueTransaction("999", "Deposit", 100.0));  // Invalid


     //Simulate time passing (in real app, this would be background thread or loop)
     cout << "Waiting for delay to pass..." << std::endl;
     this_thread::sleep_for(chrono::seconds(6));  // >5s to release at least one


     //Process (will move from waiting to main if time passed)
     bankTransactionQueue.processQueue(&bankAccounts);
     //If using delays, simulate wait: std::this_thread::sleep_for(std::chrono::seconds(120)); but for demo, skip or set delay to 0 in PendingQueue constructor.

      //Process the queue
     bankTransactionQueue.processQueue(&bankAccounts);


     //Display updated info for account 002 (should show balance 9000 +500 -200 = 9300, with 2 transactions)
     BankAccount* updatedAcc = bankAccounts.findBankAccount("002");
     if (updatedAcc) {
         updatedAcc->displayInfo();
         cout << "Transaction History for 002:" << endl;
         updatedAcc->displayTransactionHistory();  // Using the new method
     }


     // Original search/display for comparison (now updated)
     BankAccount* account002 = bankAccounts.findBankAccount("002");
     if (account002 != nullptr)
         account002->displayInfo();
    return 0;
}