#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include "../models/User.h"
#include "../models/Split.h"

class SplitwiseManager {
private:
    std::unordered_map<std::string, std::shared_ptr<User>> users;
    std::unordered_map<std::string, std::unordered_map<std::string, double>> balanceSheet;

    void printBalance(std::string user1, std::string user2, double amount);

public:
    void addUser(std::shared_ptr<User> user);
    void addExpense(double totalAmount, std::string paidBy, const std::vector<std::shared_ptr<Split>>& splits);
    void showBalance(std::string userId);
    void showAllBalances();
};