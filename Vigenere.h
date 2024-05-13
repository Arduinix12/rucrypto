
//VigenereCipher.h


#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <cctype>
#include <iostream>
#include <algorithm>

#include <string>

using namespace std;

class VigenereCipher {
public:
	void setkey(string key);
	string encrypt(const string& text);
	string decrypt(const string& text);

private:
	string key;
	string getKey(const string& text, const string& key);
	char cipherChar(char c, char key, bool encode = true);
};

#endif