# 🏦 Financial Banking System (Flower Bank)

A Java-based backend banking application built to securely manage user accounts, balances and financial transactions. 

This project was developed to solidify core **Object-Oriented Programming (OOP)** concepts while implementing foundational business logic and data security principles.

## 📌 Tech Stack
* **Language:** Java
* **Concepts:** OOP, Inheritance, Abstraction, Composition

## 📌 Security & Architecture Highlights

As an aspiring Application Security Engineer, building this system provided practical experience in structuring code to protect sensitive data and enforce strict business rules:

* **Data Encapsulation:** Implemented strict `private` access modifiers for critical state variables (e.g., `CurrentBalance`, `Password`, `AccountType`). State changes are exclusively handled through controlled public methods (`depositMoney`, `withdrawMoney`) to prevent unauthorized external modification.
* **Role-Based Access Control (RBAC):** Engineered tiered privileges utilizing a `minimumLimit()` function. The system successfully distinguishes between **Platinum** and **Standard** accounts, enforcing distinct transaction thresholds and minimum balance requirements based on the user's role.
* **Input Validation & Sanity Checks:** * The `depositMoney` and `withdrawMoney` methods strictly evaluate parameters to ensure values are `> 0`.
  * The system actively prevents overdrafts by verifying that withdrawal requests do not exceed the `CurrentBalance` and respect the assigned account limits before approving a transaction.
  * Implemented basic length validation for PIN/Passwords.

## 📌 System Structure

The application is structured into modular components to separate data handling from user execution:
* `User.java`: Abstract base class handling core identification and authentication mechanics.
* `Balance.java`: Manages the mathematical logic and integrity checks for deposits and withdrawals.
* `Transaction.java`: Extends `User` and utilizes composition with `Balance` to execute complex, multi-variable business logic.
* `FlowerBank.java`: The Main execution class handling the interactive terminal-based user interface.

## 📌 How to Run
1. Compile the Java files in a standard IDE (Eclipse, IntelliJ) or via the terminal.
2. Run `FlowerBank.java`.
3. Follow the terminal prompts to set up a secure account, choose a tier, and perform valid transactions.
