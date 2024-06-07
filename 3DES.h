
#include"DES.h"

using namespace std;
DES des;
class threDES {

public:
	string encrypt(string k1, string k2, string k3, string word);
	string decrypt(string k1, string k2, string k3, string word);
private:

	string k1;
	string k2;
	string word = "";
	string k3;
	string encode_str = "";
	string decode_str = "";
	string str;



};
