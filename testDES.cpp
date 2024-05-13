#include <iostream>
#include "DES.h"
using namespace std;
DES des;
string c, k;

int main() {
    
    cout << "Plaintext: ";
    cin >> c;
    cout << "Key: ";
    cin >> k;
    
    cout << "result: ";
    des.encode(c, k);
    cout << endl;
    cout << "Ciphertext: ";
    cin >> c;
    cout << "Key: ";
    cin >> k;
    cout << "result: ";
    des.decode(c, k);
    return 0;
}
