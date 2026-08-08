#include <iostream>
#include <memory>
#include <vector>
#include "models/User.h"
#include "models/ExactSplit.h"
#include "services/SplitwiseManager.h"

using namespace std;

int main() {
    SplitwiseManager manager;

    auto user1 = make_shared<User>("u1", "Anjali");
    auto user2 = make_shared<User>("u2", "Rahul");
    auto user3 = make_shared<User>("u3", "Aditi");

    manager.addUser(user1);
    manager.addUser(user2);
    manager.addUser(user3);

    cout << "--- Initial State ---" << endl;
    manager.showAllBalances();
    cout << endl;

    vector<shared_ptr<Split>> splits1;
    splits1.push_back(make_shared<ExactSplit>(user1, 200));
    splits1.push_back(make_shared<ExactSplit>(user2, 300));
    splits1.push_back(make_shared<ExactSplit>(user3, 500));

    manager.addExpense(1000, "u1", splits1);

    cout << "--- Balances after Anjali pays 1000 ---" << endl;
    manager.showAllBalances();
    cout << endl;

    vector<shared_ptr<Split>> splits2;
    splits2.push_back(make_shared<ExactSplit>(user2, 200));
    splits2.push_back(make_shared<ExactSplit>(user3, 300));

    manager.addExpense(500, "u2", splits2);

    cout << "--- Balances after Rahul pays 500 ---" << endl;
    manager.showAllBalances();
    cout << endl;

    cout << "--- Showing individual balances for Aditi (u3) ---" << endl;
    manager.showBalance("u3");

    return 0;
}
