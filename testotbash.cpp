#include <iostream>
#include "otbash.h"

using namespace std;


int main() {

	Otbash atbash;
	string inputText, encryptedText, decryptedText;
	setlocale(LC_ALL, "RUS");
	cout << "Введите текст для шифрования: ";
	cin >> inputText;

	encryptedText = atbash.encryptOtbas(inputText);
	cout << "Зашифрованный текст: " << encryptedText << endl;

	decryptedText = atbash.decryptOtbas(encryptedText);
	cout << "Расшифрованный текст: " << decryptedText << endl;
}