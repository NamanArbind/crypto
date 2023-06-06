#include <iostream>
#include <string>
using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
}

string encrypt(string plain, int a, int b) {
    string cipher = "";
    for (int i = 0; i < plain.length(); i++) {
         
        if (plain[i] == ' ')
            continue;
         
        cipher += (char)((a * (plain[i] - 'A') + b) % 26 + 'A');
    }
    return cipher;
}

string decrypt(string cipher, int a, int b) {
    string plain = "";
    int a_inv = modInverse(a, 26);  
    for (int i = 0; i < cipher.length(); i++) {
        if (cipher[i] == ' ')
            continue;
         
        plain += (char)((a_inv * (cipher[i] + 'A' - b)) % 26 + 'A');
    }
    return plain;
}

 
int main() {
    string plain;
    int a;  
    int b;  
    cout<<"Enter the plain text: ";
    cin>>plain;
    cout<<"Enter the Multiplicative value: ";
    cin>>a;
    cout<<"Enter the Additive value: ";
    cin>>b;
    string cipher = encrypt(plain, a, b);
    cout << "Plain text: " << plain << endl;
    cout << "Cipher text: " << cipher << endl;
    cout << "Decrypted text: " << decrypt(cipher, a, b) << endl;
    return 0;
}
