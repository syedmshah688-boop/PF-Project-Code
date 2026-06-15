// ==========================================
// PF Project - Developer's Toolkit Modules
// authentication + vault + compressor
// ==========================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// External utility functions from main.cpp
void clearScreen();
void waitForUser();

// ================= AUTHENTICATION =================

bool usernameExists(string username)
{
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p)
    {
        if (u == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void signUp()
{
    string username, password;

    cout << "\n--- Sign Up ---\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (usernameExists(username))
    {
        cout << "\nUsername already exists!";
        waitForUser();
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\nAccount created successfully!";
    waitForUser();
}

bool logIn(string &loggedInUser)
{
    string username, password;
    string u, p;

    cout << "\n--- Login ---\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> u >> p)
    {
        if (u == username && p == password)
        {
            loggedInUser = username;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// ================= PASSWORD VAULT =================

string encryptPassword(string password, int key)
{
    string enc = "";
    for (char c : password)
        enc += char(c + key);
    return enc;
}

string decryptPassword(string password, int key)
{
    string dec = "";
    for (char c : password)
        dec += char(c - key);
    return dec;
}

void saveVaultPassword(string currentUser, int key)
{
    string website, password;

    cout << "\nWebsite: ";
    cin >> website;
    cout << "Password: ";
    cin >> password;

    string encrypted = encryptPassword(password, key);

    ofstream file("vault.txt", ios::app);
    file << currentUser << "|" << website << "|" << encrypted << endl;
    file.close();

    cout << "\nSaved successfully!";
    waitForUser();
}

void retrieveVaultPassword(string currentUser, int key)
{
    string website, line;

    cout << "\nWebsite: ";
    cin >> website;

    ifstream file("vault.txt");
    bool found = false;

    while (getline(file, line))
    {
        string u = "", w = "", p = "";
        int part = 1;

        for (char c : line)
        {
            if (c == '|') part++;
            else if (part == 1) u += c;
            else if (part == 2) w += c;
            else p += c;
        }

        if (u == currentUser && w == website)
        {
            cout << "\nPassword: " << decryptPassword(p, key);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nNot found!";

    file.close();
    waitForUser();
}

// ================= TEXT COMPRESSOR =================

int stringToInt(string text)
{
    int num = 0;
    for (char c : text)
        num = num * 10 + (c - '0');
    return num;
}

string makeCompressedFileName(string name)
{
    return name + "_compressed.txt";
}

string makeDecompressedFileName(string name)
{
    return name + "_decompressed.txt";
}

void compressTextFile()
{
    string fileName;
    cout << "\nFile name: ";
    cin >> fileName;

    ifstream in(fileName);
    ofstream out(makeCompressedFileName(fileName));

    char curr, next;
    int count = 0;

    if (in.get(curr))
    {
        count = 1;
        while (in.get(next))
        {
            if (next == curr)
                count++;
            else
            {
                out << count << "#" << (int)curr << endl;
                curr = next;
                count = 1;
            }
        }
        out << count << "#" << (int)curr << endl;
    }

    in.close();
    out.close();

    cout << "\nCompressed!";
    waitForUser();
}

void decompressTextFile()
{
    string fileName;
    cout << "\nCompressed file: ";
    cin >> fileName;

    ifstream in(fileName);
    ofstream out(makeDecompressedFileName(fileName));

    string line;

    while (getline(in, line))
    {
        string countS = "", asciiS = "";
        bool hash = false;

        for (char c : line)
        {
            if (c == '#') hash = true;
            else if (!hash) countS += c;
            else asciiS += c;
        }

        int count = stringToInt(countS);
        int ascii = stringToInt(asciiS);

        for (int i = 0; i < count; i++)
            out.put(char(ascii));
    }

    in.close();
    out.close();

    cout << "\nDecompressed!";
    waitForUser();
}
