# Phase 1 - Authentication System

## Objective
Build a simple file-based authentication system in C++ using basic Programming Fundamentals concepts.

---

## Features Implemented

### 1. User Registration (Sign Up)
- Take username and password from user
- Check if username already exists in users.txt
- If not exists, store new user

### 2. User Login
- Ask for username and password
- Validate against stored records
- Allow access if credentials match

---

## File Structure

### users.txt Format
```
username password
```

Example:
```
ali 12345
ahmed abc123
```

---

## Functions Used

### usernameExists(string username)
- Opens users.txt
- Searches for username
- Returns true if found

### signUp()
- Input username/password
- Calls usernameExists()
- Stores new user in file

### logIn(string &loggedInUser)
- Input credentials
- Compare with file data
- Returns success/failure

---

## Algorithm

### Sign Up Flow
1. Input username
2. Input password
3. Check file for duplicate username
4. If not found → save user
5. Else → show error

### Login Flow
1. Input username
2. Input password
3. Read users.txt
4. Match credentials
5. If match → login success
6. Else → login failed

---

## Concepts Used
- File Handling (ifstream/ofstream)
- Strings
- Conditional Statements
- Loops
- Functions

---

## Notes
- No encryption used in Phase 1 (basic level)
- Data stored in plain text for simplicity
