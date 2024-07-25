#include<iostream>
#include<bitset>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

#ifndef XOR_H
#define XOR_H
class XOR
{
public:
	XOR();
	XOR(string inputfile);
	XOR(string inputfile, string outputfile);
	XOR(string inputfile, string outputfile, string keyfile);
	~XOR();
	string decrypt(string text, string key);
	string encrypt(string text, string key);
	int read_Datafile(int cryptomode, string key);
	int read_Datafile(int cryptomode);

private:
	string text;
	string key;
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

};



#endif 

