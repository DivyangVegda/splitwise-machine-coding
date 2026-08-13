#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include "../models/User.h"
#include "../models/Split.h"

using namespace std;

class SplitwiseManager {
private:
    unordered_map<string, shared_ptr<User>> users;
    unordered_map<string, unordered_map<string, double>> balanceSheet;

    void printBalance(string user1, string user2, double amount);

public:
    void addUser(shared_ptr<User> user);
    void addExpense(double totalAmount, string paidBy, const vector<shared_ptr<Split>>& splits);
    void showBalance(string userId);
    void showAllBalances();
};
