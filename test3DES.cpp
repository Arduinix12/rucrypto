#include"3DES.h"
string k1, k2, k3;
string word = "hello world!";
threDES tdes;
int main() {
	string k1 = "key1";
	string k2 = "key2";
	string k3 = "key3";
	string message = "Hello World";
	string encrypted_message = tdes.encrypt(k1, k2, k3, message);
	string decrypted_message = tdes.decrypt(k1, k2, k3, encrypted_message);

	cout << "Original Message: " << message << endl;
	cout << "Encrypted Message: " << encrypted_message << endl;
	cout << "Decrypted Message: " << decrypted_message << endl;

}