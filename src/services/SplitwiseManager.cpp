#include "SplitwiseManager.h"
#include <iostream>
#include <cmath>

using namespace std;

void SplitwiseManager::addUser(shared_ptr<User> user) {
    users[user->getId()] = user;
    balanceSheet[user->getId()] = unordered_map<string, double>();
}

void SplitwiseManager::addExpense(double totalAmount, string paidBy, const vector<shared_ptr<Split>>& splits) {
    double totalSplitAmount = 0;
    for (const auto& split : splits) {
        totalSplitAmount += split->getAmount();
    }
    
    if (abs(totalAmount - totalSplitAmount) > 0.001) {
        cout << "Error: Split amounts do not sum up to the total expense." << endl;
        return;
    }

    for (const auto& split : splits) {
        string paidTo = split->getUser()->getId();
        double splitAmount = split->getAmount();
        
        if (paidBy == paidTo) continue; 
        
        balanceSheet[paidTo][paidBy] += splitAmount;
        balanceSheet[paidBy][paidTo] -= splitAmount;
    }
}

void SplitwiseManager::showBalance(string userId) {
    if (users.find(userId) == users.end()) return;
    
    bool isEmpty = true;
    for (const auto& pair : balanceSheet[userId]) {
        string otherUserId = pair.first;
        double amount = pair.second;
        
        if (abs(amount) > 0.001) {
            isEmpty = false;
            printBalance(userId, otherUserId, amount);
        }
    }
    
    if (isEmpty) {
        cout << users[userId]->getName() << " has no balances." << endl;
    }
}

void SplitwiseManager::showAllBalances() {
    bool isEmpty = true;
    for (const auto& userPair : balanceSheet) {
        string userId = userPair.first;
        for (const auto& balancePair : userPair.second) {
            string otherUserId = balancePair.first;
            double amount = balancePair.second;
            
            if (amount > 0.001) {
                isEmpty = false;
                printBalance(userId, otherUserId, amount);
            }
        }
    }
    
    if (isEmpty) {
        cout << "No balances in the system." << endl;
    }
}

void SplitwiseManager::printBalance(string user1, string user2, double amount) {
    string name1 = users[user1]->getName();
    string name2 = users[user2]->getName();
    
    if (amount > 0) {
        cout << name1 << " owes " << name2 << ": " << amount << endl;
    } else if (amount < 0) {
        cout << name2 << " owes " << name1 << ": " << abs(amount) << endl;
    }
}