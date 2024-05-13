#include"Caesar.h"

using namespace std;

string Caeser::getword(string str) {
	this->str = str;
	return str;
}
int Caeser::chekkey(int key) {
    setlocale(LC_ALL, "RUS");
   
const char* type = typeid(key).name();
if (type == "i") {
    if (key != 0) {
        return 0;
    }
    else if (key == 0) {
        cerr << "переменная не может быть равна 0!\n";
        return 1;
    }
}
else if (type != "i") {

    cerr << "переменная должна быть целым числом!\n";
    return -1;
}

}
int Caeser::getkey(int key) {

	this->key = key;
  chekkey(key);
    return key;
}
string Caeser::encript(string str, int key) {
    int length = str.length();
    std::string encryptedStr = "";
    for (int i = 0; i < length; i++)
    {
        char c = str[i];

        if (isalpha(c))
        {
            int new_shift = key % 26;
            if (islower(c))
            {
                char base = 'a';
                c = (c - base + new_shift) % 26 + base;
            }
            else
            {
                char base = 'A';
                c = (c - base + new_shift) % 26 + base;
            }
        }

        encryptedStr += c;
    }

    return encryptedStr;
}

string Caeser::decript(string str, int key) {
    int n = str.length();
    std::string decryptedStr = "";

    for (int i = 0; i < n; i++) {
        char decryptedChar = str[i] - key;
        if (isalpha(str[i])) {
            if (islower(str[i]) && decryptedChar < 'a') {
                decryptedChar = decryptedChar + 26;
            }
            else if (isupper(str[i]) && decryptedChar < 'A') {
                decryptedChar = decryptedChar + 26; 
            }
        }

        decryptedStr += decryptedChar;
    }

    return decryptedStr;
    
}