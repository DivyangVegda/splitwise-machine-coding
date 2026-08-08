A C++ console application demonstrating Low-Level Design (LLD) and Object-Oriented Design (OOD) principles. This project simulates the core expense-sharing features of Splitwise.

## 🚀 Features
* **User Management:** Register and track users in the system.
* **Expense Sharing:** Add transactions and automatically calculate who owes whom.
* **Exact Splits:** Supports dividing bills by exact amounts.
* **Balance Tracking:** View balances for individual users or across the entire system.

## 🏗️ Architecture & Design Principles
This project was built with a focus on clean code and scalability:
* **Single Responsibility Principle (SRP):** Models (`User`, `Split`) only hold data, while business logic is isolated in the `SplitwiseManager`.
* **Open/Closed Principle (OCP):** The system uses a base `Split` class. New split types (like Equal or Percentage) can be added seamlessly without modifying existing manager logic.
* **In-Memory Storage:** Fast $O(1)$ lookups utilizing `std::unordered_map` for users and the balance sheet.

## 📂 Project Structure
```text
src/
 ├── main.cpp                 # Driver program and test cases
 ├── models/                  # Entity classes (User, Split, ExactSplit)
 └── services/                # Business logic (SplitwiseManager)
```

## 🛠️ How to Build and Run

### Prerequisites
* A C++ compiler that supports C++14 or higher (e.g., GCC/g++).

### Compilation
Navigate to the root directory and compile the source code:
```
g++ -std=c++14 src/main.cpp src/services/SplitwiseManager.cpp -o splitwise
```
### Execution
```
./splitwise
```
## 👨‍💻 Author
**Divyang Vegda**
