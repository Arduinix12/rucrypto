#include"Binari.h"
using namespace std;

Binari bit;
string text = "Hello, World!";
string encryptedText;
string decryptedText;

int main() {
    encryptedText = bit.encrypt(text);
     decryptedText = bit.decrypt(encryptedText);

    cout << "Original Text: " << text << "\n";
    cout << "Encrypted Text: " << encryptedText << "\n";
    cout << "Decrypted Text: " << decryptedText << "\n";

    return 0;
}