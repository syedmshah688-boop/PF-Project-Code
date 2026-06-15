# Program Flow - The Developer's Toolkit

## System Overview Flow

```
START
  |
  v
MAIN LOGIN SCREEN
  |
  +--> Sign Up
  |       |
  |       v
  |   Store User in users.txt
  |
  +--> Log In
          |
          v
   Validate Credentials
          |
     +----+----+
     |         |
    FAIL      SUCCESS
     |         |
     v         v
  Show Error   MAIN TOOLKIT MENU
                   |
                   +----------------------+
                   |                      |
                   v                      v
        Password Vault           Text Compressor
                   |                      |
                   v                      v
        Save / Retrieve        Compress / Decompress
                   |                      |
                   +----------+-----------+
                              |
                              v
                          Back to Menu

```

---

## Password Vault Flow

```
Input Username/Password
        |
        v
Check User Exists?
        |
   +----+----+
   |         |
  YES       NO
   |         |
   v         v
Login OK   Show Error
   |
   v
Enter Vault Menu
   |
   +--> Save Password
   |        |
   |        v
   |   Encrypt Password
   |        |
   |        v
   |   Store in vault.txt
   |
   +--> Retrieve Password
            |
            v
     Find Matching Entry
            |
            v
     Decrypt Password
            |
            v
        Display Result
```

---

## Text Compressor Flow

```
Select File
   |
   +--> Compress
   |       |
   |       v
   |   Read File Character by Character
   |       |
   |       v
   |   Apply Run Length Encoding (RLE)
   |       |
   |       v
   |   Save Compressed File
   |
   +--> Decompress
           |
           v
     Read Encoded File
           |
           v
     Parse count#ASCII
           |
           v
     Rebuild Original Text
           |
           v
     Save Output File
```

---

## Key Idea

- Menu-driven console system
- File-based storage
- Modular function-based design
- Step-by-step execution flow
