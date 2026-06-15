#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encryptPassword(string password, int key)
{
    string encrypted = "";

    for (char c : password)
    {
        encrypted += char(c + key);
    }

    return encrypted;
}

string decryptPassword(string password, int key)
{
    string decrypted = "";

    for (char c : password)
    {
        decrypted += char(c - key);
    }

    return decrypted;
}

void saveVaultPassword(string currentUser, int secretKey)
{
    string website, password;

    cout << "\n--- SAVE PASSWORD ---\n";
    cout << "Website: ";
    cin >> website;
    cout << "Password: ";
    cin >> password;

    string encrypted = encryptPassword(password, secretKey);

    ofstream file("vault.txt", ios::app);
    file << currentUser << "|" << website << "|" << encrypted << endl;
    file.close();

    cout << "Password saved!\n";
}

void retrieveVaultPassword(string currentUser, int secretKey)
{
    string website;
    cout << "\n--- RETRIEVE PASSWORD ---\n";
    cout << "Website: ";
    cin >> website;

    ifstream file("vault.txt");
    string line;
    bool found = false;

    while (getline(file, line))
    {
        string user = "", site = "", pass = "";
        int field = 1;

        for (char c : line)
        {
            if (c == '|') field++;
            else if (field == 1) user += c;
            else if (field == 2) site += c;
            else pass += c;
        }

        if (user == currentUser && site == website)
        {
            cout << "Password: " << decryptPassword(pass, secretKey) << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No password found!\n";

    file.close();
}