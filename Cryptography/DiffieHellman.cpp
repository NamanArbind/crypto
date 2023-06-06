#include <iostream>
#include <cmath>
using namespace std;

long long int power(long long int a, long long int b, long long int p)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % p);
}

long long int generate_key(long long int g, long long int p, long long int x, long long int y)
{

    long long int X = power(g, x, p);
    long long int Y = power(g, y, p);
    long long int ka = power(Y, x, p);
    long long int kb = power(X, y, p);
    if (ka == kb)
    {
        return ka;
    }
    else
    {
        return -1;
    }
}

int main()
{
    long long int g, p, x, y;
    cout << "Enter a prime number: ";
    cin >> p;
    cout << "Enter a primitive root of p: ";
    cin >> g;
    cout << "Enter User 1's private key: ";
    cin >> x;
    cout << "Enter User 2's private key: ";
    cin >> y;
    long long int key = generate_key(g, p, x, y);
    if (key != -1)
    {
        cout << "The symmetric key is: " << key << endl;
    }
    else
    {
        cout << "There was an error in generating the key." << endl;
    }
    return 0;
}