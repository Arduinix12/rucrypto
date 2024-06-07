#include "otbash.h"
#include<iostream>

using namespace std;



string Otbash::encryptOtbas(string text) {
    

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text += char('Z' - (text[i] - 'A'));
            }
            else {
                text += char('z' - (text[i] - 'a'));
            }
        }
        else {
            text += text[i];
        }
    }
    return text;
}

string Otbash::decryptOtbas(string text) {
    

    for (char ch : text) {
        if (isalpha(ch)) {
            if (islower(ch)) {
                text += 'z' - (ch - 'a');
            }
            else {
                text += 'Z' - (ch - 'A');
            }
        }
        else {
            text += ch;
        }
    }

    return text;
}
