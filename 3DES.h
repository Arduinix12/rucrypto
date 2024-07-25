
#include"DES.h"
#ifndef TRUDES_H
#define  TRUDES_H

using namespace std;
DES des;
class threDES {

public:
	threDES();
	threDES(string inputfile);
	threDES(string inputfile, string outputfile);
	threDES(string inputfile, string outputfile, string keyfile);
	~threDES();
	int read_Datafile(int cryptomode, string k1,string k2, string k3);
	int read_Datafile(int cryptomode);
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

	fstream finputfile;
	fstream foutputfile;
	fstream fkeyfile;
	string	inputfile = "con";
	string outputfile = "con";
	string keyfile = "con";
	string errorstr = "con";
	string end = ".txt";
	int mode;
	int cryptomode;
	bool deleteFile(string filePath);
	int chekfile();
	int get_fkey(vector<char> buffer);


};
#endif