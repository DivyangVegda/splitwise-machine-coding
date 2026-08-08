#pragma once
#include <string>

class User {
private:
    std::string id;
    std::string name;
public:
    User(std::string id, std::string name) : id(id), name(name) {}
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
};