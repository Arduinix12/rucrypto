#include"xor.h"

string XOR::encrypt(string text, string key) {
	string encrypted_text;


		for (size_t i = 0; i < text.size(); ++i) {
			encrypted_text += text[i] ^ key[i % key.size()];
		}

	return encrypted_text;
}




string XOR::decrypt(string text,string key){
	string decrypted_text;

	
		
		for (size_t i = 0; i < text.size(); ++i) {
			decrypted_text += text[i] ^ key[i % key.size()];
		}

	return decrypted_text;
}