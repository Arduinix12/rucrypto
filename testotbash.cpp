#include <iostream>
#include "otbash.h"

using namespace std;


int main() {

	Otbash atbash;
	string inputText, encryptedText, decryptedText;
	setlocale(LC_ALL, "RUS");
	cout << "������� ����� ��� ����������: ";
	cin >> inputText;

	encryptedText = atbash.encryptOtbas(inputText);
	cout << "������������� �����: " << encryptedText << endl;

	decryptedText = atbash.decryptOtbas(encryptedText);
	cout << "�������������� �����: " << decryptedText << endl;
}