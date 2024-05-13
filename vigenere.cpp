#include "Vigenere.h"

using namespace std;

void VigenereCipher::setkey(string key) {
    transform(key.begin(), key.end(), key.begin(), [](unsigned char c) {return toupper(c); });
    this->key = key;
}

string VigenereCipher::encrypt(const string& text) {
    string output;
    //���������� ������
    string effectiveKey = getKey(text, key);
    for (size_t i = 0; i < text.size(); i++) {
        output += cipherChar(text[i], effectiveKey[i], true);
    }
    return output;
}

string VigenereCipher::decrypt(const string& text) {
    string output;
    //������������ ������
    string effectiveKey = getKey(text, key);
    for (size_t i = 0; i < text.size(); i++) {
        output += cipherChar(text[i], effectiveKey[i], false);
    }
    return output;
}

string VigenereCipher::getKey(const string& text, const string& key) {
    //�������� ����
    string resultKey = key;
    while (resultKey.size() < text.size()) {
        resultKey += key;
    }
    //�������� ����
    resultKey = resultKey.substr(0, text.size());
    return resultKey;
}

char VigenereCipher::cipherChar(char c, char key, bool encode) {
    //����������/������������ �������

    if (!isalpha(c)) return c;

    char base = islower(c) ? 'a' : 'A';
    char keyBase = islower(key) ? 'a' : 'A';
    int offset = key - keyBase;

    if (encode) {
        //���������� �������
        return base + (c - base + offset) % 26;
    }
    else {
        //������������� �������
        return base + (26 + c - base + offset) % 26;
        // ��� ����� �������� �������� �� ��������
    }
}