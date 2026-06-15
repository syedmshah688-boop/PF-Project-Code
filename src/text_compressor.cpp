#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int stringToInt(string text)
{
    int num = 0;
    for (char c : text)
    {
        num = num * 10 + (c - '0');
    }
    return num;
}

string makeCompressedFileName(string input)
{
    return input + "_compressed.txt";
}

string makeDecompressedFileName(string input)
{
    return input + "_decompressed.txt";
}

void compressTextFile()
{
    string input;
    cout << "\nEnter file name: ";
    cin >> input;

    ifstream file(input);
    ofstream out(makeCompressedFileName(input));

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    char current, next;
    if (file.get(current))
    {
        int count = 1;

        while (file.get(next))
        {
            if (next == current)
                count++;
            else
            {
                out << count << "#" << (int)current << endl;
                current = next;
                count = 1;
            }
        }

        out << count << "#" << (int)current << endl;
    }

    file.close();
    out.close();

    cout << "Compression done!\n";
}

void decompressTextFile()
{
    string input;
    cout << "\nEnter compressed file: ";
    cin >> input;

    ifstream file(input);
    ofstream out(makeDecompressedFileName(input));

    string line;

    while (getline(file, line))
    {
        string countStr = "", asciiStr = "";
        bool hash = false;

        for (char c : line)
        {
            if (c == '#') hash = true;
            else if (!hash) countStr += c;
            else asciiStr += c;
        }

        int count = stringToInt(countStr);
        int ascii = stringToInt(asciiStr);

        for (int i = 0; i < count; i++)
            out.put((char)ascii);
    }

    file.close();
    out.close();

    cout << "Decompression done!\n";
}