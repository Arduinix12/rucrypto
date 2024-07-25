
#include<iostream>
#include<bitset>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

#ifndef BINARI_H
#define BINARI_H
class Binari {
public:
	Binari();
	Binari(string inputfile);
	Binari(string inputfile, string outputfile);
	Binari(string inputfile, string outputfile, string keyfile);
	~Binari();
	string encrypt(int key,string text);
	string decrypt(int key,string text);
	int read_Datafile(int cryptomode, int key);
	int read_Datafile(int cryptomode);

private:
	string text="";
	int key;
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
