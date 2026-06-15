#include <iostream>
#include <string>

using namespace std;

// External functions
void saveVaultPassword(string currentUser, int secretKey);
void retrieveVaultPassword(string currentUser, int secretKey);
void compressTextFile();
void decompressTextFile();

void passwordVaultMenu(string currentUser)
{
    int choice;
    int key = 5;

    while (true)
    {
        cout << "\n--- PASSWORD VAULT ---\n";
        cout << "1. Save Password\n";
        cout << "2. Retrieve Password\n";
        cout << "3. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            saveVaultPassword(currentUser, key);
        else if (choice == 2)
            retrieveVaultPassword(currentUser, key);
        else
            break;
    }
}

void textCompressorMenu()
{
    int choice;

    while (true)
    {
        cout << "\n--- TEXT COMPRESSOR ---\n";
        cout << "1. Compress File\n";
        cout << "2. Decompress File\n";
        cout << "3. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            compressTextFile();
        else if (choice == 2)
            decompressTextFile();
        else
            break;
    }
}

void toolkitMenu(string currentUser)
{
    int choice;

    while (true)
    {
        cout << "\n=== TOOLKIT MENU ===\n";
        cout << "1. Password Vault\n";
        cout << "2. Text Compressor\n";
        cout << "3. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            passwordVaultMenu(currentUser);
        else if (choice == 2)
            textCompressorMenu();
        else
            break;
    }
}