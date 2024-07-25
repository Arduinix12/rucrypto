#include"Vigenere.h"
string input;
string output;
string key;
int main() {
	VigenereCipher v(input, output);
	v.read_Datafile(1, key);
}