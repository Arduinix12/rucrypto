
//VigenereCipher.h


#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <cctype>
#include <iostream>
#include <algorithm>
#include<fstream>
#include <string>
#include<vector>

using namespace std;

class VigenereCipher {
public:
	VigenereCipher();
	VigenereCipher(string inputfile);
	VigenereCipher(string inputfile, string outputfile);
	VigenereCipher(string inputfile, string outputfile, string keyfile);
	void setkey(string key);
	string encrypt(const string& text);
	string decrypt(const string& text);
	~VigenereCipher();
	int read_Datafile(int cryptomode, string key);
	int read_Datafile(int cryptomode);

private:
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
	string key;
	string getKey(const string& text, const string& key);
	char cipherChar(char c, char key, bool encode = true);
	bool deleteFile(string filePath);
	int chekfile();
};

#endif