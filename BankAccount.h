#pragma once
#include <string>
#include "TransactionHistory.h"
#include <iostream>

using namespace std;


//Bank account represents the BST node that contains account information data. Encapsulation implemented!


/*Add constructors and accessors/mutators too! */
class BankAccount {
private:

	/*These 3 instance variables(attributes of BankAccount) must be initialized by user*/
	string accountNumber;
	string accountHolderName;
	double balance;

	TransactionHistory* history;
public:
	BankAccount* leftChild;
	BankAccount* rightChild;

	//BankAccount default constructor:
	BankAccount() {
		this->accountNumber = "";
		this->accountHolderName = "";
		this->balance = 0.0;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
		this->history = new TransactionHistory();
	}



	//BankAccount parametrized constructor



	BankAccount(
		string accountNumber,
		string accountHolderName,
		double balance
	) {
		this->accountNumber = accountNumber;
		this->accountHolderName = accountHolderName;
		this->balance = balance;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
		this->history = new TransactionHistory();
	}



	void depositMoney(double amount) {
		this->balance += amount;
		this->history->add(true, amount);  // true = deposit

		/* Add this transaction (node) to transaction history linked list: Direct / Queued */

		//addTransactionNode("Deposit", amount). Depending on queue

		/* Depending whether it is direct or queued:
		* 1. If direct transaction, it should immediately be added to end of the transaction history
		* 2. If queued, then only front element from PendingQueue should be added to transaction history, and this node should be dequeued from PendingQueue
		*/

	}





	void withdrawMoney(double amount) {

		/*Showing error happened if insufficient amount(amount > this.balance) (Use checker)*/

		/*Add a simple checker for balance ( if balance is 0 for example or if balance is not enough for withdrawal)*/
		if (balance < amount) {
			cout << "Insufficient balance for withdrawal! Balance: " << this->balance << ", Requested: " << amount << endl;
			return;
		}
		this->balance -= amount;
		this->history->add(false, amount);  // false = withdraw


		/* Add this transaction (node) to transaction history linked list: Direct / Queued */

		//addTransactionNode("Withdraw", amount). Depending on queue

		/* Depending whether it is direct or queued:
		* 1. If direct transaction, it should immediately be added to end of the transaction history
		* 2. If queued, then only front element from PendingQueue should be added to transaction history, and this node should be dequeued from PendingQueue
		*/

	}


	/* Add method to show info of bank account: AccountNumber, Name, balance and length of transaction history linked list*/
	void displayInfo() {
		cout << "Account number: " << this->accountNumber << endl;
		cout << "Account holder name: " << this->accountHolderName << endl;
		cout << "Balance: " << this->balance << "$" << endl;

		//5. Display Transaction History
		cout << "Number of transactions: " << this->history->getTransactionCount() << endl << endl;
	}

	void displayTransactionHistory() const {
		history->displayHistory();
	}


	void setAccountNumber(string accountNumber) {
		this->accountNumber = accountNumber;
	}
	void setAccountHolderName(string accountHolderName) {
		this->accountHolderName = accountHolderName;
	}
	void setAccountBalance(double balance) {
		this->balance = balance;
	}

	string getAccountNumber() const {
		return this->accountNumber;
	}
	string getAccountHolderName() {
		return this->accountHolderName;
	}
	double getAccountBalance() {
		return this->balance;
	}
};