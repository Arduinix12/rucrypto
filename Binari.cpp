#include<iostream>
#include"Binari.h"
string  Binari::encrypt(string text) {
    string encryptedText = "";

    for (char& c : text) {
        encryptedText += bitset<8>(c).to_string();
    }

    return encryptedText;
}

string  Binari::decrypt(string text) {
    string decryptedText = "";

    for (size_t i = 0; i < text.length(); i += 8) {
        string byte = text.substr(i, 8);
        decryptedText += char(stoi(byte, nullptr, 2));
    }

    return decryptedText;
}