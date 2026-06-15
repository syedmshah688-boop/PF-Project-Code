#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool usernameExists(string username)
{
    ifstream file("users.txt");
    string storedUser, storedPass;

    while (file >> storedUser >> storedPass)
    {
        if (storedUser == username)
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

    cout << "\n--- SIGN UP ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (usernameExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Account created successfully!\n";
}

bool logIn(string &loggedInUser)
{
    string username, password;
    string storedUser, storedPass;

    cout << "\n--- LOGIN ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> storedUser >> storedPass)
    {
        if (storedUser == username && storedPass == password)
        {
            loggedInUser = username;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}