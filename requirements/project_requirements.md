# Project Requirements - The Developer's Toolkit

## Project Overview
This project is developed for Programming Fundamentals (PF) course using C++ without OOP concepts. It is a console-based toolkit containing multiple utilities.

---

## Core Modules

### 1. Authentication System
- User Sign Up
- User Login
- Username validation
- File-based storage using users.txt

### 2. Password Vault
- Save passwords securely
- Retrieve saved passwords
- Basic encryption (Caesar Cipher)
- File storage in vault.txt

### 3. Text File Compressor
- Run Length Encoding (RLE)
- Compress text files
- Decompress files
- File input/output handling

---

## Functional Requirements
- Console-based interface
- Menu-driven system
- File handling using ifstream/ofstream
- String manipulation
- Character processing
- Basic encryption/decryption

---

## Non-Functional Requirements
- Easy to use interface
- Fast execution for small files
- Error handling for missing files
- Modular function-based design

---

## Constraints
- No OOP (no classes or structs)
- No external libraries
- Only standard C++ features
- Must run in console environment

---

## Data Storage Format

### users.txt
username password

### vault.txt
username|website|encrypted_password
