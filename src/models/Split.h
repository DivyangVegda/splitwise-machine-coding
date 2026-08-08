#pragma once
#include <memory>
#include "User.h"

class Split {
protected:
    std::shared_ptr<User> user;
    double amount;
public:
    Split(std::shared_ptr<User> user) : user(user), amount(0.0) {}
    virtual ~Split() = default;
    
    std::shared_ptr<User> getUser() const { return user; }
    
    double getAmount() const { return amount; }
    void setAmount(double amt) { amount = amt; }
};