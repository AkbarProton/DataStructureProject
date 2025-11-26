#pragma once
#include <iostream>
#include "BankAccount.h"
using namespace std;

class BankTree {
private:
    BankAccount* root;


    //Method to insert the BankAccount node to BankTree comparing the account number
    BankAccount* insert(BankAccount* current, BankAccount* newAccount) {
        if (current == nullptr) {
            return newAccount;
        }

        // Comparison uses the account number string


        if (newAccount->getAccountNumber() < current->getAccountNumber()) {
            current->leftChild = insert(current->leftChild, newAccount);
        }


        else if (newAccount->getAccountNumber() > current->getAccountNumber()) {
            current->rightChild = insert(current->rightChild, newAccount);
        }

        //Impossible to happen
        else {
            cout << "Warning: Account number " << newAccount->getAccountNumber() << " already exists. Insertion skipped." << endl;
        }

        return current;
    }



    //InorderTraversal to see the sorted list of accounts
    void inOrderTraversal(BankAccount* account) const {
        if (account != nullptr) {
            inOrderTraversal(account->leftChild);
            account->displayInfo();
            inOrderTraversal(account->rightChild);
        }
    }

    //Finding minimum for inorder successor ( smallest node ( by account number ) in right subtree ( recursively ) )
    BankAccount* findMin(BankAccount* node) {
        BankAccount* current = node;

        while (current && current->leftChild != nullptr) {
            current = current->leftChild;
        }

        return current;
    }

    //Method to delete bankAccount from the BankTree
    BankAccount* deleteAccount(BankAccount* current, const string& targetNumber) {

        //In case if: 1. Root node is nullptr. 2. If even after seraching whole tree we wound nothing, and also in case of leaf node, it will correctly return nullptr to assign as child to leaf node
        if (current == nullptr) {
            cout << "Account " << targetNumber << " not found." << endl;
            return nullptr;
        }


        if (targetNumber < current->getAccountNumber()) {
            current->leftChild = deleteAccount(current->leftChild, targetNumber);
        }
        else if (targetNumber > current->getAccountNumber()) {
            current->rightChild = deleteAccount(current->rightChild, targetNumber);
        }
        else {


            if (current->leftChild == nullptr) {
                BankAccount* temp = current->rightChild;
                delete current; //Deleting the node from the memory

                //Informing user that account was deleted sucessfully
                cout << "Account deleted" << endl;

                //After deleting the node, we set the right subtree of a child (node that was deleted) to parent
                return temp;
            }

            else if (current->rightChild == nullptr) {
                BankAccount* temp = current->leftChild;
                delete current; //Deleting the node from the memory

                //Informing user that account was deleted sucessfully
                cout << "Account deleted" << endl;

                //After deleting the node, we set the left subtree of a child (node that was deleted) to parent
                return temp;
            }

            //After setting children correctly

            // Find the in-order successor (smallest in the right subtree)
            BankAccount* successor = findMin(current->rightChild);

            current->setAccountNumber(successor->getAccountNumber());
            current->setAccountHolderName(successor->getAccountHolderName());
            current->setAccountBalance(successor->getAccountBalance());

            current->rightChild = deleteAccount(current->rightChild, successor->getAccountNumber());
        }

        return current;
    }

    BankAccount* findLargestByAccountNumber(BankAccount* current) const {
        if (current == nullptr) {
            return nullptr;
        }

        // The largest key is always in the right child of the current subtree

        if (current->rightChild != nullptr) {
            return findLargestByAccountNumber(current->rightChild);
        }
        return current;
    }

public:

    BankTree() : root(nullptr) {}

    void insertAccount(BankAccount* newAccount) {
        if (newAccount == nullptr) return;
        root = insert(root, newAccount);
    }

    void displayAllAccountsSorted() const {
        cout << "\nAll bank accounts (Sorted by Account Number)" << endl;

        //Using inorder traversal for showing in sorted way
        inOrderTraversal(root);
    }

    BankAccount* findBankAccount(const string& accountNumber) const {
        return searchAccount(root, accountNumber);
    }

    BankAccount* searchAccount(BankAccount* current, const string& targetNumber) const {

        if (current == nullptr) {
            return nullptr;
        }


        if (current->getAccountNumber() == targetNumber) {
            cout << "Account is successfuly found: " << endl;
            return current;
        }


        if (targetNumber < current->getAccountNumber()) {
            return searchAccount(current->leftChild, targetNumber);
        }

        else {
            return searchAccount(current->rightChild, targetNumber);
        }
    }

    void deleteBankAccount(const string& accountNumber) {
        root = deleteAccount(root, accountNumber);
    }

    BankAccount* getLastAccount() {
        return findLargestByAccountNumber(root);
    }
};