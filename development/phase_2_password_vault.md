# Phase 2 - Password Vault Module (Developer Implementation)

## Objective
Build a secure file-based password vault using C++ without OOP concepts. The module stores and retrieves encrypted passwords for different websites/apps.

---

## Files Used
- vault.txt

Format:
```
username|website|encrypted_password
```

---

## Core Functions

### 1. encryptPassword()
- Uses Caesar Cipher encryption
- Shifts each character by a secret key

Example:
```
Input: hello
Key: 5
Output: mjqqt
```

---

### 2. decryptPassword()
- Reverses Caesar Cipher logic
- Restores original password

Example:
```
Input: mjqqt
Key: 5
Output: hello
```

---

### 3. saveVaultPassword()
Steps:
- Take website name
- Take password input
- Encrypt password
- Save in file format:
  username|website|encrypted_password

---

### 4. retrieveVaultPassword()
Steps:
- Ask for website name
- Read vault.txt line by line
- Split data using '|'
- Match username + website
- Decrypt password
- Display result

---

## Data Flow

User Input → Encryption → File Storage → Retrieval → Decryption → Output

---

## Algorithm

1. Start
2. User selects Save or Retrieve
3. If Save:
   - Encrypt password
   - Write to file
4. If Retrieve:
   - Search file
   - Match record
   - Decrypt password
   - Display result
5. End

---

## Key Concepts Used
- File Handling (ifstream/ofstream)
- String Manipulation
- Character Encoding (ASCII shift)
- Loops
- Conditional Logic
- Function-based Design

---

## Security Note
This is a basic encryption system for educational purposes only. It is not suitable for real-world security applications.
