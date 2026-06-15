# Phase 3 - Text File Compressor (RLE Engine)

## Objective
Implement a file compression and decompression system using Run Length Encoding (RLE) in C++ without OOP concepts.

---

## Concept
Run Length Encoding (RLE) is a simple compression technique where consecutive repeated characters are stored as:

```
count#ASCII_CODE
```

Example:
```
aaaabbbcc
```
becomes:
```
4#97
3#98
2#99
```

---

## Files Used
- Input file (user provided)
- Compressed file (*.txt)
- Decompressed file (*.txt)

---

## Core Functions

### 1. compressTextFile()
Steps:
- Open input file
- Read character by character
- Count consecutive same characters
- Write format: count#ASCII
- Save to new file with suffix `_compressed`

---

### 2. decompressTextFile()
Steps:
- Open compressed file
- Read line by line
- Split data using '#'
- Convert count and ASCII to integers
- Rebuild original text

---

### 3. stringToInt()
- Converts numeric string into integer
- Used in decompression

---

### 4. makeCompressedFileName()
- Adds `_compressed` before extension
- Example:
  - input.txt → input_compressed.txt

---

### 5. makeDecompressedFileName()
- Replaces `_compressed` with `_decompressed`

---

## Data Flow

File Input → RLE Encoding → Save Compressed File
Compressed File → RLE Decoding → Restore Original File

---

## Algorithm

### Compression
1. Start
2. Open file
3. Read first character
4. Count repetition
5. Write count#ASCII
6. Repeat until end
7. Close file

### Decompression
1. Start
2. Open compressed file
3. Read each line
4. Split count and ASCII
5. Convert values
6. Write characters
7. Close file

---

## Key Concepts Used
- File Handling (ifstream/ofstream)
- Loops (for/while)
- String Parsing
- ASCII Conversion
- Function-based Design

---

## Output Example

Input:
```
wwwwaaad
```

Output:
```
4#119
3#97
1#100
```

---

## Notes
This module demonstrates basic data compression techniques used in computer science fundamentals.
