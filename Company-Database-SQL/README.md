# 🏢 Company Database Schema

A comprehensive SQL database backend designed to securely manage corporate operations, including employee hierarchies, departmental tracking and project allocations. 

This project was developed to solidify core **Relational Database Management System (RDBMS)** concepts while implementing strict data integrity constraints and relationship logic.

## 📌 Tech Stack
* **Language:** SQL
* **Concepts:** DDL (Data Definition Language), DML (Data Manipulation Language), Relational Algebra, Database Normalization

## 📌 Security & Architecture Highlights

As an aspiring Application Security Engineer, building this schema provided practical experience in understanding backend data structures, which is critical for identifying vulnerabilities like SQL Injection and logical bypasses:

* **Strict Data Integrity:** Implemented rigorous `PRIMARY KEY` and `FOREIGN KEY` constraints across all tables to prevent the insertion of orphaned records and maintain structural integrity.
* **Cascading Logic Control:** Engineered controlled data deletion and updating using `ON DELETE CASCADE` and `ON DELETE SET NULL`. This ensures that when an employee or department is removed, the system safely handles related records without crashing or exposing fragmented data.
* **Input Validation & Boundary Enforcement:**
  * Utilized `CHECK` constraints to enforce logical boundaries at the database level (e.g., ensuring `Dnumber` is strictly between 0 and 21).
  * Validated temporal logic by enforcing that a department's start date (`Dept_start_date`) cannot logically exceed the manager's start date (`Mgr_start_date`), preventing bad data entry.
* **Type Strictness:** Enforced exact memory allocation and data sanitization using fixed `CHAR` lengths for Social Security Numbers and specific `DECIMAL` limits for salaries and hours.

## 📌 System Structure

The database is structured into normalized, relational tables to separate operational domains:
* `EMPLOYEE`: The core identity table handling personal data, salaries and supervisor hierarchies.
* `DEPARTMENT`: Manages departmental metadata and ties managers to specific departments.
* `PROJECT`: Tracks project names, locations and the controlling department.
* `WORKS_ON`: An associative entity resolving the many-to-many relationship between employees and projects.
* `DEPT_LOCATIONS` & `DEPENDENT`: Multi-value structural tables tied to core entities.

## 📌 How to Run
1. Open your preferred SQL IDE or command-line interface (e.g., MySQL Workbench, PostgreSQL).
2. Execute the DDL script to create the schema, tables and constraints.
3. Execute the DML script (`Company scheme.insertion`) to populate the tables with testing data.
4. Run standard `SELECT` queries to verify the relational mappings.
