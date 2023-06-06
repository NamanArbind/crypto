#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <openssl/md5.h>
using namespace std;

string generatePassword(int n)
{
    static const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;
    string password = "";
    for (int i = 0; i < n; i++)
    {
        password += alphanum[rand() % stringLength];
    }
    return password;
}

string hashPassword(string password)
{

    static const char hexDigits[] = "0123456789abcdef";
    unsigned char hash[16];
    MD5((unsigned char *)password.c_str(), password.length(), hash);
    string hashedPassword = "";
    for (int i = 0; i < 16; i++)
    {
        hashedPassword += hexDigits[hash[i] >> 4];
        hashedPassword += hexDigits[hash[i] & 0xF];
    }
    return hashedPassword;
}

string generateSalt(int n)
{

    static const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;
    string salt = "";
    for (int i = 0; i < n; i++)
    {
        salt += alphanum[rand() % stringLength];
    }
    return salt;
}

string saltPassword(string password, string salt)
{
    string saltedPassword = password + salt;
    return saltedPassword;
}

void writeFile(string fileName, string data[], int size)
{
    ofstream file(fileName);
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            file << data[i] << "\n";
        }
        file.close();
        cout << "File " << fileName << " written successfully.\n";
    }
    else
    {
        cout << "Unable to open file " << fileName << ".\n";
    }
}

void readFile(string fileName, string data[], int size)
{
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;
        int i = 0;
        while (getline(file, line) && i < size)
        {
            data[i] = line;
            i++;
        }
        file.close();
        cout << "File " << fileName << " read successfully.\n";
    }
    else
    {
        cout << "Unable to open file " << fileName << ".\n";
    }
}

bool checkPassword(string password, string hash)
{
    string hashedPassword = hashPassword(password);
    if (hashedPassword == hash)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkPasswordWithSalt(string password, string hash, string salt)
{
    string saltedPassword = saltPassword(password, salt);
    string hashedPassword = hashPassword(saltedPassword);
    if (hashedPassword == hash)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(0));
    const int N = 10;
    const int P = 8;
    const int S = 16;
    string passwords[N];
    string hashes[N];
    string salts[N];
    for (int i = 0; i < N; i++)
    {
        passwords[i] = generatePassword(P);
    }
    writeFile("passwords.txt", passwords, N);
    for (int i = 0; i < N; i++)
    {
        hashes[i] = hashPassword(passwords[i]);
    }
    writeFile("hashes.txt", hashes, N);
    for (int i = 0; i < N; i++)
    {
        salts[i] = generateSalt(S);
        hashes[i] = hashPassword(saltPassword(passwords[i], salts[i]));
    }
    writeFile("salts.txt", salts, N);
    return 0;
}