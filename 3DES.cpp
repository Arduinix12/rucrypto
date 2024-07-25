#include"3DES.h"

string threDES::encrypt(string k1, string k2, string k3, string word) {
	string encode_str = "";
	encode_str = des.encode(word, k1);
	word = encode_str;
	encode_str = des.decode(word, k2);
	word = encode_str;
	encode_str = des.encode(word, k3);
	return encode_str;
}
string threDES::decrypt(string k1, string k2, string k3, string word) {
	string decode_str = "";
	decode_str = des.decode(word, k3);
	word = decode_str;
	decode_str = des.encode(word, k2);
	word = decode_str;
	decode_str = des.decode(word, k1);
	return decode_str;

}