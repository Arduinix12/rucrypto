

#include<fstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

#ifndef OTBASH_H
#define OTBASH_H

class Otbash
{
public:
	Otbash();
	Otbash(string inputfile);
	Otbash(string inputfile, string outputfile);
	~Otbash();
	string encryptOtbas(string text);
	string decryptOtbas(string text);
	int read_Datafile(int cryptomode);
private:
	string text;
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
