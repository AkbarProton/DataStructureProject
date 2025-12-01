#pragma once
#include <string>

#include <iostream>
#include <memory>
#include <unordered_map>
#include "BankAccount.h"
#include "BankTree.h"

using namespace std;
void displayAllAccounts(const unordered_map<string, BankAccount*>& accountMap) {
    if (accountMap.empty()) {
        cout << "\nThe Bank Account Hash Map is Empty" << endl;
        return;
    }
    cout << "\nCurrent Bank Accounts in Hash Map (" << accountMap.size() << " accounts) ---\n";
    for (const auto& pair : accountMap) {
        // pair.first is the key (account number)
        // pair.second is the value (BankAccount* pointer)
        cout << "Key: " << pair.first << " | Holder: " << pair.second->getAccountHolderName()
            << " | Balance: $" << pair.second->getAccountBalance() << endl;
    }
}


int main() {
    //unordered_map 
    unordered_map<string, BankAccount*> bankAccountMap;

    BankAccount* readyBankAccounts[] = {
        new BankAccount("001", "Abarxoja", 10000),
        new BankAccount("002", "Atabek", 9000),
        new BankAccount("003", "Sarvar", 460000),
        new BankAccount("004", "Jaxongir", 33920),
        new BankAccount("005", "Abdulloh", 7040),
        new BankAccount("006", "User_006", 6000),
        new BankAccount("007", "User_007", 7000),
        new BankAccount("008", "User_008", 8000),
        new BankAccount("009", "User_009", 9000),
        new BankAccount("010", "User_010", 10000),
        new BankAccount("011", "User_011", 11000),
        new BankAccount("012", "User_012", 12000),
        new BankAccount("013", "User_013", 13000),
        new BankAccount("014", "User_014", 14000),
        new BankAccount("015", "User_015", 15000),
        new BankAccount("016", "User_016", 16000),
        new BankAccount("017", "User_017", 17000),
        new BankAccount("018", "User_018", 18000),
        new BankAccount("019", "User_019", 19000),
        new BankAccount("020", "User_020", 20000),
        new BankAccount("021", "User_021", 21000),
        new BankAccount("022", "User_022", 22000),
        new BankAccount("023", "User_023", 23000),
        new BankAccount("024", "User_024", 24000),
        new BankAccount("025", "User_025", 25000),
        new BankAccount("026", "User_026", 26000),
        new BankAccount("027", "User_027", 27000),
        new BankAccount("028", "User_028", 28000),
        new BankAccount("029", "User_029", 29000),
        new BankAccount("030", "User_030", 30000),
        new BankAccount("031", "User_031", 31000),
        new BankAccount("032", "User_032", 32000),
        new BankAccount("033", "User_033", 33000),
        new BankAccount("034", "User_034", 34000),
        new BankAccount("035", "User_035", 35000),
        new BankAccount("036", "User_036", 36000),
        new BankAccount("037", "User_037", 37000),
        new BankAccount("038", "User_038", 38000),
        new BankAccount("039", "User_039", 39000),
        new BankAccount("040", "User_040", 40000),
        new BankAccount("041", "User_041", 41000),
        new BankAccount("042", "User_042", 42000),
        new BankAccount("043", "User_043", 43000),
        new BankAccount("044", "User_044", 44000),
        new BankAccount("045", "User_045", 45000),
        new BankAccount("046", "User_046", 46000),
        new BankAccount("047", "User_047", 47000),
        new BankAccount("048", "User_048", 48000),
        new BankAccount("049", "User_049", 49000),
        new BankAccount("050", "User_050", 50000),
        new BankAccount("051", "User_051", 51000),
        new BankAccount("052", "User_052", 52000),
        new BankAccount("053", "User_053", 53000),
        new BankAccount("054", "User_054", 54000),
        new BankAccount("055", "User_055", 55000),
        new BankAccount("056", "User_056", 56000),
        new BankAccount("057", "User_057", 57000),
        new BankAccount("058", "User_058", 58000),
        new BankAccount("059", "User_059", 59000),
        new BankAccount("060", "User_060", 60000),
        new BankAccount("061", "User_061", 61000),
        new BankAccount("062", "User_062", 62000),
        new BankAccount("063", "User_063", 63000),
        new BankAccount("064", "User_064", 64000),
        new BankAccount("065", "User_065", 65000),
        new BankAccount("066", "User_066", 66000),
        new BankAccount("067", "User_067", 67000),
        new BankAccount("068", "User_068", 68000),
        new BankAccount("069", "User_069", 69000),
        new BankAccount("070", "User_070", 70000),
        new BankAccount("071", "User_071", 71000),
        new BankAccount("072", "User_072", 72000),
        new BankAccount("073", "User_073", 73000),
        new BankAccount("074", "User_074", 74000),
        new BankAccount("075", "User_075", 75000),
        new BankAccount("076", "User_076", 76000),
        new BankAccount("077", "User_077", 77000),
        new BankAccount("078", "User_078", 78000),
        new BankAccount("079", "User_079", 79000),
        new BankAccount("080", "User_080", 80000),
        new BankAccount("081", "User_081", 81000),
        new BankAccount("082", "User_082", 82000),
        new BankAccount("083", "User_083", 83000),
        new BankAccount("084", "User_084", 84000),
        new BankAccount("085", "User_085", 85000),
        new BankAccount("086", "User_086", 86000),
        new BankAccount("087", "User_087", 87000),
        new BankAccount("088", "User_088", 88000),
        new BankAccount("089", "User_089", 89000),
        new BankAccount("090", "User_090", 90000),
        new BankAccount("091", "User_091", 91000),
        new BankAccount("092", "User_092", 92000),
        new BankAccount("093", "User_093", 93000),
        new BankAccount("094", "User_094", 94000),
        new BankAccount("095", "User_095", 95000),
        new BankAccount("096", "User_096", 96000),
        new BankAccount("097", "User_097", 97000),
        new BankAccount("098", "User_098", 98000),
        new BankAccount("099", "User_099", 99000),
        new BankAccount("100", "User_100", 100000),
    };

    for (auto const& account : readyBankAccounts) {
        //adding to hashmap
        bankAccountMap[account->getAccountNumber()] = account;
    }

    // 1. Insertion
    cout << "\nINSERTION: the map with accounts (O(1) average time).\n";
    for (auto const& account : readyBankAccounts) {
        // Adding to hash map: Key = Account Number, Value = BankAccount*
        bankAccountMap[account->getAccountNumber()] = account;
    }
    cout << "Inserted " << bankAccountMap.size() << " accounts.\n";

    // Manual Insertion of a new account
    BankAccount* newAcc = new BankAccount("101", "New_User_101", 1000.0);
    bankAccountMap.insert({ "101", newAcc });
    cout << "Inserted account 101.\n";

    // 2. Traversal
    displayAllAccounts(bankAccountMap);
    

    // 3. Search and Access Logic (O(1) average time)
    string searchKey = "003";
    cout << "\nSEARCH Checking account " << searchKey << " using .find() (O(1) average).\n";

    // Using find(): returns iterator to the element or end() if not found.
    auto it_found = bankAccountMap.find(searchKey);

    if (it_found != bankAccountMap.end()) {
        BankAccount* foundAccount = it_found->second;

        cout << "Account Found: ";
        foundAccount->displayInfo();

        // Update functionality demonstration
        double depositAmount = 5000;
        cout << "Updating Balance: Depositing " << depositAmount << "to this account\n";
        foundAccount->depositMoney(depositAmount); // Calls existing BankAccount method

        cout << "Updated Info: ";
        foundAccount->displayInfo();
    }
    else {
        cout << "Account " << searchKey << " not found.\n";
    } 


    string invalidKey = "999";
    cout << "\nAttempting to search for invalid account " << invalidKey << "\n";
    if (bankAccountMap.count(invalidKey) == 0) { // O(1) check if key exists
        cout << "Account " << invalidKey << " does not exist in the map.\n";
    }
    return 0;
}