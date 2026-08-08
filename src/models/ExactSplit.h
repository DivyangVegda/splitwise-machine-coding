#pragma once
#include "Split.h"

class ExactSplit : public Split {
public:
    ExactSplit(std::shared_ptr<User> user, double amount) : Split(user) {
        this->amount = amount;
    }
};