#include <iostream>
#include <string>
using namespace std;

int hashe(string message)
{
    int result = 0;
    for (char c : message)
    {
        result = (result * 31 + c) % 1000000;
    }
    return result;
}

void check_integrity(string message, int original_hashe)
{
    int new_hashe = hashe(message);
    if (new_hashe == original_hashe)
    {
        cout << "The message is intact.\n";
    }
    else
    {
        cout << "The message is corrupted.\n";
    }
}

int main()
{
    string message;
    cout<<"Enter the original message: ";
    cin>>message;
    int original_hashe = hashe(message);
    cout << "The original message is: " << message << "\n";
    cout << "The original  hashe is: " << original_hashe << "\n";
    check_integrity(message, original_hashe);
    message[0] = 'n';
    cout << "The changed message is: " << message << "\n";
    check_integrity(message, original_hashe);
    return 0;
}
