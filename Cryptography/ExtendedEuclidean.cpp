#include <iostream>
using namespace std;

int extendedEuclid(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extendedEuclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

int modInverse(int a, int m) {
  int x, y;
  int gcd = extendedEuclid(a, m, x, y);
  if (gcd != 1) {
    return -1;
  }
  return (x % m + m) % m;
}

int main() {
   
  int a, m;
  cout << "Enter a number: ";
  cin >> a;
  cout << "Enter a modulus: ";
  cin >> m;
  int inverse = modInverse(a, m);
  if (inverse == -1) {
    cout << "There is no modular inverse of " << a << " modulo " << m << endl;
  }
  else {
    cout << "The modular inverse of " << a << " modulo " << m << " is " << inverse << endl;
  }
  return 0;
}
