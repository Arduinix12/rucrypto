#ifndef CAESER_H
#define CAESER_H

#include<fstream>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <typeinfo>
#include<vector>
#include<cstdio>
#include <stdlib.h>
using namespace std;

class Caeser {
public:
	Caeser();
	Caeser(string filename);
	Caeser(string inputfile,string outputfile);
	Caeser(string inputfile, string outputfile, string keyfile);
	~Caeser();
	string decript(string str, int key);
	string encript(string str, int key);
	string setword(string str);
	int setkey(int key);
	int read_Datafile( int cryptomode,int key);
	int read_Datafile(int cryptomode);
	

private:
	fstream finputfile;
	fstream foutputfile;
	fstream fkeyfile;
	string str;
		string	inputfile = "con";
		string outputfile = "con";
		string keyfile = "con";
		string errorstr = "con";
		string end = ".txt";
		int key;
		int mode;
		int cryptomode;
	int chekkey(int key);
	bool deleteFile(string filePath);
	int chekfile();

};
#endif
