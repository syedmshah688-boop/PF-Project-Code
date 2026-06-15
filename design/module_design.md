# Module Design - The Developer's Toolkit

## Overview
This document explains the internal structure of each module in the system.

---

# 1. Authentication Module

## Purpose
Handle user registration and login using file-based storage.

## Files Used
- users.txt

## Functions

### signUp()
- Takes username and password
- Checks if username already exists
- Stores new user in file

### logIn()
- Takes username and password
- Compares with stored records
- Returns login success or failure

### usernameExists()
- Scans users.txt
- Returns true if username found

## Data Flow
User Input → Validation → File Check → Success/Fail

---

# 2. Password Vault Module

## Purpose
Store and retrieve encrypted passwords securely.

## Files Used
- vault.txt

## Functions

### encryptPassword()
- Caesar Cipher encryption
- Shifts ASCII values by key

### decryptPassword()
- Reverses Caesar Cipher

### saveVaultPassword()
- Encrypts password
- Saves in file format:
  username|website|encrypted_password

### retrieveVaultPassword()
- Searches file
- Matches user + website
- Decrypts password

## Data Flow
Input → Encrypt → Save → Retrieve → Decrypt → Output

---

# 3. Text Compressor Module

## Purpose
Compress and decompress text files using RLE

## Functions

### compressTextFile()
- Reads file character by character
- Counts repeated characters
- Saves format: count#ASCII

### decompressTextFile()
- Reads compressed file
- Splits count and ASCII
- Rebuilds original text

### stringToInt()
- Converts string numbers to integer

### makeCompressedFileName()
- Adds _compressed suffix

### makeDecompressedFileName()
- Replaces suffix with _decompressed

## Data Flow
File Input → RLE Encode → Save → Decode → Restore File

---

# Design Principles
- Modular programming
- Separation of concerns
- File-based persistence
- Function-based structure (No OOP)
