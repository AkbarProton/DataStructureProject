#include "PendingQueue.h"
#include "BankTree.h"
#include <iostream>
#include <memory>

int main() {
    PendingQueue bankTransactionQueue;
    BankTree bankAccounts;

    BankAccount* readyBankAccounts[] = {
        new BankAccount("001", "Abarxoja", 10000),
        new BankAccount("002", "Atabek", 9000),
        new BankAccount("003", "Sarvar", 460000),
        new BankAccount("004", "Jaxongir", 33920),
        new BankAccount("005", "Abdulloh", 7040),
        new BankAccount("100", "User_100", 100000)
    };

    for (auto const& account : readyBankAccounts) {
        bankAccounts.insertAccount(account);
    }

    BankAccount* lastAcc = bankAccounts.getLastAccount();
    if (lastAcc != nullptr)
        std::cout << lastAcc->getAccountNumber() << std::endl;

    if (lastAcc != nullptr) {
        int nextNumber = 0;
        try {
            nextNumber = std::stoi(lastAcc->getAccountNumber()) + 1;
        } catch (...) {
            std::cerr << "Account Number Creation Error\n";
        }
        bankAccounts.insertAccount(
            new BankAccount(std::to_string(nextNumber), "Hi", 110000)
        );
    }

    bankAccounts.displayAllAccountsSorted();

    BankAccount* account002 = bankAccounts.findBankAccount("002");
    if (account002 != nullptr)
        account002->displayInfo();

    return 0;
}
