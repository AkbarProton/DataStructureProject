#include <iostream>
#include "BankTree.h"
#include "BankAccount.h"
#include <string>
#include "PendingQueue.h"
using namespace std;

int main() {

	//Creating a bankTree of bank Accounts 
	BankTree* bankAccounts = new BankTree();

	//For menu flag value
	bool isProgramActive = true;
	PendingQueue* pendingTransactions = new PendingQueue(5);

	//Greeting the user
	cout << "Welcome User, welcome to bank system simulation!" << endl;
	cout << "Before using our system, we ask you to initialize you account" << endl;


	//Initializing upcoming user
	string userName;
	cout << "Please enter the name: ";
	cin >> userName;

	bankAccounts->insertAccount(
		new BankAccount(
			"00000001",
			userName,
			0.0
		)
	);

	//Dummy accounts
	BankAccount* bankDummyAccounts[] = {
		new BankAccount("00000002", "Atabek", 1000),
		new BankAccount("00000003", "Jaxongir", 2000),
		new BankAccount("00000004", "Abdufayyoz", 3000),
		new BankAccount("00000005", "Akbarxoja", 4000),

		new BankAccount("00000006", "User 06", 5000),
		new BankAccount("00000007", "User 07", 6000.0),
		new BankAccount("00000008", "User 08", 7000.0),
		new BankAccount("00000009", "User 09", 8000.0),
		new BankAccount("00000010", "User 10", 9000.0),
		new BankAccount("00000011", "User 11", 10000.0),
		new BankAccount("00000012", "User 12", 11000.0),
		new BankAccount("00000013", "User 13", 12000.0),
		new BankAccount("00000014", "User 14", 13000.0),
		new BankAccount("00000015", "User 15", 14000.0),
		new BankAccount("00000016", "User 16", 15000.0),
		new BankAccount("00000017", "User 17", 16000.0),
		new BankAccount("00000018", "User 18", 17000.0),
		new BankAccount("00000019", "User 19", 18000.0),
		new BankAccount("00000020", "User 20", 19000.0),
		new BankAccount("00000021", "User 21", 20000.0),
		new BankAccount("00000022", "User 22", 21000.0),
		new BankAccount("00000023", "User 23", 22000.0),
		new BankAccount("00000024", "User 24", 23000.0),
		new BankAccount("00000025", "User 25", 24000.0),
		new BankAccount("00000026", "User 26", 25000.0)
	};

	//ADding dummy accounts to program

	for (auto const& account : bankDummyAccounts) {
		bankAccounts->insertAccount(account);
	}
	BankAccount* thisUser = bankAccounts->findBankAccount("00000001");
	//Menu Program
	while (isProgramActive) {
		cout << "Hi user: " << thisUser->getAccountHolderName() << endl;
		
		cout << "\nChoose option \n\n" << endl;

		//Displaying menu to the user
		int choice;
		cout << "\n1.Show balance\n2.Deposit money\n3.Withdraw Money\n4.Show transaction history\n5.Switch account\n6.Delete my account.\n7.Process Pending Queue\nExit (Write -1) \n";
		cout << "Input: ";
		cin >> choice;

		switch (choice) {
		case -1:
		{
			isProgramActive = false;
			break;
		}
		case 1:
		{
			cout << "\n\n-------------------------SHOWING BALANCE-------------------------\n\n";
			cout << "Your current balance is: " << thisUser->getAccountBalance() << endl;
			break;
		}
		case 2:
		{
			cout << "\n\n-------------------------DEPOSIT-------------------------\n\n";
			int amountToDeposit;

			cout << "Choose the amount you want to deposit: ";
			cin >> amountToDeposit;
			cout << endl;

			cout << "Choose deposit type:\n1. Direct Deposit (Immediate)\n2. Queued Deposit (Delayed)\nInput:" << endl;
			int depositChoice;
			cin >> depositChoice;
			cout << endl;
			if (depositChoice == 1) {
				// Direct Deposit: Immediate update to account and history
				thisUser->depositMoney(amountToDeposit);
				cout << "Operation of depositing is done succesfully (Direct). New Balance: " << thisUser->getAccountBalance();
			}
			else if(depositChoice == 2){
				pendingTransactions->addTransaction(
					thisUser->getAccountNumber(),
					"Deposit",
					(double)amountToDeposit
				);
				cout << "Deposit request of " << amountToDeposit << " added to the pending queue.";
			}
			else {
				cout << "canceled" << endl;
			}

			cout << "Operation of depositing is done succesfully...";
			cout << endl;

			break;
		}

		case 3:
		{
			cout << "\n\n-------------------------WITHDRAW-------------------------\n\n";
			int amountToWithdraw;

			cout << "Choose the amount you want to withdraw: ";
			cout << endl;
			cin >> amountToWithdraw;

			cout << "Choose withdraw type:\n1. Direct withdraw (Immediate)\n2. Queued withdraw (Delayed)\nInput:" << endl;
			int withdrawChoice;
			cin >> withdrawChoice;
			cout << endl;
			if (withdrawChoice == 1) {
				thisUser->withdrawMoney(amountToWithdraw);
			}
			else if (withdrawChoice == 2) {
				pendingTransactions->addTransaction(
					thisUser->getAccountNumber(),
					"Withdraw",
					(double)amountToWithdraw
				);
				cout << "Withdraw request of " << amountToWithdraw << " added to the pending queue.";
			}
			else {
				cout << "canceled" << endl;
			}
			cout << endl;

			break;
		}
		case 4:
		{

			cout << "\n\n-------------------------TRANSACTION HISTORY-------------------------\n\n";
			thisUser->displayTransactionHistory();
			cout << endl;
			break;
		}
		case 5: {
			cout << "\n\n-------------------------ACCOUNT SWITCHING-------------------------\n\n";
			bankAccounts->displayAllAccountsSorted();

			string accountNumber;
			cout << "Choose account number to enter from the list ";
			cin >> accountNumber;
			cout << endl;

			if (bankAccounts->findBankAccount(accountNumber) != nullptr) {
				thisUser = bankAccounts->findBankAccount(accountNumber);
			}
			else {
				cout << "Incorrect account number" << endl;
			}
			break;
		}
		case 6: {
			cout << "\n\n-------------------------DELETING ACCOUNT-------------------------\n\n";
			cout << "Account " << thisUser->getAccountNumber() << " deleted.\n";
			bankAccounts->deleteBankAccount(thisUser->getAccountNumber());

			cout << "Now choose different account to enter: " << endl;
			bankAccounts->displayAllAccountsSorted();
			cout << "Input the account number: ";
			string input;
			cin >> input;
			BankAccount* selectedNewThisUser = bankAccounts->findBankAccount(input);

			if (selectedNewThisUser != nullptr) {
				thisUser = selectedNewThisUser;
			}
			else {
				while (selectedNewThisUser == nullptr) {
					cout << "Incorrect account number, choose again!" << endl;
					cout << "Now choose different account to enter: " << endl;
					bankAccounts->displayAllAccountsSorted();
					cout << "Input the account number: ";
					cin >> input;
					selectedNewThisUser = bankAccounts->findBankAccount(input);
				}
			}

			break;
		}
		case 7: {
			cout << "\n\n-------------------------PROCESSING DAILY QUEUE-------------------------\n\n";

			pendingTransactions->processQueue(bankAccounts);

			cout << "\nQueue processing complete. Check transaction history for updates." << endl;
			break;
		}
		default:
			break;
		}
	}
	delete bankAccounts;
	delete pendingTransactions;
	return 0;
}