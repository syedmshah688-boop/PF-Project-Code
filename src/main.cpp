// ==========================================
// The Developer's Toolkit (PF Project)
// Main.cpp - Starter Integration Version
// ==========================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// ---------- Utility Functions ----------
void clearScreen() {
    system("cls");
}

void waitForUser() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// ---------- Authentication Module (Prototypes) ----------
bool usernameExists(string username);
void signUp();
bool logIn(string &loggedInUser);

// ---------- Password Vault Module (Prototypes) ----------
string encryptPassword(string password, int key);
string decryptPassword(string password, int key);
void saveVaultPassword(string currentUser, int secretKey);
void retrieveVaultPassword(string currentUser, int secretKey);

// ---------- Text Compressor Module (Prototypes) ----------
int stringToInt(string text);
string makeCompressedFileName(string inputFileName);
string makeDecompressedFileName(string inputFileName);
void compressTextFile();
void decompressTextFile();

// ---------- Menus ----------
void passwordVaultMenu(string currentUser);
void textCompressorMenu();
void toolkitMenu(string currentUser);

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    int choice;
    string loggedInUser;
    bool loginSuccess;

    while (true) {
        clearScreen();
        cout << "[ MAIN LOGIN SCREEN ]\n";
        cout << "1. Sign Up\n";
        cout << "2. Log In\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            clearScreen();
            signUp();
        }
        else if (choice == 2) {
            clearScreen();
            loginSuccess = logIn(loggedInUser);

            if (loginSuccess) {
                cout << "\nLogin successful.";
                waitForUser();
                toolkitMenu(loggedInUser);
            } else {
                cout << "\nInvalid username or password.";
                waitForUser();
            }
        }
        else if (choice == 3) {
            cout << "\nExiting The Developer's Toolkit...";
            break;
        }
        else {
            cout << "\nInvalid choice.";
            waitForUser();
        }
    }

    return 0;
}
