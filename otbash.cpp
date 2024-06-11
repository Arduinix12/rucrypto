#include "otbash.h"
#include<iostream>

using namespace std;



string Otbash::encryptOtbas(string text) {
    string encryptedText = "";


        for (int i = 0; i < text.length(); i++) {
            if (isalpha(text[i])) {
                if (isupper(text[i])) {
                    encryptedText += char('Z' - (text[i] - 'A'));
                }
                else {
                    encryptedText += char('z' - (text[i] - 'a'));
                }
            }
            else {
                encryptedText += text[i];
            }
        }
    return encryptedText;
}

string Otbash::decryptOtbas(string text) {
    string decryptedText = "";


        for (char ch : text) {
            if (isalpha(ch)) {
                if (islower(ch)) {
                    decryptedText += 'a' + ('z' - ch);
                }
                else {
                    decryptedText += 'A' + ('Z' - ch);
                }
            }
            else {
                decryptedText += ch;
            }
        }

    return decryptedText;
}
